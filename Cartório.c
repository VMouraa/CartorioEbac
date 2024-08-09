#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se ao salvamento de strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo no modo de inclusão
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
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen("%r",cpf); //%r serve para encontrar o arquivo desejado 
	
	if(file == NULL)
	{
		printf("O usurio não está cadastrado no sistema!\n");
		system("pause");
	}
}
  

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
    for(laco=1;laco=1;)	
	{
		
		system("cls"); //responsável por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cartório da EBAC###\n\n"); //Inicio do menu
     	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar os nomes\n");
    	printf("\t3 - Deletar os nomes\n\n");
     	printf("Esse Software é de livre uso de Vinícius Moura\n");
    	printf("Opção: "); //Fim do menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls"); //responsável por limpar a tela
    	
    	
    	
    	switch(opcao)
    	{
    	   case 1:
    	   registro();	//chamada da função registra
		   break;
		   
		   case 2:
		   consulta(); //chamada da função consulta
    	   break;
    	   
    	   case 3:
    	   deletar(); //chamada da função deletar
		   break;
		   
		   default:
		   printf("Essa opção não está disponivel!\n");
    	   system("pause");	
		   break;
	}

	
}
}
