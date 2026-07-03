package org.example.connected;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;

import java.io.*;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.List;

public class DeleteControll {

    String LoginUser = LoginControll.getLoggedInUsername();

    @FXML
    Button Back;

    @FXML
    protected void BacK_F() throws Exception {
        ConnectED_MainApp.switchScene("ProfileDisplay.fxml");
    }

    @FXML
    Button DeleteAccount;
    @FXML
    VBox DeleteBox;

    @FXML
    protected void setDeleteAccount() {
        TextField userName = new TextField();
        PasswordField passwordField = new PasswordField();
        Button deleteConfirm = new Button("Confirm Delete");
        Label warningLabel = new Label();

        DeleteBox.getChildren().addAll(userName, passwordField, warningLabel, deleteConfirm);

        deleteConfirm.setOnAction(event -> {
            String user = userName.getText().trim();
            if (user.equals(LoginUser)) {
                File userDirectory = new File("src/main/resources/" + LoginUser);
                try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/" + LoginUser + "/Bio/biodata.txt"))) {
                    String pass;
                    while ((pass = br.readLine()) != null) {
                        String[] parts = pass.split(":");
                        if (parts[1].equals(passwordField.getText())) {
                            // Delete user directory
                            deleteNonEmptyDirectory(userDirectory);

                            // Update the All User file
                            if (updateUserFile()) {
                                warningLabel.setText("Account Deleted Successfully");
                                warningLabel.setStyle("-fx-text-fill: green;");
                                ConnectED_MainApp.switchScene("Login.fxml");
                            } else {
                                warningLabel.setText("Failed to update user records.");
                                warningLabel.setStyle("-fx-text-fill: red;");
                            }
                            return; // Stop further processing
                        }
                    }
                    warningLabel.setText("Wrong Information!");
                    warningLabel.setStyle("-fx-text-fill: red;");
                } catch (Exception e) {
                    System.out.println("Error reading user bio: " + e.getMessage());
                }
            } else {
                warningLabel.setText("Username mismatch!");
                warningLabel.setStyle("-fx-text-fill: red;");
            }
        });
    }

    /**
     * Updates the All User file by removing the deleted user's record.
     *
     * @return true if the update is successful, false otherwise.
     */
    private boolean updateUserFile() {
        File userFile = new File("src/main/resources/All User/User.txt");
        List<String> allUsers = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(userFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(":");
                if (!LoginUser.equals(parts[1])) {
                    allUsers.add(line);
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading user file: " + e.getMessage());
            return false;
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(userFile, false))) {
            for (String remainingUser : allUsers) {
                writer.write(remainingUser);
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Error writing to user file: " + e.getMessage());
            return false;
        }

        return true;
    }

    /**
     * Deletes a non-empty directory and all its contents.
     *
     * @param directory the directory to delete
     */
    private void deleteNonEmptyDirectory(File directory) {
        try {
            Path directoryPath = directory.toPath();
            Files.walk(directoryPath)
                    .sorted((path1, path2) -> path2.compareTo(path1)) // Delete files before directories
                    .forEach(path -> {
                        try {
                            Files.delete(path);
                        } catch (IOException e) {
                            System.out.println("Error deleting: " + path + " - " + e.getMessage());
                        }
                    });
        } catch (IOException e) {
            System.out.println("Error while deleting directory: " + e.getMessage());
        }
    }
}
