import java.io.FileWriter;
import java.io.IOException;
import java.lang.StringBuilder;
public class Writer {
    public static void write(Course course) throws IOException {
        try (FileWriter writer = new FileWriter("output"))
        {
            writer.write(course.toString());
        }
    }
}
