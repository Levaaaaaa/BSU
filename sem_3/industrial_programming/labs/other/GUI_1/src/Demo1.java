// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import javax.swing.*;
public class Demo1 {
    public static void main(String[] args) {
        String answer = JOptionPane.showInputDialog("Enter ");
        //String answer2 = JOptionPane.showInputDialog("Enter2 ");
        JOptionPane.showMessageDialog(null, answer, "Title", JOptionPane.INFORMATION_MESSAGE);
    }
}