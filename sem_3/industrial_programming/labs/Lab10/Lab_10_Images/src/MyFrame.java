import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class MyFrame extends JFrame implements ActionListener {
    private MyPanel paintPanel = new MyPanel();
    private JButton redColorButton = new JButton("RED");
    private JButton greenColorButton = new JButton("GREEN");
    private JButton blueColorButton = new JButton("BLUE");
    private JButton clearButton = new JButton("CLEAR");
    private JButton saveButton = new JButton("SAVE");
    private JButton openButton = new JButton("OPEN");
    private JPanel colorButtonsPanel = new JPanel(new GridLayout(1, 3));
    private JPanel otherButtonPanel = new JPanel(new GridLayout(1, 3));
    private JPanel buttonsPanel = new JPanel(new GridLayout(2, 1));
    public MyFrame() {
        super("My Frame");
        addComponentListener(paintPanel);
        paintPanel.setPreferredSize(new Dimension(this.getWidth(), this.getHeight()));
        add(buttonsPanel, BorderLayout.NORTH);
        add(paintPanel);
        buttonsPanel.setBounds(colorButtonsPanel.getX(), colorButtonsPanel.getY(), colorButtonsPanel.getWidth(), 50);
        colorButtonsPanel.add(redColorButton);
        colorButtonsPanel.add(greenColorButton);
        colorButtonsPanel.add(blueColorButton);

        otherButtonPanel.add(clearButton);
        otherButtonPanel.add(saveButton);
        otherButtonPanel.add(openButton);

        buttonsPanel.add(colorButtonsPanel);
        buttonsPanel.add(otherButtonPanel);

        redColorButton.addActionListener(this);
        greenColorButton.addActionListener(this);
        blueColorButton.addActionListener(this);
        clearButton.addActionListener(this);
        saveButton.addActionListener(this);
        openButton.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        if (event.getSource().equals(redColorButton)) {
            paintPanel.setColor(Color.RED);
        }
        else if (event.getSource().equals(greenColorButton)) {
            paintPanel.setColor(Color.GREEN);
        }
        else if (event.getSource().equals(blueColorButton)) {
            paintPanel.setColor(Color.BLUE);
        }
        else if (event.getSource().equals(clearButton)) {
            paintPanel.clear();
        }
        else if (event.getSource().equals(saveButton)) {
            saveButton.setText("SAVE");
            JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
            int ret = chooser.showOpenDialog(null);
            if (ret == JFileChooser.APPROVE_OPTION) {
                File file = new File(chooser.getSelectedFile().getAbsolutePath());
                try {
                    ImageIO.write(paintPanel.getBufferedImage(),
                            "png",
                            file);
                }
                catch (IOException exception) {
                    saveButton.setText("IOException!!!");
                }
            }
        }
        else if (event.getSource().equals(openButton)) {
            openButton.setText("OPEN");
            JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
            int ret = chooser.showSaveDialog(null);
            if (ret == JFileChooser.APPROVE_OPTION) {
                File file = chooser.getSelectedFile().getAbsoluteFile();
                try {
                    paintPanel.setBuffImage(ImageIO.read(file));
                    paintPanel.repaint();
                }
                catch (IOException exception) {
                    openButton.setText("IOEXCEPTION!!!");
                }
            }
        }
    }
}
