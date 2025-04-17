public class Student implements Notifiable{
    private String login;
    private String email;

    public Student(String login, String email) {
        this.login = login;
        this.email = email;
    }

    public String getLogin() {
        return login;
    }

    public String getEmail() {
        return email;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    public void notify(String message) {
        System.out.println("Student " + login + " got a message: " + message);
    }
    public String toString() {
        return "Login: " + this.getLogin() + " | " + "Email: " + this.getEmail();
    }
}
