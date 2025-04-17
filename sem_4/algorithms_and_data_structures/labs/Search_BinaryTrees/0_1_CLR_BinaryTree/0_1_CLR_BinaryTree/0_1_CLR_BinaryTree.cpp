// 0_1_CLR_BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

template <class T>
class MyNode {
public:
    MyNode<T>(T v) : value(v) {
        value = v;
    }
    T value;
    MyNode* left = nullptr;
    MyNode* right = nullptr;
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

    void buildTree(istream &in) {
        U u;
        while (!in.eof()) {
            in >> u;
            this->insert(u);
        }
    }

    static void CLR(MyNode<int>* root, ostream& out) {
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
private:
    static void DestroyNode(MyNode<U>* node) {
        if (node) {
            DestroyNode(node->left);
            DestroyNode(node->right);
            delete node;
        }
    }
};

int main() {
    ifstream in("input.txt");
    MyTree<int> tree = MyTree<int>();
    tree.buildTree(in);
    in.close();

    ofstream out("output.txt");
    MyTree<int>::CLR(tree.root, out);
    out.close();

    return 0;
}