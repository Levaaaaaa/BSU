// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.ArrayList;
import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        int start = 1;
        int n = 1;
        Scanner scanner = new Scanner(System.in);
        try {
            n = scanner.nextInt();
        }catch (InputMismatchException e) {
            System.out.println(e.toString());
            return;
        }
        ArrayList<ArrayList<Integer>> arrayList = new ArrayList<ArrayList<Integer>>(n);
        ArrayList<Integer> current = new ArrayList<Integer>(n);
        current.add(1);
        arrayList.add(new ArrayList(Arrays.asList(1)));
        arrayList.add(new ArrayList(Arrays.asList(1, 1)));
        //arrayList.add(new ArrayList(Arrays.asList(1, 2, 1)));
        for (int i = 2; i < n; i++) {
            current.clear();
            current.add(1);
            for (int j = 1; j < i; j++) {
                int next = arrayList.get(i - 1).get(j - 1) + arrayList.get(i - 1).get(j);
                current.add(next);
            }
            current.add(1);
            arrayList.add(new ArrayList<Integer>(current));
        }
        for (ArrayList<Integer> arr : arrayList) {
            for (int item : arr) {
                System.out.print(item + " ");
            }
            System.out.print("\n");
        }
        String space = "";
/*        for (int i = 0; i < n - 1; i++) {
            space += " ";
        }
        */
        for (int i = 0; i < n; i++) {
            space = "";
            for (int k = 0; k < n - i - 1; k++) {
                space += " ";
            }
            System.out.printf(space);
            System.out.printf("%80d ", arrayList.get(i).get(0));
            for (int j = 1; j < arrayList.get(i).size(); j++) {
                System.out.print(arrayList.get(i).get(j).toString() + " ");
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