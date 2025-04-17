// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.StringTokenizer;
public class Main {
    public static void main(String[] args) {
        String str = "nfkjv,ifveb 35464.brb39rejer,25";
        StringTokenizer st = new StringTokenizer(str, ". ,", true);
        String result = "";
        while (st.hasMoreTokens()) {
            String token = st.nextToken();
            try {
                double d = Double.parseDouble(token);
            }
            catch (NumberFormatException e) {
                result += token;
            }
        }

        StringTokenizer epilogue = new StringTokenizer(result, ". ,", true);
        boolean hasPreviousDelim = false;
        result = "";
        while (epilogue.hasMoreTokens()) {
            String token = epilogue.nextToken();
            if (". ,".contains(token)) {
                if (!hasPreviousDelim) {
                    result += token;
                }
                hasPreviousDelim = true;
            }
            else {
                result += token;
                hasPreviousDelim = false;
            }
        }
        if (" .,".contains(result.substring(result.length() - 1))) {
            result = result.substring(0, result.length() -2);
        }
        System.out.println(result);
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