package gui;

import javax.swing.*;
import MyStack.*;

import java.awt.*;

public class CounterView extends JTextField {
    private MyStack model;

    public CounterView(MyStack model) {
        this.model = model;
        setBorder(BorderFactory.createLineBorder(Color.BLACK, 3));
    }

    public void update() {
        setText(Integer.toString(model.size()));
    }
}
