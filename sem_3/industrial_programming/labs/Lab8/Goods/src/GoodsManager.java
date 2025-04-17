import javax.swing.*;
import java.io.*;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
//import java.io.StringReader;

public class GoodsManager implements Iterable{
    private Set<Goods> goodsSet = new HashSet<>();
    public GoodsManager(Set<Goods> set) {
        this.goodsSet = set;
    }
    public GoodsManager(Goods goods) {
        this.goodsSet.add(goods);
    }
    public GoodsManager(String path) throws IOException{
        try {
            this.goodsSet = readGoodsFromFile(path);
        }
        catch (FileNotFoundException e) {
            System.out.println("Uncorrect file name or path!!!");
            //throw new FileNotFoundException();
        }
        catch (NumberFormatException e) {
            System.out.println("Invalid file format!!!");
            //throw new NumberFormatException();
        }
    }
    public Set<Goods> getGoodsSet() {
        return goodsSet;
    }
    @Override
    public Iterator<Goods> iterator() {
        return goodsSet.iterator();
    }
    public void add(Goods goods) {
        this.goodsSet.add(goods);
    }
    private Set<Goods> getSingleGoods(String goodsName) {
        Set<Goods> singleGoods = new HashSet<>();
        this.goodsSet.forEach(g -> {
            if(goodsName.equals(g.getName()))
            {
                singleGoods.add(g);
            }
        });
        return singleGoods;
    }
    public Set<String> getCountryByGoods(String goodsName) {
        Set<Goods> singleGoods = this.getSingleGoods(goodsName);
        Set<String> countries = new HashSet<>();
        for (Goods g : singleGoods) {
            countries.add(g.getImportCountry());
        }
        return countries;
    }
    public int getGeneralCount(String goodsName) {
        Set<Goods> singleGoods = this.getSingleGoods(goodsName);
        int result = 0;
        for (Goods g : singleGoods) {
            result += g.getCount();
        }

        return result;
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Goods g : goodsSet) {
            sb.append(g.toString());
            sb.append("\n");
        }
        return sb.toString();
    }
    private Set<Goods> readGoodsFromFile(String path) throws FileNotFoundException, IOException, NumberFormatException{
        Set<Goods> result = new HashSet<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(path)))
        {
            Set<String> lines = new HashSet<>();
            reader.lines().forEach(str -> lines.add(str));
            for (String line : lines) {
                String[] parametersOfGood = line.split("/");
                result.add(new Goods(parametersOfGood[0], parametersOfGood[1], Integer.parseInt(parametersOfGood[2])));
            }
        }

        /*
        try (StringReader reader = new StringReader(path) {
            //String[] lines = new String[2]; //reader..split("\n");
            for (String line : lines) {
                String[] parametersOfGood = line.split("|");
                result.add(new Goods(parametersOfGood[0], parametersOfGood[1], Integer.parseInt(parametersOfGood[2])));
            }
        }
         */
        return result;
    }
    public void writeIntoFile(File file) throws IOException{
        try (FileWriter writer = new FileWriter(file)) {
            StringBuilder builder = new StringBuilder();
            for (Goods goods : this.goodsSet) {
                builder.append(goods.toString());
                builder.append("\n");
            }
            writer.write(builder.toString());
        }
    }
    public void showFrame(String title) {
        Frame frame = new Frame(title);
        frame.setSize(500, 500);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}