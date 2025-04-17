import java.util.HashSet;
import java.util.Set;

public class GoodsProcessorWithoutStreamAPI implements GoodsProcessStrategy{

    @Override
    public int getGeneralCount(String goodsName, Set<Goods> set) {
        int result = 0;
        for (Goods g : set ){
            if (g.getName().equals(goodsName)){
                result += g.getCount();
            }
        }
        return result;
    }

    @Override
    public Set<String> getCountryByGoods(String goodsName, Set<Goods> set) {
        Set<String> countries = new HashSet<>();
        for (Goods g : set) {
            if (g.getName().equals(goodsName)) {
                countries.add(g.getImportCountry());
            }
        }

        return countries;
    }
}
