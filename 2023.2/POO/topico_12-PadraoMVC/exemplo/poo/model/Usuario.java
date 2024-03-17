package poo.model;

/*
 * Classe de entidade: USUARIO
 */
public class Usuario {
	private String nome;	// nome completo do usuário
	private String login;	// login do usuário
	private String senha;	// senha do usuário
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		if (nome != null) {
			this.nome = nome;
		}
	}
	
	public String getLogin() {
		return login;
	}
	
	public void setLogin(String login) {
		if (login != null) {
			this.login = login;
		}
	}
	
	public String getSenha() {
		return senha;
	}
	
	public void setSenha(String senha) {
		if (senha != null) {
			this.senha = senha;
		}
	}
	
	public String toString() {
		return nome + " " + login;
	}
}
