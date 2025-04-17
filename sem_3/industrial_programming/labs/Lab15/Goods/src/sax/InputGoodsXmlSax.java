package sax;

import Goods.Goods;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import readFromFileStrategy.InputFromXmlStrategy;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class InputGoodsXmlSax implements InputFromXmlStrategy {
    @Override
    public ArrayList<Goods> readFromFile(File file) throws SAXException, IOException, ParserConfigurationException{
        if (file == null) throw new IllegalArgumentException("file is null");
        else if (!file.getName().endsWith(".xml")) throw new IllegalArgumentException("It's not XML file");
        DefaultHandler handler = new GoodsHandler();
        SAXParserFactory factory = SAXParserFactory.newInstance();
        ArrayList<Goods> result = new ArrayList<Goods>();
        SAXParser parser = factory.newSAXParser();
        parser.parse(file, handler);
        result = ((GoodsHandler)handler).getResult();
        return result;
    }

    @Override
    public String toString() {
        return "input SAX strategy";
    }
}
