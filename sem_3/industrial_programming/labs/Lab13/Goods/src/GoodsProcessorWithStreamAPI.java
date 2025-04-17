import java.util.HashSet;
import java.util.Set;

public class GoodsProcessorWithStreamAPI implements GoodsProcessStrategy{
    @Override
    public int getGeneralCount(String goodsName, Set<Goods> goods) {
        return (int)goods.stream()
                .filter(g -> g.getName().equals(goodsName))
                .mapToInt(g -> g.getCount())
                .sum()
                ;
    }

    @Override
    public Set<String> getCountryByGoods(String goodsName, Set<Goods> goods) {
        Set<String> countries = new HashSet<>();
        goods.stream()
                .filter(g -> g.getName().equals(goodsName))
                .forEach(g -> countries.add(g.getImportCountry())
                );
        return countries;
    }
}
