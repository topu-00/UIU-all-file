import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.security.cert.TrustAnchor;
import java.util.Formatter;

public class MainFrame extends JFrame implements ActionListener {
    ButtonField button = new ButtonField();
    JTextArea textArea = new JTextArea();

    public MainFrame() {
        setLayout(new BorderLayout());
        add(textArea, BorderLayout.CENTER);
        add(button, BorderLayout.NORTH);

        button.Save.addActionListener(this);

        setTitle("Sample Word Editor");
        setVisible(true);
        setSize(1000, 1200);
        setLocation(450, 450);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            FileWriter file = new FileWriter("Output.txt", true);
            Formatter file1 = new Formatter(file);
            if (e.getActionCommand().equals("Save")) {
                file1.format("%s\r\n", textArea.getText());
                file1.close();
            }

        } catch (Exception h) {
            //ubasiudbiw8
        }
    }

}
