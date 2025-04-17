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
    private ArrayList<Observer> observers;
    public MySet() {
        list = new ArrayList<>();
        cardinalityStrategy = new CalculateCardinalityByVisitorStrategy();
        observers = new ArrayList<>();
    }
    public void add(int item) {
        if (item < 0) {
            return;
        }
        if (list.size() <= item) {
            int oldSize = list.size();
            for(int i = oldSize; i < item; i++) {
                list.add(0);
            }
            list.add(1);
        }
        else {
            list.set(item, 1);
        }
        notifyAllSubscribers();
    }
    public void save(File file) throws IOException {
        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> ordinaryList = toOrdinaryNumbers();
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
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == 1) {
                normalNumbers.add(i);
            }
        }
        return normalNumbers;
    }
    public void setCardinalityStrategy(CalculateCardinalityStrategy strategy) {
        cardinalityStrategy = strategy;
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
    public void setCalculateCardnalityStrategy(CalculateCardinalityStrategy s) {
        this.cardinalityStrategy = s;
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
}
