#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar ds string

int registro()// Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite cpf a ser cadastrado: ");//coletando informa��es do usu�rio
    scanf("%s" , cpf);//%s refere-se a string
    
    strcpy(arquivo , cpf);//responsavel por criar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); //pasta criando arquivo e o "w" significa escrever
    fprintf(file,cpf);// salva o valor da vareavel
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo,"a");//entra na pasta e "a" significa pasta a ser aberta
    fprintf(file,", ");//adicionando a virgula nos dados adicionados
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");// coletando informa��es do usu�rio
    scanf("%s",nome);//%s refere-se a string
    
    file = fopen(arquivo, "a"); //abrindo pasta "a" significa qual e a pasta 
    fprintf(file,nome);//salva valor das vari�veis
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//entra na pasta e "a" significa pasta a ser aberta
    fprintf(file,", ");//adicionando a virgula nos dados adicionados
    fclose(file);//fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es do usu�rio
    scanf("%s",sobrenome);//%s refere-se a string
    
    file = fopen(arquivo,"a");//abrindo pasta "a" significa qual e a pasta 
    fprintf(file, sobrenome);//salva valor das vari�veis
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//abrindo pasta "a" significa qual e a pasta 
    fprintf(file,", ");//adicionando a virgula nos dados adicionados
    fclose(file);//fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");// coletando informa��es do usu�rio
    scanf("%s",cargo);//%s refere-se a string
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//abrindo pasta "a" significa qual e a pasta 
    fprintf(file, cargo);//adicionando nos dados adicionados cargo
    fclose(file);//fecha o arquivo
    system("pause");//pause
    
}
int consulta()// Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
    char cpf[40];//delimitando quantidade de caracteres 
	char conteudo[200];
	
	printf("DIgite o CPF a ser consultado : ");	// coletando informa��es do usu�rio
	scanf("%s" ,cpf);//%s refere-se a string
	
	FILE*file;//abrir pasta ir em pasta 
	file = fopen(cpf, "r");//em pasta "r" significa ler
	
	if(file == NULL)//comando, se a pasta for igual a nulo 
	{
	    printf("N�o foi possivel abrir o arquivo, arquivo n�o localizado! \n");//adicionando mensagem informa��o
	} 
	
	while(fgets (conteudo, 200, file) != NULL)//la�o de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");// coletando informa��es do usu�rio
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n"); //dando espa�o nas palavras
	}
	
	system("pause");//pause
}
int deletar()// Fun��o responsavel por deletar os usu�rios do sistema
{
    char cpf[40];//delimitando quantidade de caracteres 
    
    printf("Digite o CPF do usu�rio ser deletado: ");	// coletando informa��es do usu�rio
    scanf("%s", cpf);//%s refere-se a string
    
    remove(cpf);//remover 
    
    FILE *file;//abrir pasta ir em pasta 
    file = fopen(cpf, "r");//em pasta "r" significa ler
    
    if(file == NULL)//comando, se a pasta for igual a nulo 
    {
    	printf(" CPF deletado com sucesso! \n O usu�rio n�o se encontra no sistema! \n");//informa��o ao usu�rio
    	system("pause");//pause
	}
    
}
int main()
    {  
    int opcao=0;// Definindo as variaveis
    int laco=1;
    char senhadigitada[10]="a";
    
    printf("### Cart�rio Da EBAC ###\n\n");
    printf("Loguin de administrador !\n\n Digite a sua senha:");
    scanf("%s",senhadigitada);
    
    if(senhadigitada[10]=="admin")
    {
	
	   
    	for(laco=1;laco=1;)
    

	    {
    		system("cls");//responsavel porlimpar a tela
		
	        setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
        	printf("### Cart�rio Da EBAC ###\n\n");//Inicio do menu
    	    printf("Escolha a Op��o Desejada Do Menu:\n\n");
            printf("\t1 - Registrar Nomes\n");
    	    printf("\t2 - Consultar Nomes\n");
    	    printf("\t3 - Deletar Nomes\n\n");
    	    printf("Op��o: ");//Final do menu
    	    scanf("%d" , &opcao);//Armazenando a escolha do usuario 
    	    system("cls");//responsavel por limpara tela
	        
    	    switch(opcao)
	       {
	        	case 1://Inicio da cele��o
	        	registro();//chamada de fun��es
	            break;//parar
            
                case 2:
                consulta();
	            break;
	        
	            case 3:
		        deletar();
	            break;
	        
	            default:
	            printf("Essa op��o n�o est� disponivel!\n");
	            system("pause");
	            break;//Fim da sele��o
		    }
    	}
   }
   
   else
       printf("Senha Incorreta!");
}


	
