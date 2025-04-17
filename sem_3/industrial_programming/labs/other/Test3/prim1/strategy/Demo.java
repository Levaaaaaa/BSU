package prim1.strategy;

public class Demo {
    public static void main(String[] args) {
//        NotificationStrategy strSMS = new SmsNotificationStrategy();
        NotificationStrategy strEmail = new EmailNotificationStrategy();
        Context context = new Context();

        context.addUser(new User("user1", "email1", 1));
        context.addUser(new User("user2", "email2", 2));
        context.addUser(new User("user3", "email3", 3));

//        context.setStrategy(strSMS);
        context.doSomething("SMS message");

        System.out.println("\n");

        context.setStrategy(strEmail);
        context.doSomething("Email message");

    }
}
