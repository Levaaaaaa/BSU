import Goods.Goods;

import java.util.Set;

public interface GoodsProcessStrategy {
    public int getGeneralCount(String goodsName, Set<Goods> set);
    public Set<String> getCountryByGoods(String goodsName, Set<Goods> set);
}
