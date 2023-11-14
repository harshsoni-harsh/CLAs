import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.geometry.Insets;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;

public class calculator extends Application {
    public void start(Stage s) {
        VBox vb = new VBox();
        
        HBox hb = new HBox();
        TextField tf1 = new TextField();
        TextField tf2 = new TextField();
        TextField tf3 = new TextField();
        hb.getChildren().addAll(new Label("Num 1 :"), tf1);
        HBox hb1 = new HBox();
        hb1.getChildren().addAll(new Label("Num 2 :"), tf2);

        HBox hb2 = new HBox();
        Button btMul = new Button("*");
        Button btDiv = new Button("/");
        Button btAdd = new Button("+");
        Button btMin = new Button("-");
        hb2.getChildren().addAll(btMul, btDiv, btAdd, btMin);
        hb2.setSpacing(10);

        HBox hb3 = new HBox();
        hb3.getChildren().addAll(new Label("Result  :"), tf3);
        
        vb.getChildren().addAll(hb, hb1, hb3, hb2);
        vb.setSpacing(10);
        vb.setPadding(new Insets(10));


        btAdd.setOnAction(e -> {
            Double a = Double.parseDouble(tf1.getText());
            Double b = Double.parseDouble(tf2.getText());
            String c = "" + (a+b);
            tf3.setText(c);
        });
        btMul.setOnAction(e -> {
            Double a = Double.parseDouble(tf1.getText());
            Double b = Double.parseDouble(tf2.getText());
            String c = "" + (a*b);
            tf3.setText(c);
        });
        btMin.setOnAction(e -> {
            Double a = Double.parseDouble(tf1.getText());
            Double b = Double.parseDouble(tf2.getText());
            String c = "" + (a-b);
            tf3.setText(c);
        });
        btDiv.setOnAction(e -> {
            Double a = Double.parseDouble(tf1.getText());
            Double b = Double.parseDouble(tf2.getText());
            String c = "" + (a/b);
            tf3.setText(c);
        });
        
        Scene sc = new Scene(vb);
        s.setScene(sc);
        s.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}