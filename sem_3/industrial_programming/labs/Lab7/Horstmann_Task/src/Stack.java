import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class Stack<E> {
    private Set<E> set = new HashSet<>(1);
    public Stack(E first) {
        set.add(first);
    }
    public void push(E item) {
        set.add(item);
    }
    public E pop() {
        Iterator<E> iterator = set.iterator();
        E last;
        if (isEmpty()) throw new IndexOutOfBoundsException();
        int count = set.size();
        while (count > 1) {
            count--;
            iterator.next();
        }
        last = iterator.next();
        set.remove(last);
        return last;
    }
    public boolean isEmpty() {
        return set.isEmpty();
    }
}
