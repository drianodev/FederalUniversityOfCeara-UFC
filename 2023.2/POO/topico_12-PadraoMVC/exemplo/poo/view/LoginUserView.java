package poo.view;

import java.util.*;
import poo.model.*;

/*
 * Classe de View - o único lugar que pode enviar System.out.println para views do prompt de comando
 */
public class LoginUserView implements Observer {
	private Model model;
	private LoginUserViewController controller;
	private String login;
	private String senha;

	public void initLoginUserView(Model model) {
		this.model = model;
		controller = new LoginUserViewController();
		controller.initLoginUserViewController(model, this);
		model.attachObserver(this);
		logarUsuario();
	}

	public void logarUsuario() {
		Scanner sc = new Scanner(System.in);
		System.out.println("TELA DE LOGIN");
		System.out.println("======================");
		System.out.println();
		System.out.print("Login: ");
		login = sc.nextLine();
		System.out.print("Senha: ");
		senha = sc.nextLine();
		controller.handleEvent("OK");
		model.detachObserver(this);
		// sc.close();
	}

	public String getLogin() {
		return login;
	}

	public String getSenha() {
		return senha;
	}

	public void update() {

	}

	public void exibeMSG(String msg) {
		System.out.println();
		System.out.println(msg);
		System.out.println();
	}
}