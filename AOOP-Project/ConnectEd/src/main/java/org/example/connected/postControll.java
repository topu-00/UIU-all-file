package org.example.connected;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.FileChooser;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ResourceBundle;

public class postControll implements Initializable {
    String User = LoginControll.getLoggedInUsername();

    @FXML
    private Button postButton;
    @FXML
    private TextField ProjectName;
    @FXML
    private Label Url;
    private String URL;
    @FXML
    private Label W_L;

    protected void upload() throws Exception {
        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("PDF Files", "*.pdf"),
                new FileChooser.ExtensionFilter("ZIP Files", "*.zip"),
                new FileChooser.ExtensionFilter("All Files", "*.*")
        );

        File file = fileChooser.showOpenDialog(null);

        if (file != null) {
            URL = file.getAbsolutePath();
            Url.setText(URL);
            System.out.println("Selected file path: " + URL);
        } else {
            W_L.setText("File empty");
            postButton.setVisible(false);
            System.out.println("No file was selected.");
        }
    }

    @FXML
    protected void postButton_f() {
        String P_N = ProjectName.getText().trim();

        if (!P_N.isEmpty()) {
            Path sourcePath = Paths.get(URL);
            Path destinationPath = Paths.get("src/main/resources/" + User + "/post/" + P_N + ".pdf");
            Path destinationPath2 = Paths.get("src/main/resources/All Post/" + P_N + ".pdf");

            try {
                if (Files.exists(destinationPath)) {
                    String newFileName = getNewFileName(destinationPath);
                    destinationPath = destinationPath.resolveSibling(newFileName);
                }
                Files.copy(sourcePath, destinationPath);
                System.out.println("File copied to: " + destinationPath.toString());

                if (Files.exists(destinationPath2)) {
                    String newFileName = getNewFileName(destinationPath2);
                    destinationPath2 = destinationPath2.resolveSibling(newFileName);
                }
                Files.copy(sourcePath, destinationPath2);
                System.out.println("File copied to: " + destinationPath2.toString());

                W_L.setText("Uploaded Successfully");
                ProjectName.clear();
                postButton.setVisible(false);
            } catch (IOException e) {
                System.err.println("An error occurred while copying the file: " + e.getMessage());
                W_L.setText("Error occurred during upload.");
            }
        } else {
            W_L.setText("Please enter a valid project name.");
            System.out.println("Please enter a valid project name.");
        }
    }

    @FXML
    protected void PostBack_f() throws Exception {
        ConnectED_MainApp.switchScene("MainFrame.fxml");
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        try {
            upload();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private static String getNewFileName(Path destinationPath) {
        String fileName = destinationPath.getFileName().toString();
        String fileNameWithoutExtension = fileName.substring(0, fileName.lastIndexOf('.'));
        String fileExtension = fileName.substring(fileName.lastIndexOf('.'));

        int counter = 1;
        Path newDestination = destinationPath.resolveSibling(fileNameWithoutExtension + "_" + counter + fileExtension);

        while (Files.exists(newDestination)) {
            counter++;
            newDestination = destinationPath.resolveSibling(fileNameWithoutExtension + "_" + counter + fileExtension);
        }

        return newDestination.getFileName().toString();
    }
}
