package observer;

public interface Observable {
    public void subscribe(Observer o);
    public void describe(Observer o);
    public void notifyAllSubscribers();
}
