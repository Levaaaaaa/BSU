// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.Scanner;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Press Alt+Enter with your caret at the highlighted text to see how
        // IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        // Press Shift+F10 or click the green arrow button in the gutter to run the code.
        for (int i = 1; i <= 5; i++) {

            // Press Shift+F9 to start debugging your code. We have set one breakpoint
            // for you, but you can always add more by pressing Ctrl+F8.
            System.out.println("i = " + i);
        }
    }
}

class Thirteen {
    public static void main(String[] args) {
        ArrayList<Integer> startArray = new ArrayList<Integer>(50);
        int[] start = new int[50];
        ArrayList<Integer> result = new ArrayList<Integer>(6);
        int[] result2 = new int[6];
        for (int i = 1; i <= 50; i++) {
            startArray.add(i);
            start[i-1] = i;
        }
        Random random = new Random();
        int j = 49;
        for (int i = 0; i < 6; i++) {
            int index = random.nextInt(j);
            result.add(startArray.get(index));
            result2[i] = start[index];
            startArray.remove(index);
            j--;
        }
        result.sort(null);
        Arrays.sort(result2);
        for (int i : result) {
            System.out.print(i + " ");
        }
        System.out.print("\n");
        for (int i : result2) {
            System.out.print(i + " ");
        }
    }
}

class Fourteen {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> list;
        try {
            list = input();
        } catch (InputMismatchException | IllegalArgumentException e) {
            System.out.println(e);
            return;
        }
        int i = sumOfArray(list.get(0));



        /*
        int sum = sumOfArray(list.get(0));
        int sumRow = 0;
        int sumColumn = 0;
        int sumDiag = 0;
        int sumDiag2 = 0;

        for (int i = 0; i < n; i++) {
            ArrayList<Integer> a = list.get(0);
            sum += a.get(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumRow += list.get(i).get(j);
                sumColumn += list.get(j).get(i);
            }
            sumRow = sumOfArray(list.get(i));

            if (sumRow != sum || sumColumn != sum) {
                System.out.println("No");
                return;
            }
            sumDiag += list.get(i).get(i);
            sumDiag2 += list.get(n - i).get(i);
        }
        if (sumDiag != sum || sumDiag2 != sum) {
            System.out.println("No");
            return;
        }
        else {
            System.out.println("Yes");
        } */
    }
    private static boolean isMagicSquare (ArrayList<ArrayList<Integer>> list) {
        return false;
    }
    private static ArrayList<ArrayList<Integer>> input() throws IllegalArgumentException, InputMismatchException{
        Scanner scanner = new Scanner(System.in);
        String first = scanner.nextLine();
        int n = 0;
//        try {
            n = (int) (first.chars().filter(c -> c == ' ').count()) + 1;
            //      }
        /*catch (InputMismatchException e) {
            System.out.print(e.toString());
            return;
        }*/
        if ((n == 1) || (n == 0)) throw new IllegalArgumentException();
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>(n);
        list.add(new ArrayList(Arrays.asList(addNewLine(first, n))));
        for (int i = 1; i < n; i++) {
            String next = scanner.nextLine();
            //try {
                list.add(new ArrayList(Arrays.asList(addNewLine(next, n))));
            /*} catch (IllegalArgumentException e) {
                System.out.print(e);
                return;
            }*/
        }
        return list;
    }
    private static int sumOfArray(ArrayList<Integer> array) {
        int sum = 0;
        Integer[] arr = new Integer[array.size()];
        for (int i = 0; i < array.size(); i++) {
            arr[i] = array.get(i);  //?????
        }
        //int[] arr = array.toArray();
        /*for (int i = 0; i < array.size(); i++) {
          //  sum +=
        }*/
        return sum;
    }
    private static int[] addNewLine(String line, int length) throws NumberFormatException{
        String[] str = line.split(" ");
        if (str.length != length) throw new IllegalArgumentException();
        int[] result = new int[str.length];
        for (int i = 0; i < str.length; i++) {
             result[i] = Integer.parseInt(str[i]);
        }

        return result;
    }
}

class Fiveteen {
    public static void main(String[] args) {
        int start = 1;
        int n = 1;
        Scanner scanner = new Scanner(System.in);
        try {
            n = scanner.nextInt();
        }catch (InputMismatchException e) {
            System.out.println(e.toString());
            return;
        }
        ArrayList<ArrayList<Integer>> arrayList = new ArrayList<ArrayList<Integer>>(n);
        ArrayList<Integer> current = new ArrayList<Integer>(n);
        current.add(1);
        arrayList.add(new ArrayList(Arrays.asList(1)));
        arrayList.add(new ArrayList(Arrays.asList(1, 2, 1)));
        for (int i = 2; i <= n; i++) {
            current.clear();
            current.add(1);
            for (int j = 1; j <= i; j++) {
                int next = arrayList.get(i - 1).get(j - 1) + arrayList.get(i - 1).get(j);
                current.add(next);
            }
            current.add(1);
            arrayList.add(new ArrayList<Integer>(current));
        }
        for (ArrayList<Integer> arr : arrayList) {
            for (int item : arr) {
                System.out.print(item + " ");
            }
            System.out.print("\n");
        }
    }
}