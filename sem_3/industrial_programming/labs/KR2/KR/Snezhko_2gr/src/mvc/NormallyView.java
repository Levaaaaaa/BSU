package mvc;

import iterator.MyIterator;
import observer.Observable;
import observer.Observer;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class NormallyView extends JTextArea implements MyView {
    //private MySet model;

    public NormallyView() {
        super();
        setBorder(BorderFactory.createLineBorder(Color.BLACK, 3));
        //this.model = m;
        //model.subscribe(this);
    }
    public NormallyView(MySet model) {
        this();
        model.subscribe(this);
    }

    @Override
    public String parseModel(MySet model) {
        StringBuilder result = new StringBuilder();
        result.append(this.getNormalModel(model).toString())
                .append("\n Cardinality: " + model.cardinality())
                .append("\n Current min: " + Math.abs(model.getMin()))
                .append("\n Strategy " + model.getCardinalityStrategy())
        ;
        return result.toString();
    }

    public ArrayList<Integer> getNormalModel(MySet model) {
        ArrayList<Integer> result = new ArrayList<>();
        int min = Math.abs(model.getMin());
        for(int i = 0; i < min; i++) {
            if (model.get(i) == 1) {
                result.add((-1)*(min - i)); //?
            }
        }
        for (int i = min; i < model.size(); i++) {
            if (model.get(i) == 1) {
                result.add(i - min);
            }
        }


        return result;
    }

    @Override
    public void update(Observable o) {
        this.setText(parseModel((MySet)o));
        //this.update((MySet)o);
    }
}
