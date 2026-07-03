package org.example.connected;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
public class LoginControll {
    @FXML
    private TextField username;
    @FXML
    private Button login;
    @FXML
    private Button create;
    @FXML
    private TextField pass;
    @FXML
    private Label Warning;
    String Username;
    String Pass;
    private static String loggedInUsername;

    @FXML
    protected void Login_f() throws Exception {
        Username = username.getText();
        Pass = pass.getText();
        Username = Username.trim();
        Username = Username.toLowerCase();
        Pass = Pass.trim();
        File User_name = new File("src/main/resources/" + Username);
        if (Username.isEmpty() || Pass.isEmpty()) {
            if (Username.isEmpty()) {
                Warning.setText("*Please enter Username.");
            } else {
                Warning.setText("*Please enter Password.");
            }
        } else if (User_name.exists()) {
            String Read_Pass;
            try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/" + Username + "/Bio/biodata.txt"))) {
                Read_Pass = br.readLine();
                if (("Password:" + Pass).equals(Read_Pass)) {
                    loggedInUsername = Username;
                    username.clear();
                    pass.clear();
                    Warning.setText("");
                    ConnectED_MainApp.switchScene("MainFrame.fxml");
                } else {
                    Warning.setText("Wrong Password!");
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        } else {
            Warning.setText("*Account Not Found!");
        }
    }

    public static String getLoggedInUsername() {
        return loggedInUsername; // Access the shared username
    }

    @FXML
    protected void CreatePage() throws Exception {
        ConnectED_MainApp.switchScene("Create.fxml");
    }
}
