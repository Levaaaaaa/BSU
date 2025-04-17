#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

#include <chrono>
#include <iostream>

using namespace std;

int n;
vector<list<int>> g;
vector<vector<bool>> adjacent_matrix;

vector<bool> visited;
vector<int> h, d;
set<pair<int, int>> cut_vertexes_set = set<pair<int, int>>();
set<int> special_vertexes;
vector<int> bridges;
vector<bool> is_cut_vertex;
vector<vector<int>> blocks;

vector<vector<int>> local_painted_blocks;
vector<int> block_colors_count;
vector<int> general_colors;
int barrier;
int global_max_color = 0;

void dfs(int v, int p = -1) {
	visited[v] = true;
	d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
	int children = 0;
	for (int u : g[v]) {
		if (u != p) {
			if (visited[u]) {
				d[v] = min(d[v], h[u]);
			}
			else {
				dfs(u, v);
				d[v] = min(d[v], d[u]);
				if (h[v] < d[u]) {
					cut_vertexes_set.insert(pair<int, int>(u, v));
					//					cut_vertexes_set.insert(v);
						//				bridges.push_back(pair<int, int>(u, v));
				}
				else if (h[v] == d[u] && p != -1) {
					cut_vertexes_set.insert(pair<int, int>(v, v));
					//bridges.push_back(pair<int, int>(v, v));
				}
				children++;
			}
		}
	}

	if (p == -1 && children > 1) {
		cut_vertexes_set.insert(pair<int, int>(v, v));
	}
}

set<int> build_block(int start, int current_vertex, set<int> current_block, vector<bool> &local_visited) {
	if (current_vertex == start) {
		return current_block;
	}

	local_visited[current_vertex] = true;
	current_block.insert(current_vertex);

	if (is_cut_vertex[current_vertex] && current_vertex != start) {
		for (int adjacent_vertex : special_vertexes) {
			if (adjacent_matrix[current_vertex][adjacent_vertex] && !local_visited[adjacent_vertex] && bridges[current_vertex] != adjacent_vertex) {
				current_block = build_block(start, adjacent_vertex, current_block, local_visited);
			}
		}
		return current_block;
	}
	for (int adjacent_vertex : g[current_vertex]) {
		if (!local_visited[adjacent_vertex] && bridges[adjacent_vertex] != current_vertex) {
			current_block = build_block(start, adjacent_vertex, current_block, local_visited);
		}
	}

	return current_block;
}
void build_blocks() {
	list<set<int>> blocks_list = list<set<int>>();
	vector<bool> local_visited = vector<bool>(n, false);
	for (int spec_vertex : special_vertexes) {
		for (int adjacent_vertex : g[spec_vertex]) {

			if (!local_visited[adjacent_vertex] && bridges[spec_vertex] != adjacent_vertex) {
				set<int> block = set<int>();
				block.insert(spec_vertex);

				block = build_block(spec_vertex, adjacent_vertex, block, local_visited);
				blocks_list.push_back(block);
				local_visited[spec_vertex] = false;
			}
		}
		local_visited[spec_vertex] = true;
	}


	if (blocks_list.empty()) {
		blocks = vector<vector<int>>(1);
		vector<int> single_block = vector<int>(n-1);
		for (int i = 1; i < n; i++) {
			single_block[i-1] = i;
		}
		blocks[0] = single_block;
		return;
	}

	blocks = vector<vector<int>>(blocks_list.size());

	int k = 0;
	for (set<int> block : blocks_list) {
		vector<int> vector_block = vector<int>(block.size());
		int j = 0;
		for (int item : block) {
			vector_block[j++] = item;
		}
		blocks[k++] = vector_block;
	}
}

list<int> find_clique(int start) {
	list<int> clique = list<int>();
	clique.push_back(start);
	for (int adjacent_vertex : g[start]) {
		bool is_adjacent_for_all = true;
		for (int clique_vertex : clique) {
			if (!adjacent_matrix[clique_vertex][adjacent_vertex]) {
				is_adjacent_for_all = false;
			}
		}
		if (is_adjacent_for_all) {
			clique.push_back(adjacent_vertex);
		}
	}

	return clique;
}

