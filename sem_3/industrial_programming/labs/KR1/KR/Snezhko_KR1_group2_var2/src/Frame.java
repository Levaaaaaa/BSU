import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.stream.Collectors;

public class Frame extends JFrame implements ActionListener {
    private ArrayList<Employee> employees = new ArrayList<>();
    private JPanel mainPanel = new JPanel(new GridLayout(2, 1));
    private JPanel buttonsPanel = new JPanel(new GridLayout(3, 2));
    private JPanel textAreasPanel = new JPanel(new GridLayout(1, 2));

    private JButton getByDecreaseSalaryButton = new JButton("get sorted list by salary");
    private JButton getListBySalaryAndJobCoeffButton = new JButton("get list by salary divided to job coeff.");
    private JButton getListOrganizationsStartedWithBButton = new JButton("get organizations that started with B");
    private JButton getAverageSalaryOfOrganizationButton = new JButton("get average salary of organization");
    private JButton openFileButton = new JButton("open file");
    private JComboBox selectOrganizationComboBox = new JComboBox();

    private JTextArea printAllEmployers = new JTextArea();
    private JTextArea printProcessedEmployers = new JTextArea();

    public Frame() {
        super("Main Frame");

        initTextAreasPanel();
        initButtonsPanel();
        mainPanel.add(textAreasPanel);
        mainPanel.add(buttonsPanel);
        add(mainPanel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(openFileButton)) {
            try {
                readEmployeersFromFile(employees);
                printListInComponent(employees, printAllEmployers);
            }
            catch (IOException | NumberFormatException ex) {
                printProcessedEmployers.setText("File not found or damaged!!!");
                return;
            }
        }
        else if (e.getSource().equals(getByDecreaseSalaryButton)) {
            printListInComponent(ProcessCollection.getListByDecreaseSalary(employees), printProcessedEmployers);
        }
        else if (e.getSource().equals(getListBySalaryAndJobCoeffButton)) {
            printListInComponent(ProcessCollection.getListBySalaryAndJobCoeff(employees), printProcessedEmployers);
        }
        else if (e.getSource().equals(getListOrganizationsStartedWithBButton)) {
            printListInComponent(ProcessCollection.findOrganizationStartWithB(employees), printProcessedEmployers);
        }
/*        else if (e.getSource().equals(getAverageSalaryOfOrganizationButton)) {
            initComboBox();
            printListInComponent(ProcessCollection.calculateAverageSalary(selectOrganizationComboBox.getSelectedItem()), printProcessedEmployers);
        }

 */
    }
    private void initTextAreasPanel() {
        printAllEmployers.setEditable(false);
        printProcessedEmployers.setEditable(false);

        textAreasPanel.add(printAllEmployers);
        textAreasPanel.add(printProcessedEmployers);
    }

    private void initButtonsPanel() {
        /*
        readGiftButton.addActionListener(this);
        saveButton.addActionListener(this);
        getGeneralWeightButton.addActionListener(this);
        getSweetBySugarButton.addActionListener(this);
        addSweetToGiftButton.addActionListener(this);
        */

        openFileButton.addActionListener(this);
        getListOrganizationsStartedWithBButton.addActionListener(this);
        getByDecreaseSalaryButton.addActionListener(this);
        getListBySalaryAndJobCoeffButton.addActionListener(this);
        getAverageSalaryOfOrganizationButton.addActionListener(this);

        buttonsPanel.add(getAverageSalaryOfOrganizationButton);
        buttonsPanel.add(selectOrganizationComboBox);
        buttonsPanel.add(openFileButton);
        buttonsPanel.add(getByDecreaseSalaryButton);
        buttonsPanel.add(getListBySalaryAndJobCoeffButton);
        buttonsPanel.add(getListOrganizationsStartedWithBButton);
        changeButtonsStatus(false);
    }
    private void changeButtonsStatus(boolean status) {
        getAverageSalaryOfOrganizationButton.setEnabled(status);
        getByDecreaseSalaryButton.setEnabled(status);
        getListBySalaryAndJobCoeffButton.setEnabled(status);
        getListOrganizationsStartedWithBButton.setEnabled(status);
        selectOrganizationComboBox.setEnabled(status);
    }
    private void printListInComponent(Collection collection, JTextArea textArea) {
        StringBuilder sb = new StringBuilder();
        collection.stream()
                .forEach(x -> sb.append(x.toString()).append("\n"));
        textArea.setText(sb.toString());
    }
/*
    private void initComboBox() {
            for(Employee empl : employees) {
                selectOrganizationComboBox.addItem(empl.getOrganization());
            }
    }
*/
    private void readEmployeersFromFile(ArrayList<Employee> array) throws NumberFormatException, IOException{
        JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
        int r = chooser.showOpenDialog(null);
        if (r == JFileChooser.APPROVE_OPTION) {
            File file = chooser.getSelectedFile().getAbsoluteFile();
            if (!file.getName().endsWith(".txt")) throw new IOException();
            try {
                BufferedReader reader = new BufferedReader(new FileReader(file));
                if (file.getName().equals("input1.txt")) {
                    for (String line : reader.lines().collect(Collectors.toSet())) {
                        //array.add(createEmployee(line));
                        array.add(new SecurityGuard(line));
                    }
                }
                else {
                    for (String line : reader.lines().collect(Collectors.toSet())) {
                        //array.add(createEmployee(line));
                        array.add(new Seller(line));
                    }
                }
                reader.close();
            }
            catch (IOException e) {
                throw new IOException();
            }
            changeButtonsStatus(true);
        }
    }
    /*
    private Employee createEmployee(String empl) throws IOException{

        else {
            return new Seller(empl);
        }
    }

     */
}
