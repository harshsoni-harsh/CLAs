import javafx.stage.Stage;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.layout.GridPane;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.Button;
import javafx.geometry.Insets;

public class App extends Application {
    public void start(Stage s) {
        s.setTitle("Pizza Hut app");
        Label h1 = new Label("Pizza Hut");
        h1.setFont(Font.font("Arial", FontWeight.EXTRA_BOLD, 15));
        GridPane gp = new GridPane();
        
        Label pizzaSize = new Label("Select your pizza size");
        
        String st[] = {"Small", "Medium", "Large", "Extra Large"};
        ChoiceBox<String> sizes = new ChoiceBox<String>(FXCollections.observableArrayList(st));
        sizes.getSelectionModel().select("Medium");
        
        Label toppings = new Label("Toppings");
        HBox toppingBox = new HBox();
        RadioButton cheese = new RadioButton("cheese");
        RadioButton sauce = new RadioButton("sauce");
        RadioButton mushroom = new RadioButton("mushroom");
        ToggleGroup tg = new ToggleGroup();
        cheese.setToggleGroup(tg);
        sauce.setToggleGroup(tg);
        mushroom.setToggleGroup(tg);
        toppingBox.getChildren().addAll(cheese, sauce, mushroom);
        
        Button generate = new Button("Generate");
        
        Label result = new Label("Result");
        TextField resultVal = new TextField();
        
        generate.setOnAction(e -> {
            String size = sizes.getValue();
            String topping = tg.getSelectedToggle().toString();
            int price = 0;
            
            if (size == "Small") price += 200;
            else if (size == "Medium") price += 300;
            else if (size == "Large") price += 400;
            else if (size == "Extra Large") price += 500;
            
            if (topping.compareTo(sauce.toString()) == 0) {
                price += 50;
            }
            else if (topping.compareTo(mushroom.toString()) == 0) {
                price += 80;
            }
            resultVal.setText(Integer.toString(price));
        });
        
        gp.add(h1, 1, 0);
        gp.add(pizzaSize, 0, 1);
        gp.add(sizes, 2, 1);
        gp.add(toppings, 0, 2);
        gp.add(toppingBox, 2, 2);
        gp.add(generate, 1, 3);
        gp.add(result, 0, 4);
        gp.add(resultVal, 2, 4);
        gp.setHgap(10);
        gp.setVgap(10);

        gp.setPadding(new Insets(10));
        Scene sc = new Scene(gp);
        s.setScene(sc);
        s.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
    
}
