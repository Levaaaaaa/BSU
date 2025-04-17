// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import Goods.Goods;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        Goods goods1 = new Goods("goods 1", "Australia", 5);
        Goods goods2 = new Goods("goods 2", "Germany", 3);
        Goods goods3 = new Goods("goods 3", "USA", 10);
        Goods goods4 = new Goods("goods 4", "UK", 7);
        Goods goods5 = new Goods("goods 5", "France", 15);
        /*
        GoodsManager manager = new GoodsManager(goods1);
        manager.add(goods2);
        manager.add(goods3);
        manager.add(goods4);
        manager.add(goods5);
         */
        /*
        try {

            GoodsManager manager = new GoodsManager("input.txt");
            System.out.println(manager.toString());
            System.out.println(manager.getCountryByGoods("goods 1"));
            System.out.println(manager.getGeneralCount("goods 2"));
            System.out.println(manager.getCountryByGoods("goods 6"));
            System.out.println(manager.getGeneralCount("goods 6"));

            GoodsManager manager = new GoodsManager();
        }
        catch (IOException e) {
            System.out.println("Trouble with file reading!!!");
        }
        */
        //GoodsManager manager = new GoodsManager();
        Frame frame = new Frame("Main Frame");
        frame.setSize(500, 500);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}