import java.util.*;
import java.util.function.Consumer;

public class MySet<T> implements Iterable<T>{
    private ArrayList<T> set;
    private ArrayList<MyObserver> observers;
    public MySet() {
        set = new ArrayList<>();
        observers = new ArrayList<>();
    }
    public MySet(T first) {
        this();
        add(first);
    }

//iterator
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


//features
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

//for observers
    public void subscribe(MyObserver o) {
        observers.add(o);
    }
    public void deescribe(MyObserver o) {
        observers.remove(o);
    }
    public void notifyMyObservers(T addedItem) {
        for (MyObserver o : observers) {
            o.update(addedItem);
        }
    }

    //add
    public boolean add(T t) {
        if (!set.contains(t)) {
            set.add(t);
            notifyMyObservers(t);
            return true;
        }
        return false;
    }

//simple methods
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
    public void addAll(Collection<T> c) {
        for(T item : c) {
            add(item);
        }
    }
    public boolean remove(Object t) {
        if (set.contains(t)) {
            set.remove(t);
            return true;
        }
        return false;
    }
}
