// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.util.Scanner;
public class HorstmannTask {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = 0;
        try {
            x = scanner.nextInt();//0;
        }
        catch (InputMismatchException e) {
            System.out.println("Uncorrect input!");
        }
            /*try {*/
            //x = scanner.nextInt();
        /*}
        catch ()*/
        System.out.println("Hex: " + Integer.toHexString(x));
        System.out.println("Bin: " + Integer.toBinaryString(x));
        System.out.println("Oct: " + Integer.toOctalString(x));
        System.out.printf("Reverse: %a", (double)1/x);
    }
}

class Two {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = 0;
        try {
            x = scanner.nextInt();
        }
        catch (InputMismatchException e) {
            System.out.println("Uncorrect input!!");
            return;
        }
        System.out.println("Normal: " + (x % 360));
        System.out.println("Floor mod: " + Math.floorMod(x, 360));
    }
}

class Three {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x1 = 0;
        int x2 = 0;
        int x3 = 0;
        try {
            x1 = scanner.nextInt();
            x2 = scanner.nextInt();
            x3 = scanner.nextInt();
        }
        catch (InputMismatchException e) {
            System.out.println("Uncorrect input!!");
            return;
        }
        int max = x1 > x2 ? (x1 > x3 ? x1 : x3) : (x2 > x3 ? x2 : x3);
        System.out.println("Max: " + max);
        System.out.println("Math max: " + Math.max(x1, Math.max(x2, x3)));
    }
}

class Four {
    public static void main(String[] args) {
        double d = 0.0;
        System.out.println("Double: "+ Double.MAX_VALUE);
        System.out.println("Min: " + Math.nextUp(d));
    }
}

class Five {
    public static void main(String[] args) {
        double d = Integer.MAX_VALUE + 1;
        int x = (int)d;
        System.out.println(x);
    }
}
class Six {
    public static void main(String[] args) {
        System.out.println(factorial(1000).toString());
    }

    static BigInteger factorial(int a) {
        BigInteger result = BigInteger.valueOf(1);
        for (int i = 1; i <= a; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }

        return result;
    }
}

class Seven {
    public static void main(String[] args) {
        short x1 = 0;
        short x12 = 0;
        short x13 = 0;
        short x21 = 0;
        short x22 = 0;
        short x23 = 0;
        Scanner scanner = new Scanner(System.in);
        long l1, l2 = 0;
        try {
            l1 = scanner.nextInt();
            l2 = scanner.nextInt();
            if (l1 < 0 || l2 < 0) {
                System.out.println("Uncorrect input!!");
                return;
            }
            x1 = (short)(l1 / 3);
            x12 = (short)((l1 - x1) / 2);
            x13 = (short)(l1 - x1 - x12);
            x21 = (short)(l2 / 3);
            x22 = (short)((l2 - x21) / 2);
            x23 = (short)(l2 - x21 - x22);
            /*
            x1 = scanner.nextShort();
            x12 = scanner.nextShort();
             */
        }
        catch (InputMismatchException e) {
            System.out.println("Uncorrect input!!");
            return;
        }

        long result = (x1+x12 + x13) + (x21+x22 + x23);
        System.out.println(result);
        result = (x1+x12 + x13) - (x21+x22 + x23);
        System.out.println(result);
        result = (long)(x1+x12 + x13) * (long)(x21+x22 + x23);
        System.out.println(result);
        result = (x1+x12 + x13) / (x21+x22 + x23);
        System.out.println(result);
        result = (x1+x12 + x13) % (x21+x22 + x23);
        System.out.println(result);
    }
}