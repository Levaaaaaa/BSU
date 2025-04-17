package readFromFileStrategy;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import Goods.*;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;

public interface InputFromXmlStrategy {
    public ArrayList<Goods> readFromFile(File file) throws SAXException, IOException, ParserConfigurationException;
    public String toString();
}
