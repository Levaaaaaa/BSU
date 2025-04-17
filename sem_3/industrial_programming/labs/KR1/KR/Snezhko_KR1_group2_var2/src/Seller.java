import java.io.IOException;

public class Seller extends Employee{
    private static final double PERCENT = 0.5;
    private int proceeds;

    public Seller(String lastName, String organization, Double jobCoefficient, int proceeds) {
        super(lastName, organization, jobCoefficient);
        this.proceeds = proceeds;
    }

    public Seller(String unparseString) throws IOException, NumberFormatException{
        super(unparseString);
        String[] parameters = unparseString.split("/");
        proceeds = Integer.parseInt(parameters[4]);
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString())
                .append("/")
                .append(this.proceeds);
        return sb.toString();
    }
    @Override
    public int calculateSalary() {
        return (int)(this.jobCoefficient * this.proceeds * PERCENT);
    }

    public int getProceeds() {
        return proceeds;
    }

    public void setProceeds(int proceeds) {
        this.proceeds = proceeds;
    }
}
