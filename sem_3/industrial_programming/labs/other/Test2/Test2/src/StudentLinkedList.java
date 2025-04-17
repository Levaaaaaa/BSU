import java.util.Iterator;
import java.util.function.Consumer;

public class StudentLinkedList implements StudentList, Iterable<Student>{
    private StudentNode head;

    public StudentLinkedList() {
        this.head = new StudentNode(new Student(""), null);
    }
    public StudentLinkedList(Student head) {
        this.head = new StudentNode(head, null);
    }

    public StudentNode getHead() {
        return head;
    }

    public void setHead(StudentNode head) {
        this.head = head;
    }

    @Override
    public Iterator<Student> iterator() {
        Iterator<Student> result = new Iterator<Student>() {
            StudentNode current = head;
            @Override
            public boolean hasNext() {
                return current.getNext() != null;
            }

            @Override
            public Student next() {
                Student student = current.getData();
                current = current.getNext();
                return student;
                /*
                if (current.getNext() == null) {
                    return current.getData();
                }
                StudentNode old = current;
                current = current.getNext();
                return old.getData();

                 */
            }

        };
        return result;
    }

    private class StudentNode {
        Student data;
        StudentNode next;

        public StudentNode(Student data, StudentNode next) {
            this.data = data;
            this.next = next;
        }

        public Student getData() {
            return data;
        }

        public StudentNode getNext() {
            return next;
        }

        public void setData(Student data) {
            this.data = data;
        }

        public void setNext(StudentNode next) {
            this.next = next;
        }
    }

    @Override
    public void add(Student student) {
        StudentNode newNode = new StudentNode(student, head);
        head = newNode;
    }

    @Override
    public void delete(Student name) {

    }
/*
    private StudentLinkedList sort() {
        StudentLinkedList result = new StudentLinkedList(head.getData());

    }

 */
    public int size() {
        int result = 0;
        StudentNode cur = head;
        while(cur.getNext() != null) {
            result++;
            cur = cur.getNext();
        }
        return result;
    }
    @Override
    public void print() {
        StudentNode curNode = head;
        while(curNode.getNext() != null) {
            System.out.println(curNode.getData());
            curNode = curNode.next;
        }
        System.out.println(curNode.getData());
    }
}
