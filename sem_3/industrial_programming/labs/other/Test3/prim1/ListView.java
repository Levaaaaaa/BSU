package prim1;

import javax.swing.*;

public class ListView extends JList<Student> {
    private StudentLinkedList students;
    private DefaultListModel<Student> model;

    public ListView(StudentLinkedList students) {
        this.students = students;
        model = new DefaultListModel<>();
        for (Student s : students) {
            model.addElement(s);
        }
        setModel(model);
    }

    public void updateView() {
        model.removeAllElements();
        for (Student s : students) {
            model.addElement(s);
        }
    }
}
