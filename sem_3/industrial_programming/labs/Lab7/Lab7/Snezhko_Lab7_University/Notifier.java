import java.util.Set;
public class Notifier {
    private Set<Notifiable> notifiables;

    public Notifier(Set<Notifiable> notifiables) {
        this.notifiables = notifiables;
    }
    public void doNotifyAll(String message) {
        for (Notifiable n : notifiables) {
            n.notify(message);
        }
    }
}
