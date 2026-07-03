package org.example.connected;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Hyperlink;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.awt.*;
import java.io.*;
import java.net.URL;
import java.util.ResourceBundle;

public class profileControll implements Initializable {

    //Login user info;
    String LogInUser = LoginControll.getLoggedInUsername();
    String UserIn = LoginControll.getLoggedInUsername();



    @FXML
    ImageView imageView;
    @FXML
    Label Name;
    @FXML
    Button follow;
    @FXML
    VBox vBox_l;
    @FXML
    VBox vBox_M;
    @FXML
    VBox vBox_R;
    private static String selectedUser;
    MainFrameControll mainControll = new MainFrameControll();
    String User = mainControll.User;

    public static void setSelectedUser(String user) {
        selectedUser = user;
         System.out.println("Cherksds");
        System.out.println(selectedUser);
    }

    @FXML
    Button Back;

    @FXML
    protected void BacK_F() throws Exception {
        ConnectED_MainApp.switchScene("MainFrame.fxml");
    }

    String Info;
    String AllUser;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        // Add left side following list
        loadFollowers();

        // Add right side all user list
        loadAllUsers();

        loadProfile();
        NewsFeed();
        loadFollowOptin();
    }

    // Load followers from file
    private void loadFollowers() {
        int count2 = 0;
        // System.out.println("chek");
        // System.out.println(selectedUser);
        try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/" + selectedUser + "/Bio/biodata.txt"))) {
            while ((Info = br.readLine()) != null) {
                count2++;
                Info = Info.trim();
                //System.out.println(Info);
                if (count2 == 1 || count2 == 9) {
                    continue;
                }
                Label label = new Label(Info);
                label.setStyle("-fx-font-family: Arial; -fx-font-weight: bold; -fx-font-size: 20px;");
                vBox_l.getChildren().add(label);
                Label label1 = new Label();
                vBox_l.getChildren().add(label1);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }


    // Load all users from the file
    private void loadAllUsers() {
        try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/All User/User.txt"))) {
            while ((AllUser = br.readLine()) != null) {
                AllUser = AllUser.trim();
                String[] parts1 = AllUser.split(":");
                String AlUser = parts1[1];
                if (AlUser.equals(User)) {
                    continue;
                }

                Image image = new Image(getClass().getResource("/" + AlUser + "/Profile/Profile.png").toExternalForm());
                ImageView imageView = new ImageView(image);
                imageView.setFitWidth(35);
                imageView.setFitHeight(35);

                String Name;
                int count = 1;
                try (BufferedReader br2 = new BufferedReader(new FileReader("src/main/resources/" + AlUser + "/Bio/biodata.txt"))) {
                    while ((Name = br2.readLine()) != null) {
                        if (count == 2) {
                            String[] parts = Name.split(":");

                            // Creating a Hyperlink for each user
                            Hyperlink nameLink = new Hyperlink(parts[1]);
                            nameLink.setStyle("-fx-font-family: Arial; -fx-font-weight: bold; -fx-font-size: 20px;");
                            nameLink.setOnAction(event -> {
                                System.out.println("Clicked on " + parts[1]);
                                try {
                                    //System.out.println(AlUser);
                                    ConnectED_MainApp.switchScene("ProfileDisplay.fxml");
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                            });

                            // Create HBox for displaying the user profile and hyperlink
                            HBox hbox = new HBox(10);
                            hbox.getChildren().addAll(imageView, nameLink);
                            vBox_R.setSpacing(15);
                            vBox_R.getChildren().add(hbox);
                            break;
                        }
                        count++;
                    }
                } catch (Exception e2) {
                    System.out.println(e2.getMessage());
                }
            }
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }

    private void loadProfile() {


        String OldFollower;
        try (BufferedReader br2 = new BufferedReader(new FileReader("src/main/resources/" + LogInUser + "/Followers/Followers_List.txt"))) {
            while ((OldFollower = br2.readLine()) != null) {
                if (OldFollower.equals(selectedUser)) {
                    follow.setText("Following");
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        int count = 0;
        try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/" + selectedUser + "/Bio/biodata.txt"))) {
            while ((Info = br.readLine()) != null) {
                count++;

                Image image = new Image(getClass().getResource("/" + selectedUser + "/Profile/Profile.png").toExternalForm());
                imageView.setImage(image);

                if (count == 2) {
                    String[] parts = Info.split(":");
                    Info = Info.trim();
                    Name.setText(parts[1]);
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @FXML
    protected void Follow() {
        String OldFollower;
        int check = 0;
        try (BufferedReader br2 = new BufferedReader(new FileReader("src/main/resources/" + LogInUser + "/Followers/Followers_List.txt"))) {
            while ((OldFollower = br2.readLine()) != null) {
                if (OldFollower.equals(selectedUser)) {
                    check = 1;
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        if (check == 0) {
            try (BufferedWriter brx = new BufferedWriter(new FileWriter("src/main/resources/" + LogInUser + "/Followers/Followers_List.txt", true))) {
                brx.write(selectedUser + "\n");
                follow.setText("Following");
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }

        }

    }

    @FXML
    Button setting;

    @FXML
    protected void Setting_f() throws Exception {
        ConnectED_MainApp.switchScene("Delete.fxml");

    }


    @FXML

    //Load News Feed;
    private void NewsFeed() {
        File folder = new File("src/main/resources/" + selectedUser + "/post"); // Specify the folder path here
        File[] files = folder.listFiles(); // Get all files in the directory

        if (files != null) {
            int pdfCount = 0;

            // Iterate through the files
            for (File file : files) {
                if (file.isFile() && file.getName().endsWith(".pdf")) {
                    System.out.println("PDF File name: " + file.getName());

                    // Create a button for each PDF
                    Button projectButton = new Button(file.getName());

                    // Set button size
                    projectButton.setPrefWidth(500); // Set button width
                    projectButton.setPrefHeight(200); // Set button height

                    // Style the button
                    projectButton.setStyle("-fx-font-size: 22; -fx-font-weight: bold; -fx-background-color:  #613F75; -fx-text-fill: white; -fx-background-radius: 10;");


                    // Attach the file path to the button's action
                    projectButton.setOnAction(event -> openPDF(file.getAbsolutePath()));

                    // Add the button to a VBox or other layout
                    vBox_M.setSpacing(15); // Set spacing between elements
                    vBox_M.setAlignment(Pos.TOP_CENTER); // Align items to the left
                    vBox_M.setStyle("-fx-padding: 10;");
                    vBox_M.getChildren().add(projectButton);

                    pdfCount++;
                }
            }

            System.out.println("Number of PDF files: " + pdfCount);
        } else {
            System.out.println("An error occurred or the folder is empty.");
        }
    }

    // Method to open the PDF file
    private void openPDF(String filePath) {
        try {
            File pdfFile = new File(filePath);
            if (pdfFile.exists()) {
                // Open the PDF using the system's default PDF viewer
                Desktop.getDesktop().open(pdfFile);
            } else {
                System.out.println("File not found: " + filePath);
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Error opening PDF file: " + filePath);
        }
    }
        protected void loadFollowOptin(){
        if (selectedUser.equals(UserIn)){
            follow.setVisible(false);
        }
        }

}
