// 16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

/*
шаг 1: обратным обходом посчитать h и lh для каждой вершины, а также найти MSL(T). 
        Вторым обходом найдём b(v) - кол-во полупутей длины MSL c корнем v
шаг 2:  найти а(v) - кол-во различных полупутей MSL(T), которые приходят в v сверху (от отца)
        для этого найдём h_up(v) - MSL приходящая в v сверху и l_up(v) - кол-во таких полупутей
шаг 3: сложим b(v) и a(v). Получим искомый результат с(v)
*/

long long max(long long a, long long b) {
    if (a > b) {
        return a;
    }
    return b;
}
//declarations
template <class T>
class MyNode {
public:
    MyNode<T>(T v) : value(v), left(0), right(0), a(0), b(0), h(0), l_h(1), c(0), msl_node(0), h_up(0), l_up(1) {
    }
    T value;
    MyNode<T>* left;
    MyNode<T>* right;

    //marks
    long long a;    //число MS приходящих сверху
    long long b;    //число MS для которых тек. вершина - корень
    long long h;    //высота вершины
    long long l_h;//число листьев, лежащих на максимальном расстоянии под этой вершиной
    long long c;    //число MS проходящих  через эту вершину
    long long msl_node;//MSL c корнем в тек. вершине
    long long h_up; //MSL из v в лист, не принадл. поддереву v, h' у Котова
    long long l_up; //число полупутей h_up, l' у Котова

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
    long long msl;

    void buildTree(istream& in);

    void CLR(MyNode<U>* root, ostream& out);
    void findMslHeightsLeafsCount(MyNode<U>* root);   //cчитаем MSL by LRC
    void findBForEachNode(MyNode<U>* v);                //by LRC, вызвать после findMslHeightsLeafsCount!!!
    void findHeightsCountForA(MyNode<U>* root);         //заполняем h' и l' прямым обходом (CLR)
    void calculateHeightCountForAOneSon(MyNode<U>* root, MyNode<U>* i, MyNode<U>* brother);//cчитает h', l' для i используя родителя и "брата"
    void findA(MyNode<U>* v);                           //by CLR, считает А и С, завершающий этап, вызывать после findMslHeightsLeafsCount и findBForEachNode!!!

    void remove_node_right(U u);
    void insert(U t);
    bool isRootOfMS(MyNode<U>* v);
    void replace_child(MyNode<U>* parent, MyNode<U>* old, MyNode<U>* n);
private:
    static void DestroyNode(MyNode<U>* node) {
        if (node) {
            DestroyNode(node->left);
            DestroyNode(node->right);
            delete node;
        }
    }
};

//main
int main()
{
    ifstream in("input.txt");
    MyTree<long long> tree = MyTree<long long>();
    tree.buildTree(in);
    in.close();
    //delete root
    
    tree.remove_node_right(tree.root->value);
    //этап 1
    tree.findMslHeightsLeafsCount(tree.root);
    tree.findBForEachNode(tree.root);

    //этап 2
    tree.findHeightsCountForA(tree.root);
    tree.findA(tree.root);

    ofstream out("output.txt");
    tree.CLR(tree.root, out);
    out.close();

    return 0;
}

//implamentations
template <typename U>
void MyTree<U>::buildTree(istream& in) {
    U u;
    while (!in.eof()) {
        in >> u;
        this->insert(u);
    }
}

template <typename U>
void MyTree<U>::CLR(MyNode<U>* root, ostream& out) {
    if (root == nullptr) {
        return;
    }
    out << root->value << " " << root->c << endl;
    CLR(root->left, out);
    CLR(root->right, out);
}

