package org.example.connected;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Hyperlink;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.layout.VBox;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class SearchControll implements Initializable {

    // Assuming this method fetches the search term from somewhere (like user input in MainFrame)
    String SearchItem = MainFrameControll.SearchItem();

    @FXML
    private Button Back;
    @FXML
    ScrollPane SearchPen;

    @FXML
    private VBox SearchBox; // VBox to display search results
    // To display search results or message

    protected void SearchList() {
        // Define the directory where the PDFs are located
        File directory = new File("src/main/resources/All Post");

        // Check if the directory exists and is a directory
        if (directory.exists() && directory.isDirectory()) {
            // Clear previous results from the VBox
            SearchBox.getChildren().clear();

            // Get the list of files in the directory
            File[] files = directory.listFiles((dir, name) -> name.toLowerCase().endsWith(".pdf"));

            if (files != null && files.length > 0) {
                boolean found = false;

                // Loop through the PDF files
                for (File file : files) {
                    // Check if the file name contains the SearchItem (case-insensitive)
                    if (file.getName().toLowerCase().contains(SearchItem.toLowerCase())) {
                        found = true;

                        // Create a hyperlink for each matching file
                        // Hyperlink fileLink = new Hyperlink(file.getName());


                        // Create a button for each PDF
                        Button projectButton = new Button(file.getName());

                        // Set button size
                        projectButton.setPrefWidth(500); // Set button width
                        projectButton.setPrefHeight(200); // Set button height

                        // Style the button
                        projectButton.setStyle("-fx-font-size: 22; -fx-font-weight: bold; -fx-background-color:  #613F75; -fx-text-fill: white; -fx-background-radius: 10;");
                        projectButton.setOnAction(event -> openPDF(file.getAbsolutePath()));


                        // Set the action to open the file when the hyperlink is clicked

                        // Add the hyperlink to the VBox

                        SearchBox.setSpacing(15); // Set spacing between elements
                        // vBox_M.setAlignment(Pos.TOP_CENTER); // Align items to the left
                        SearchBox.setStyle("-fx-padding: 10;");
                        SearchPen.setStyle("-fx-background: #d8cfff; -fx-background-color:  #d8cfff;");

                        SearchBox.getChildren().add(projectButton);
                    }
                }

                if (!found) {


                    Label WRL = new Label();
                    WRL.setStyle("-fx-font-size: 20px;");

                    WRL.setText("No results found.");
                    SearchBox.setPadding(new Insets(100, 20, 10, 20));
                    SearchBox.setAlignment(Pos.TOP_CENTER);
                    SearchBox.getChildren().add(WRL);
                    // resultLabel.setText("No matching PDF file found.");
                } else {


                    Label WRL = new Label();

                    // WRL.setText("Directory not found or invalid path.");
                    SearchBox.getChildren().add(WRL);
                    // resultLabel.setText("Found the following files:");
                }
            } else {

                Label WRL = new Label();

                // WRL.setText("Directory not found or invalid path.");
                SearchBox.getChildren().add(WRL);
                // resultLabel.setText("No PDF files found in the directory.");
            }
        } else {
            Label WRL = new Label();

            WRL.setText("Directory not found or invalid path.");
            SearchBox.getChildren().add(WRL);
        }
    }

    private void openFile(File file) {
        try {
            // Open the file with the default system application
            if (Desktop.isDesktopSupported()) {
                Desktop.getDesktop().open(file);
            } else {
                System.out.println("Desktop operations not supported on this platform.");
            }
        } catch (IOException e) {
            System.err.println("Error opening file: " + file.getName());
            e.printStackTrace();
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


    @FXML
    protected void BacK_F() throws Exception {
        System.out.println(SearchItem);
        SearchBox.getChildren().clear();
        ConnectED_MainApp.switchScene("MainFrame.fxml");
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        SearchList(); // Call the search method when the scene is initialized
    }
}
