import javax.swing.*;

public class MySetView extends JList {
    private DefaultListModel listModel = new DefaultListModel();
    private MySet<String> set = new MySet<>();
    public MySetView() {
        super();
        this.setModel(listModel);
    }
    public MySetView(MySet<String> mySet) {
        this();
        set = mySet;
        int i = 0;
        for (String item : set) {
            listModel.add(i, item);
            i++;
        }
    }
    public DefaultListModel getListModel() {
        int i = 0;
        for (String str : set) {
            if (!listModel.contains(str)) {
                listModel.add(i, str);
            }
            i++;
        }
        return listModel;
    }
    public void setMySet(MySet<String> set) {
        this.set = set;
    }
}
