package dom;

import Goods.Goods;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import readFromFileStrategy.InputFromXmlStrategy;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class InputGoodsXmlDom implements InputFromXmlStrategy {
    @Override
    public ArrayList<Goods> readFromFile(File file) throws SAXException, IOException, ParserConfigurationException {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        Document document = builder.parse(file);
        document.getDocumentElement().normalize();

        NodeList nodes = document.getElementsByTagName("goods");
        ArrayList<Goods> result = new ArrayList<>();

        for (int i = 0; i < nodes.getLength(); i++) {
            result.add(getGoods(nodes.item(i)));
        }

        return result;
    }
    public Goods getGoods(Node node) throws NumberFormatException {
        Goods goods = new Goods();
        if (node.getNodeType() == Node.ELEMENT_NODE) {
            Element elem = (Element)node;
            goods.setName(getTagValue("name", elem));
            goods.setImportCountry(getTagValue("country", elem));
            goods.setCount(Integer.parseInt(getTagValue("count", elem)));
        }

        return goods;
    }
    public static String getTagValue(String tag, Element elem) {
        NodeList list = elem.getElementsByTagName(tag).item(0).getChildNodes();
        Node node = (Node)list.item(0);
        return node.getNodeValue();
    }

    @Override
    public String toString() {
        return "input DOM strategy";
    }
}
