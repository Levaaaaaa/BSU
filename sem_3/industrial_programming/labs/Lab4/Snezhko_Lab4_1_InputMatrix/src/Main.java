// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.InvalidPropertiesFormatException;
import java.util.Locale;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.FileInputStream;
public class Main {
    public static void main(String[] args) {
        File file = new File("input.txt");
        String invSizeMessage = "Uncorrect row! Someone elements will replece of 0!";
        Scanner scanner;
        try {
            scanner = new Scanner(new FileInputStream(file));
        }
        catch (FileNotFoundException e) {
            return;
        }

        scanner.useLocale(Locale.US);
        System.out.println(scanner.locale());
        System.out.println(scanner.delimiter());
        scanner.useDelimiter("[,|\\s]+");

        int n = 0;
        String first = scanner.nextLine();
        String[] firstLineArray = first.split(" ");
        n = firstLineArray.length;
        Double[][] matrix = new Double[n][n];
        for (int i = 0; i < n; i++) {
            try {
                matrix[0][i] = Double.parseDouble(firstLineArray[i]);
            }
            catch (NumberFormatException e) {
                /*
                System.out.println("Uncorrect input");
                matrix[0][i] = 0;  //process
                */
                throw new NumberFormatException("Uncorrect input");     //throw exception

            }
        }

        String[] curLine;
        int row = 1;
        while (row < n) { //scanner.hasNext()) {
            curLine = scanner.nextLine().split(" ");
            if (curLine.length != n) {
                throw new IllegalArgumentException("Uncorrect row length");    //throw exception
                /*
                System.out.println(invSizeMessage);
                for (int j = 0; j < n; j++) curLine[j] = "0";     //process
                */
            }
            for (int j = 0; j < n; j++) {
                try {
                    matrix[row][j] = Double.parseDouble(curLine[j]);
                }
                catch (NumberFormatException e) {
                    /*
                    System.out.println("Uncorrect input");
                    matrix[row][j] = 0;     //process
                    */
                    throw new NumberFormatException("Uncorrect input");     //throw exception
                }
            }

            row++;

        }

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j].toString() + " ");
            }
            System.out.println();
        }
        /*// Press Alt+Enter with your caret at the highlighted text to see how
        // IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        // Press Shift+F10 or click the green arrow button in the gutter to run the code.
        for (int i = 1; i <= 5; i++) {

            // Press Shift+F9 to start debugging your code. We have set one breakpoint
            // for you, but you can always add more by pressing Ctrl+F8.
            System.out.println("i = " + i);
        }*/
    }
}