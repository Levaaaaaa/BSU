import MyStack.MyStack;
import gui.Frame;
import strategy.MyCountStrategyByIteratorImpl;
import strategy.MyCountStrategyByVisitorImpl;
import visitor.*;

import javax.swing.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        Frame frame = new Frame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(0, 0, 500, 500);
        frame.setVisible(true);

        MyStack stack = new MyStack();
        stack.push(2);
        stack.push(1);
        stack.push(3);

        stack.setStrategy(new MyCountStrategyByIteratorImpl());
        System.out.println("Size by iterator - " + stack.size());
        System.out.println("Removed item - " + stack.pop());
        stack.setStrategy(new MyCountStrategyByVisitorImpl());
        System.out.println("Size by visitor - " + stack.size());

        SumVisitor sumV = new SumVisitor();
        stack.acceptMyStack(sumV);
        System.out.println("Sum - " + sumV.getSum());
/*
        MyIterator<Integer> iterator = stack.iterator();
        while(iterator.hasNext()) {
            System.out.println(iterator.next());
        }
        System.out.println("\n");
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());

 */
    }
}