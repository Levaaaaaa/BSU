package prim1.strategy;

public class EmailNotificationStrategy implements NotificationStrategy{
    @Override
    public void notifyUser(User user, String message) {
        System.out.println("Message \"" + message + "\" has been sent by email " + user.getEmail() + " - user: " + user.getName());
    }
}
