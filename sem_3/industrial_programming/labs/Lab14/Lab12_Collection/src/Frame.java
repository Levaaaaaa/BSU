import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collection;

public class Frame extends JFrame implements ActionListener {
//Panels
    private JPanel mainPanel = new JPanel(new GridLayout(1, 3));
    private JPanel list1Panel = new JPanel(new GridLayout(5, 1));
    private JPanel list2Panel = new JPanel(new GridLayout(5, 1));
    private JPanel listResultPanel = new JPanel(new GridLayout(1, 1));
    private JPanel buttonsPanel = new JPanel(new GridLayout(3, 1));
//Buttons
    private JButton conButton = new JButton("CONJUNCT");
    private JButton disButton = new JButton("DISJUNCT");
    private JButton xorButton = new JButton("XOR");
//Models
    private MySet<Person> set1 = new MySet<>();
    private MySet<Person> set2 = new MySet<>();
    private MySet<String> setResult = new MySet<>();

//Views
    private MySetView<Person> list1 = new MySetView(set1);
    private MySetView<Person> list2 = new MySetView(set2);
    private MySetView<Person> listResult = new MySetView(setResult);
//Main Frame
    public Frame() {
        super("Frame");
        initSet1();
        initSet2();

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

        set1.add(new Student("st1", 1L, 1L));
        set1.add(new Student("st2", 2L, 2L));
        set1.add(new Academic("ac1", 3L, "+111111"));
        set1.add(new Academic("ac2", 4L, "+222222"));
    }
    private void initSet2() {
        set2.add(new Student("st1", 1L, 1L));
        set2.add(new Student("st2", 2L, 2L));
        set2.add(new Academic("ac2", 4L, "+222222"));
        set2.add(new Academic("ac4", 5L, "+4444444"));
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        listResult.getListModel().clear();
        if (e.getSource().equals(conButton)) {
            java.util.List list = set1.conjunction(set2).getCollection();
            listResult.getListModel().addAll(list);
        }
        else if (e.getSource().equals(disButton)) {
            java.util.List list = set1.disjunction(set2).getCollection();
            listResult.getListModel().addAll(list);
        }
        else if (e.getSource().equals(xorButton)) {
            java.util.List list = set1.xor(set2).getCollection();
            listResult.getListModel().addAll(list);
        }
    }
}
