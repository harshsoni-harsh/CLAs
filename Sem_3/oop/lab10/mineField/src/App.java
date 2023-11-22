import java.util.Random;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.Node;

public class App extends Application {
    static int count = 0;
    public void start(Stage s) {
        BorderPane bp = new BorderPane();
        TextField tf = new TextField();
        bp.setTop(tf);

        GridPane gp = startGame(tf);

        bp.setCenter(gp);
        bp.setPadding(new Insets(10));
        Scene sc = new Scene(bp);
        s.setScene(sc);
        s.show();
    }
    public GridPane startGame(TextField tf) {
        GridPane gp = new GridPane();
        Background blue = new Background(new BackgroundFill(Color.BLUE, CornerRadii.EMPTY, Insets.EMPTY));
        Background red = new Background(new BackgroundFill(Color.RED, CornerRadii.EMPTY, Insets.EMPTY));
        Background white = new Background(new BackgroundFill(Color.WHITE, CornerRadii.EMPTY, Insets.EMPTY));
        int width = 40;
        for (int i=0; i<4; i++) {
            for (int j=0; j<5; j++) {
                Button b = new Button();
                b.setBackground(blue);
                b.setStyle("-fx-border-color: grey;");
                b.setId(Integer.toString(i*10+j));
                b.setMinWidth(width);
                b.setMinHeight(width);
                b.setMaxWidth(width);
                b.setMaxHeight(width);
                b.setOnAction(e -> {
                    count++;
                    if (count == 10) {
                        tf.setText("Congratulations");
                    }
                    b.setBackground(white);
                });
                gp.add(b, i, j);
            }
        }

        Random rand = new Random();
        int i = rand.nextInt(4);
        int j = rand.nextInt(5);
        for (Node n : gp.getChildren()) {
            if (n instanceof Button) {
                Button button = (Button) n;
                if (button.getId().equals(Integer.toString(10*i+j))) {

                    button.setOnAction(e -> {
                        for (Node p : gp.getChildren()) {
                            Button b = (Button) p;
                            b.setBackground(white);
                        }
                        count = 0;
                        tf.setText("Failed");
                        button.setBackground(red);
                    });
                
                }
            }
        }
        return gp;
    }
    public static void main(String[] args) {
        launch(args);
    }
}
