package gui;
import MyStack.*;

import javax.swing.*;
import java.awt.*;

public class TextAreaView extends JTextArea {
    private MyStack model;
    public TextAreaView(MyStack model) {
        this.model = model;
        setBorder(BorderFactory.createLineBorder(Color.BLACK, 3));
    }
    public void update() {
        this.setText(model.toString());
    }
}
