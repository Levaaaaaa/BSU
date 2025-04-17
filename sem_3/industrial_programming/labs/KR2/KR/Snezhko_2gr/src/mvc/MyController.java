package mvc;

import observer.Observable;
import observer.Observer;
import strategy.CalculateCardinalityByStreamAPIStrategy;
import strategy.CalculateCardinalityByVisitorStrategy;
import strategy.CalculateCardinalityStrategy;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class MyController extends JPanel implements ActionListener {
    private MySet model;
    private ArrayList<MyView> views = new ArrayList<>();
    private JButton addButton = new JButton("add");
    private JSpinner addSpinner = new JSpinner(new SpinnerNumberModel());
    private JComboBox<CalculateCardinalityStrategy> selectStrategyBox = new JComboBox();
    private JButton saveButton = new JButton("save");
    private final String outputFileName = "output.txt";
    private String defaultMessage = "Message label";
    private JLabel messageLabel = new JLabel(defaultMessage);
    private JPanel addPanel = new JPanel(new GridLayout(1, 4));
    public MyController(MySet set, MyView v) {
        super();
        model = set;
        views.add(v);

        setLayout(new GridLayout(3, 1));

        initComboBox();
        initAddPanel();

        addButton.addActionListener(this);
        saveButton.addActionListener(this);
        selectStrategyBox.addActionListener(this);

        add(addPanel);
        add(selectStrategyBox);
        add(messageLabel);
     }

    public MyController(MySet model, MyView view1, MyView view2) {
        this(model, view1);
        views.add(view2);
    }

    private void initComboBox() {
        selectStrategyBox.addItem(new CalculateCardinalityByStreamAPIStrategy());
        selectStrategyBox.addItem(new CalculateCardinalityByVisitorStrategy());
    }
    private void initAddPanel() {
        addPanel.add(new JLabel("Add item: "));
        addPanel.add(addSpinner);
        addPanel.add(addButton);
        addPanel.add(saveButton);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        messageLabel.setText(defaultMessage);
        if (e.getSource().equals(addButton)) {
            model.add((int)addSpinner.getValue());
        }
        else if (e.getSource().equals(saveButton)) {
            File file = new File(System.getProperty("user.dir") + "/" + outputFileName);
            try {
                model.save(file);
                messageLabel.setText("Save successful! Your set was saved in " + file.getAbsolutePath());
            } catch (IOException ex) {
                messageLabel.setText(ex.getMessage());
            }
        }
        else if (e.getSource().equals(selectStrategyBox)) {
            model.setCardinalityStrategy(selectStrategyBox.getItemAt(selectStrategyBox.getSelectedIndex()));
        }
    }
}
