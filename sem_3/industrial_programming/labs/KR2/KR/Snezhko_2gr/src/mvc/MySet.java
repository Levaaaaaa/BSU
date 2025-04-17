package mvc;

import iterator.MyIterable;
import iterator.MyIterator;
import iterator.MyIteratorImpl;
import observer.Observable;
import observer.Observer;
import strategy.CalculateCardinalityByVisitorStrategy;
import strategy.CalculateCardinalityStrategy;
import visitor.MyVisitable;
import visitor.MyVisitor;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MySet implements MyIterable<Integer>, MyVisitable, Observable {
    private ArrayList<Integer> list;
    private CalculateCardinalityStrategy cardinalityStrategy;
    private int min;
    private ArrayList<Observer> observers;
    public MySet() {
        list = new ArrayList<>();
        cardinalityStrategy = new CalculateCardinalityByVisitorStrategy();
        observers = new ArrayList<>();
        min = 0;
    }
    public void add(int item) {
        if (item < min) {
            while(item < min) {
                list.add(0, 0);
                min--;
            }
            list.set(0, 1);
            return;
        }
        int actualSize = list.size() - Math.abs(min);
        if (actualSize <= item) {
            int oldSize = actualSize;
            for(int i = oldSize; i < item; i++) {
                list.add(0);
            }
            list.add(1);
        }
        else {
            list.set(item + Math.abs(min), 1);
        }
        notifyAllSubscribers();
    }
    public void save(File file) throws IOException {
        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> ordinaryList = toOrdinaryNumbers();

        list.forEach(bin -> sb.append(bin + " "));
        sb.deleteCharAt(sb.length() - 1);

        sb.append("\n");

        ordinaryList.forEach(num -> sb.append(num + " "));
        sb.deleteCharAt(sb.length() - 1);

        FileWriter writer = new FileWriter(file);
        writer.write(sb.toString());
        writer.close();
    }
    public int cardinality() {
        return cardinalityStrategy.calculateCardinality(this);
    }
    public Integer get(int index) {
        if (index < 0 || index > list.size()) {
            return null;
        }
        return list.get(index);
    }
    public int size() {
        return list.size();
    }
    public ArrayList<Integer> toOrdinaryNumbers() {
        ArrayList<Integer> normalNumbers = new ArrayList<>();
        int umin = Math.abs(min);
        for (int i = 0; i < umin; i++) {
            if (list.get(i) == 1) {
                normalNumbers.add(i - umin);
            }
        }
        for (int i = umin; i < list.size(); i++) {
            if (list.get(i) == 1) {
                normalNumbers.add(i - umin);
            }
        }
        return normalNumbers;
    }
    public void setCardinalityStrategy(CalculateCardinalityStrategy strategy) {

        cardinalityStrategy = strategy;
        notifyAllSubscribers();
    }
    public CalculateCardinalityStrategy getCardinalityStrategy() {
        return cardinalityStrategy;
    }
    public String toString() {
        return list.toString();//toOrdinaryNumbers().toString();
    }

    @Override
    public MyIterator<Integer> iterator() {
        return new MyIteratorImpl(this);
    }

    @Override
    public int acceptMyVisitor(MyVisitor v) {
        return v.visitMySet(this);
    }

    public int getMin() {
        return min;
    }

    @Override
    public void subscribe(Observer o) {
        observers.add(o);
    }

    @Override
    public void describe(Observer o) {
        observers.add(o);
    }

    @Override
    public void notifyAllSubscribers() {
        observers.forEach(o -> o.update(this));
    }

    public ArrayList<Integer> asList() {
        return list;
    }
}
