
public class Academic extends Person implements MyVisitable{
    private String phoneNumber;

    public Academic(String name, long id, String phoneNumber) {
        super(name, id);
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public String acceptMyVisitor(MyVisitor v) {
        return v.visitAcademic(this);
    }

}
