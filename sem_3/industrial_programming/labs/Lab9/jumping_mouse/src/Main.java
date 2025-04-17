import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JumpingMouseFrame mouseTrackerFrame = new JumpingMouseFrame();
        mouseTrackerFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mouseTrackerFrame.setSize(400, 300);
        mouseTrackerFrame.setVisible(true);
    }
}