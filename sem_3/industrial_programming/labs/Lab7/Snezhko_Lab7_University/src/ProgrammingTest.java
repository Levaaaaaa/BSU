import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.io.IOException;
import java.util.List;

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

        JFrame frame = new JFrame("University");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 400);
        frame.setBounds(100, 200, 300, 400);

        List<Integer> intList = new ArrayList<>();
        intList.add(10);
        intList.add(7);
        intList.add(5);


        CollectionTextArea startTextArea = new CollectionTextArea();
        //frame.add(startTextArea);
        CollectionTextArea finishTextArea = new CollectionTextArea();

/*        GridLayout layout = new GridLayout();
        layout.addLayoutComponent("start", startTextArea);
        layout.addLayoutComponent("finish", finishTextArea);
*/
        frame.setLayout(new GridLayout(1, 2));
        startTextArea.showCollection(intList);
        Iterator<Integer> iterator1 = intList.iterator();
        //intList.sort(i -> [i] <= intList[i+1]);
        //finishTextArea.showCollection();

        frame.add(startTextArea);
        frame.add(finishTextArea);

        frame.setVisible(true);
/*
        CoursePanel cp = new CoursePanel("Course 1", course1);
        cp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        cp.setSize(500,500);
        cp.setVisible(true);
 */
        /*
        Set<Course> set = new HashSet<>();
        set.add(course1);
        //Frame frame = new Frame("All Courses", set);
        Frame frame = new Frame("All Courses", course1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,500);
        frame.setVisible(true);
         */
    }
}
