import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

public class TwoListsPanel extends JPanel implements ActionListener {
    DefaultListModel<String> dlmRight = new DefaultListModel<>();
    DefaultListModel<String> dlmLeft = new DefaultListModel<>();
    private JList leftList;
    private JList rightList;
    private JButton toRightButton;
    private JButton toLeftButton;
    public TwoListsPanel() {
        setLayout(new BorderLayout());
        leftList = new JList<String>(dlmLeft);
        dlmLeft.addAll(Arrays.stream(new String[]{"11", "12"}).toList());
        rightList = new JList<String>(dlmRight);
        dlmRight.addAll(Arrays.stream(new String[]{"21","22"}).toList());

        toRightButton = new JButton(">");
        toLeftButton = new JButton("<");

        add(toLeftButton, BorderLayout.SOUTH);
        add(rightList, BorderLayout.EAST);
        add(leftList, BorderLayout.WEST);
        add(toRightButton, BorderLayout.NORTH);

        toRightButton.addActionListener(this);
        toLeftButton.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(toRightButton)) {
            java.util.List selectedValues = leftList.getSelectedValuesList();
            if (selectedValues.size() == 0 || dlmLeft.isEmpty()) return;
            dlmRight.addAll(selectedValues);
            selectedValues.forEach(elem -> dlmLeft.removeElement(elem));
            //validate();
        }
        else if (e.getSource().equals(toLeftButton)) {
            java.util.List selectedValues = rightList.getSelectedValuesList();
            if (selectedValues.size() == 0 || dlmRight.isEmpty()) return;
            dlmLeft.addAll(selectedValues);
            selectedValues.forEach(elem -> dlmRight.removeElement(elem));
            //validate();
        }
    }
}
