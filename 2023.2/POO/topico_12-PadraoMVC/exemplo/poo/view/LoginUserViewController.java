package poo.view;

import poo.model.Model;
import poo.model.Usuario;

public class LoginUserViewController implements Observer{
	private Model model;
	private LoginUserView view;
	
	public void initLoginUserViewController(Model model, LoginUserView view) {
		this.model = model;
		this.view = view;
		model.attachObserver(this);
	}
	public void handleEvent(String event) {
		switch (event) {
		case "OK" :
			Usuario usuario = model.autenticarUsuario(view.getLogin(), view.getSenha());
			if (usuario == null) {
				view.exibeMSG("ERRO: Usuario e/ou Senha invalidos!");				
			} else {
				view.exibeMSG("SUCESSO: Usuario autenticado!");
			}
			model.detachObserver(this);
			break;
		}
	}

	public void update() {
	}
}
