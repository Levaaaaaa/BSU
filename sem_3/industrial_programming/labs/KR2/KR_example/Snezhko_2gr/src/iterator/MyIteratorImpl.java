package iterator;

import mvc.MySet;

import java.util.ArrayList;

public class MyIteratorImpl implements MyIterator<Integer>{

    private Integer current;
    //private ArrayList<Integer> list;
    private MySet set;
    public MyIteratorImpl(MySet set_) {
        //list = set_.toOrdinaryNumbers();
        current = 0;
        set = set_;
    }
    @Override
    public Integer next() {
        return set.get(current++);
    }

    @Override
    public boolean hasNext() {
        return set.size() > current;
    }
}
