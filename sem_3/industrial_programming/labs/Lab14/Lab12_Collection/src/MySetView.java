import javax.swing.*;
import java.util.HashSet;
import java.util.Set;

public class MySetView<T> extends JList implements MyObserver<T>{
    private DefaultListModel listModel = new DefaultListModel();
    public MySetView() {
        super();
        this.setModel(listModel);
    }

    public MySetView(MySet<T> mySet) {
        this();
        mySet.subscribe(this);
    }
    public DefaultListModel getListModel() {
        return listModel;
    }

    @Override
    public void update(T addedItem) {
        listModel.addElement(addedItem);
    }
}
