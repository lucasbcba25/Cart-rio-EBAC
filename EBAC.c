#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()  //Função respósavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[60];
	char sobrenome[60];
	char cargo[60];
	//Final da criação de variáveis/string
	
	printf("Digite seu CPF para se cadastrarm: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo valor da variável
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
		printf("Arquivo não encontrado, tente novamente! \n");
		return 1; 
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	return 0;
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no cartório! \n");
		system("pause");
	}
		
}

int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("---- Cartório da EBAC ----\n\n"); //inicio do menu
	    printf("Escolha a opção desejada no menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n"); //Fim do menu
    	printf("\t4 - Sair do Cartório de Registro\n\n");
    	printf("Selecione a opção desejada:"); //Selecionar a opção desejada
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls"); //Responsavel por limpar a tela
    	
    	switch(opcao) //Inicio da seleção do menu
    	{
    	case 1:
		registro(); //Chamada de funções
    	break;
    	
    	case 2:
    	consulta();
    	break;
    	
    	case 3:
    	deletar();
    	break;
    	
    	case 4:
    	printf("Obrigado por utilizar nosso Cartório de Registro EBAC!\n");
    	return 0;
    	break;
    	
    	default:
    	printf("Essa opção não está dispónivel! Tente novamente com uma opção existente.");
		system("pause");
		break;
		} //Fim da seleção

    }
 } 
 
 
 
 
