import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Frame extends JFrame implements ActionListener {
    private Gift gift;
    private JPanel mainPanel = new JPanel(new GridLayout(2, 1));
    private JPanel buttonsPanel = new JPanel(new GridLayout(3, 2));
    private JPanel textAreasPanel = new JPanel(new GridLayout(1, 2));

    private JButton readGiftButton = new JButton("read gift");
    private JButton getGeneralWeightButton = new JButton("get general wight of gift");
    private JButton addSweetToGiftButton = new JButton("add sweet to gift");
    private JButton getSweetBySugarButton = new JButton("get sweet by sugar");
    private JButton saveButton = new JButton("Save");
    private JButton getSortedGiftButton = new JButton("sort");

    private JTextArea printGiftArea = new JTextArea();
    private JTextArea output = new JTextArea();

    public Frame(String title) {
        super(title);

        initButtonsPanel();
        initTextAreasPanel();

        mainPanel.add(textAreasPanel);
        mainPanel.add(buttonsPanel);

        this.add(mainPanel);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            if (e.getSource().equals(addSweetToGiftButton)) {
                AddNewSweetFrame addFrame = new AddNewSweetFrame(this.gift);
                //addFrame.setDefaultCloseOperation();
                addFrame.setSize(500, 500);
                addFrame.setVisible(true);
                addFrame.setBounds(this.getBounds());
                output.setText(gift.toString());

            }
            else if (e.getSource().equals(saveButton)) {
                try (FileWriter writer = new FileWriter(new File("output.txt"))) {
                    writer.write(this.gift.toString());
                }
            }
            else if (e.getSource().equals(getGeneralWeightButton)) {
                StringBuilder sb = new StringBuilder();
                sb.append("General width: ")
                        .append(Double.toString(gift.findGeneralWeight()));
                output.setText(sb.toString());
            }
            else if (e.getSource().equals(readGiftButton)) {
                JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
                int r = chooser.showOpenDialog(null);
                if (r==JFileChooser.APPROVE_OPTION) {
                    this.gift = FrameFeatures.createGiftFromFile(chooser.getSelectedFile().getAbsoluteFile());
                    printGiftArea.setText(gift.toString());
                }
                changeButtonsStatus(true);
            }
            else if (e.getSource().equals(getSortedGiftButton)) {
                FrameFeatures.printSortedGift(BaseSweet::compareTo, gift, output);
            }
            else if (e.getSource().equals(getSweetBySugarButton)) {
                GetSweetBySugarFrame sugarFrame = new GetSweetBySugarFrame(gift);
                sugarFrame.setSize(500, 500);
                sugarFrame.setVisible(true);
                sugarFrame.setBounds(this.getBounds());
            }
        }
        catch (IOException ex) {
            output.setText("Input or output error!!!");
            return;
        }
        catch(IllegalArgumentException ex) {
            output.setText("File is damaged!!!");
        }
    }
    private void initTextAreasPanel() {
        printGiftArea.setEditable(false);
        output.setEditable(false);

        textAreasPanel.add(printGiftArea);
        textAreasPanel.add(output);
    }
    private void initButtonsPanel() {
        readGiftButton.addActionListener(this);
        saveButton.addActionListener(this);
        getGeneralWeightButton.addActionListener(this);
        getSweetBySugarButton.addActionListener(this);
        addSweetToGiftButton.addActionListener(this);
        getSortedGiftButton.addActionListener(this);
        getSweetBySugarButton.addActionListener(this);

        buttonsPanel.add(readGiftButton);
        buttonsPanel.add(saveButton);
        buttonsPanel.add(getGeneralWeightButton);
        buttonsPanel.add(getSweetBySugarButton);
        buttonsPanel.add(addSweetToGiftButton);
        buttonsPanel.add(getSortedGiftButton);
        changeButtonsStatus(false);
    }
    private void changeButtonsStatus(boolean status) {
        saveButton.setEnabled(status);
        getGeneralWeightButton.setEnabled(status);
        getSweetBySugarButton.setEnabled(status);
        addSweetToGiftButton.setEnabled(status);
        getSortedGiftButton.setEnabled(status);
    }
}
