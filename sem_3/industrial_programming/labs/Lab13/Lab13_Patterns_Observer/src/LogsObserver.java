import javax.swing.*;
import java.awt.event.KeyEvent;

public class LogsObserver implements MyObserver {
    private DefaultListModel dlm = new DefaultListModel();
    private JList<String> logs = new JList(dlm);
    @Override
    public void update(KeyEvent event) {
        dlm.add(dlm.size(), "Key " + event.getKeyChar() + " was pressed");
    }

    public JList<String> getLogs() {
        return logs;
    }
}
