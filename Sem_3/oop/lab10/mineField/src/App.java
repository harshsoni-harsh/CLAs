import java.util.Random;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.Node;

public class App extends Application {
    static int count = 0;
    public void start(Stage s) {
        BorderPane bp = new BorderPane();
        Label wel = new Label("< Welcome to the MineField Game >");
        wel.setFont(Font.font("Arial", 15));
        Label tf = new Label("");
        tf.setFont(Font.font("Arial", FontWeight.BOLD, 20));
        tf.setAlignment(Pos.CENTER);
        VBox vb = new VBox(wel, tf);
        vb.setSpacing(15);
        vb.setAlignment(Pos.CENTER);
        bp.setTop(vb);

        GridPane gp = startGame(tf);

        bp.setCenter(gp);
        bp.setPadding(new Insets(40));
        Scene sc = new Scene(bp);
        s.setScene(sc);
        s.show();
    }
    public GridPane startGame(Label tf) {
        GridPane gp = new GridPane();
        Background blue = new Background(new BackgroundFill(Color.BLUE, CornerRadii.EMPTY, Insets.EMPTY));
        Background red = new Background(new BackgroundFill(Color.RED, CornerRadii.EMPTY, Insets.EMPTY));
        Background white = new Background(new BackgroundFill(Color.WHITE, CornerRadii.EMPTY, Insets.EMPTY));
        int width = 40;
        for (int i=0; i<5; i++) {
            for (int j=0; j<4; j++) {
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
                        tf.setText("</ Congratulations You Won!! >");
                    }
                    b.setBackground(white);
                });
                gp.add(b, i, j);
            }
        }

        Random rand = new Random();
        int i = rand.nextInt(4);
        int j = rand.nextInt(3);
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
                        tf.setText("</ You Lose!!! >");
                        button.setBackground(red);
                    });
                
                }
            }
        }
        gp.setMinWidth(300);
        gp.setMinHeight(300);
        gp.setAlignment(Pos.CENTER);
        return gp;
    }
    public static void main(String[] args) {
        launch(args);
    }
}
