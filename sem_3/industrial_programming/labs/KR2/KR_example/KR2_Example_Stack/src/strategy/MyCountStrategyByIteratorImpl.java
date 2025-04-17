package strategy;

import MyStack.MyStack;
import iterator.MyIteratorImpl;

public class MyCountStrategyByIteratorImpl implements MyCountStrategy{

    @Override
    public int countElements(MyStack stack) {
        MyIteratorImpl<Integer> iterator = (MyIteratorImpl<Integer>)stack.iterator();
        int result = 0;
        while(iterator.hasNext()) {
            result++;
            iterator.next();
        }

        return result;
    }
    public String toString() {
        return "Strategy by iterator";
    }
}

