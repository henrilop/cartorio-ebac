#include <stdio.h>  //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de aloçação de espaco em memória
#include <locale.h> //biblioteca de aloçacões de texto por região
#include <string.h> //biblioteca responsavel por cuidar dos string

int registro()  // Funcçao responsavel por cadastrar os usuarios no sistema
{
	//inicio criaçao de variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criacao de variaveis/string
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s", cpf); //%s refere-se a string
   
   strcpy(arquivo, cpf); //responsavel por copiar os valores das string
   
   FILE *file; // cria o arquivo
   file = fopen(arquivo,"w"); // cria o arquivo e o"w" significa escrever
   fprintf(file,cpf); //salvo o valor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado:");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file, nome);
   fclose(file);
  
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado:");
   scanf("%s", sobrenome);
   
    file = fopen(arquivo,"a");
   fprintf(file,sobrenome);
   fclose(file);
   
    file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado:");
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
   } 
    
    				
int consulta()
 {
 	
 	setlocale(LC_ALL, "portuguese"); //definindo o idioma
 	 
 	//inicio das variaveis
  	char cpf [40];  
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado. \n");
	   }   
	while(fgets(conteudo, 200, file) !=NULL)
	{ 
	  printf("\nEssas sao as informacoes do usuario:");
	  printf("%s", conteudo);
	  printf("\n\n");
	}
 	system("pause");
 }
 int deletar()
 {
 	
 	char cpf[40];
 	
 	printf("Digite o cpf do usuario a ser deletado ");
 	scanf("%s", cpf);
 	
 	remove(cpf);
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file == NULL)
     {
     	printf("O usuario nao se encontra no sistema!.\n");
     	system("pause");
	 }
	 
 	
 }
  int main() 
  { 
   int opcao=0; //definindo as variaveis
   int laco=1;
   
   for(laco=1;laco=1;)
   { 
     
  system("cls");  
   
    setlocale(LC_ALL, "portuguese-brazilian"); //definindo a linguagem 
    
    printf("###cartorio da ebac###\n\n"); //inicio do menu
    printf("escolha a opcao desejada do menu:\n\n");
    printf("\t1-registrar nomes\n");
    printf("\t2-consultar nomes\n");
    printf("\t3- deletar nomes\n\n"); 
    printf("\t4- sair do sistema\n");
    
	printf("opcao: "); //fim do menu
     
    scanf("%d", &opcao); //armazenando a escolha do usuario
    
    system("cls");// para limpar a tela
    
    system("cls");
    switch(opcao)
    {  case 1:
       registro(); //chamada de funcoes
       break;
     
	   case 2:
       consulta();
       break;
      
       case 3:
	   deletar();
	   break;
	   
	   case 4:
	   printf("Obrigado por usar o sistema");
	   return 0;
	   break;
	   
	   default:
	   printf("essa opcao nao esta disponivel!\n");
	   system ("pause");
       break;	
	  
	  }//fim da seleçao  
     
}
}
 
