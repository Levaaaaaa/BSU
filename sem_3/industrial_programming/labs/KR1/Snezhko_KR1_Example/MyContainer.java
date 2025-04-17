import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.lang.Comparable;
import java.util.Comparator;

public class MyContainer<Comparable> {
    ArrayList<Comparable> arrayList = new ArrayList<>();
    public MyContainer(ArrayList list) {
        this.arrayList = list;
    }
    public Comparable getMin() {
        return (Comparable)this.arrayList.stream().sorted().toArray()[0];
    }
    public Comparable getMax() {
        return (Comparable)this.arrayList.stream().sorted((Comparator<Comparable>)Comparator.reverseOrder()).toArray()[0];
    }
    public String toString() {
        StringBuilder builder = new StringBuilder();
        this.arrayList.forEach(item -> {
            builder.append(item.toString());
            builder.append("\n");
        });
        return builder.toString();
    }
}
