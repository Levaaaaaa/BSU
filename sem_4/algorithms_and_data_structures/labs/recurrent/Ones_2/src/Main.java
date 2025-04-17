import java.math.BigDecimal;
import java.util.Scanner;

public class Main
{
    private static long accuracy = 1000000007;
    private static BigDecimal bdAccuracy = BigDecimal.valueOf(accuracy);
    public static void main(String[] args) {
        long n, k;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextLong();
        k = scanner.nextLong();

        BigDecimal numerator = BigDecimal.ONE;
        for (long i = n; i > n - k; i--) {
            numerator = numerator.multiply(BigDecimal.valueOf(i)).remainder(bdAccuracy);
        }

        BigDecimal denominator = BigDecimal.ONE;
        for (long i = 1; i <= k; i++) {
            denominator = denominator.multiply(BigDecimal.valueOf(i)).remainder(bdAccuracy);
        }

        //BigDecimal result = BigDecimal.ONE;//numerator.multiply(inv(denominator))

        //a mod p * b^(-1) mod p
//        BigDecimal b = inv(denominator);
  //      BigDecimal ab = numerator.remainder(bdAccuracy).multiply(b).remainder(bdAccuracy);
        BigDecimal result = numerator.remainder(bdAccuracy).multiply(inv(denominator)).remainder(bdAccuracy);

        //result = result.remainder(BigDecimal.valueOf(1000000007));
        System.out.print(result.toString());

    }
    private static BigDecimal factorial(int num) {
        if (num == 0) {
            return BigDecimal.ONE;
        }

        BigDecimal result = BigDecimal.ONE;
        for (int i = 1; i <= num; i++) {
            result = result.multiply(BigDecimal.valueOf(i));
        }

        return result;
    }
    private static BigDecimal binpow(BigDecimal a, long p) {
        if (p == 0) {
            return BigDecimal.ONE;
        }
        else if (p % 2 == 1) {
            return binpow(a, p - 1).multiply(a).remainder(bdAccuracy);
        }
        else {
            BigDecimal b = binpow(a, p / 2).remainder(bdAccuracy);
            return b.multiply(b);
        }
    }

    private static BigDecimal inv(BigDecimal a) {
        return binpow(a, accuracy - 2).remainder(bdAccuracy);
    }
}