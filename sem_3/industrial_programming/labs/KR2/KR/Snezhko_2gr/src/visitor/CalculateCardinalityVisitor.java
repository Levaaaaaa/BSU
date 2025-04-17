package visitor;

import iterator.MyIterator;
import mvc.MySet;

public class CalculateCardinalityVisitor implements MyVisitor{

    private int cardinality = 0;
    @Override
    public int visitMySet(MySet set) {
        MyIterator<Integer> iter = set.iterator();
        while(iter.hasNext()) {
            if (iter.next() == 1) {
                cardinality++;
            }
        }
        return cardinality;
        //return 0;
    }
}
