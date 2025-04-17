public abstract class BaseSweet implements Comparable<BaseSweet>{
    private String name;
    private double weight;
    private double sugarProportion;
    public BaseSweet(String name, double weight, double sugarProportion) {
        this.name = name;
        this.weight = weight;
        this.sugarProportion = sugarProportion;
    }

    public static BaseSweet createSweetByString(String sweet) throws NumberFormatException{
        BaseSweet result;
        String[] parameters = sweet.split("/");
        if (parameters.length != 4) throw new IllegalArgumentException();
        double weight = Double.parseDouble(parameters[2]);
        double sugarProprtion = Double.parseDouble(parameters[3]);
        switch (parameters[0]) {
            case "Candy" : result = new Candy(parameters[1], weight, sugarProprtion);
            case "Chocolate" : result = new Chocolate(parameters[1], weight, sugarProprtion);
            default : result = new Candy(parameters[1], weight, sugarProprtion);
        }
        return result;
    }
    @Override
    public int compareTo(BaseSweet sweet) {
        return Double.valueOf(this.weight).compareTo(sweet.weight);
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getSugarProportion() {
        return sugarProportion;
    }

    public void setSugarProportion(double sugarProportion) {
        this.sugarProportion = sugarProportion;
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        return sb.append("Name: ")
                .append(this.name)
                .append(" Weight(kg): ")
                .append(this.weight)
                .append(" sugar proportion: ")
                .append(this.sugarProportion)
                .toString();
    }
    public String toStringForWriting() {
        StringBuilder sb = new StringBuilder();
        return sb.append(this.name)
                .append("/")
                .append(this.weight)
                .append("/")
                .append(this.sugarProportion)
                .toString();
    }
}
