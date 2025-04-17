package visitor;

public class MyVisitorImpl implements MyVisitor {
    private int count = 0;
    public MyVisitorImpl() {
        count = 0;
    }
    @Override
    public void visitInteger(Integer i) {
        count++;
    }
    public int getCount() {
        return count;
    }
}
