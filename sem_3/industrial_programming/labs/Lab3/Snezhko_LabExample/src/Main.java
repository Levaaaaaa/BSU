// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.StringTokenizer;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        StringTokenizer st = new StringTokenizer("a+b = 1", "+=", true);
        while (st.hasMoreTokens()) {
            System.out.println(st.nextToken());
        }

        String s = "   a   =   b  ";
        String o = s.replaceAll(" ", "");
        String j = s.replaceAll("[0-9]", "");
        System.out.println(o);

        String[] words = s.split(" ");
        System.out.println(Arrays.toString(words));

        /*// Press Alt+Enter with your caret at the highlighted text to see how
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