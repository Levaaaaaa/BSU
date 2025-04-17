import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;

public class AddNewSweetFrame extends JFrame implements ActionListener {
    private Gift gift;
    private JButton closeButton = new JButton("Exit");
    private JPanel editablePanel = new JPanel(new GridLayout(4, 2));
    private JPanel mainPanel = new JPanel(new GridLayout(3, 1));
    private JButton addButton = new JButton("ADD");
    private JComboBox addSweetsTypeComboBox = new JComboBox<>();
    private JTextArea addSweetsNameArea = new JTextArea();
    private JSpinner addSweetsWeightSpinner = new JSpinner(new SpinnerNumberModel(0.0, 0.0, 20.0, 0.1));
    private JSpinner addSweetsSugarSpinner = new JSpinner(new SpinnerNumberModel(0.0, 0.0, 100, 1));
    private JLabel typeLabel = new JLabel("Type: ");
    private JLabel nameLabel = new JLabel("Name: ");
    private JLabel weightLabel = new JLabel("Weight(kg): ");
    private JLabel sugarLabel = new JLabel("Sugar proportion(%): ");
    public AddNewSweetFrame(Gift gift) {
        super("Add new sweet");
        this.gift = gift;
        addSweetsTypeComboBox.addItem("Candy");
        addSweetsTypeComboBox.addItem("Chocolate");

        editablePanel.add(new Label("Type: "));
        editablePanel.add(addSweetsTypeComboBox);
        editablePanel.add(new Label("Name: "));
        editablePanel.add(addSweetsNameArea);
        editablePanel.add(new Label("Weight(kg): "));
        editablePanel.add(addSweetsWeightSpinner);
        editablePanel.add(new Label("Sugar proportion(%): "));
        editablePanel.add(addSweetsSugarSpinner);

        mainPanel.add(editablePanel, BorderLayout.NORTH);
        mainPanel.add(addButton);
        mainPanel.add(closeButton);
        addButton.addActionListener(this);
        closeButton.addActionListener(this);
        this.add(mainPanel, BorderLayout.CENTER);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(addButton)) {
            FrameFeatures.addSweetToGift(this.gift, addSweetsTypeComboBox, addSweetsNameArea, addSweetsWeightSpinner, addSweetsSugarSpinner);
        }
        else if (e.getSource().equals(closeButton)) {
            this.dispose();
        }
    }
}
