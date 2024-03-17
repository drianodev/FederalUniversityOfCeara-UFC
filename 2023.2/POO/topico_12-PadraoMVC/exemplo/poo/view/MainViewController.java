package poo.view;

import poo.model.*;
public class MainViewController implements Observer{
	private Model model;	// Guarda o modelo a ser utilizado
	private MainView view;	// Guarda a view a ser controlada
	
	/*
	 * Inicialização do controller da view principal
	 */
	public void initMainViewController(Model model, MainView view) {
		this.model = model;  // Guarda o modelo
		this.view = view;	 // Guarda a view
	}
	
	/*
	 * O controller só implementa o update se for necessário
	 */
	public void update() {
		
	}

	/*
	 * Utilizado para verificar o que deve ser feito em resposta ao evento que aconteceu na view
	 */
	public void handleEvent(String event) {
		switch (event) {
		case "1" : if (model.getUsuarioAutenticado() == null) {
					   LoginUserView view3 = new LoginUserView(); // ir para tela de login
				       view3.initLoginUserView(model);
				   } else {
					   model.deslogarUsuario();
				   }
				   break;
		case "2" : NewUserView view2 = new NewUserView(); // ir para tela de cadastro de usuário
				   view2.initNewUserView(model);
				   break;
		case "3" : view.finalizarSistema(); break;	// finalizar sistema
		}
	}
}
