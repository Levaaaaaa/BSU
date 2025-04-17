import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame implements ActionListener {
    private JLabel label = new JLabel("I am JLabel");
    private JButton buttonAdd;
    private JButton buttonDelete;
    private JButton button;
    public MyFrame(String title) throws HeadlessException {
        super(title);

        this.add(label, BorderLayout.NORTH);

        buttonAdd = new JButton("Add");
        this.add(buttonAdd, BorderLayout.WEST);
        buttonAdd.addActionListener(this);

        buttonDelete = new JButton("Delete");
        this.add(buttonDelete, BorderLayout.EAST);
        buttonDelete.addActionListener(this);

        button = new JButton("Button");
        this.add(button);
        button.addActionListener (new ActionListener() {        //анонимный класс
           @Override
           public void actionPerformed(ActionEvent e) {
               button.setText("Hello");
           }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        //JOptionPane.showMessageDialog(this, "Action Event");
        if (e.getSource() == this.buttonAdd) {
            JOptionPane.showMessageDialog(this, "Add button Action Event");
        } else if (e.getSource() == this.buttonDelete) {
            JOptionPane.showMessageDialog(this, "Delete button Action Event");
        }
    }
}







