package prim1.iterator;

import prim1.Student;
import prim1.StudentLinkedList;

import java.util.List;
import java.util.NoSuchElementException;

public class ConcreteStudentListIterator implements StudentListIterator{
    private List<Student> students;
    private int current;

    public ConcreteStudentListIterator(List<Student> students) {
        this.students = students;
    }

    @Override
    public void first() {
        current = 0;
    }

    @Override
    public void next() {
        ++current;
    }

    @Override
    public boolean isDone() {
        return current >= students.size();
    }

    @Override
    public Student currentItem() {
        if (isDone()) {
            throw new NoSuchElementException();
        }
        return students.get(current);
    }
}
