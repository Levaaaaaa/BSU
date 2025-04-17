package MyStack;

import iterator.*;
import strategy.MyCountStrategy;
import strategy.MyCountStrategyByVisitorImpl;
import visitor.MyVisitable;
import visitor.MyVisitor;

import java.util.ArrayList;

public class MyStack implements MyVisitable {
    private ArrayList<Integer> list;
    private MyCountStrategy strategy;
    public MyStack() {
        list = new ArrayList<>();
        strategy = new MyCountStrategyByVisitorImpl();
    }

    public void push(Integer item) {
        list.add(item);
    }

    public boolean isEmpty() {
        return list.size() == 0;
    }
    public Integer pop() {
        return this.isEmpty() ? null : list.remove(list.size() - 1);
    }
    public MyIterator<Integer> iterator() {
        return new MyIteratorImpl<Integer>(list);
    }

    @Override
    public void acceptMyStack(MyVisitor v) {
        MyIteratorImpl<Integer> iterator = (MyIteratorImpl<Integer>)this.iterator();
        while(iterator.hasNext()) {
            v.visitInteger(iterator.next());
        }
    }

    public int size() {         //calculateCounter
        return (strategy != null)
                ? strategy.countElements(this)
                : 0;
    }

    public void setStrategy(MyCountStrategy strategy) {
        this.strategy = strategy;
    }

    @Override
    public String toString() {
        return "MyStack{" +
                "list=" + list +
                ", strategy=" + strategy +
                ", size = " + this.size() +
                '}';
    }
}
