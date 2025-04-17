import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Frame extends JFrame implements MouseListener, ActionListener {
    private boolean isNegButtonDown = false;
    private JButton positiveButton = new JButton("Yes");
    private JButton negativeButton = new JButton("No");
    private JLabel label = new JLabel("Устраивает ли Вас ваш средний балл?");
    private JLabel output = new JLabel();
    private JPanel buttonsPanel = new JPanel(new GridLayout(1, 2));
    private JPanel mainPanel = new JPanel(new GridLayout(3, 1));

    private JPanel negativePanel = new JPanel();
    private JPanel positiveButtonPanel = new JPanel();
    public Frame() {
        super("Two Buttons");
/*
        buttonsPanel.add(positiveButton);
        buttonsPanel.add(negativeButton);
*/
        negativeButton.addMouseListener(this);
        positiveButton.addActionListener(this);
        /*
        mainPanel.add(label);
        mainPanel.add(buttonsPanel);
        mainPanel.add(output);
        add(mainPanel);
        */
        positiveButtonPanel.add(positiveButton);
        negativePanel.add(negativeButton);
        add(label, BorderLayout.NORTH);
        add(positiveButtonPanel, BorderLayout.WEST);
        add(negativePanel, BorderLayout.EAST);
        add(output, BorderLayout.SOUTH);
  //      positiveButtonPanel.setLocation(200, 200);
        positiveButtonPanel.setBounds(100, 0, 100, 50);
        negativePanel.setBounds(200, 0, 100, 50);
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        if (event.getSource().equals(positiveButton)) {
            output.setText("Well!");
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        return;
    }

    @Override
    public void mousePressed(MouseEvent e) {
        return;
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        return;
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        if (isNegButtonDown) {
            negativePanel.setBounds(negativePanel.getX() + 100, negativePanel.getY() - 100, negativePanel.getWidth(), negativePanel.getHeight());
            isNegButtonDown = false;
        }
        else {
            negativePanel.setBounds(negativePanel.getX() - 100, negativePanel.getY() + 100, negativePanel.getWidth(), negativePanel.getHeight());
            isNegButtonDown = true;
        }
    }

    @Override
    public void mouseExited(MouseEvent e) {
        return;
    }
}
