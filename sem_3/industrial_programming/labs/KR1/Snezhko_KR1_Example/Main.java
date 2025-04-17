import javax.swing.*;
import java.io.IOException;
import java.util.ArrayList;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Frame frame = new Frame("frame");
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        /*
        try {
            ArrayList<Double> list = MyReader.readDouble("double_input.txt");
            ArrayList<Student> listOfStudents = MyReader.readStudents("students_input.txt");

        list.add(5.0d);
        list.add(3.0d);
        list.add(50.0d);
        list.add(53.0d);
        list.add(9.0d);
        list.add(15.0d);

            MyContainer<Integer> container = new MyContainer<>(list);
            System.out.println(container.getMin());
            System.out.println(container.getMax());

            MyContainer<Student> students = new MyContainer<>(listOfStudents);
            System.out.println(students.getMin());
            System.out.println(students.getMax());
        }
        catch (IOException e) {
            System.out.println("IOException throw!!!");
            return;
        }
        */
    }
}