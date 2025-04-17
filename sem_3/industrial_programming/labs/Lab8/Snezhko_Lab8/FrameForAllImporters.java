import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
public class FrameForAllImporters extends JFrame implements ItemListener{
    private GoodsManager curManager;
    private JTextArea outputImporters = new JTextArea();
    private JTextArea outputCount = new JTextArea();
    private JComboBox selectCountryComboBox = new JComboBox();
    public FrameForAllImporters(String title, GoodsManager manager) {
        super(title);
        curManager = manager;
        GridLayout layout = new GridLayout(3, 2);

        //add(new JLabel(""));
        add(selectCountryComboBox, BorderLayout.NORTH);
        add(new JLabel(""));
        add(new JLabel("Importers: "));
        add(outputImporters);
        add(new JLabel("Count: "));
        add(outputCount);

//        layout.addLayoutComponent("emptyLabel", new JLabel(""));
        layout.addLayoutComponent("comboBox", selectCountryComboBox);
        //layout.addLayoutComponent("labelImporters", new JLabel("Importers: "));
        layout.addLayoutComponent("outputImporters", outputImporters);
//        layout.addLayoutComponent("labelCount", new JLabel("Count: "));
        layout.addLayoutComponent("count", outputCount);

        setLayout(layout);
        //output.setEditable(false);
        initComboBox();

        outputImporters.setSize(50, 30);
        outputImporters.setEditable(false);
        outputCount.setSize(50, 30);
        outputCount.setEditable(false);
    }
    @Override
    public void itemStateChanged(ItemEvent e) {
        if (e.getStateChange() == ItemEvent.SELECTED) {
            StringBuilder builder = new StringBuilder();
            StringBuilder builderCount = new StringBuilder();
            curManager.getCountryByGoods((String)e.getItem()).forEach(str -> builder.append(str + "\n"));
            outputCount.setText(Integer.toString(curManager.getGeneralCount((String)e.getItem())));
            outputImporters.setText(builder.toString());
        }
    }
    public void initComboBox() {
        for(Goods goods : curManager.getGoodsSet()) {
            selectCountryComboBox.addItem(goods.getName());
        }
        selectCountryComboBox.addItemListener(this);
    }
}
