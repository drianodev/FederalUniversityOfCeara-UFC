package poo.view;

import poo.model.Model;
import poo.model.Usuario;

public class NewUserViewController implements Observer{
	private Model model;
	private NewUserView view;
	
	public void initNewUserViewController(Model model, NewUserView view) {
		this.model = model;
		this.view = view;
		model.attachObserver(this);
	}
	public void handleEvent(String event) {
		switch (event) {
		case "OK" :
			Usuario usuario = new Usuario();
			usuario.setLogin(view.getLogin());
			usuario.setNome(view.getNome());
			usuario.setSenha(view.getSenha());
			model.setUsuario(usuario);
			model.detachObserver(this);
			break;			
		}
	}

	public void update() {
	}
}
