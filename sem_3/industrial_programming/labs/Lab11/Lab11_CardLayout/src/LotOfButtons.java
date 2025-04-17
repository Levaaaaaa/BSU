import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LotOfButtons extends JPanel implements MouseListener {
    private int n = 5;
    private ArrayList<JButton> buttons = new ArrayList<>(n * n);
    private JPanel layoutPanel = new JPanel(new GridLayout(n, n));

    private String currentButtonText = "";
    public LotOfButtons(){
        super();
        initAllButtons();
        buttons.forEach(button -> {
            layoutPanel.add(button);
            button.addMouseListener(this);
            button.setPreferredSize(new Dimension(100, 30));
            button.setBackground(Color.WHITE);
        });
//        layoutPanel.setBounds(0, 0, this.getWidth(), this.getHeight());
        layoutPanel.setSize(this.getWidth(), this.getHeight());
        add(layoutPanel, BorderLayout.CENTER);


    }
    private void initAllButtons() {
        for(int i=1; i <= n*n; i++) {
            buttons.add(new JButton(Integer.toString(i)));
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        JButton curButton = (JButton)e.getSource();
        currentButtonText = curButton.getText();
        (curButton).setText("Clicked!");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        ((JButton)e.getSource()).setText(currentButtonText);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        JButton button = (JButton)e.getSource();
        button.setBackground(Color.GREEN);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        JButton button = (JButton)e.getSource();
        button.setBackground(Color.WHITE);
    }
}
