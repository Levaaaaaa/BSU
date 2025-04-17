package strategy;

import MyStack.MyStack;
import visitor.MyVisitorImpl;

public class MyCountStrategyByVisitorImpl implements MyCountStrategy{
    @Override
    public int countElements(MyStack stack) {
        MyVisitorImpl visitor = new MyVisitorImpl();
        stack.acceptMyStack(visitor);
        return visitor.getCount();
    }
    public String toString() {
        return "Strategy by visitor";
    }
}
