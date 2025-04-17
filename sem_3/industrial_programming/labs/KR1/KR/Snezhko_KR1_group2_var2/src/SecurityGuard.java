import java.io.IOException;

public class SecurityGuard extends Employee{
    private static final double BASE = 0.5;
    private Double area;

    public SecurityGuard(String lastName, String organization, Double jobCoefficient, Double area) {
        super(lastName, organization, jobCoefficient);
        this.area = area;
    }
    public SecurityGuard(String unparseString) throws IOException, NumberFormatException{
        super(unparseString);
        String[] parameters = unparseString.split("/");
        area = Double.parseDouble(parameters[3]);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString())
                .append("/")
                .append(this.area);
        return sb.toString();
    }
    @Override
    public int calculateSalary() {
        return (int)Math.round(BASE * this.area * this.jobCoefficient);
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }
}
