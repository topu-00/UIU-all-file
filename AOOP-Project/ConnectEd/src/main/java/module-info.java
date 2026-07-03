module org.example.connected {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens org.example.connected to javafx.fxml;
    exports org.example.connected;
}