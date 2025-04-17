package gui;

import javax.swing.*;
import java.awt.*;
import MyStack.*;

public class Frame extends JFrame {
    private MyStack model = new MyStack();
    private TextAreaView view1 = new TextAreaView(model);
    private CounterView view2 = new CounterView(model);
    private MyController controller = new MyController(model, view1, view2);
    public Frame() {
        super("Frame");

        setLayout(new GridLayout(1, 3));
        add(view1);
        add(view2);
        add(controller);
    }
}