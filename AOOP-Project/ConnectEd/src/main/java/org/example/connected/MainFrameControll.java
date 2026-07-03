package org.example.connected;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;

import java.awt.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.net.URL;
import java.util.ResourceBundle;

public class MainFrameControll implements Initializable {

    // Assuming this comes from a login process
    String User = LoginControll.getLoggedInUsername();

    @FXML
    private ChoiceBox<String> server;
    @FXML
    private VBox vBox_l;
    @FXML
    private VBox vBox_R;
    @FXML
    private VBox Profile_Vbox;

    String[] Server = {"United International University", "Dhaka International University", "Dhaka University",
            "University of Cambridge", "University of Oxford"};

    String Follower;
    String AllUser;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        // Initialize server list
       // server.getItems().add("Server");
        server.setValue("Select University");
        server.getItems().addAll(Server);

        // Add left side following list
        loadFollowers();

        // Add right side all user list
        loadAllUsers();
        NewsFeed();
    }

    // Load followers from file
    private void loadFollowers() {
        try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/" + User + "/Followers/Followers_List.txt"))) {
            while ((Follower = br.readLine()) != null) {
                Follower = Follower.trim();
                Image image = new Image(getClass().getResource("/" + Follower + "/Profile/Profile.png").toExternalForm());
                ImageView imageView = new ImageView(image);
                imageView.setFitWidth(35);
                imageView.setFitHeight(35);
                String Name;
                int count = 1;
                try (BufferedReader br2 = new BufferedReader(new FileReader("src/main/resources/" + Follower + "/Bio/biodata.txt"))) {
                    while ((Name = br2.readLine()) != null) {
                        if (count == 2) {
                            String[] parts = Name.split(":");
                            Label label = new Label(parts[1]);
                            label.setStyle("-fx-font-family: Arial; -fx-font-weight: bold; -fx-font-size: 20px;");
                            HBox hbox = new HBox(10);
                            hbox.getChildren().addAll(imageView, label);
                            vBox_l.setSpacing(15);
                            vBox_l.getChildren().add(hbox);
                            break;
                        }
                        count++;
                    }
                } catch (Exception e2) {
                    System.out.println(e2.getMessage());
                }
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
                                    System.out.println(AlUser);
                                    profileControll.setSelectedUser(AlUser);

                                    ConnectED_MainApp.switchScene("ProfileDisplay.fxml");
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                            });

                            if (AlUser.equals(User)) {
                                // System.out.println("fuff");
                                //System.out.println(User);
                                HBox hbox = new HBox(10);
                                hbox.getChildren().addAll(imageView, nameLink);
                                Profile_Vbox.getChildren().add(hbox);
                            } else {
                                // Create HBox for displaying the user profile and hyperlink
                                HBox hbox = new HBox(10);
                                hbox.getChildren().addAll(imageView, nameLink);
                                vBox_R.setSpacing(15);
                                vBox_R.getChildren().add(hbox);
                                break;
                            }

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






    @FXML
    private VBox vBox_M;
    @FXML
    ScrollPane scrollPane_M;
    //Load News Feed;
    private void NewsFeed() {
        File folder = new File("src/main/resources/All Post"); // Specify the folder path here
        File[] files = folder.listFiles(); // Get all files in the directory

        if (files != null) {
            int pdfCount = 0;
            scrollPane_M.setStyle("-fx-background: #d8cfff; -fx-background-color:  #d8cfff;");

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













    // search Part
    @FXML
    Button Search;
    @FXML
    TextField SearchField;

    static String SearechItems;
    @FXML
    protected void Search_f() throws Exception {
        SearechItems = SearchField.getText(); // Get text from the input field
        if (SearechItems == null || SearechItems.trim().isEmpty()) {
            // Handle null or empty input
            System.out.println("Search field is empty or invalid!");
            return; // Exit the method
        }
        SearechItems = SearechItems.trim(); // Trim whitespace for valid input
        ConnectED_MainApp.switchScene("Search.fxml"); // Proceed with navigation
    }


    public static String SearchItem() {
        return  SearechItems; // Access the shared Items
    }










    @FXML
    private Button logout;
    @FXML
    private Button post;
    @FXML
    protected void upload() throws Exception {
        ConnectED_MainApp.switchScene("Post.fxml");

    }




    @FXML
    Button Messenger;
    @FXML
    protected void Messenger_f() throws Exception {
        ConnectED_MainApp.switchScene("Messenger.fxml"); // Proceed with navigation



    }

    @FXML
    protected void Logout() throws Exception {
        ConnectED_MainApp.switchScene("Login.fxml");
    }

}
