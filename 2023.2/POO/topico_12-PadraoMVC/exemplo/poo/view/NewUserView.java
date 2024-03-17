package poo.view;

import java.util.*;
import poo.model.*;

/*
 * Classe de View - o único lugar que pode enviar System.out.println para views do prompt de comando
 */
public class NewUserView implements Observer {
	private Model model;
	private NewUserViewController controller;
	private String nome;
	private String login;
	private String senha;

	public void initNewUserView(Model model) {
		this.model = model;
		controller = new NewUserViewController();
		controller.initNewUserViewController(model, this);
		model.attachObserver(this);
		cadastrarUsuario();
	}

	public void cadastrarUsuario() {
		Scanner sc = new Scanner(System.in);
		System.out.println("TELA CADASTRAR USUARIO");
		System.out.println("======================");
		System.out.println();
		System.out.print("Nome: ");
		nome = sc.nextLine();
		System.out.print("Login: ");
		login = sc.nextLine();
		System.out.print("Senha: ");
		senha = sc.nextLine();
		controller.handleEvent("OK");
		model.detachObserver(this);
	}

	public String getNome() {
		return nome;
	}

	public String getLogin() {
		return login;
	}

	public String getSenha() {
		return senha;
	}

	public void update() {

	}
}