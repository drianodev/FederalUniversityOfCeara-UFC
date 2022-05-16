def saudacoes(msg: str) -> str:
	if msg == "Later!":
		return "Alligator!"
	qnt = msg.count('e')
	if msg[0] == 'h' and msg[-1] == 'y' and qnt == len(msg) - 2:
		return f"h{ (qnt * 2) * 'e' }y"
	return msg

msg = input("Digite a saudação: ")

print(saudacoes(msg))
