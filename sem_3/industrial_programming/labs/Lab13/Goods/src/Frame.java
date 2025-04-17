import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import java.io.*;

public class Frame extends JFrame implements ActionListener, ItemListener {
    private GoodsManager manager;
    private JLabel errorMessageLabel = new JLabel();
    private JButton openFileButton = new JButton("Open File");
    private JButton editButton = new JButton("Edit");
    private JButton saveChangesButton = new JButton("Save");
    private JPanel editButtonsPanel = new JPanel(new GridLayout(3, 1));
    private JPanel generalEditPanel = new JPanel(new GridLayout(2, 1));
    //private FlowLayout buttonsLayout = new FlowLayout();
    //private  GridLayout buttonsLayout = new GridLayout(3, 1);
    private JPanel showPanel = new JPanel(new GridLayout(3,1));
    private JPanel mainPanel = new JPanel(new GridLayout(1, 2));
    private JTextArea showDataField = new JTextArea(30, 50);
    //private JTextArea editDataField = new JTextArea(20, 20);
    private JPanel editDataPanel = new JPanel(new GridLayout(3, 2));
    private JSpinner setGoodsCount = new JSpinner();
    private JEditorPane setGoodsName = new JEditorPane();
    private JEditorPane setGoodsImporter = new JEditorPane();
    private JComboBox selectGoodsComboBox = new JComboBox();
    private JButton getImportersButton = new JButton("get by goods");
    public Frame(String title) {
        super(title);
        initEditPanel();
        initShowPanel();

        mainPanel.add(showPanel);
        mainPanel.add(generalEditPanel);
        add(mainPanel, BorderLayout.CENTER);
        /*
        add(openFileButton);
        add(editButton);
        add(saveChangesButton);
*/
        /*
        buttonsLayout.addLayoutComponent("open file", openFileButton);
        buttonsLayout.addLayoutComponent("edit", editButton);
        buttonsLayout.addLayoutComponent("save", saveChangesButton);
        */
        //setLayout(buttonsLayout);

//        editButtonsPanel.add(editDataField);

        //add(paneSetGoodsName, BorderLayout.WEST);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        errorMessageLabel.setText("");
        if (e.getSource().equals(openFileButton)) {
            try {
                this.openFile();
            }
            catch (IOException|NumberFormatException ex) {
                errorMessageLabel.setText("Invalid file!!");
                return;
            }
        }
        else if (e.getSource().equals(saveChangesButton)) {
            JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
            int ret = chooser.showSaveDialog(null);
            if (ret == JFileChooser.APPROVE_OPTION) {
                this.saveChanges(chooser.getSelectedFile());
            }
        }
        else if (e.getSource().equals(getImportersButton)) {
            FrameForAllImporters frame = new FrameForAllImporters("Get all importers", manager);
            frame.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
            frame.setVisible(true);
            frame.setSize(500, 500);
        }
    }
    @Override
    public void itemStateChanged(ItemEvent e) {
        if (e.getStateChange() == ItemEvent.SELECTED) {
            Goods selectGoods = (Goods)selectGoodsComboBox.getSelectedItem();
            setGoodsName.setText(selectGoods.getName());
            setGoodsCount.setValue(selectGoods.getCount());
            setGoodsImporter.setText(selectGoods.getImportCountry());
        }
    }
    private void openFile() throws FileNotFoundException, IOException {
        JFileChooser chooser = new JFileChooser(System.getProperty("user.dir"));
        int ret = chooser.showOpenDialog(openFileButton);
        if (ret == JFileChooser.APPROVE_OPTION) {
            File origin = chooser.getSelectedFile();
            if (!origin.getName().endsWith(".txt")) {
                errorMessageLabel.setText("Invalid file format!!!");
                return;
            }
            manager = new GoodsManager(origin.getPath());
            showDataField.append(manager.toString());
            initComboBox(manager);
            getImportersButton.setEnabled(true);
        }
    }
    private void saveChanges(File file) {
        Goods currentGoods = (Goods)selectGoodsComboBox.getSelectedItem();
        Goods newGoods = new Goods(setGoodsName.getText(), setGoodsImporter.getText(), Integer.parseInt(setGoodsCount.getValue().toString()));
        manager.getGoodsSet().remove(currentGoods);
        manager.add(newGoods);
        selectGoodsComboBox.removeItem(currentGoods);
        selectGoodsComboBox.addItem(newGoods);
        try {
            manager.writeIntoFile(file);
        }
        catch (IOException e) {
            errorMessageLabel.setText("Invalid file for saving!!!");
        }
    }

    private void initEditPanel() {
        getImportersButton.setEnabled(false);

        editButtonsPanel.add(openFileButton);
        editButtonsPanel.add(getImportersButton);
        editButtonsPanel.add(saveChangesButton);

        saveChangesButton.addActionListener(this);
        openFileButton.addActionListener(this);
        getImportersButton.addActionListener(this);

        editDataPanel.add(new JLabel("set name: "));
        editDataPanel.add(setGoodsName);
        editDataPanel.add(new JLabel("set count: "));
        editDataPanel.add(setGoodsCount);
        editDataPanel.add(new JLabel("set importer: "));
        editDataPanel.add(setGoodsImporter);

        generalEditPanel.add(editDataPanel);
        generalEditPanel.add(editButtonsPanel);
        //add(generalEditPanel, BorderLayout.EAST);
    }
    private void initShowPanel() {
        showPanel.add(showDataField);
        showDataField.setEditable(false);
        showPanel.add(new JPanel().add(selectGoodsComboBox));
        selectGoodsComboBox.addItemListener(this);
        selectGoodsComboBox.setSize(5, 2);
        showPanel.add(errorMessageLabel);
        //add(showPanel, BorderLayout.WEST);
    }
    private void initComboBox(GoodsManager manager) {
        for(Goods goods : manager.getGoodsSet()) {
            selectGoodsComboBox.addItem(goods);
        }

    }
}
