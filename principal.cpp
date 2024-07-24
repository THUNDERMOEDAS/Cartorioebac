#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

	int registro()//função responsavel por cadastrar os usários no sistema
	{
		//inicio da criação de variáveis/string(string conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o (w) significa esrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");	
	}
	int consulta()//consultando a string
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		FILE *file;
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Não foi possivel abrir esse arquivo, não localizado!.\n");	
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas sao as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
			
	}
	int deletar()
	{
		char cpf[40];
		
		printf("Digite o CPF do uasuário a ser deletado: ");
		scanf("%s",cpf);
		
		FILE *file;//expecificando o arquivo  
		file = fopen(cpf,"r");//abrindo o arquivo 
		fclose(file);//fechando o arquivo
		
		if(file == NULL) //conferindo se nao tem nada no arquvo 
		{
			printf("\nCPF não encontrado!\n\n");
			system("pause");
		}
		
		remove(cpf);
		
		if(file != NULL)//conferindo se tem alguma coisa no arquivo
		{
				printf("\n\nUsuário deletado!.\n\n");
				system("pause");
		}
	
	}	
			
int main()
    {
	int opcao=0; //Definindo variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		setlocale(LC_ALL, "Portuguese");
		
		system("cls");//responsável por limpar a tela 
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registro de nomes\n");
		printf("\t2 - Consulta de nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opçao: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");
		
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções 
	    	break;
	    	case 2:
	    	consulta();
	    	break; 
	    	case 3:
	    	deletar();
			break;
			default:
				printf("Essa opcão não esta disponivel!\n");
			system("pause");
			break;
				
		}
	}
}
