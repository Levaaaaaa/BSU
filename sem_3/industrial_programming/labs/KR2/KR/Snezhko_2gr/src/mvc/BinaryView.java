package mvc;

import observer.Observable;
import observer.Observer;

import javax.swing.*;
import java.awt.*;

public class BinaryView extends JTextArea implements MyView {
    //private MySet model;
    public BinaryView() {
        super();
        setBorder(BorderFactory.createLineBorder(Color.BLACK, 3));
    }
    public BinaryView(MySet model) {
        this();
        model.subscribe(this);
    }

    @Override
    public void update(Observable o) {
        this.setText(parseModel((MySet)o));
    }

    @Override
    public String parseModel(MySet model) {
        StringBuilder result = new StringBuilder();
        result.append(model.toString())
                .append("\n Cardinality: " + model.cardinality())
                .append("\n Current min: " + Math.abs(model.getMin()))
                .append("\n Strategy " + model.getCardinalityStrategy())
        ;
        return result.toString();
    }
}
