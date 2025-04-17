// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Locale;
public class Main {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Scanner scan = new Scanner(new FileInputStream(new File("input.txt")));
        scan.useLocale(Locale.US);
        scan.useDelimiter("[\\s,;\\n]+");
        double sum = 0;
        while(scan.hasNext()) {
            try {
                sum += scan.nextDouble();
            }
            catch (InputMismatchException e) {
                scan.next();

            }
        }
        System.out.println(sum);
        FileWriter writer = new FileWriter("output.txt");
        writer.write(Double.toString(sum));
        writer.close();
        /*
        // Press Alt+Enter with your caret at the highlighted text to see how
        // IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        // Press Shift+F10 or click the green arrow button in the gutter to run the code.
        for (int i = 1; i <= 5; i++) {

            // Press Shift+F9 to start debugging your code. We have set one breakpoint
            // for you, but you can always add more by pressing Ctrl+F8.
            System.out.println("i = " + i);
        }
         */
    }
}