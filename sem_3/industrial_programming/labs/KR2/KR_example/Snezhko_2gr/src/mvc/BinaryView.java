package mvc;

import observer.Observable;
import observer.Observer;

import javax.swing.*;

public class BinaryView extends JTextArea implements MyView {
    //private MySet model;
    public BinaryView() {
        super();
        //this.model = model_;
        //model.subscribe(this);
    }

    @Override
    public void update(MySet model) {
        //model = (MySet)o;
        setText(model.toString() + " Cardinality: " + model.cardinality());
    }
}
