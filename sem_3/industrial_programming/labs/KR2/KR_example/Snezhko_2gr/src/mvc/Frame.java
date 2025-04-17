package mvc;

import javax.swing.*;
import javax.swing.text.Position;
import java.awt.*;

public class Frame extends JFrame {
    private MySet model = new MySet();
    private BinaryView view1 = new BinaryView();
    private NormallyView view2 = new NormallyView();
    private MyController controller = new MyController(model, view1, view2);
    public Frame() {
        super("Frame");
        setLayout(new GridLayout(1, 3));

        //model.subscribe(view1);

        initModel();
        add(view1);
        add(view2);
        add(controller);
    }

    private void initModel() {
        model.add(0);
        model.add(5);
        model.add(3);
        model.add(12);
    }
}
