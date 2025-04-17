// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        System.out.println("  y | 1y | 2y | 3y | 4y | 5y ");
        System.out.println("----|----|----|----|----|----");
        for (int i = 1; i <= 10; i++) {
            System.out.printf("%3d |%3d |%3d |%3d |%3d |%3d\n",1*i, 1*i, 2*i, 3*i, 4*i, 5*i);
        }
        /*
        // Press Alt+Enter with your caret at the highlighted text to see how
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