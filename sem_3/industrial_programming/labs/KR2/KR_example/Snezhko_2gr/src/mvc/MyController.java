package mvc;

import observer.Observable;
import observer.Observer;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class MyController extends JPanel implements ActionListener, Observer {
    private MySet model;
    private ArrayList<MyView> views = new ArrayList<>();
    private MyView view;
    private JButton addButton = new JButton("add");
    private JSpinner addSpinner = new JSpinner(new SpinnerNumberModel());
    private JButton saveButton = new JButton("save");
    private final String outputFileName = "output.txt";
    private JLabel messageLabel = new JLabel();
    public MyController(MySet set, MyView v) {
        super();
        model = set;
        views.add(v);

        model.subscribe(this);
        setLayout(new GridLayout(4, 1));

        addButton.addActionListener(this);
        saveButton.addActionListener(this);

        add(addButton);
        add(addSpinner);
        add(saveButton);
        add(messageLabel);
    }

    public MyController(MySet model, MyView view1, MyView view2) {
        this(model, view1);
        views.add(view2);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        messageLabel.setText("");
        if (e.getSource().equals(addButton)) {
            model.add((int)addSpinner.getValue());
        }
        else if (e.getSource().equals(saveButton)) {
            //JFileChooser ch = new JFileChooser(System.getProperty("user.dir"));
            File file = new File(System.getProperty("user.dir") + "/" + outputFileName);
            try {
                model.save(file);
                messageLabel.setText("Save successful!");
            } catch (IOException ex) {
                messageLabel.setText(ex.getMessage());
            }
        }
    }

    @Override
    public void update(Observable o) {
        views.forEach(v -> v.update(model));
    }
}
