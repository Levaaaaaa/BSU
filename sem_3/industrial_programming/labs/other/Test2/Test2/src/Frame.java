import javax.swing.*;

public class Frame extends JFrame {
    private JList list;
    public Frame() {
        super("Frame");
        list = new ListView(initList());
        add(list);
    }
    private StudentLinkedList initList() {
        StudentLinkedList list = new StudentLinkedList(new Student("student1"));
        list.add(new Student("student1"));
        list.add(new Student("student2"));
        list.add(new Student("student3"));
        return list;
    }
}
