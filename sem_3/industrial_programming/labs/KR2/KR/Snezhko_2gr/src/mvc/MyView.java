package mvc;

import observer.Observer;

public interface MyView extends Observer {
//    public void update(MySet model);
    public String parseModel(MySet model);
}
