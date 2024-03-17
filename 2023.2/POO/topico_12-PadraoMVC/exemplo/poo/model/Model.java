package poo.model;

import java.util.HashMap;
import java.util.ArrayList;
import poo.view.*;

/*
 * Classe Modelo que provê alguns dados e serviços para views e controllers
 */
public class Model {
	private HashMap<String,Usuario> usuarios = new HashMap<String, Usuario>(); // Usuários do sistema
	private Usuario usuarioAutenticado;	// Usuário autenticado pelo sistema
	private ArrayList<Observer> observers = new ArrayList<Observer>(); // Lista de observadores interessados no modelo
	
	/*
	 * Método utilizado para notificar todos os observadores contidos no ArrayList que o modelo mudou
	 */
	public void notifica() {
		for (Observer o : observers) {
			o.update(); // update é a operação definida na interface Observer
		}
	}
	
	/*
	 * Devolve um usuário do mapeamento
	 */
	public Usuario getUsuario(String login) {
		if (login != null) {
			Usuario usuario = usuarios.get(login);
			return usuario;
		}
		return null;
	}
	
	/*
	 * Adiciona um usuário no mapeamento
	 */
	public void setUsuario(Usuario usuario) {
		if (usuario != null && usuario.getLogin() != null) {
			usuarios.put(usuario.getLogin(), usuario);
			notifica();
		}
	}
	
	/*
	 * Serviço para autenticar um usuário
	 */
	public Usuario autenticarUsuario(String login, String senha) {
		Usuario usuario;
		if (login != null && senha != null) {
			usuario = usuarios.get(login);
			if (usuario != null) {
				if (login.equals(usuario.getLogin()) && senha.equals(usuario.getSenha())){
					usuarioAutenticado = usuario;					
				}
			}
		}
		return usuarioAutenticado;
	}
	
	/*
	 * Desloga um usuário do sistema
	 */
	public void deslogarUsuario() {
		usuarioAutenticado = null;
		notifica();
	}
	
	/*
	 * Devolve o usuário autenticado. Se não tiver nenhum usuário autenticado ele devolve null
	 */
	public Usuario getUsuarioAutenticado() {
		return usuarioAutenticado;
	}

	/*
	 * Registra um observador na lista de observadores
	 */
	public void attachObserver(Observer observer) {
		if (observer != null) {
			observers.add(observer);
		}		
	}
	
	/*
	 * Exclui um observador da lista de observadores
	 */
	public void detachObserver(Observer observer) {
		if (observer != null) {
			observers.remove(observer);
		}
	}
	
	/*
	 * Informa o total de usuários cadastrados
	 */
	public int getTotalUsuarios() {
		return usuarios.size();
	}
}