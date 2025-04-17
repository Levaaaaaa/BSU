// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.Arrays;
import java.util.function.Predicate;

public class Main {
    public static void main(String[] args) {
        int[] array = new int[10];
        array[0] = 1;
        array[1] = 20;
        array[2] = 15;
        array[3] = 37;
        array[4] = 49;
        array[5] = 15;
        array[6] = 25;
        array[7] = 58;
        array[8] = 42;
        array[9] = 37;
        System.out.println(Arrays.stream(array).filter(i -> i == 37).count());     //count of equals 37
        System.out.println(Arrays.stream(array).filter(i -> i > 37).count());      //count of large then 37
        System.out.println(Arrays.stream(array).sum());                            //sum of all elements
        System.out.println((double)Arrays.stream(array).sum() / Arrays.stream(array).count());  //middle
    }

    public static int countEqualOf(Comparable[] array, int number) {
        int count = 0;
        for (Comparable i : array) {
            count += i.compareTo(number) == 0 ? 1 : 0;
        }
        return count;
    }
    public static int countLargeOf(Comparable[] array, int number) {
        int count = 0;
        for (Comparable i : array) {
            count += i.compareTo(number) > 0 ? 1 : 0;
        }
        return count;
    }
    public static int sumAll(int[] array) {
        int sum = 0;
        for (int i : array) {
            sum += i;
        }
        return sum;
    }
    public static double middle(int[] array) {
        double sum = 0;
        int count = 0;
        for (int i : array) {
            sum += i;
            count++;
        }
        return sum / count;
    }
    public static int countByCondition(Object[] array, Predicate condition) {
        int count = 0;
        for (Object i : array) {
            count = condition.test(i) ? 1 : 0;
        }
        return count;
    }
}