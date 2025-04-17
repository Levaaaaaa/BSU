import javax.swing.*;
import java.awt.event.KeyEvent;

public class LabelObserver implements MyObserver{

    private JLabel label = new JLabel();
    @Override
    public void update(KeyEvent event) {
        label.setText(String.valueOf(event.getKeyChar()));
    }

    public JLabel getLabel() {
        return label;
    }
}
