import javax.swing.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.stream.Collectors;

public class FrameFeatures {
    public static void printSortedGift(Comparator<BaseSweet> comparator, Gift gift, JTextArea output) {
        gift.sort(comparator);
        output.setText(gift.toString());
    }
    public static void printGeneralWeight(Gift gift, JTextArea output) {
        output.setText(Double.toString(gift.findGeneralWeight()));
    }
    public static void addSweetToGift(Gift gift, JComboBox typeFrom, JTextArea nameFrom, JSpinner weightFrom, JSpinner sugarProportionFrom) {
        String type = typeFrom.getSelectedItem().toString();
        String name = nameFrom.getText();
        String weight = weightFrom.getValue().toString();
        String sugarProprotion = sugarProportionFrom.getValue().toString();
        StringBuilder sweetString = new StringBuilder();
        sweetString.append(type)
                .append("/")
                .append(name)
                .append("/")
                .append(weight)
                .append("/")
                .append(sugarProprotion);
        BaseSweet sweet = BaseSweet.createSweetByString(sweetString.toString());
        gift.add(sweet);
    }
    public static void printSweetFoundBySugar(Gift gift, JSpinner min, JSpinner max, JTextArea out) {
         out.setText(
                 gift.findSweetBySugar(
                         (Double)min.getValue(),
                         (Double)max.getValue())
                         .toString()
         );
    }
    public static Gift createGiftFromFile(File file) throws IOException, NumberFormatException, IllegalArgumentException {
        if (!file.getName().endsWith(".txt")) throw new IOException();
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            //Gift gift = new Gift(reader.lines().collect(Collectors.joining("/")));
            Gift gift = new Gift(new ArrayList<>());
            reader.lines().forEach(line -> gift.add(BaseSweet.createSweetByString(line)));
            return gift;
        }
    }
}
