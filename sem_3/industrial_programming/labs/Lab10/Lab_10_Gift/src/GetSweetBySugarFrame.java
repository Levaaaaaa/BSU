import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GetSweetBySugarFrame extends JFrame implements ActionListener {
    private Gift gift;
    private JPanel mainPanel = new JPanel(new GridLayout(3, 1));
    private JPanel spinnersPanel = new JPanel(new GridLayout(1, 4));
    private JPanel buttonsPanel = new JPanel(new GridLayout(1, 2));

    private JButton closeButton = new JButton("Exit");
    private JButton executeButton = new JButton("Get sweet");
    private JSpinner minSugarSpinner = new JSpinner(new SpinnerNumberModel(0.0, 0.0, 100, 1));
    private JSpinner maxSugarSpinner = new JSpinner(new SpinnerNumberModel(0.0, 0.0, 100, 1));
    private JTextArea output = new JTextArea();
    public GetSweetBySugarFrame(Gift gift) {
        super("Sweet by sugar");
        this.gift = gift;

        output.setEditable(false);
        mainPanel.add(output);

        spinnersPanel.add(new JLabel("min: "));
        spinnersPanel.add(minSugarSpinner);
        spinnersPanel.add(new Label("max: "));
        spinnersPanel.add(maxSugarSpinner);
        mainPanel.add(spinnersPanel);

        buttonsPanel.add(executeButton);
        buttonsPanel.add(closeButton);
        mainPanel.add(buttonsPanel);

        add(mainPanel);
        executeButton.addActionListener(this);
        closeButton.addActionListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(executeButton)) {
            FrameFeatures.printSweetFoundBySugar(gift, minSugarSpinner, maxSugarSpinner, output);
        }
        else if (e.getSource().equals(closeButton)) {
            this.dispose();
        }
    }
}
