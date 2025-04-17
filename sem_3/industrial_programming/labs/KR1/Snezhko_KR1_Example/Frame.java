import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class Frame extends JFrame implements ActionListener {
    private JPanel mainPanel = new JPanel(new GridLayout(2, 1));

    private JPanel studentsPanel = new JPanel(new GridLayout(1, 3));
    private JPanel studentsButtonsPanel = new JPanel(new GridLayout(2, 1));
    //private GridLayout studentsLayout = new GridLayout(1, 2);
    private JTextArea showAllStudents = new JTextArea("showAllStudents",30, 50);
    private JTextArea showProcessedStudents = new JTextArea("showProcessedStudents", 30, 50);
    private JButton studentsReadButton = new JButton("Read students");
    private JButton studentsProcessButton = new JButton("Process students");
    MyContainer students;

    private JPanel doublesPanel = new JPanel(new GridLayout(1, 2));
    private JPanel doublesButtonsPanel = new JPanel(new GridLayout(2, 1));
    //private GridLayout doublesLayout = new GridLayout(1, 2);
    private JTextArea showAllDoubles = new JTextArea("showAllDoubles", 30, 50);
    private JTextArea showProcessedDoubles = new JTextArea("showProcessedDoubles",30, 50);
    private JButton doublesReadButton = new JButton("Read doubles");
    private JButton doublesProcessButton = new JButton("Process doubles");
    private MyContainer doubles;
    public Frame(String title) {
        super(title);

        studentsButtonsPanel.add(studentsReadButton);
        studentsReadButton.addActionListener(this);
        studentsButtonsPanel.add(studentsProcessButton);
        studentsProcessButton.setEnabled(false);
        studentsProcessButton.addActionListener(this);
        studentsPanel.add(studentsButtonsPanel);

        studentsPanel.add(showAllStudents);
        studentsPanel.add(showProcessedStudents);
        showAllStudents.setEditable(false);
        showProcessedStudents.setEditable(false);

        mainPanel.add(studentsPanel);


        doublesButtonsPanel.add(doublesReadButton);
        doublesReadButton.addActionListener(this);
        doublesButtonsPanel.add(doublesProcessButton);
        doublesProcessButton.setEnabled(false);
        doublesPanel.add(doublesButtonsPanel);

        showAllDoubles.setEditable(false);
        showProcessedDoubles.setEditable(false);
        doublesPanel.add(showAllDoubles);
        doublesPanel.add(showProcessedDoubles);

        mainPanel.add(doublesPanel);

        this.add(mainPanel, BorderLayout.CENTER);
    }
    private MyContainer readStudents(String name) throws IOException{
        students = new MyContainer(MyReader.readStudents(name));
        return students;
    }
    private MyContainer readDoubles(String name) throws IOException{
        doubles = new MyContainer(MyReader.readDouble(name));
        return doubles;
    }
    private void showMinAndMax(JTextArea area, MyContainer container) {
        StringBuilder builder = new StringBuilder();
        builder.append(container.getMin());
        builder.append("\n");
        builder.append(container.getMax());
        area.setText(builder.toString());
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(studentsReadButton)) {         //обработать нажатие кнопки "Чтение студентов"
            JFileChooser chooser = new JFileChooser();
            if (chooser.showOpenDialog(studentsReadButton) == JFileChooser.APPROVE_OPTION) {
                File file = chooser.getSelectedFile();          //получаем файл
                try {
                    showAllStudents.setText(readStudents(file.getName()).toString());       //если файл устраивает, то вывести на экран
                    studentsProcessButton.setEnabled(true);                                 // и разблокировать кнопку "Найти максимум и минимум"
                } catch (IOException ex) {
                    showAllStudents.setText("File not found or invalid file format!!!");    //иначе вывод сообщения об ошибке
                    return;
                }
            }
        }
        else if (e.getSource().equals(studentsProcessButton)) {
            showMinAndMax(showProcessedStudents, this.students);
        }
        else if (e.getSource().equals(doublesReadButton)) {
            JFileChooser chooser = new JFileChooser();
            if (chooser.showOpenDialog(studentsReadButton) == JFileChooser.APPROVE_OPTION) {
                File file = chooser.getSelectedFile();
                try {
                    showAllDoubles.setText(readDoubles(file.getName()).toString());
                    doublesProcessButton.setEnabled(true);
                } catch (IOException ex) {
                    showAllDoubles.setText("File not found or invalid file format!!!");
                    return;
                }
            }
        }
        else if (e.getSource().equals(doublesProcessButton)) {
            showMinAndMax(showProcessedDoubles, this.doubles);
        }
    }
}
