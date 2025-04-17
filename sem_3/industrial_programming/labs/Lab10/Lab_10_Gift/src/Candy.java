public class Candy extends BaseSweet {

    private static final String TYPE = "Candy";
    public Candy(String name, double weight, double sugarProportion) {
        super(name, weight, sugarProportion);
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        return sb.append("Type: ")
                .append(TYPE)
                .append(" ")
                .append(super.toString())
                .toString();
    }
    public String toStringForWriting() {
        StringBuilder sb = new StringBuilder();
        return sb.append(TYPE)
                .append("/")
                .append(super.toStringForWriting())
                .toString();
    }
}
