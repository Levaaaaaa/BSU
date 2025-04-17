import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    private MyPanel panel1;
    private MyPanel panel2;
    private JPanel mainPanel = new JPanel(new GridLayout(2, 1));
    //GridLayout layout = new GridLayout(2,1);
    public MyFrame() {
        super("My Frame");

        JColorChooser chooser = new JColorChooser();
        Color color = JColorChooser.showDialog(mainPanel, "color dialog", Color.BLACK);

        panel1 = new MyPanel(color);
        panel2 = new MyPanel(color);
        //layout.addLayoutComponent("Panel1", panel1);
        //layout.addLayoutComponent("Panel2", panel2);
        mainPanel.add(panel1);
        mainPanel.add(panel2);
        add(mainPanel, BorderLayout.CENTER);
    }
}
