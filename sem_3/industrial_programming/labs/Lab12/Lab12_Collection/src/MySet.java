import java.util.*;
import java.util.function.Consumer;

public class MySet<T> implements Iterable<T>{
    private ArrayList<T> set;
    public MySet() {
        set = new ArrayList<>();
    }
    public MySet(T first) {
        this();
        set.add(first);
    }
    public int size() {
        int result = 0;
        for (T t : set) {
            result++;
        }
        return result;
    }

    public boolean isEmpty() {
        return size() == 0;
    }
    public void clear() {
        for (T t : set) {
            set.remove(t);
        }
    }
    public boolean equals(MySet<T> set1) {
        for (T t : set1) {
            if (!contains(t)) {
                return false;
            }
        }
        return true;
    }
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{");
        for (T t : this) {
            builder.append(t.toString())
                    .append(",");
        }
        builder.append("}");
        return builder.toString();
    }
    public ArrayList<T> getCollection() {
        return set;
    }
    public boolean add(T t) {
        if (!set.contains(t)) {
            set.add(t);
            return true;
        }
        return false;
    }
    public boolean remove(Object t) {
        if (set.contains(t)) {
            set.remove(t);
            return true;
        }
        return false;
    }

/*
    public boolean addAll(Collection collection) {
        if (collection == null) {
            return false;
        }
        collection.forEach(item -> {
            if (!set.contains(item)) {
                set.add((T)item);
            }
        });
        return true;
    }
 */
    /*
    public boolean removeAll(Collection c) {
        return false;
    }
     */

    @Override
    public Iterator<T> iterator() {
        Iterator<T> iterator = new Iterator<>()
        {
            private int curIndex;
            @Override
            public boolean hasNext() {
                return curIndex < set.size() && set.get(curIndex) != null;
            }
            @Override
            public T next() {
                return set.get(curIndex++);
            }
        };

        return iterator;
    }

    public Object[] toArray() {
        return set.toArray();
    }


    @Override
    public void forEach(Consumer action) {
        Objects.requireNonNull(action);
        for(T t : set) {
            action.accept(t);
        }
    }
    public boolean contains(T t) {
        if (t == null) return false;
        for (T item : set) {
            if (item.equals(t)) {
                return true;
            }
        }
        return false;
    }
    public MySet<T> conjunction(MySet<T> set1) {
        MySet<T> result = new MySet<>();
        if (set1 != null) {
            this.forEach(item -> {
                if (set1.contains((T) item)) {
                    result.add((T) item);
                }
            });
        }
        return result;
    }
    public MySet<T> disjunction(MySet<T> set1) {
        MySet<T> result = new MySet<>();
        this.forEach(item -> result.add((T)item));
        set1.forEach(item -> result.add((T)item));
        return result;
    }
    public MySet<T> xor(MySet<T> set1) {
        MySet<T> result = new MySet<>();
        if (set1 != null) {
            MySet<T> con = this.conjunction(set1);
            MySet<T> dis = this.disjunction(set1);
            dis.forEach(item -> {
                if (!con.contains((T) item)) {
                    result.add((T) item);
                }
            });
        }
        return result;
    }
}