template <typename U>
void MyTree<U>::findMslHeightsLeafsCount(MyNode<U>* root) {
    if (root == nullptr) {
        return;
    }
    findMslHeightsLeafsCount(root->left);
    findMslHeightsLeafsCount(root->right);

    //calculate height
    if (root->left == nullptr && root->right == nullptr) {      //root hasn't sons
        root->h = 0;
    }
    else if (root->left != nullptr && root->right != nullptr) { //root has both sons
        root->h = max(root->left->h, root->right->h) + 1;
        root->msl_node = root->left->h + root->right->h + 2;
        //calculate l_h for root with both sons
        if (root->left->h == root->right->h) {
            root->l_h = root->left->l_h + root->right->l_h;
        }
        else if (root->left->h > root->right->h) {
            root->l_h = root->left->l_h;
        }
        else {
            root->l_h = root->right->l_h;
        }
    }
    else {                                                      //root has one son
        if (root->left != nullptr) {
            root->h = root->left->h + 1;
            root->msl_node = root->left->h + 1;
            root->l_h = root->left->l_h;
        }
        else if (root->right != nullptr) {
            root->h = root->right->h + 1;
            root->msl_node = root->right->h + 1;
            root->l_h = root->right->l_h;
        }
    }

    //calculate tree msl
    if (root->msl_node > this->msl) {
        this->msl = root->msl_node;
    }
}

template <typename U>
void MyTree<U>::findBForEachNode(MyNode<U>* v) {
    if (v == nullptr) {
        return;
    }
    findBForEachNode(v->left);
    findBForEachNode(v->right);
    if (isRootOfMS(v)) {
        long long left = 1;
        long long right = 1;
        if (v->left != nullptr) {
            left = v->left->l_h;
        }
        if (v->right != nullptr) {
            right = v->right->l_h;
        }
        v->b = left * right;
    }
    else {
        v->b = 0;
    }
}
template <typename U>
void MyTree<U>::findHeightsCountForA(MyNode<U>* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr && root->right != nullptr) {
        //has both sons
        calculateHeightCountForAOneSon(root, root->left, root->right);
        calculateHeightCountForAOneSon(root, root->right, root->left);
    }
    else if (root->left == nullptr && root->right == nullptr) {
        //hasn't any sons, all calculation done
        return;
    }
    else {
        //has one son
        if (root->left != nullptr) {
            root->left->h_up = root->h_up + 1;
            root->left->l_up = root->l_up;
        }
        else {
            root->right->h_up = root->h_up + 1;
            root->right->l_up = root->l_up;
        }
    }

    findHeightsCountForA(root->left);
    findHeightsCountForA(root->right);
}

template <typename U>
void MyTree<U>::calculateHeightCountForAOneSon(MyNode<U>* root, MyNode<U>* i, MyNode<U>* brother) {
    if (root->h_up == (brother->h + 1)) {
        i->h_up = brother->h + 2;
        i->l_up = root->l_up + brother->l_h;
    }
    else if (root->h_up < (brother->h + 1)) {
        i->h_up = brother->h + 2;
        i->l_up = brother->l_h;
    }
    else {
        i->h_up = root->h_up + 1;
        i->l_up = root->l_up;
    }
}

template <typename U>
void MyTree<U>::findA(MyNode<U>* v) {
    if (v == nullptr) {
        return;
    }

    if (v == this->root) {      //возможно удалить, т.к. 0 - значение по умолчанию
        v->a = 0;
    }
    else {
        if ((v->h_up + v->h) == this->msl) {
            v->a = v->l_h * v->l_up;
        }
        else {                      //возможно удалить, т.к. 0 - значение по умолчанию
            v->a = 0;
        }
    }
    v->c = v->a + v->b;
    findA(v->left);
    findA(v->right);
}

template <typename U>
void MyTree<U>::remove_node_right(U u) {
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

template <typename U>
void MyTree<U>::insert(U t) {
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

template<typename U>
bool MyTree<U>::isRootOfMS(MyNode<U>* v) {
    return v->msl_node == this->msl;
}

template <class U>
void MyTree<U>::replace_child(MyNode<U>* parent, MyNode<U>* old, MyNode<U>* n) {
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