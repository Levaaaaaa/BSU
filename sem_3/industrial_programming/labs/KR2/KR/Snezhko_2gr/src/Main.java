import iterator.MyIterator;
import mvc.Frame;
import mvc.MySet;
import strategy.CalculateCardinalityByStreamAPIStrategy;

import javax.swing.*;

//M - MySet (aktiv)
//V - interface MyView, implementation BinaryView and NormallyView
//C - MyController

public class Main {
    public static void main(String[] args) {
        Frame frame = new Frame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(0, 0, 500, 500);
        frame.setVisible(true);

    }

}