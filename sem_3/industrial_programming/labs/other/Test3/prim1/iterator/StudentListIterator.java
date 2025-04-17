package prim1.iterator;

import prim1.Student;

public interface StudentListIterator {
    void first();
    void next();
    boolean isDone();
    Student currentItem();
}
