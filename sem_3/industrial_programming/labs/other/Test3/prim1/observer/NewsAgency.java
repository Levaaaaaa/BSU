package prim1.observer;

import java.util.ArrayList;
import java.util.List;

public class NewsAgency implements MySubject{
    private String news;

    private List<MyObserver> observers = new ArrayList<>();

    public NewsAgency(String news) {
        this.news = news;
    }

    public String getNews() {
        return news;
    }

    public void setNews(String news) {
        this.news = news;
        notifyObservers();
    }

    @Override
    public void attach(MyObserver observer) {
        observers.add(observer);
    }

    @Override
    public void detach(MyObserver observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        observers.forEach(o -> o.update(this));
    }
}
