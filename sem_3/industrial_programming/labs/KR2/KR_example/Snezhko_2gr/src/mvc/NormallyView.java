package mvc;

import iterator.MyIterator;
import observer.Observable;
import observer.Observer;

import javax.swing.*;
import java.util.ArrayList;

public class NormallyView extends JTextArea implements MyView {
    //private MySet model;

    public NormallyView() {
        super();
        //this.model = m;
        //model.subscribe(this);
    }

    @Override
    public void update(MySet model) {
        //model = (MySet)o;
        setText(this.getNormalModel(model).toString() + " Cardinality: " + model.cardinality());
    }
    public ArrayList<Integer> getNormalModel(MySet model) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < model.size(); i++) {
            if (model.get(i) == 1) {
                result.add(i);
            }
        }

        return result;
    }
}
