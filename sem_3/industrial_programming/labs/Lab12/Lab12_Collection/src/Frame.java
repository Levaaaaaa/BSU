import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collection;

public class Frame extends JFrame implements ActionListener {
    private JPanel mainPanel = new JPanel(new GridLayout(1, 3));
    private JPanel list1Panel = new JPanel(new GridLayout(5, 1));
    private JPanel list2Panel = new JPanel(new GridLayout(5, 1));
    private JPanel listResultPanel = new JPanel(new GridLayout(1, 1));
    private JPanel buttonsPanel = new JPanel(new GridLayout(3, 1));

    private JButton conButton = new JButton("CONJUNCT");
    private JButton disButton = new JButton("DISJUNCT");
    private JButton xorButton = new JButton("XOR");

    DefaultListModel model1 = new DefaultListModel<>();
    DefaultListModel model2 = new DefaultListModel<>();
    DefaultListModel modelResult = new DefaultListModel<>();
    private MySetView list1 = new MySetView();
    private MySetView list2 = new MySetView();
    private MySetView listResult = new MySetView();
    private MySet<String> set1 = new MySet<>();
    private MySet<String> set2 = new MySet<>();
    private MySet<String> setResult = new MySet<>();
    public Frame() {
        super("Frame");
        initSet1();
        initSet2();

        modelResult = listResult.getListModel();
/*        model1.addAll(set1);
        model2.addAll(set2);
        modelResult.addAll(setResult);
*/
        list1Panel.add(list1);
        list2Panel.add(list2);
        listResultPanel.add(listResult);

        buttonsPanel.add(conButton);
        buttonsPanel.add(disButton);
        buttonsPanel.add(xorButton);

        conButton.addActionListener(this);
        disButton.addActionListener(this);
        xorButton.addActionListener(this);

        mainPanel.add(list1Panel);
        mainPanel.add(list2Panel);
        mainPanel.add(buttonsPanel);
        mainPanel.add(listResultPanel);

        add(mainPanel);
    }
    private void initSet1() {
        set1.add("s11");
        set1.add("s12");
        set1.add("s13");
        list1.setMySet(set1);
        model1 = list1.getListModel();
    }
    private void initSet2() {
        set2.add("s11");
        set2.add("s22");
        set2.add("s23");
        set2.add("s24");
        list2.setMySet(set2);
        model2 = list2.getListModel();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(conButton)) {
            modelResult.clear();
            java.util.List<String> list = set1.conjunction(set2).getCollection();
            modelResult.addAll(list);
        }
        else if (e.getSource().equals(disButton)) {
            modelResult.clear();
            java.util.List<String> list = set1.disjunction(set2).getCollection();
            modelResult.addAll(list);
        }
        else if (e.getSource().equals(xorButton)) {
            modelResult.clear();
            java.util.List<String> list = set1.xor(set2).getCollection();
            modelResult.addAll(list);
        }
    }
}
