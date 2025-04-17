// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        //I will processed sequence #1
        if (args.length < 2) {
            throw new IllegalArgumentException();
        }

        double x;
        double accuracy;
        try {
            x = Double.parseDouble(args[0]);
            accuracy = Double.parseDouble(args[1]);
        }
        catch (NumberFormatException e) {
            System.out.println("Uncorrect input!!");
            return;
        }
        double addend = Math.pow(x, 3);
        System.out.println(addend);
        double sum = addend;
        int k = 1;

        while (addend > accuracy) {
            addend *= Math.pow(x, (6 * k) + 3);
            System.out.println(addend);
            sum += addend;
            k++;
        }

        System.out.printf("Sum is %2.15f", sum);

        // Press Alt+Enter with your caret at the highlighted text to see how
        // IntelliJ IDEA suggests fixing it.
        /*System.out.printf("Hello and welcome!");

        // Press Shift+F10 or click the green arrow button in the gutter to run the code.
        for (int i = 1; i <= 5; i++) {

            // Press Shift+F9 to start debugging your code. We have set one breakpoint
            // for you, but you can always add more by pressing Ctrl+F8.
            System.out.println("i = " + i);
        }*/
    }
}