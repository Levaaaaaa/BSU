import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.security.InvalidParameterException;
import java.util.HashSet;
import java.util.Set;
public class Frame extends JFrame implements ActionListener {
    private Set<JButton> courseButtons = new HashSet<>(1);
    Set<Course> courses;
    JButton button1;
    Course course;
    public Frame(String title, Course course) {
        super(title);
/*        this.courses = courses;
        for (Course course : this.courses) {
            JButton button = new JButton(course.getName());
            courseButtons.add(button);
            this.add(button,BorderLayout.NORTH);
            }
*/
        this.course = course;
        button1 = new JButton(course.getName());
        this.add(button1, BorderLayout.NORTH);
        button1.addActionListener(this);

    }
    @Override
    public void actionPerformed(ActionEvent e) {
        //try {
            if (this.button1 == e.getSource()) {
            //if (courseButtons.contains(e.getSource())) {
                //CoursePanel cp = new CoursePanel("Course", getCourseByButton(this.courses, (JButton) e.getSource()));
                CoursePanel cp = new CoursePanel(this.course.getName(), this.course);
                cp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                cp.setSize(500, 500);
                cp.setVisible(true);
            }
        //}
        /*catch (InvalidParameterException ex) {
            System.out.println("Uncorrect courses set!");
            return;
        }*/
    }
    /*
    private Course getCourseByButton(Set<Course> courses, JButton button) {
        for (Course c : courses) {
            if (c.getName().equals(button.getName())) {
                return c;
            }
        }
        throw new InvalidParameterException();
    }*/
}
