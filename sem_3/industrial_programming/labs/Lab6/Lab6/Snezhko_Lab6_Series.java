// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.lang.IllegalArgumentException;
import java.io.File;
import java.nio.charset.StandardCharsets;

public class Main {
    public static void main(String[] args) {
        double a0 = 1.0d;
        double d = 1.0d;
        Series liner = new Liner(a0, d);
        double q = 2.0d;
        Series exponential = new Exponential(a0, q);
        System.out.println(liner.getNext());
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

abstract class Series {
    protected double first;
    protected double current;
    protected int count;
    public Series (double first) {
        this.first = first;
        this.current = first;
        this.count = 1;
    }
    public abstract double getNext();
    public double getSum() {
        double sum = 0;
        for (int i = 0; i < this.count; i++) {
            sum += this.getNext();
        }
        return sum;
    }
    public String toString() {
        String result = "";
        for (int i = 0; i < this.count; i++) {
            result = Double.toString(this.getNext()) + " ";
        }
        return result;
    }
    public void saveToFile(String output) throws FileNotFoundException, IOException {
        FileOutputStream out = new FileOutputStream(new File(output));
        out.write(this.toString().getBytes(StandardCharsets.UTF_8));
        out.write(("Sum is " + Double.toString(this.getSum())).getBytes(StandardCharsets.UTF_8));
        out.close();
    }
}

class Liner extends Series {
    private double d;
    public Liner(double first, double d) {
        super(first);
        this.d = d;
    }
    @Override
    public double getNext() {
        this.current += d;
        this.count++;
        return this.current;
    }
}

class Exponential extends Series {
    private double q;
    public Exponential(double first, double q)
    {
        super(first);
        if ((first == 0) || (q == 0)) {
            throw new IllegalArgumentException();
        }
        this.q = q;
    }
    @Override
    public double getNext() {
        this.current *= q;
        this.count++;
        return current;
    }
}