//оптимально красит блок
bool paint_periphery_block(int cur_v_index, vector<int> &colors, vector<bool> &local_visited, int block) {
	if (cur_v_index == blocks[block].size()) {
		return true;
	}

	int current_vertex = blocks[block][cur_v_index];
	if (local_visited[current_vertex]) {
		return paint_periphery_block(cur_v_index+1, colors, local_visited, block);
	}

	vector<bool> available = vector<bool>(n, true);
	for (int adjacent_vertex : g[current_vertex]) {
		int adj_color = colors[adjacent_vertex];
		available[adj_color] = adj_color == 0;
	}

	for (int color = 1; color < barrier; color++) {
		if (available[color]) {
			colors[current_vertex] = color;
			if (paint_periphery_block(cur_v_index + 1, colors, local_visited, block)) {
				return true;
			}
		}
	}

	colors[current_vertex] = 0;
	return false;
}

vector<int> paint_block(int block) {
	list<int> clique = find_clique(*blocks[block].begin());
	vector<bool> local_visited(n, false);
	int max_color = blocks[block].size();
	vector<int> local_colors = vector<int>(n, 0);
	int color = 1;
	for (int i : clique) {
		local_colors[i] = color++;
		local_visited[i] = true;
	}

	for (barrier = color; barrier < n; barrier++) {
		if (paint_periphery_block(1, local_colors, local_visited, block)) {
			break;
		}
	}

	local_painted_blocks[block] = local_colors;
	block_colors_count[block] = barrier - 1;
	global_max_color = max(global_max_color, barrier - 1);
	return local_colors;
}

void solve_conflict(int block, int vertex) {
	vector<bool> available = vector<bool>(n, true);
	for (int adjacent_vertex : g[vertex]) {
		int color = general_colors[adjacent_vertex];
		available[color] = color == 0;
	}

	for (int color = global_max_color; color >= 1; color--) {
		if (available[color]) {
			general_colors[vertex] = color;
			return;
		}
	}

	int main_color = general_colors[vertex];
	int local_color = local_painted_blocks[block][vertex];

	for (int block_vertex : blocks[block]) {
		if (general_colors[block_vertex] == main_color) {
			general_colors[block_vertex] = local_color;
		}
		else if (general_colors[block_vertex] == local_color) {
			general_colors[block_vertex] = main_color;
		}
	}
}

int main() {
	
	//chrono::time_point<chrono::steady_clock> start, finish;

	//start = chrono::steady_clock::now();
	
	clock_t start = clock();
	std::ios_base::sync_with_stdio(false);
	ifstream in("colgraph.in");
	in.tie(nullptr);
	in >> n;
	n++;

	g = vector<list<int>>(n, list<int>());
	general_colors = vector<int>(n, 0);
	int u, v;
	adjacent_matrix = vector<vector<bool>>(n, vector<bool>(n, false));
	while (!in.eof()) {
		in >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		adjacent_matrix[u][v] = true;
		adjacent_matrix[v][u] = false;
	}

	visited = vector<bool>(n, false);
	h = vector<int>(n);
	d = vector<int>(n);

	//separate graph to blocks
	dfs(1);
//	visited = vector<bool>(n, false);
	special_vertexes = set<int>();
	int k = 0;
	bridges = vector<int>(n, 0);
	for (pair<int, int> vertex : cut_vertexes_set) {
		special_vertexes.insert(vertex.first);
		special_vertexes.insert(vertex.second);
	}
	is_cut_vertex = vector<bool>(n, false);
	for (pair<int, int> vertex : cut_vertexes_set) {
		if (vertex.first == vertex.second) {
			is_cut_vertex[vertex.first] = true;
		}
		else {
			bridges[vertex.first] = vertex.second;
			bridges[vertex.second] = vertex.first;
		}
	}
	build_blocks();
	block_colors_count = vector<int>(blocks.size(), 1);
	local_painted_blocks = vector<vector<int>>(blocks.size());

	for (int i = 0; i < blocks.size(); i++) {
		paint_block(i);
	}

	for (int block = 0; block < blocks.size(); block++) {
		for (int vertex = 1; vertex < n; vertex++) {
			if (local_painted_blocks[block][vertex] != 0) {
				if (general_colors[vertex] == 0) {
					general_colors[vertex] = local_painted_blocks[block][vertex];
				}
				else {
					//solve conflict
					solve_conflict(block, vertex);
				}
			}
		}
	}
	in.close();

	
	ofstream out("colgraph.out");

	out.tie(nullptr);

	out << global_max_color << "\n";
	for (int i = 1; i < n; i++) {
		out << general_colors[i] << " ";
	}

	out.close();
	
//	finish = chrono::steady_clock::now();

	
	clock_t end = clock();

	cout << (double)(end - start) / CLOCKS_PER_SEC;
	//auto duration = chrono::duration_cast<chrono::microseconds>(finish - start);
	//cout << duration.count() / 1000;
	
	return 0;
}