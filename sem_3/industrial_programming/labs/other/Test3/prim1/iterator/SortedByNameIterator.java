package prim1.iterator;

import prim1.Student;
import prim1.StudentLinkedList;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;

public class SortedByNameIterator implements Iterator {

    //private StudentLinkedList students;
    private ArrayList<Student> list = new ArrayList<>();
    private int current;
    public SortedByNameIterator(StudentLinkedList students) {
        //students = studentsList;
        for (Student s : students) {
            list.add(s);
        }
        list.sort(Comparator.comparing(Student::getName));
    }

    @Override
    public boolean hasNext() {
        return current < list.size();
    }

    @Override
    public Object next() {
        return list.get(current++);
    }
}
