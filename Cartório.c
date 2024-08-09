#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se ao salvamento de strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo no modo de inclus�o
	fprintf(file, ", "); //acrescenta a virgula entre os arquivos 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " e ");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
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
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
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
	file = fopen("%r",cpf); //%r serve para encontrar o arquivo desejado 
	
	if(file == NULL)
	{
		printf("O usurio n�o est� cadastrado no sistema!\n");
		system("pause");
	}
}
  

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
    for(laco=1;laco=1;)	
	{
		
		system("cls"); //respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
     	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar os nomes\n");
    	printf("\t3 - Deletar os nomes\n\n");
     	printf("Esse Software � de livre uso de Vin�cius Moura\n");
    	printf("Op��o: "); //Fim do menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); //respons�vel por limpar a tela
    	
    	
    	
    	switch(opcao)
    	{
    	   case 1:
    	   registro();	//chamada da fun��o registra
		   break;
		   
		   case 2:
		   consulta(); //chamada da fun��o consulta
    	   break;
    	   
    	   case 3:
    	   deletar(); //chamada da fun��o deletar
		   break;
		   
		   default:
		   printf("Essa op��o n�o est� disponivel!\n");
    	   system("pause");	
		   break;
	}

	
}
}
