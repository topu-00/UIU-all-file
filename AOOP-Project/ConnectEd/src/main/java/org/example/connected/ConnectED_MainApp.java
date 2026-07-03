package org.example.connected;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class ConnectED_MainApp extends Application {
    private static Stage primaryStage;

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(ConnectED_MainApp.class.getResource("Login.fxml"));
        primaryStage = stage;

        Scene scene = new Scene(fxmlLoader.load(), 1430, 785);
        stage.setTitle("ConnectEd");
        stage.setScene(scene);
        stage.show();
    }

    public static void switchScene(String fxmlFile) throws Exception {
        Parent root = FXMLLoader.load(ConnectED_MainApp.class.getResource(fxmlFile));
        primaryStage.setScene(new Scene(root));
    }

    public static void main(String[] args) {
        launch();
    }
}