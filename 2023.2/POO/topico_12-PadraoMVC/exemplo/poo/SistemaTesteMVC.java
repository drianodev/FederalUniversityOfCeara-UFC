package poo;

import poo.model.*;
import poo.view.*;

public class SistemaTesteMVC {

	public static void main(String[] args) {
		Model model = new Model(); // Primeiro instancia-se o modelo
		MainView view = new MainView(); // Depois cria-se a primeira view
		view.initMainView(model); // Por fim, inicializa a view passando o modelo
	}
}
