import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
public class Table<K, V> {
    private ArrayList<Map.Entry<K,V>> array = new ArrayList<>();
    Map<K,V> map = new HashMap<>();
    public Table(K firstKey, V firstValue) {
//        array.add(new HashMap.Entry<K, V>(firstKey, firstValue));
    }
}
