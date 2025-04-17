package sax;

import org.xml.sax.helpers.DefaultHandler;

import org.xml.sax.*;

import java.util.ArrayList;
import Goods.*;

public class GoodsHandler extends DefaultHandler {
    private ArrayList<Goods> result = new ArrayList<>();
    private boolean collectGoods;
    private boolean collectName;
    private boolean collectCountry;
    private boolean collectCount;
    private String currentName;
    private String currentCountry;
    private int currentCount;

    public ArrayList<Goods> getResult() {
        return result;
    }

    private Goods currentGoods;
    public void startElement(String namespace,
                             String localName,
                             String qualifiedName,
                             Attributes attributes)
        throws SAXException
    {
        if (qualifiedName.equals("name")) {
            collectName = true;
        }
        else if (qualifiedName.equals("country")) {
            collectCountry = true;
        }
        else if (qualifiedName.equals("count")) {
            collectCount = true;
        }
        else if (qualifiedName.equals("goods")) {
            currentGoods = new Goods("defautName", "defaultCountry", 0);
            collectGoods = true;
        }
    }

    public void endElement(String namespace,
                             String localName,
                             String qualifiedName)
            throws SAXException
    {
        if (qualifiedName.equals("name")) {
            collectName = false;
        }
        else if (qualifiedName.equals("country")) {
            collectCountry = false;
        }
        else if (qualifiedName.equals("count")) {
            collectCount = false;
        }
        else if (qualifiedName.equals("goods")) {
            result.add(currentGoods);
            collectGoods = true;
        }
    }
    public void characters(char[] chars,
                           int startIndex,
                           int length)
    {
        if (collectName) {
            currentName = new String(chars, startIndex, length);
            currentGoods.setName(currentName);
        }
        else if (collectCountry) {
            currentCountry = new String(chars, startIndex, length);
            currentGoods.setImportCountry(currentCountry);
        }
        else if (collectCount) {
            try {
                currentCount = Integer.parseInt(new String(chars, startIndex, length));
                currentGoods.setCount(currentCount);
            }
            catch (NumberFormatException e) {
                throw new NumberFormatException();
            }
        }
    }
}
