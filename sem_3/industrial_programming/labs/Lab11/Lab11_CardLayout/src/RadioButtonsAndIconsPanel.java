import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

public class RadioButtonsAndIconsPanel extends JPanel implements ActionListener, MouseListener {
    private Icon icon1 = new ImageIcon("1.png");
    private Icon icon2 = new ImageIcon("2.png");
    private Icon icon3 = new ImageIcon("3.png");
    private Icon icon4 = new ImageIcon("4.png");
    private Icon defaultIcon = icon1;

    private ButtonGroup group = new ButtonGroup();
    private ArrayList<JRadioButton> buttons = new ArrayList<>();
    private JRadioButton radioButton1 = new JRadioButton("Radio Button 1", false);
    private JRadioButton radioButton2 = new JRadioButton("Radio Button 2", false);
    private JRadioButton radioButton3 = new JRadioButton("Radio Button 3", false);
    public RadioButtonsAndIconsPanel() {
        super();
        buttons.add(radioButton1);
        buttons.add(radioButton2);
        buttons.add(radioButton3);

        buttons.forEach(button -> {
            button.setIcon(icon1);
            add(button);
            button.addActionListener(this);
            button.addMouseListener(this);
        });
//        radioButton1.setIcon(icon1);
        //add(radioButton1);

        //radioButton1.addActionListener(this);
        //radioButton1.addMouseListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JRadioButton button = (JRadioButton)e.getSource();
            if (button.isSelected()) {
                button.setIcon(icon2);
                defaultIcon = icon2;
            }
            else {
                button.setIcon(icon1);
                defaultIcon = icon1;
            }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        JRadioButton button = (JRadioButton) e.getSource();
        button.setIcon(icon4);
    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {
        JRadioButton button = (JRadioButton)e.getSource();
        button.setIcon(icon3);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        JRadioButton button = (JRadioButton)e.getSource();
        button.setIcon(defaultIcon);
    }
}
