import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.List;

public class Frame extends JFrame implements KeyListener {
    private List<MyObserver> observers = new ArrayList<>();
    public Frame() {
        super("Frame");
        LabelObserver labelObserver = new LabelObserver();
        LogsObserver logsObserver = new LogsObserver();

        observers.add(labelObserver);
        observers.add(logsObserver);

        JLabel label = labelObserver.getLabel();
        JList list = logsObserver.getLogs();

//        label.setBounds(label.getX(), label.getY(), 100, 100);
        label.setSize(new Dimension(100, 100));
        this.add(label, BorderLayout.WEST);
        this.add(list, BorderLayout.EAST);

        this.addKeyListener(this);
        setFocusable(true);
    }
    private void subscribe(MyObserver o) {
        observers.add(o);
    }
    private void describe(MyObserver o) {
        observers.remove(o);
    }
    private void notify(KeyEvent event) {
        for (MyObserver o : observers) {
            o.update(event);
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void keyPressed(KeyEvent e) {
        this.notify(e);
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
