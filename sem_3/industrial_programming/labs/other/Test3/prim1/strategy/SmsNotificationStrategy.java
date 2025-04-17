package prim1.strategy;

public class SmsNotificationStrategy implements NotificationStrategy{
    @Override
    public void notifyUser(User user, String message) {
        System.out.println("Message \"" + message + "\" has been sent by phone " + user.getPhone() + " - user: " + user.getName());
    }
}
