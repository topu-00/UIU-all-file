package org.example.connected;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.io.*;
import java.net.Socket;
import java.net.URL;
import java.util.ResourceBundle;

public class MessengerControll implements Initializable {

    @FXML
    private VBox vBox_R; // Right-side VBox for received messages
    @FXML
    private VBox vBox_M; // Main VBox for both sent and received messages
    @FXML
    private VBox vBox_L; // Left-side VBox (can be used for other purposes)

    // Chat message display area
    @FXML
    private TextArea MessengeTet; // Input box for messages
    @FXML
    private Button SendButton; // Send button
    @FXML
    private Button Back; // Back button
    @FXML
    private Label selectedUserLabel; // Label for selected user
    @FXML
    private ImageView imageView;


    private final String User = LoginControll.getLoggedInUsername(); // Logged-in username
    private Socket socket;
    private PrintWriter out; // For sending messages
    private BufferedReader in; // For receiving messages

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        connectToServer();
        new Thread(this::listenForMessages).start(); // Start listening for messages from the server

        // Set the username on the selectedUserLabel
        loadProfile();
    }



    private void loadProfile() {


        String OldFollower;
        try (BufferedReader br2 = new BufferedReader(new FileReader("src/main/resources/" + User + "/Followers/Followers_List.txt"))) {
            while ((OldFollower = br2.readLine()) != null) {
                if (OldFollower.equals(User)) {
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        String Info;
        int count = 0;
        try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/" + User + "/Bio/biodata.txt"))) {
            while ((Info = br.readLine()) != null) {
                count++;

                Image image = new Image(getClass().getResource("/" + User + "/Profile/Profile.png").toExternalForm());
               imageView.setImage(image);

                if (count == 2) {
                    String[] parts = Info.split(":");
                    Info = Info.trim();

                    selectedUserLabel.setText(parts[1]);
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }







    /**
     * Connect to the chat server.
     */
    private void connectToServer() {
        try {
            // Connect to server at localhost on port 12346
            socket = new Socket("localhost", 12346);
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Send the username to the server
            out.println(User + " has joined the chat!");
        } catch (IOException e) {
            System.out.println("Error connecting to server: " + e.getMessage());
        }
    }

    /**
     * Listen for messages from the server and update the UI.
     */
    private void listenForMessages() {
        try {
            String message;
            while ((message = in.readLine()) != null) {
                String finalMessage = message;
                Platform.runLater(() -> {
                    // Display received messages on the right side
                    Label messageLabel = new Label(finalMessage);
                    messageLabel.setStyle("-fx-background-color: pink; -fx-padding: 10; -fx-border-radius: 10; -fx-background-radius: 10;");
                    messageLabel.setWrapText(true);

                    HBox hbox = new HBox();
                    hbox.setStyle("-fx-alignment: center-left; -fx-spacing: 5;");
                    hbox.getChildren().add(messageLabel);
                    vBox_M.setSpacing(10);
                    vBox_M.getChildren().add(hbox);
                });
            }
        } catch (IOException e) {
            System.out.println("Error reading from server: " + e.getMessage());
        }
    }

    /**
     * Send a message to the server when the send button is clicked.
     */
    @FXML
    protected void sendMessage() {
        String message = MessengeTet.getText().trim(); // Get the text from the input box
        if (!message.isEmpty()) {
            out.println(User + ": " + message); // Send the message to the server

            // Display the sent message on the left side
            Platform.runLater(() -> {
                Label messageLabel = new Label("You: " + message);
                messageLabel.setStyle("-fx-background-color: lightblue; -fx-padding: 10; -fx-border-radius: 10; -fx-background-radius: 10;");
                messageLabel.setWrapText(true);

                HBox hbox = new HBox();
                hbox.setStyle("-fx-alignment: center-right; -fx-spacing: 5;");
                hbox.getChildren().add(messageLabel);
                vBox_M.setSpacing(10);
                vBox_M.getChildren().add(hbox);
            });

            MessengeTet.clear(); // Clear the input box
        }
    }

    /**
     * Handle the Back button click to return to the previous screen.
     */
    @FXML
    protected void BacK_F() throws Exception {
        ConnectED_MainApp.switchScene("MainFrame.fxml"); // Switch to the main frame
        try {
            if (socket != null && !socket.isClosed()) {
                socket.close(); // Close the socket when going back
            }
        } catch (IOException e) {
            System.out.println("Error closing socket: " + e.getMessage());
        }
    }
}
