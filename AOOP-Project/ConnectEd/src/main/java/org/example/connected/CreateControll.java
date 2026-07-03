package org.example.connected;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Calendar;
import java.util.Date;

public class CreateControll {
    @FXML
    private TextField name;
    @FXML
    private TextField uni;
    @FXML
    private TextField id;
    @FXML
    private TextField country;
    @FXML
    private TextField gender;
    @FXML
    private TextField dateofbirth;
    @FXML
    private TextField phone_email;
    @FXML
    private TextField username;
    @FXML
    private TextField pass;
    @FXML
    private TextField confirm_pass;
    @FXML
    private Label warning;
    @FXML
    private Button create;
    @FXML
    private Button back;
    String Name;

    String Uni;

    String Id;

    String Country;

    String Gender;

    String Dateofbirth;

    String Phone_email;

    String Username;

    String Pass;

    String Confirm_pass;

    @FXML
    protected void Create() throws Exception {
        Name = name.getText();
        Name = Name.trim();

        Uni = uni.getText();
        Uni = Uni.trim();

        Id = id.getText();
        Id = Id.trim();

        Country = country.getText();
        Country = Country.trim();

        Gender = gender.getText();
        Gender = Gender.trim();

        Dateofbirth = dateofbirth.getText();
        Dateofbirth = Dateofbirth.trim();

        Phone_email = phone_email.getText();
        Phone_email = Phone_email.trim();

        Username = username.getText();
        Username = Username.trim();
        Username = Username.toLowerCase();

        Pass = pass.getText();
        Pass = Pass.trim();

        Confirm_pass = confirm_pass.getText();
        Confirm_pass = Confirm_pass.trim();
        String Read_User;
        int check = 0;
        try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/All User/User.txt"))) {
            while ((Read_User = br.readLine()) != null) {
                Read_User = Read_User.trim();
                if (Read_User.equals("Username:" + Username)) {
                    check = 1;
                    break;
                }
            }
        }

        if (Name.isEmpty() || Uni.isEmpty() || Id.isEmpty() || Country.isEmpty() || Gender.isEmpty() || Dateofbirth.isEmpty() || Phone_email.isEmpty() || Username.isEmpty() || Pass.isEmpty() || Confirm_pass.isEmpty()) {

            if (Confirm_pass.isEmpty()) {
                warning.setText("*Please enter your Confirm Password.");
            } else if (Pass.isEmpty()) {
                warning.setText("*Please enter your Password.");
            } else if (Username.isEmpty()) {
                warning.setText("*Please enter your Username.");
            } else if (Phone_email.isEmpty()) {
                warning.setText("*Please enter your Phone or Email.");
            } else if (Dateofbirth.isEmpty()) {
                warning.setText("*Please enter your date of birth.");
            } else if (Gender.isEmpty()) {
                warning.setText("*Please enter your Gender.");
            } else if (Country.isEmpty()) {
                warning.setText("*Please enter your Country.");
            } else if (Id.isEmpty()) {
                warning.setText("*Please enter your Id.");
            } else if (Uni.isEmpty()) {
                warning.setText("*Please enter your University.");
            } else if (Name.isEmpty()) {
                warning.setText("*Please enter your name.");
            }
        } else if (check == 1) {
            warning.setText("*Username already Used!");
        } else if (Pass.equals(Confirm_pass)) {

            name.clear();
            uni.clear();
            id.clear();
            country.clear();
            gender.clear();
            dateofbirth.clear();
            phone_email.clear();
            username.clear();
            pass.clear();
            confirm_pass.clear();
            warning.setText("");


            File Maindir = new File("src/main/resources/" + Username);
            Maindir.mkdir();

            File bio = new File("src/main/resources/" + Username + "/Bio");
            bio.mkdir();

            File Followers = new File("src/main/resources/" + Username + "/Followers");
            Followers.mkdir();

            File Followers_list = new File("src/main/resources/" + Username + "/Followers/Followers_List.txt");
           Followers_list.createNewFile();

            File ProfillePic = new File("src/main/resources/" + Username + "/Profile");
            ProfillePic.mkdir();

            File post = new File("src/main/resources/" + Username + "/post");
            post.mkdir();



            Path sourcePath = Paths.get("src/main/resources/png-transparent-user-profile-computer-icons-profile-heroes-black-silhouette-thumbnail-removebg-preview.png");

            // Destination file path with the same or new name
            Path destinationPath = Paths.get("src/main/resources/" + Username + "/Profile/Profile.png");

            try {
                // Copy the .jpg file
                Files.copy(sourcePath, destinationPath);
               // System.out.println("Image file copied successfully!");
            } catch (IOException e) {
                System.err.println("An error occurred while copying the image file: " + e.getMessage());
            }



            try (BufferedWriter bw = new BufferedWriter(new FileWriter("src/main/resources/" + Username + "/Bio/" + "biodata.txt"))) {

                bw.write("Password:" + Pass + "\n");
                bw.write("Name: " + Name + "\n");
                bw.write("University: " + Uni + "\n");
                bw.write("Id: " + Id + "\n");
                bw.write("Country: " + Country + "\n");
                bw.write("Gender: " + Gender + "\n");
                bw.write("Date of birth: " + Dateofbirth + "\n");
                bw.write("Phone: " + Phone_email + "\n");
                bw.write("Username:" + Username + "\n");

            } catch (Exception e) {
                System.out.println("Error writing");
            }

            try (BufferedWriter bw = new BufferedWriter(new FileWriter("src/main/resources/All User/User.txt", true))) {
                bw.write("Username:" + Username + "\n");
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
            ConnectED_MainApp.switchScene("Login.fxml");
        } else {
            warning.setText("*Please enter same Password.");

        }

    }

    @FXML
    protected void Back() throws Exception {
        ConnectED_MainApp.switchScene("Login.fxml");
    }
}
