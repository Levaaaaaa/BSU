import javax.swing.*;
import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
import java.io.IOException;

public class ProgrammingTest {
    public static void main(String[] args) {
        Academic horstmann = new Academic("Cay Horstmann");
        Academic deitel = new Academic("Paul Deitel");
        Course course1 = new Course(new HashSet<Student>(5), "Course 1");

        Undergraduate gg4 = new Undergraduate("gg4", "1@gmail.com", deitel);
        course1.addStudent(gg4);
        Undergraduate pr3 = new Undergraduate("pr3", "2@gmail.com", horstmann);
        course1.addStudent(pr3);
        Postgraduate te2 = new Postgraduate("te2", "3@gmail.com", deitel);
        course1.addStudent(te2);
        Postgraduate yj34 = new Postgraduate("yj34","4@gmail.com", horstmann);
        course1.addStudent(yj34);
        Postgraduate jj8 = new Postgraduate("jj8", "5@gmail.com", horstmann);
        course1.addStudent(jj8);

        Set<Postgraduate> keyHorstmannsStudents = course1.getPostgraduates("Cay Horstmann");
        keyHorstmannsStudents.forEach(pg -> System.out.println(((Postgraduate)pg).toString()));

        Set<Notifiable> notifiables = new HashSet<>(keyHorstmannsStudents.size());
        Iterator<Student> iterator = course1.iterator();
        while (iterator.hasNext())
        {
            Student next = iterator.next();
            if (keyHorstmannsStudents.contains(next)) {
                notifiables.add((Notifiable)next);
            }
        }
        Notifier notifierForKeyHorstmannsStudents = new Notifier(notifiables);
        notifierForKeyHorstmannsStudents.doNotifyAll("Hello, student!");
        try
        {
            Writer.write(course1);
        }
        catch (IOException e)
        {
            System.out.println("Error of file writer!");
            return;
        }
/*
        CoursePanel cp = new CoursePanel("Course 1", course1);
        cp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        cp.setSize(500,500);
        cp.setVisible(true);
 */
        Set<Course> set = new HashSet<>();
        set.add(course1);
        //Frame frame = new Frame("All Courses", set);
        Frame frame = new Frame("All Courses", course1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setVisible(true);
    }
}
