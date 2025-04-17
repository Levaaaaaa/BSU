public class Student extends Person implements MyVisitable{
    private long recordBookNumber;
    public Student(String name, long id, long recordBookNumber) {
        super(name, id);
        this.recordBookNumber = recordBookNumber;
    }

    @Override
    public String acceptMyVisitor(MyVisitor v) {
        return v.visitStudent(this);
    }

    public long getRecordBookNumber() {
        return recordBookNumber;
    }

    public void setRecordBookNumber(long recordBookNumber) {
        this.recordBookNumber = recordBookNumber;
    }
}
