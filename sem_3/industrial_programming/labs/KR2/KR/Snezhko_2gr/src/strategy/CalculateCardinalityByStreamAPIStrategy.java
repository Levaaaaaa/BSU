package strategy;

import mvc.MySet;

public class CalculateCardinalityByStreamAPIStrategy implements CalculateCardinalityStrategy{
    @Override
    public int calculateCardinality(MySet set) {
        return set.asList()
                .stream()
                .mapToInt(x -> Integer.valueOf(x))
                .sum();
    }
    public String toString() {
        return "Cardinality by stream API";
    }
}
