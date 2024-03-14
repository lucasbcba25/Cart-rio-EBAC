#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()  //Fun��o resp�savel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[60];
	char sobrenome[60];
	char cargo[60];
	//Final da cria��o de vari�veis/string
	
	printf("Digite seu CPF para se cadastrarm: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo valor da vari�vel
	fclose(file); //fecha arquivo
	
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
	scanf("%s", sobrenome);
	
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

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //Cria arquivo
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado, tente novamente! \n");
		return 1; 
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	return 0;
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no cart�rio! \n");
		system("pause");
	}
		
}

int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("---- Cart�rio da EBAC ----\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n"); //Fim do menu
    	printf("\t4 - Sair do Cart�rio de Registro\n\n");
    	printf("Selecione a op��o desejada:"); //Selecionar a op��o desejada
	
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); //Responsavel por limpar a tela
    	
    	switch(opcao) //Inicio da sele��o do menu
    	{
    	case 1:
		registro(); //Chamada de fun��es
    	break;
    	
    	case 2:
    	consulta();
    	break;
    	
    	case 3:
    	deletar();
    	break;
    	
    	case 4:
    	printf("Obrigado por utilizar nosso Cart�rio de Registro EBAC!\n");
    	return 0;
    	break;
    	
    	default:
    	printf("Essa op��o n�o est� disp�nivel! Tente novamente com uma op��o existente.");
		system("pause");
		break;
		} //Fim da sele��o

    }
 } 
 
 
 
 
