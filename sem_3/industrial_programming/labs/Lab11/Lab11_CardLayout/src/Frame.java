import javax.swing.*;
import java.awt.*;

public class Frame extends JFrame {
    //private JPanel cards = new JPanel(new CardLayout());
    private JTabbedPane tabbedPane = new JTabbedPane();
    private JPanel twoListsPanel = new TwoListsPanel();
    private JPanel gridLayoutButtonsPanel = new LotOfButtons();
    private JPanel radioButtonWithIconsPanel = new RadioButtonsAndIconsPanel();
    private JList leftList;
    private JList rightList;
    private JButton toRight;
    private JButton toLeft;
    public Frame() {
        super("My Frame");
        tabbedPane.addTab("TWO LISTS", twoListsPanel);
        tabbedPane.addTab("BUTTONS", gridLayoutButtonsPanel);
        tabbedPane.addTab("RADIO BUTTON", radioButtonWithIconsPanel);
        add(tabbedPane);
    }
}
