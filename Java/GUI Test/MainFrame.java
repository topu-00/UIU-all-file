import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainFrame extends JFrame implements ActionListener {
    private JTextField textField;
    private ButtonLayout buttonLayout;

    public MainFrame() {
        super("Calculator");


        setLayout(new BorderLayout());
        creatURI();
        ActionListenar();
        ShowWind();

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // System.out.println("pressed: " +e.getActionCommand());
        //textField.setText(textField.getText() + e.getActionCommand());
        if (e.getActionCommand().equals("=")){
            //Add
            String expr=textField.getText();
            System.out.println(expr);
            if (expr.contains("+")){
                String [] nums=expr.split("[+]");
                int sum=0;
                for (String num:nums){
                   // System.out.println(num);
                    sum+=Integer.parseInt(num);
                    textField.setText(Integer.toString(sum));
                }
            }
        }
        else if (e.getActionCommand().equals("C")){
            textField.setText("");
        }
        else {
            textField.setText(textField.getText() + e.getActionCommand());
        }
    }

    private void ShowWind() {
        setSize(600, 700);
        setLocation(400, 50);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    private void creatURI(){
        textField = new JTextField();
       // textField.getHorizontalAlignment(SwingConstants.RIGHT);
        buttonLayout = new ButtonLayout();
        add(textField, BorderLayout.NORTH);
        add(buttonLayout, BorderLayout.CENTER);
    }
    private void ActionListenar(){
        for (int i = 0; i < buttonLayout.getButtons().length; i++) {
            for (int j = 0; j < buttonLayout.getButtons()[i].length; j++) {
                buttonLayout.getButtons()[i][j].addActionListener(this);
            }
        }
    }
}
