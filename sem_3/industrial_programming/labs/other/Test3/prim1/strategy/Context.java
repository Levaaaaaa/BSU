package prim1.strategy;

import java.util.ArrayList;
import java.util.List;

public class Context {
    private List<User> users = new ArrayList<>();
    private NotificationStrategy strategy = new EmailNotificationStrategy();
    public void setStrategy(NotificationStrategy strategy) {
        this.strategy = strategy;
    }
    public void doSomething(String message) {
        users.forEach(user -> strategy.notifyUser(user, message));
    }
    public void addUser(User user) {
        users.add(user);
    }
}
