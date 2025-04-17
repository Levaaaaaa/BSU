import javax.swing.*;
import java.io.IOException;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        System.out.println("");
        //try {
        //Gift gift = FrameFeatures.createGiftFromFile("input.txt");
        //System.out.println(gift.toString());
/*
        AddNewSweetFrame addFrame = new AddNewSweetFrame(gift);
        addFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        addFrame.setSize(500, 500);
        addFrame.setVisible(true);
*/
            Frame frame = new Frame("frame");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(500, 500);
            frame.setVisible(true);
        //System.out.println(addFrame.getGift().toString());
    /*
    }
        catch (IOException | IllegalArgumentException e) {
            System.out.println("Exception!!!");
            return;
        }
        
     */

    }
}