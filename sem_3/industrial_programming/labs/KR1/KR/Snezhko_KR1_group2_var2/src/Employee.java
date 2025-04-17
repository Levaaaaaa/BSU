import java.io.IOException;

public abstract class Employee {
    private String lastName;
    private String organization;
    Double jobCoefficient;

    public Employee(String lastName, String organization, Double jobCoefficient) {
        this.lastName = lastName;
        this.organization = organization;
        this.jobCoefficient = jobCoefficient;
    }
    public Employee(String unparseString) throws IOException, NumberFormatException {
        String[] parameters = unparseString.split("/");
        if (parameters.length != 4) throw new IOException();
        lastName = parameters[0];
        organization = parameters[1];
        jobCoefficient = Double.parseDouble(parameters[2]);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lastName)
                .append("/")
                .append(this.jobCoefficient)
                .append("/")
                .append(this.organization);
        return sb.toString();
    }
    public abstract int calculateSalary();
    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getOrganization() {
        return organization;
    }

    public void setOrganization(String organization) {
        this.organization = organization;
    }

    public Double getJobCoefficient() {
        return jobCoefficient;
    }

    public void setJobCoefficient(Double jobCoefficient) {
        this.jobCoefficient = jobCoefficient;
    }
}
