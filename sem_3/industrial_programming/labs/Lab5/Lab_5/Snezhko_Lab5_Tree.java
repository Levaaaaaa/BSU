// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.lang.Comparable;
public class Main {
    public static void main(String[] args) {
        Tree tree = new Tree(5.0d);
        tree.add(6.4d);
        tree.add(4.9d);
        tree.add(4.95d);
        System.out.println(tree.size());
        System.out.println(tree.find(5.0d));
        System.out.println(tree.find(4.96d));
    }
}

class Node<T> {
    private Comparable<T> value;
    //private T value;
    private Node left;
    private Node right;
    private Node root;
    public Node(Comparable<T> value) {
        this.value = value;
    }
    public Comparable<T> getValue() {   return value; }
    public void setValue(Comparable newValue) { this.value = newValue; }
    public Node getLeft() {  return left; }
    public void setLeft(Node newLeft) { this.left = newLeft; }
    public Node getRight() {  return right; }
    public void setRight(Node newRight) { this.right = newRight; }
    public Node getRoot() {return this.root;}
    public void setRoot(Node newRoot) {this.root = newRoot;}
}
class Tree<T> {
    Node root;
    public Tree(Comparable<T> first) {
        this.root = new Node(first);
    }
    public Tree(Node first) {
        this.root = first;
    }
    public void add(Comparable<T> newItem) {
        Node newNode = new Node(newItem);
        Tree subTree;
        if (newItem.compareTo((T)root.getValue()) <= 0) {
            if (root.getLeft() == null) {
                root.setLeft(newNode);
                newNode.setRoot(root);
                return;
            }
            else {
                subTree = new Tree(root.getLeft());
            }
        }
        else {
            if (root.getRight() == null) {
                root.setRight(newNode);
                newNode.setRoot(root);
                return;
            }
            else {
                subTree = new Tree(root.getRight());
            }
        }
        subTree.add(newItem);
    }
    public int size() {
        int result = 1;
        Tree subTree;
        /*
        Node cur = this.root;

        while(cur.getLeft() != null) {
            cur = cur.getLeft();
        }
        if (cur.getRoot() != null) {
            result++;
            cur = cur.getRoot();
        }
        */

        if (root.getLeft() != null) {
            subTree = new Tree(root.getLeft());
            result += subTree.size();
        }
        if (root.getRight() != null) {
            subTree = new Tree(root.getRight());
            result += subTree.size();
        }
        
        return result;
    }

    public boolean find(Comparable item) {      //обход "Корень-Левый-Правый"
        Tree subTree;
        if (item.compareTo(this.root.getValue()) == 0) return true;
        if (item.compareTo(this.root.getValue()) <= 0) {
            if (root.getLeft() == null) return false;
            subTree = new Tree(root.getLeft());
        }
        else {
            if (root.getRight() == null) return false;
            subTree = new Tree(root.getRight());
        }
        return subTree.find(item);
    }
}