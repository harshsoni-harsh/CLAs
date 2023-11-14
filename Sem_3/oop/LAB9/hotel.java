import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.control.ToggleGroup;
import javafx.stage.Stage;
import javafx.scene.control.TextField;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

public class hotel extends Application {
    public void start(Stage s) {
        HBox hb1 = new HBox();
        ToggleGroup tg1 = new ToggleGroup();
        RadioButton bt1 = new RadioButton("Parkside for 4000 per day");
        RadioButton bt2 = new RadioButton("Poolside for 5000 per day");
        RadioButton bt3 = new RadioButton("Lakeside for 6000 per day");
        bt1.setToggleGroup(tg1);
        bt2.setToggleGroup(tg1);
        bt3.setToggleGroup(tg1);
        hb1.getChildren().addAll(bt1, bt2, bt3);

        HBox hb2 = new HBox();
        ToggleGroup tg2 = new ToggleGroup();
        RadioButton bt21 = new RadioButton("1");
        RadioButton bt22 = new RadioButton("2");
        RadioButton bt23 = new RadioButton("3");
        bt21.setToggleGroup(tg2);
        bt22.setToggleGroup(tg2);
        bt23.setToggleGroup(tg2);
        hb2.getChildren().addAll(bt21, bt22, bt23, new Label("  (Price: 1000 per bedroom)"));

        HBox hb3 = new HBox();
        ToggleGroup tg3 = new ToggleGroup();
        RadioButton bt31 = new RadioButton("Yes");
        RadioButton bt32 = new RadioButton("No");
        bt31.setToggleGroup(tg3);
        bt32.setToggleGroup(tg3);
        hb3.getChildren().addAll(bt31, bt32, new Label("  (Price: 200)"));

        hb1.setSpacing(15);
        hb2.setSpacing(15);
        hb3.setSpacing(15);

        TextField tf = new TextField("0");
        Button button = new Button("Generate Bill");

        GridPane g = new GridPane();
        g.addRow(0, new Label("Select your location: "), hb1);
        g.addRow(1, new Label("Select number of bed rooms: "), hb2);
        g.addRow(2, new Label("Include meals? "), hb3);
        g.addRow(3, button);
        g.addRow(4, new Label("Total Amount: "), tf);
        g.setHgap(10);
        g.setVgap(10);
        g.setAlignment(Pos.CENTER);
        g.setPadding(new Insets(25));

        button.setOnAction(e -> {
            int a = 0;
            if (bt1.isSelected()) {
                a += 4000;
            }
            else if (bt2.isSelected()) {
                a += 5000;
            }
            else if (bt3.isSelected()) {
                a += 6000;
            }

            if (bt21.isSelected()) {
                a += 1000;
            }
            else if (bt22.isSelected()) {
                a += 2000;
            }
            else if (bt23.isSelected()) {
                a += 3000;
            }

            if (bt31.isSelected()) {
                a += 200;
            }
            tf.setText(String.valueOf(a));
        });

        Scene sc = new Scene(g);
        s.setScene(sc);
        s.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}