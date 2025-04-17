// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
public class Main {
    public static void main(String[] args) {
        // Press Alt+Enter with your caret at the highlighted text to see how

   /*     // IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        // Press Shift+F10 or click the green arrow button in the gutter to run the code.
        for (int i = 1; i <= 5; i++) {

            // Press Shift+F9 to start debugging your code. We have set one breakpoint
            // for you, but you can always add more by pressing Ctrl+F8.
            System.out.println("i = " + i);
    */
        String str = "String str Map result";
        Map<String, Integer> map = new TreeMap<>();
        for (int i = 0; i < str.length(); i++) {
            String letter = "" + str.charAt(i);
            Integer freq = map.get(letter);
            if (freq.equals(null)) {
                freq = 0;
            }
            map.put(letter, freq + 1);
        }
    }

    public Set<String> makeLetterSet(String str)
    {
        // TODO: Complete method
        Set<String> result = new TreeSet<>(1);
        for (int i = 0; i < str.length(); i++) {
            result.add(Character.toString(str.charAt(i)));
        }
        return result;
    }
}