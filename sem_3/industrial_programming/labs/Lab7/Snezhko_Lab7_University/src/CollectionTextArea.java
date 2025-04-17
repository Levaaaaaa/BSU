import javax.swing.*;
import java.util.Collection;
public class CollectionTextArea extends JTextArea
{
    public <T> void showCollection(Collection<T> collection) {
        for (T item : collection) {
            this.append(item.toString());
            this.append("\n");
        }
    }
}
