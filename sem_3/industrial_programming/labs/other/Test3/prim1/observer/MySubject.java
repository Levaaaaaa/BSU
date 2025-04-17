package prim1.observer;

public interface MySubject {
    public void attach(MyObserver observer);
    public void detach(MyObserver observer);
    public void notifyObservers();
}
