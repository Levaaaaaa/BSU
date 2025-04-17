import javax.swing.*;

public class ListView extends JList {
    private StudentLinkedList list;
    private DefaultListModel model = new DefaultListModel();
    public ListView(Student first) {
        list = new StudentLinkedList(first);
    }
    public ListView(StudentLinkedList list_) {
        list = list_;
        int i = 0;
        for(Student s : list) {
            model.add(i, s);
            i++;
        }
    }
    public void add(Student s) {
        model.add(list.size(), s);
    }
    public DefaultListModel getModel() {
        return model;
    }
}
