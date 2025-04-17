// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.LinkedList;
import java.util.Iterator;
import java.util.NoSuchElementException;
public class Main {
    public static void main(String[] args) {
        int a = 5;
        MyCollection<Integer> list = new MyCollection<Integer>(Integer.valueOf(a));
        //Integer a1 = new Integer(a);
//        list.add(Integer.parseInt(a));
        int b = 6;
        list.add(Integer.valueOf(6));
        MyIterator<Integer> iterator = list.myIterator();
        do {
            System.out.println(iterator.next() + " ");
        } while (iterator.hasNext());
    }
}

class Node<T> {
    public Node(T value) {
        this.value = value;
    }
    T value;
    Node<T> next;
    Node<T> prev;
}
class MyIterator<T> {
    public MyIterator(Node<T> first) {
        current = first;
    }
    private Node<T> current;
    public boolean hasNext() {
        if (current.next != null) return true;
        return false;
    }
    public T next() {
        T result = current.value;
        if (current.next == null) throw new IndexOutOfBoundsException("End of list");
        current = current.next;
        return result;
    }
}
class MyCollection<T>  {//MyIterator<T>{

    public MyCollection(T first) {
        Node<T> firstNode = new Node<T>(first);
        this.first = firstNode;
        this.last = firstNode;
    }
    Node<T> first;
    Node<T> last;
    //MyIterator<T> iterator;
    public void add(T newItem) {
        Node<T> newNode = new Node<T>(newItem);
        last.next = newNode;
        newNode.prev = last;
        last = newNode;
    }
    public MyIterator<T> myIterator() {
        return new MyIterator<T>(this.first);
    }
}
