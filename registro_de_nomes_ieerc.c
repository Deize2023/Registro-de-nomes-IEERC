#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável por cuidar ds string

int registro()// Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite cpf a ser cadastrado: ");//coletando informações do usuário
    scanf("%s" , cpf);//%s refere-se a string
    
    strcpy(arquivo , cpf);//responsavel por criar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); //pasta criando arquivo e o "w" significa escrever
    fprintf(file,cpf);// salva o valor da vareavel
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo,"a");//entra na pasta e "a" significa pasta a ser aberta
    fprintf(file,", ");//adicionando a virgula nos dados adicionados
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");// coletando informações do usuário
    scanf("%s",nome);//%s refere-se a string
    
    file = fopen(arquivo, "a"); //abrindo pasta "a" significa qual e a pasta 
    fprintf(file,nome);//salva valor das variáveis
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//entra na pasta e "a" significa pasta a ser aberta
    fprintf(file,", ");//adicionando a virgula nos dados adicionados
    fclose(file);//fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuário
    scanf("%s",sobrenome);//%s refere-se a string
    
    file = fopen(arquivo,"a");//abrindo pasta "a" significa qual e a pasta 
    fprintf(file, sobrenome);//salva valor das variáveis
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//abrindo pasta "a" significa qual e a pasta 
    fprintf(file,", ");//adicionando a virgula nos dados adicionados
    fclose(file);//fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");// coletando informações do usuário
    scanf("%s",cargo);//%s refere-se a string
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//abrindo pasta "a" significa qual e a pasta 
    fprintf(file, cargo);//adicionando nos dados adicionados cargo
    fclose(file);//fecha o arquivo
    system("pause");//pause
    
}
int consulta()// Função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
    char cpf[40];//delimitando quantidade de caracteres 
	char conteudo[200];
	
	printf("DIgite o CPF a ser consultado : ");	// coletando informações do usuário
	scanf("%s" ,cpf);//%s refere-se a string
	
	FILE*file;//abrir pasta ir em pasta 
	file = fopen(cpf, "r");//em pasta "r" significa ler
	
	if(file == NULL)//comando, se a pasta for igual a nulo 
	{
	    printf("Não foi possivel abrir o arquivo, arquivo não localizado! \n");//adicionando mensagem informação
	} 
	
	while(fgets (conteudo, 200, file) != NULL)//laço de repetição
	{
		printf("\nEssas são as informações do usuário: ");// coletando informações do usuário
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n"); //dando espaço nas palavras
	}
	
	system("pause");//pause
}
int deletar()// Função responsavel por deletar os usuários do sistema
{
    char cpf[40];//delimitando quantidade de caracteres 
    
    printf("Digite o CPF do usuário ser deletado: ");	// coletando informações do usuário
    scanf("%s", cpf);//%s refere-se a string
    
    remove(cpf);//remover 
    
    FILE *file;//abrir pasta ir em pasta 
    file = fopen(cpf, "r");//em pasta "r" significa ler
    
    if(file == NULL)//comando, se a pasta for igual a nulo 
    {
    	printf(" CPF deletado com sucesso! \n O usuário não se encontra no sistema! \n");//informação ao usuário
    	system("pause");//pause
	}
    
}
int main()
    {  
    int opcao=0;// Definindo as variaveis
    int laco=1;
    char senhadigitada[10]="a";
    
    printf("### Cartório Da EBAC ###\n\n");
    printf("Loguin de administrador !\n\n Digite a sua senha:");
    scanf("%s",senhadigitada);
    
    if(senhadigitada[10]=="admin")
    {
	
	   
    	for(laco=1;laco=1;)
    

	    {
    		system("cls");//responsavel porlimpar a tela
		
	        setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
        	printf("### Cartório Da EBAC ###\n\n");//Inicio do menu
    	    printf("Escolha a Opção Desejada Do Menu:\n\n");
            printf("\t1 - Registrar Nomes\n");
    	    printf("\t2 - Consultar Nomes\n");
    	    printf("\t3 - Deletar Nomes\n\n");
    	    printf("Opção: ");//Final do menu
    	    scanf("%d" , &opcao);//Armazenando a escolha do usuario 
    	    system("cls");//responsavel por limpara tela
	        
    	    switch(opcao)
	       {
	        	case 1://Inicio da celeção
	        	registro();//chamada de funções
	            break;//parar
            
                case 2:
                consulta();
	            break;
	        
	            case 3:
		        deletar();
	            break;
	        
	            default:
	            printf("Essa opção não está disponivel!\n");
	            system("pause");
	            break;//Fim da seleção
		    }
    	}
   }
   
   else
       printf("Senha Incorreta!");
}


	
