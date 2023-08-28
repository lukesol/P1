#include <iostream>
using namespace std;

#define max_padrao 30
#define teto_limite_max 100

/// @brief Realiza um printf com as instruções de uso.
void usoCorreto(){
	cout << "===================================================" << endl;
	cout << "Maneira de usar: ./hot_cold [<limite_maximo>]" << endl;
	cout << "onde <limite_maximo> é o valor máximo para ser advinhado (padrão: 30)." << endl;
	cout << "o intervalo de número para ser descoberto é definido por [1,<limite_maximo>]." << endl;
	cout << "===================================================" << endl;
}

/// @brief Inicia o jogo com o valor máximo do intervalo.
/// @param valorMaximo 
void iniciarJogo(int valorMaximo){
	int palpite_usuario;
	int numero_gerado;

	srand(time(0));
	numero_gerado = 1 + (rand() % valorMaximo);

	// Debugando o valor gerado pela máquina.
		// cout << "valor gerado pela máquina" << numero_gerado << endl;
	cout << ">>> Advinhe o número: ";
	cin >> palpite_usuario;

		if(palpite_usuario < 0){
			cout << endl << "===================================================" << endl;
			cout << ">>> Muito obrigado por jogar e até a próxima ;)" << endl;
			cout << "===================================================" << endl;
			exit(1);	
		}else{
				while (palpite_usuario != numero_gerado){
					if(palpite_usuario < 0){
						cout << ">>> Muito obrigado por jogar e até a próxima ;)" << endl;
						exit(1);
					}else{

						int diferenca{palpite_usuario - numero_gerado};
						if(diferenca < 0) diferenca = diferenca*-1;

						if(diferenca >= 20 && diferenca <= 100){
							cout << ">>> Frio demais rapaz, tente de novo: ";
						}else if(diferenca >= 10 && diferenca < 20){
							cout << ">>> Frio, mas ta ficando quente, tente um novo número: ";
						}else if(diferenca >= 5 && diferenca < 10){
							cout << ">>> Está mais quente, tente de novamente: ";
						}else if(diferenca >= 3 && diferenca < 5){
							cout << ">>> Ta quente homi, insira outro número: ";
						}else if(diferenca >= 1 && diferenca < 3){
							cout << ">>> Afe maria, quente demais homi, digite de novo: ";
						}
							// Testando o intervalo da diferença mais próxima de uma experiência aceitável.
								// cout << endl << ">>> Diferença: " << diferenca << endl << ">>>";
							cin >> palpite_usuario;
						}
				}
			}
		cout << endl << "===================================================" << endl;
		cout << ">>> Aee, o homi é bom viu" << endl;
		cout << ">>> Muito obrigado por jogar e até a próxima ;)" << endl;
		cout << "===================================================" << endl;
		exit(1);
}

/// @brief Exibe as regras do jogo antes de iniciar.
/// @param valorMaximo 
void exibirRegras(int valorMaximo) {
  cout << "===================================================\n";
  cout << "Bem vindo ao jogo de advinhar 'quenteOUfrio' ou 'hot_cold', copyright 2023.\n";
  cout << "---------------------------------------------------\n";
  cout << "Aqui estão as regras do jogo:\n";
  cout << "    * Eu vou escolher um número aleatório em [1," << valorMaximo
       << "]. Seu trabalho é advinhar esse número.\n";
  cout << "    * Eu vou te dizer se";
  cout << "      está quente (mais próximo que a tentativa anterior) ou frio (mais distante\n";
  cout << "      que a tentativa anterior).\n";
  cout << "    * Se desejar encerrar o jogo, basta inserir um número negativo.\n";
  cout << "      Boa sorte!\n";
  cout << "----------------------------------------------------\n";
  iniciarJogo(valorMaximo);
}

/// @brief Lê os argumentos de entrada, checa a quantidade e retornar um resultado.
/// @param argc 
/// @param argv
auto checarEntrada(int argc, char* argv[]){
	int max_usuario{max_padrao};

	if(argc > 2){
		cout << "Quantidade de argumentos inválida." << endl;
		usoCorreto();
		exit(1);
	}else if(argc == 2){
		if(stoi(argv[1]) > teto_limite_max){
			cout << "Quantidade do <limite_maximo> muito alta (máximo: " << teto_limite_max << ")" << endl
			<< "Não precisa ficar tanto tempo aqui :D" << endl;
			usoCorreto();
			exit(1);
		}else if(stoi(argv[1]) < 1){
			cout << "Quantidade do <limite_maximo> muita baixa (mínimo: 1)" << endl
			<< "Assim também não né xD" << endl;
			usoCorreto();
			exit(1);
		}else if(stoi(argv[1]) < 0){
			cout << "Vá com Deus." << endl;
			exit(1);
		}
			max_usuario = stoi(argv[1]);
			
	}
		return max_usuario;
}


int main(int argc, char* argv[]){

	auto max_usuario_retorno{checarEntrada(argc,argv)};

	exibirRegras(max_usuario_retorno);


	return 0;
}
