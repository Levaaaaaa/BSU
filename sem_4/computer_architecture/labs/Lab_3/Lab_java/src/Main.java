import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.Time;
import java.time.LocalTime;
import java.util.Arrays;
import java.util.Date;
import java.util.Random;

import static java.lang.Math.abs;
import static java.time.LocalTime.now;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        try (FileWriter writer = new FileWriter(new File("data.txt"), false)) {
            StringBuilder sb = new StringBuilder();
            for (double i = 5000; i < 20000000; i *= 1.2) {
                sb.append((int)i)
                .append(" ")
                        .append(benchmarkLatency((int)i, 100000000))
                        .append("\n");

            }
            writer.write(sb.toString());
        } catch (IOException e) {
            System.out.println(e.toString());
        }

    }

    static int[] remove(int[] s, int i) {
        s[i] = s[s.length-1];
        return Arrays.copyOfRange(s, 0, s.length-1);
    }
    static int[] randomCyclicPermutation(int length) {
        int[] result = new int[length];
        int[] unusedIndexes = new int[length - 1];

        for (int i = 0; i < length-1; i++) {
            unusedIndexes[i] = i+1;
        }

        int currentIndex = 0;

        Random random = new Random();
        for (int i = 0; i < length - 1; i++) {
            int r = abs(random.nextInt()) % unusedIndexes.length;
            int nextInd = unusedIndexes[r];
            unusedIndexes = remove(unusedIndexes, r);
            result[currentIndex] = nextInd;
            currentIndex = nextInd;
        }

        return result;
    }

    static double benchmarkLatency(int sizeBytes, long iterations) {
        int[] array = randomCyclicPermutation(sizeBytes / 4);
        int pointer = 0;
        Date start = new Date();
        for(long i = 0; i < iterations; i++) {
            pointer = array[pointer];
        }
        Date finish = new Date();

        return (double)(finish.getTime() - start.getTime()) * 1000000/ (double)iterations;
    }
}