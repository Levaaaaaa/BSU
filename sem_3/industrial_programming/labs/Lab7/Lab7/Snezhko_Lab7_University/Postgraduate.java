public class Postgraduate extends Student implements Notifiable{
    private Academic supervisior;
    public Postgraduate(String login, String email, Academic supervisior) {
        super(login, email);
        this.supervisior = supervisior;
    }

    public Academic getSupervisior() {
        return supervisior;
    }

    public void setSupervisior(Academic supervisior) {
        this.supervisior = supervisior;
    }
    public String toString() {
        return super.toString() + " | " + "Supervisior: " + this.getSupervisior().getName();
    }
}
