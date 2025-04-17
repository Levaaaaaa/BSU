import java.util.*;

public class Gift implements Iterable{
    private ArrayList<BaseSweet> sweets = new ArrayList<>();

    public Gift(ArrayList<BaseSweet> sweets) {
        this.sweets = sweets;
    }
    public Gift(String gift) throws NumberFormatException, IllegalArgumentException{
        gift.lines().forEach(line -> sweets.add(BaseSweet.createSweetByString(line)));
    }
    public void add(BaseSweet sweet) {
        sweets.add(sweet);
    }
    public double findGeneralWeight() {
        double result = 0;
        /*Iterator<BaseSweet> iter = sweets.iterator();
        while (iter.hasNext()) {
            result += iter.next().getWeight();
        }*/
        result = sweets.stream()
                .mapToDouble(sweet -> sweet.getWeight())
                .sum();
        return result;
    }
    public void sort(Comparator<BaseSweet> comparator) {
        sweets.sort(comparator);
    }
    public BaseSweet findSweetBySugar(double minSugar, double maxSugar) {
        return sweets.stream().
                filter(sweet ->
                        (sweet.getSugarProportion() >= minSugar
                                && sweet.getSugarProportion() <= maxSugar))
                .findFirst().orElse(null);
    }
    @Override
    public Iterator<BaseSweet> iterator() {
        return sweets.iterator();
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sweets.forEach(sweet -> {
            sb.append(sweet.toString())
                    .append("\n");
        });
        return sb.toString();
    }
}
