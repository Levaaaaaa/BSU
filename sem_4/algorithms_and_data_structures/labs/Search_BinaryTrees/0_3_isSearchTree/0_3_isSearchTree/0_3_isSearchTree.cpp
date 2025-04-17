// 0_3_isSearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <chrono>

using namespace std;

long long source[800001] = { 0 };
//long long range_min[800001] = { 0 };
//long long range_max[800001] = { 0 };
int main()
{
    
    //chrono::system_clock::time_point start = chrono::system_clock::now();
    std::ios_base::sync_with_stdio(false);

    
    ifstream in("bst.in");
    in.tie(nullptr);
    long long count;
    in >> count;
    //    vector<long long> source(count);
    in >> source[0];
    int j;
    vector<pair<long long, long long>> intervals(count);
    //vector<long long> range_min(count);
    //vector<long long> range_max(count);

    intervals[0].first = -LLONG_MAX;
    intervals[0].second = LLONG_MAX;
    //range_min[0] = LLONG_MIN;
    //range_max[0] = LLONG_MAX;
    //bool result = true;
    char l;
    ofstream out("bst.out");
    for (long long i = 1; i < count; i++) {
        in >> source[i] >> j >> l;
        if (l == 'L') {
            if (!(intervals[j - 1].first <= source[i] && source[i] < source[j - 1])) {
      //          result = false;
                out << "NO";
                return 0;
            }
            intervals[i].first = intervals[j - 1].first;
//            range_min[i] = range_min[j - 1];
  //          range_max[i] = source[j - 1];
            intervals[i].second = source[j - 1];
        }
        else {
            if (!(source[j - 1] <= source[i] && source[i] < intervals[j-1].second/*range_max[j - 1]*/)) {
        //        result = false;
                out << "NO";
                return 0;
            }
            intervals[i].first = source[j - 1];
            intervals[i].second = intervals[j - 1].second;
          //  range_min[i] = source[j - 1];
          //  range_max[i] = range_max[j - 1];
        }
    }
    in.close();
    //out << chrono::system_clock::now() - start << "\n";
    out << "YES";
    out.close();

    return 0;
}

/*
long long source[800001] = { 0 };
long long range_min[800001] = { 0 };
long long range_max[800001] = { 0 };
int main()
{
    std::ios_base::sync_with_stdio(false);

    ifstream in("bst.in");
    in.tie(nullptr);
    long long count;
    in >> count;
//    vector<long long> source(count);
    in >> source[0];
    long long j;
    vector<long long> range_min(count);
    vector<long long> range_max(count);

    range_min[0] = numeric_limits<long long>::min();
    range_max[0] = numeric_limits<long long>::max();
    bool result = true;
    char l;
    for (long long i = 1; i < count; i++) {
        in >> source[i] >> j >> l;
        
        //j = parents[i - 1];
        if (l == 'L') {
            range_min[i] = range_min[j - 1];
            range_max[i] = source[j - 1];
        }
        else {
            range_min[i] = source[j - 1];
            range_max[i] = range_max[j - 1];
        }
        if (source[i] < range_min[i] || source[i] >= range_max[i]) {
            result = false;
        }
    }
    in.close();

    ofstream out("bst.out");
    out.tie(nullptr);
    if (result) {
        out << "YES";
    }
    else {
        out << "NO";
    }
    out.close();

    return 0;
}
*/
/*
2
-2147483647
-2147483647 1 R
*/