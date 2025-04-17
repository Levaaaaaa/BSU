package strategy;

import mvc.MySet;
import visitor.CalculateCardinalityVisitor;
import visitor.MyVisitor;

public class CalculateCardinalityByVisitorStrategy implements CalculateCardinalityStrategy{
    @Override
    public int calculateCardinality(MySet set) {
        MyVisitor visitor = new CalculateCardinalityVisitor();
        return set.acceptMyVisitor(visitor);
        /*ArrayList<Integer> list = set.toOrdinaryNumbers();
        return list.size();
         */
    }
}
