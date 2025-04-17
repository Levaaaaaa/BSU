import iterator.MyIterator;
import iterator.MyIteratorImpl;
import mvc.Frame;
import mvc.MySet;
import strategy.CalculateCardinalityByIteratorStrategy;

import javax.swing.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        MySet set = new MySet();
        set.add(0);
        set.add(5);
        set.add(3);
        set.add(12);
        MyIterator<Integer> iterator = set.iterator();
        while(iterator.hasNext()) {
            System.out.println(iterator.next());
        }
//        System.out.println(set);
        System.out.println("Cardinality - " + set.cardinality());
        set.setCardinalityStrategy(new CalculateCardinalityByIteratorStrategy());
        System.out.println("Cardinality by iterator - " + set.cardinality());

        Frame frame = new Frame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(0, 0, 500, 500);
        frame.setVisible(true);
    }
}