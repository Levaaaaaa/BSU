import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.awt.image.Raster;
import java.util.ArrayList;

public class MyPanel extends JPanel implements MouseMotionListener, MouseListener, ComponentListener{
    //private static boolean isMousePressed = false;
    //private ArrayList<Polygon> lines = new ArrayList<>();
    //private Polygon curPolygon = new Polygon();
    private int width = 5;
    private int lastX;
    private int lastY;
//    private Graphics2D g2;
    private Color color = Color.BLACK;
    //private Graphics currentGraphics;
    private BufferedImage buffImage;
    public MyPanel() {
        super();
        //this.setBounds(this.getX(), this.getY(), 500, 500);
        Dimension size = Toolkit.getDefaultToolkit().getScreenSize();
        buffImage = new BufferedImage(size.width, size.height, BufferedImage.TYPE_INT_ARGB);
        addMouseListener(this);
        addMouseMotionListener(this);
    }
    public MyPanel(Color color) {
        this();
        this.color = color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(buffImage, this.getX(), this.getY(), null);
        //g.setColor(Color.BLACK);
    }
    public void clear() {
        this.getGraphics().clearRect(0, 0, this.getWidth(), getHeight());
    }

    public BufferedImage getBufferedImage() {
        return buffImage;
    }
    /*
    public void clear() {
        this.
    }
    */

    public void setBuffImage(BufferedImage buffImage) {
        this.buffImage = buffImage;
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();
        Graphics2D g2 = (Graphics2D) buffImage.getGraphics();//createGraphics();//(Graphics2D)this.getGraphics();
        g2.setStroke(new BasicStroke(width));
        g2.setColor(color);
        g2.drawLine(lastX, lastY, x, y);
        lastX = x;
        lastY = y;
        repaint();
        //this.getGraphics().drawImage(buffImage, this.getX(), this.getY(), this);
        //buffImage.setData();
        //currentGraphics = g2;
    }

    @Override
    public void mousePressed(MouseEvent e) {
        lastX = e.getX();
        lastY = e.getY();
    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }

    @Override
    public void mouseClicked(MouseEvent e) {
        return;
    }
    @Override
    public void mouseEntered(MouseEvent e) {
        return;
    }

    @Override
    public void mouseExited(MouseEvent e) {
        return;
    }

    @Override
    public void componentResized(ComponentEvent e) {
        this.getGraphics().drawImage(buffImage, this.getX(), this.getY(), null);
        repaint();
    }

    @Override
    public void componentMoved(ComponentEvent e) {

    }

    @Override
    public void componentShown(ComponentEvent e) {

    }

    @Override
    public void componentHidden(ComponentEvent e) {

    }
}
