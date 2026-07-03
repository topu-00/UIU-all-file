import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.util.PrimitiveIterator;

public class ButtonLayout extends JPanel {


    private JButton[][] buttons=new JButton[4][4];


    public ButtonLayout(){
        setLayout(new GridLayout(4,4));
        createButton();
    }

    private void createButton(){
        String [][] opts={
                {"9","8","7","+"},
                {"6","5","4","-"},
                {"3","2","1","/"},
                {"0","C","=","/"}
        };
        for (int i=0;i<opts.length;i++){
            for (int j=0;j<opts[i].length;j++){
                buttons[i][j]=new JButton(opts[i][j]);
                add(buttons[i][j]);
            }
        }
    }

    public JButton[][] getButtons() {
        return buttons;
    }
}
