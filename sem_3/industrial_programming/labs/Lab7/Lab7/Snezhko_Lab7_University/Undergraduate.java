public class Undergraduate extends Student{
    private Academic tutor;

    public Undergraduate(String login, String email, Academic tutor) {
        super(login, email);
        this.tutor = tutor;
    }

    public Academic getTutor() {
        return tutor;
    }

    public void setTutor(Academic tutor) {
        this.tutor = tutor;
    }
    public String toString() {
        return super.toString() + " | " + "Tutor: " + this.getTutor().getName();
    }
}
