import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.stream.Stream;

public class MyReader {
    public static ArrayList<Double> readDouble(String fileName) throws IOException {
        if (!fileName.endsWith(".txt")) {
            throw new IOException();
        }
        ArrayList<Double> result = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            Iterator<String> iterator = reader.lines().iterator();
            while (iterator.hasNext()) {
                try {
                    result.add(Double.parseDouble(iterator.next()));
                }
                catch (NumberFormatException e) {
                    throw new IOException();
                }
            }
        }
        return result;
    }
    public static ArrayList<Student> readStudents(String fileName) throws IOException {
        ArrayList<Student> result = new ArrayList<>();
        if (!fileName.endsWith(".txt")) {
            throw new IOException();
        }
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            Iterator<String> iterator = reader.lines().iterator();
            while (iterator.hasNext()) {
                try {
                    result.add(new Student(iterator.next()));
                }
                catch (NumberFormatException | IOException e) {
                    throw new IOException();
                }
            }
        }
        return result;
    }
}
