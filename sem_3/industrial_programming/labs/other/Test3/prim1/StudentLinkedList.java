package prim1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class StudentLinkedList implements StudentList, Iterable<Student> {
    private StudentNode head;

    private class StudentNode {
        private Student data;
        private StudentNode next;

        public StudentNode(Student student, StudentNode initialLink) {
            this.data = student;
            next = initialLink;
        }

        public Student getData() {
            return data;
        }

        public void setData(Student student) {
            this.data = student;
        }

        public StudentNode getNext() {
            return next;
        }

        public void setNext(StudentNode node) {
            next = node;
        }
    }

    @Override
    public Iterator<Student> iterator() {
        return new Iterator<Student>() {
            private StudentNode current = head;

            @Override
            // Returns true if the iteration has more elements.
            public boolean hasNext() {
                return current != null;
            }

            @Override
            // Returns the next element in the iteration.
            // Throws: NoSuchElementException - if the iteration has no more elements
            public Student next() {
                Student curStud = current.data;
                current = current.next;
                return curStud;
            }
        };
    }

    public void add(Student student) {
        head = new StudentNode(student, head);
    }

    public void delete(String studentName) {
        if (head == null) {
            return;
        }
        if (head.getData().getName().equals(studentName)) {
            head = head.getNext();
        } else {
            for (StudentNode temp = head.getNext(), previous = head;
                 temp != null; temp = temp.getNext()) {
                if (temp.getData().getName().equals(studentName)) {
                    previous.setNext(temp.getNext());
                    return;
                }
            }
        }
    }

    public void print() {
        System.out.print("List: ");
        for (StudentNode temp = head; temp != null; temp = temp.getNext()) {
            System.out.print(temp.getData() + " ");
        }
        System.out.println();
    }

    public List<Student> toList(){
        List<Student> result = new ArrayList<>();
        for (StudentNode temp = head; temp != null; temp = temp.getNext()) {
            result.add(temp.getData());
        }
        return result;
    }
}
