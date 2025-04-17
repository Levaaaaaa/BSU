// 0_2_DeleteFromTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

template <class T>
class MyNode {
public:
    MyNode<T>(T v) : value(v), left(0), right(0) {
    }
    T value;
    MyNode* left;
    MyNode* right;
};

template <class U>
class MyTree {
public:
    MyTree<U>() : root(0) {
    }

    ~MyTree<U>() {
        DestroyNode(root);
    }

    MyNode<U>* root;

    void buildTree(istream& in) {
        U u;
        while (!in.eof()) {
            in >> u;
            this->insert(u);
        }
    }

    static void CLR(MyNode<U>* root, ostream& out) {
        if (root == nullptr) {
            return;
        }
        out << root->value << endl;
        CLR(root->left, out);
        CLR(root->right, out);
    }

    void insert(U t) {
        MyNode<U>** cur = &root;
        while (*cur) {
            MyNode<U>& node = **cur;
            if (t < node.value) {
                cur = &node.left;
            }
            else if (t > node.value) {
                cur = &node.right;
            }
            else {
                return;
            }
        }
        *cur = new MyNode<U>(t);
    }

    void remove_node_right(U u) {
        MyNode<U>* v = root;
        MyNode<U>* parent = nullptr;
        while (true) {
            if (v == nullptr) {
                return;
            }
            if (u < v->value) {
                parent = v;
                v = v->left;
            }
            else if (u > v->value) {
                parent = v;
                v = v->right;
            }
            else if (u == v->value) {
                break;
            }
        }

        MyNode<U>* result = nullptr;
        if (v->left == nullptr) {
            result = v->right;
            replace_child(parent, v, result);
            delete v;
        }
        else if (v->right == nullptr) {
            result = v->left;
            replace_child(parent, v, result);
            delete v;
        }
        else {
            MyNode<U>* parent_min_node = v;
            MyNode<U>* min_node = v->right;
            while (min_node->left != nullptr) {
                parent_min_node = min_node;
                min_node = min_node->left;
            }

            v->value = min_node->value;
            replace_child(parent_min_node, min_node, min_node->right);
            delete min_node;
        }
    }

private:
    static void DestroyNode(MyNode<U>* node) {
        if (node) {
            DestroyNode(node->left);
            DestroyNode(node->right);
            delete node;
        }
    }

    void replace_child(MyNode<U>* parent, MyNode<U>* old, MyNode<U>* n) {
        if (parent == nullptr) {
            this->root = n;
        }
        else if (parent->left != nullptr && parent->left->value == old->value) {
            parent->left = n;
        }
        else if (parent->right != nullptr && parent->right->value == old->value) {
            parent->right = n;
        }
    }

    MyNode<U>* findMin(MyNode<U>* root_) {
        if (root_->left != nullptr) {
            return findMin(root_->left);
        }

        return root_;
    }
};

/*
5

2
5
3
6
*/
int main()
{
    ifstream in("input.txt");
    long long x;
    in >> x;
    in.ignore();
    MyTree<long long> tree = MyTree<long long>();
    tree.buildTree(in);
    in.close();

    ofstream out("output.txt");
    tree.remove_node_right(x);
    tree.CLR(tree.root, out);
    out.close();

    return 0;
}