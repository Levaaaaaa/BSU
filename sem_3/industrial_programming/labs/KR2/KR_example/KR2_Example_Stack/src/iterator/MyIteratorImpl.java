package iterator;

import java.util.ArrayList;

public class MyIteratorImpl<T> implements MyIterator{

    private int current;
    private ArrayList<T> list;
    public MyIteratorImpl(ArrayList<T> arr) {
        current = 0;
        list = arr;
    }
    @Override
    public T next() {
        return list.get(current++);
    }

    @Override
    public boolean hasNext() {
        return current < list.size();
    }
}
