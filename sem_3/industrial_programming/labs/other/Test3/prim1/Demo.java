package prim1;

import prim1.iterator.ConcreteStudentListIterator;
import prim1.iterator.SortedByNameIterator;
//import prim1.iterator.SortedByNameIterator;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Iterator;

public class Demo {
    public static void main(String[] args) {
        StudentLinkedList students;
        students = new StudentLinkedList();
        Student s1 = new Student("Ivan");
        students.add(s1);
        s1 = new Student("Petr");
        students.add(s1);
        s1 = new Student("Oleg");
        students.add(s1);
        students.print();

        System.out.println("enhanced for = for-each loop");
        for (Student s : students) {
            System.out.println(s);
        }

        System.out.println("\nmethod forEach");
        students.forEach(System.out::println);  //forEach(Consumer<? super T> action)

        System.out.println("\nSOrt");
        Iterator<Student> it = new SortedByNameIterator(students);
        while (it.hasNext()) {
            System.out.println(it.next());

        }

        System.out.println("\nONE: ConcreteStudentListIterator");
        ConcreteStudentListIterator iter = new ConcreteStudentListIterator(students.toList());
        for (iter.first(); !iter.isDone(); iter.next()) {
            System.out.println(iter.currentItem());
        }

        System.out.println("\nTWO: ConcreteStudentListIterator");
        iter = new ConcreteStudentListIterator(students.toList());
        for (iter.first(); !iter.isDone(); iter.next()) {
            System.out.println(iter.currentItem());
        }

        JFrame frame = new JFrame();

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(100, 200, 1000, 600);
        ListView list = new ListView(students);
        frame.add(list);
        JTextField inputText = new JTextField("Input text");
        inputText.setBorder(new LineBorder(Color.BLUE, 3));
        inputText.setFont(new Font("Times New", Font.BOLD | Font.ITALIC, 14));
        frame.add(inputText, BorderLayout.NORTH);

        JButton addButton = new JButton("Add Student") {
            {
                addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        students.add(new Student(inputText.getText()));
                        list.updateView();
                        inputText.setText("Input text");
                    }
                });
            }
        };
        frame.add(addButton, BorderLayout.SOUTH);
        frame.setVisible(true);

    }


}
