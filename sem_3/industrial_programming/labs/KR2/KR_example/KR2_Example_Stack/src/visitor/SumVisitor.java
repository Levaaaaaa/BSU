package visitor;

public class SumVisitor implements MyVisitor{
    private int sum = 0;
    @Override
    public void visitInteger(Integer i) {
        sum += i;
    }

    public int getSum() {
        return sum;
    }
}
