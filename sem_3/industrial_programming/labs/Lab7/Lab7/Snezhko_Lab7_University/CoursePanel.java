import javax.swing.*;
import java.awt.*;
public class CoursePanel extends JFrame {
    private Course course;
    private JLabel label;
//    private JButton buttonAdd;
//  private JButton buttonDelete;
//    private JButton button;

    public CoursePanel(String title, Course c) throws HeadlessException {
        super(title);
        this.course = c;

//        this.label = new JLabel(course.toString());
        //JTextField text = new JTextField(course.toString());
        JTextArea area = new JTextArea(course.toString());
        //this.add(label, BorderLayout.NORTH);
        this.add(area, BorderLayout.NORTH);

//        buttonAdd = new JButton("Add");
//        this.add(buttonAdd, BorderLayout.WEST);
        //buttonAdd.addActionListener(this);

//        buttonDelete = new JButton("Delete");
//        this.add(buttonDelete, BorderLayout.EAST);
        //buttonDelete.addActionListener(this);

//        button = new JButton("Button");
//        this.add(button);
    }
}
