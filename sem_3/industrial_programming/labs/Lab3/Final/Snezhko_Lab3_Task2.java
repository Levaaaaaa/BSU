// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.StringTokenizer;
import java.util.Scanner;
import java.util.InputMismatchException;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        if (input.length() == 0) {
            return;
        }
        int x = 0;
        try {
            x = scanner.nextInt();
        }
        catch (InputMismatchException e) {
            return;
        }
        StringTokenizer st = new StringTokenizer(input, "+-", true);
        int result = 0;
        int sign = "-".equals(input.charAt(0)) ? -1 : 1;
        while (st.hasMoreTokens()) {
            String token = st.nextToken();
            int temp = 0;
            try {
                temp = Integer.parseInt(token);
            }
            catch (NumberFormatException e) {
                if ("-".equals(token)) {
                    sign = -1;
                    continue;
                }
                else if ("+".equals(token)) {
                    sign = 1;
                    continue;
                }
                else if ("x".equals(token)) {
                    temp = x;
                }
            }
            temp *= sign;
            result += temp;
        }
        System.out.println(result);
        /*        // Press Alt+Enter with your caret at the highlighted text to see how
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