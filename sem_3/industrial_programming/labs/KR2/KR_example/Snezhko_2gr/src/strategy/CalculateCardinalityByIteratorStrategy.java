package strategy;

import iterator.MyIterator;
import mvc.MySet;

public class CalculateCardinalityByIteratorStrategy implements CalculateCardinalityStrategy{
    @Override
    public int calculateCardinality(MySet set) {
        MyIterator<Integer> iter = set.iterator();
        int result = 0;
        while(iter.hasNext()) {
            if (iter.next() == 1) {
                result++;
            }
        }

        return result;
    }
}
