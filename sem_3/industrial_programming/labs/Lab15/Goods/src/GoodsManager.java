import Goods.Goods;
import readFromFileStrategy.InputFromXmlStrategy;
import sax.InputGoodsXmlSax;

import java.io.*;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
import java.util.stream.Collectors;
//import java.io.StringReader;

public class GoodsManager implements Iterable{
    private GoodsProcessStrategy strategy = new GoodsProcessorWithoutStreamAPI();
    private InputFromXmlStrategy inputStrategy = new InputGoodsXmlSax();
    private Set<Goods> goodsSet = new HashSet<>();
    public GoodsManager() {

    }
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
        catch (Exception e) {
            System.out.println(e.getMessage());
            //throw new FileNotFoundException();
        }
        /*catch (NumberFormatException e) {
            System.out.println("Invalid file format!!!");
            //throw new NumberFormatException();
        }

         */
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

    private Set<Goods> getSingleGoods(String goodsName, Set<Goods> goodsSet) {
        Set<Goods> singleGoods = new HashSet<>();
        this.goodsSet.forEach(g -> {
            if(goodsName.equals(g.getName()))
            {
                singleGoods.add(g);
            }
        });
        return singleGoods;
    }

    //for strategy
    public Set<String> getCountryByGoods(String goodsName) {
        return strategy.getCountryByGoods(goodsName, goodsSet);
    }
    //for strategy
    public int getGeneralCount(String goodsName) {
        return strategy.getGeneralCount(goodsName, goodsSet);
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Goods g : goodsSet) {
            sb.append(g.toString());
            sb.append("\n");
        }
        return sb.toString();
    }
    public Set<Goods> readGoodsFromFile(String path) throws Exception {//FileNotFoundException, IOException, NumberFormatException{
        File fileXML = new File(path);
        //InputGoodsXmlSax input = new InputGoodsXmlSax();
        Set<Goods> result = inputStrategy.readFromFile(fileXML).stream().collect(Collectors.toSet());//new HashSet<>();


            /*try (BufferedReader reader = new BufferedReader(new FileReader(path)))
        {
            Set<String> lines = new HashSet<>();
            reader.lines().forEach(str -> lines.add(str));
            for (String line : lines) {
                String[] parametersOfGood = line.split("/");
                result.add(new Goods(parametersOfGood[0], parametersOfGood[1], Integer.parseInt(parametersOfGood[2])));
            }
        }
*/
        this.goodsSet = result;
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

    public void setInputStrategy(InputFromXmlStrategy inputStrategy) {
        this.inputStrategy = inputStrategy;
    }

    public void setStrategy(GoodsProcessStrategy strategy) {
        this.strategy = strategy;
    }
}