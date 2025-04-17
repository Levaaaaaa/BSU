import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

public class MyPanel extends JPanel implements MouseMotionListener {
    private ArrayList<MyPair<Point, Color>> points = new ArrayList<>();
    private Color propertyColor;
    private MyPanel listenedPanel;
    public MyPanel() {
        super();
    }
    public MyPanel(Color color) {
        super();
        this.propertyColor = color;
    }
    public MyPanel(Color color, MyPanel panel) {
        super();
        this.propertyColor = color;
        this.listenedPanel = panel;
    }
    @Override
    public void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        graphics.setColor(propertyColor);
        graphics.drawOval(0, 0, getWidth(), getHeight());//this.getX(), this.getY(), this.getWidth(), this.getHeight());

        points.forEach(point -> {
            graphics.setColor(point.getSecond());
            graphics.drawOval(point.getFirst().x, point.getFirst().y, 1,1);
        });
        if (listenedPanel != null) {
            this.points = listenedPanel.getPoints();
            points.forEach(point -> {
                graphics.setColor(point.getSecond());
                graphics.drawOval(point.getFirst().x, point.getFirst().y, 1,1);
            });
        }

        addMouseMotionListener(this);
    }

    public ArrayList<MyPair<Point, Color>> getPoints() {
        return points;
    }

    @Override
    public void mouseDragged(MouseEvent event) {
        points.add(new MyPair<>(event.getPoint(), Color.RED));
        this.repaint();
    }
    @Override
    public void mouseMoved(MouseEvent event) {
        return;
    }

}
