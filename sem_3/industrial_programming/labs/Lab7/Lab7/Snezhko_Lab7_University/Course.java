import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
import java.util.function.Predicate;

public class Course {
    private Set<Student> students;
    private String name;

    public Course(Set<Student> students, String name) {
        this.students = students;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public Set<Student> getStudents() {
        return students;
    }

    public Set<Postgraduate> getPostgraduates(String NameOfSuperVisior) {
        Set<Student> studentsSet = this.findAll(student -> student.getClass().equals(Postgraduate.class) && ((Postgraduate)student).getSupervisior().getName().equals(NameOfSuperVisior));//null;
        Set<Postgraduate> set = new HashSet<>(studentsSet.size());
        studentsSet.forEach(student -> set.add((Postgraduate) student));
        return set;
    }
    public void addStudent(Student s) {
        students.add(s);
    }
    public Iterator<Student> iterator() {
        return students.iterator();
    }
    public Set<Student> findAll(Predicate p) {
        Set<Student> result = new HashSet<>();
        for(Student s : students) {
            if (p.test(s)) {
                result.add(s);
            }
        }

        return result;
    }
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Name: ");
        builder.append(this.name);
        builder.append("\nStudents:\n");
        this.students.forEach(student -> builder.append(student.toString()+ "\n"));
        builder.append("\n\n");
        return builder.toString();
    }
}
