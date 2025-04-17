// 0_0_SumTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class MyNode {
public :
    MyNode<T>(T v) : value(v) {
        value = v;
    }
    T value;
    MyNode *left = nullptr;
    MyNode *right = nullptr;
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

void CLR(MyNode<int>* root, ostream &out) {
    if (root == nullptr) {
        return;
    }
    out << root->value;
    CLR(root->left, out);
    CLR(root -> right, out);
}

long long sumLCR(MyNode<long long>* root) {
    if (root == nullptr) {
        return 0;
    }
    long long result = 0;
    result += sumLCR(root->left);
    result += root->value;
    result += sumLCR(root->right);

    return result;
}

MyTree<long long> buildTree(ifstream &in) {
    long long tmp;
    MyTree<long long> tree = MyTree<long long>();
    while (!in.eof()) {
        in >> tmp;
        tree.insert(tmp);
    }

    return tree;
}
int main()
{
    ifstream in("input.txt");
    MyTree<long long> tree = buildTree(in);
    in.close();

    ofstream out("output.txt");
    out << sumLCR(tree.root);
    out.close();

    return 0;
}