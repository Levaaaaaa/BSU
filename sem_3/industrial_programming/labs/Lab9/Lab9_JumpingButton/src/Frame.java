import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Frame  extends JFrame {

    private final JButton button;
    private final JPanel panel;
    private final JLabel statusBar;
    private boolean editingMode = false;
    private final StringBuilder buttonTextBuilder = new StringBuilder("Button");

    public Frame() {
        super("mouse tracker");

        panel = new JPanel();
        panel.setLayout(null);


        button = new JButton("Button");
        panel.add(button);
        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                editingMode = true;
            }
        });

        button.addKeyListener(new KeyAdapter() {

            @Override
            public void keyPressed(KeyEvent e) {
                if (editingMode) {
                    if (KeyEvent.getKeyText(e.getKeyCode()).equals("Backspace")) {
                        if (!buttonTextBuilder.isEmpty()) {
                            buttonTextBuilder.setLength(buttonTextBuilder.length() - 1);
                        }
                        button.setText(buttonTextBuilder.toString());
                    }
                    else {
                        buttonTextBuilder.append(e.getKeyChar());
                        button.setText(buttonTextBuilder.toString());
                    }
                }
            }
        });




        Insets insets = panel.getInsets();
        button.setBounds(25 + insets.left, 5 + insets.top,
                200, 50);

        statusBar = new JLabel("Coordinates: ");
        add(statusBar, BorderLayout.SOUTH);
        add(panel, BorderLayout.CENTER);
        panel.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                statusBar.setText(String.format("Coordinates: [%d, %d]", e.getX(), e.getY()));
                editingMode = false;
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                if (e.isControlDown()) {
                    button.setBounds(e.getX() - 50 + insets.left, e.getY() - 25 + insets.top,
                            200, 50);
                }
            }
        });
        panel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                button.setBounds(e.getX() - 50 + insets.left, e.getY() - 25 + insets.top,
                        200, 50);
            }
        });

    }

}
