#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings


int registro() //fun��o responsavel por cadastrar o usu�rio no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char profissao[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coleta informa��es do usuario
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite a profiss�o a ser cadastrada: ");
	scanf("%s", profissao);
	
	file = fopen(arquivo, "a");
	fprintf(file,profissao);
	fclose(file);

}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
		fclose(file);
	}
	
}


int main()
{
	
	int opcao=0; //Definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls"); //limpa asinforma��es da tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	
		printf("### Cart�rio da EBAC ###\n \n"); //inicio do menu
		printf("Escolha a op��o desejada abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Op��o: "); // fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usuario
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
				registro(); //chamada da fun��o de registro
			break;
			
			case 2:
				consultar(); //chamada da fun��o de consultar
			break;
			
			case 3:
				deletar(); //chamada da fun��o de deletar
			break;
			
			default:
				printf("Essa op��o n�o est� disponivel no momento!\n");
			system("pause");
			break;	
			//fim da sele��o
			
		}
		
	
	
	}
	
}


