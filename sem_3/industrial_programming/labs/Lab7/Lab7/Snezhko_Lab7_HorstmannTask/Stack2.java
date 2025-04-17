import java.util.Iterator;

public class Stack2<E> {
    private Object[] array;
    public Stack2(E first) {
        push(first);
    }
    public void push(E item) {
        Object[] array2 = new Object[array.length + 1];
        for (int i = 0; i < array.length; i++) {
            array2[i] = array[i];
        }
        array2[array.length] = item;
        array = array2;
    }
    public E pop() {
        if (this.isEmpty()) throw new IndexOutOfBoundsException();
        Object[] array2 = new Object[array.length - 1];
        for (int i = 0; i < array.length - 1; i++) {
            array2[i] = array[i];
        }
        E last = (E)array[array.length - 1];
        array = array2;
        return last;
    }
    public boolean isEmpty() {
        return array.length == 0;
    }
}
