import java.io.IOException;

public class Student implements Comparable<Student>{
    private String name;
    private int course;
    private double averrageGrades;

    public Student(String unparseString) throws NumberFormatException, IOException {
        String[] param = unparseString.split(" ");
        if (param.length != 3) {
            throw new IOException();
        }
        this.name = param[0];
        this.course = Integer.parseInt(param[1]);
        this.averrageGrades = Double.parseDouble(param[2]);
    }
    public Student(String name, int course, double averrageGrades) {
        this.name = name;
        this.course = course;
        this.averrageGrades = averrageGrades;
    }
    @Override
    public int compareTo(Student student) {
        return (int)(this.averrageGrades * 10 - student.getAverrageGrades() * 10);
    }
    public String toString() {
        return this.name + " " + this.course + " " + this.averrageGrades;
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCourse() {
        return course;
    }

    public void setCourse(int course) {
        this.course = course;
    }

    public double getAverrageGrades() {
        return averrageGrades;
    }

    public void setAverrageGrades(double averrageGrades) {
        this.averrageGrades = averrageGrades;
    }
}
