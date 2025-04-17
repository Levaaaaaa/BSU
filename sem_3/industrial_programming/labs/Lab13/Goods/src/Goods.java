import java.lang.StringBuilder;
public class Goods {
    private String name;
    private String importCountry;
    private int count;

    public Goods(String name, String importCountry, int count) {
        this.name = name;
        this.importCountry = importCountry;
        this.count = count;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setImportCountry(String importCountry) {
        this.importCountry = importCountry;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public String getName() {
        return name;
    }

    public String getImportCountry() {
        return importCountry;
    }

    public int getCount() {
        return count;
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(name);
        sb.append("/");
        sb.append(importCountry);
        sb.append("/");
        sb.append(count);
        return sb.toString();
    }
}
