package gui;

import MyStack.*;
import strategy.MyCountStrategy;
import strategy.MyCountStrategyByIteratorImpl;
import strategy.MyCountStrategyByVisitorImpl;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyController extends JPanel implements ActionListener {
    private MyStack model;
    private TextAreaView view;
    private CounterView view2;
    private JButton pushButton = new JButton("push");
    private JTextField input = new JTextField();
    private JComboBox<MyCountStrategy> selectStrategy = new JComboBox<>();
    public MyController(MyStack model, TextAreaView view) {
        super();
        this.model = model;
        this.view = view;

        setLayout(new GridLayout(5, 1));

        initComboBox();

        selectStrategy.addActionListener(this);
        pushButton.addActionListener(this);
        add(pushButton);
        add(input);
        add(selectStrategy);
    }

    public MyController(MyStack model, TextAreaView view, CounterView view2) {
        this(model, view);
        add(view2);
    }

    private void initComboBox() {
        selectStrategy.addItem(new MyCountStrategyByIteratorImpl());
        selectStrategy.addItem(new MyCountStrategyByVisitorImpl());
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(pushButton)) {
            model.push(Integer.parseInt(input.getText()));
            view.update();
            view2.update();
            input.setText("");
        }
        else if (e.getSource().equals(selectStrategy)) {
            model.setStrategy(selectStrategy.getItemAt(selectStrategy.getSelectedIndex()));
            view.update();
            view2.update();
        }
    }
}
