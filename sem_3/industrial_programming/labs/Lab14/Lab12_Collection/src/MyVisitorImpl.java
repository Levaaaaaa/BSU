public class MyVisitorImpl implements MyVisitor{
    @Override
    public String visitStudent(Student s) {
        StringBuilder sb = new StringBuilder();
        sb.append("Student ")
                .append(s.getName())
                .append("//Id: ")
                .append(s.getId())
                .append("//Record book number: ")
                .append(s.getRecordBookNumber());
        return sb.toString();
    }

    @Override
    public String visitAcademic(Academic a) {
        StringBuilder sb = new StringBuilder();
        sb.append("Academic ")
                .append(a.getName())
                .append("// ")
                .append(a.getId())
                .append("//")
                .append(a.getPhoneNumber());
        return sb.toString();
    }
}
