import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JumpingMouseFrame  extends JFrame {

    private final JButton positiveButton;
    private final JButton jumpingButton;
    private final JPanel panel;
    private final JLabel question;
    private final JLabel label;

    public JumpingMouseFrame() {
        super("jumping button");

        question = new JLabel("Are you satisfied with your scolarship?", SwingConstants.CENTER);
        question.setBorder(BorderFactory.createEmptyBorder(20,20,20,20));
        add(question, BorderLayout.NORTH);

        label = new JLabel();
        label.setBorder(BorderFactory.createEmptyBorder(0,50,10, 0));
        add(label, BorderLayout.SOUTH);

        panel = new JPanel();
        panel.setLayout(null);

        positiveButton = new JButton("Yes");
        panel.add(positiveButton);
        positiveButton.addActionListener(
                event -> label.setText("You are right!")
        );


        jumpingButton = new JButton("No");
        panel.add(jumpingButton);
        jumpingButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                if (jumpingButton.getY() == 50) {
                    jumpingButton.setBounds(225, 125,
                            100, 50);
                }
                else {
                    jumpingButton.setBounds(225, 50,
                            100, 50);
                }
            }
        });




        positiveButton.setBounds(75, 50,
                100, 50);
        jumpingButton.setBounds(225, 50,
                100, 50);


        add(panel, BorderLayout.CENTER);

    }

}
