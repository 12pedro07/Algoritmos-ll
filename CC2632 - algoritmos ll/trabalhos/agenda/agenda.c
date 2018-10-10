#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct contato{
	char Nome[50];
	char Telefone[20];
	char email[30];
	char RG[16];
	char CPF[20];
	char TSang[4];
	char Convenio[15];
	char Religiao[10];
	char Cidade[20];
	char Estado[2];
};

struct agenda{
	struct contato contatos[100];
	int num_contatos;
};

void trata_gets(char* obj_tratado){
	int i;
	for (i=0;obj_tratado[i]!='\0';i++){
		if (obj_tratado[i] == '\n')
			obj_tratado[i] = '\0';
	}
}

int busca_contato(struct agenda ag, char cont[]){
	int i;
	for (i=0;i<ag.num_contatos;i++){
		if (strcmp(ag.contatos[i].Nome,cont) == 0)
			return i;
	}
	return -1;
}

void encontrar_contato(struct agenda ag){
	
	printf("\n\n-------------------------------------------------------\n\n");
	
	char encontra[50];
	fflush(stdin);
	printf("Por favor digite o nome do contato: ");
	gets(encontra);
	trata_gets(encontra);
	
	int idx = busca_contato(ag,encontra);
	
	if (idx >= 0){
		printf("\n---> Informações:\n");
		printf("Nome: %s\n", ag.contatos[idx].Nome);
		printf("Telefone %s\n", ag.contatos[idx].Telefone);
		printf("e-mail: %s\n", ag.contatos[idx].email);
		printf("RG: %s\n", ag.contatos[idx].RG);
		printf("CPF: %s\n", ag.contatos[idx].CPF);
		printf("Tipo Sanguíneo: %s\n", ag.contatos[idx].TSang);
		printf("Operadora do Convênio: %s\n", ag.contatos[idx].Convenio);
		printf("Religião: %s\n", ag.contatos[idx].Religiao);
		printf("Cidade: %s\n", ag.contatos[idx].Cidade);
		printf("Estado (2 letras): %s\n", ag.contatos[idx].Estado);
	} else {
		printf("\n\n\t\tERRO: CONTATO INEXISTENTE");
	}

	printf("\n\n-------------------------------------------------------\n\n");

}

void mostrar_agenda(struct agenda ag){
	
	printf("\n\n-------------------------------------------------------\n\n");
	
	int i;
	if (ag.num_contatos == 0){
		printf("Agenda Vazia...\n");
		printf("\n\n-------------------------------------------------------\n\n");
		return;
	}
	
	printf("\n\t*** CONTATOS ***\n\nID   Nome\n\n");
	for (i=0 ; i<ag.num_contatos ; i++){
		printf("%d -> %s\n", i, ag.contatos[i].Nome);
	}
	printf("\n---> Numero total de contatos: %d\n",ag.num_contatos);
	
	printf("\n\n-------------------------------------------------------\n\n");
	
}

void inserir_contato(struct agenda* ag){
	
	printf("\n\n-------------------------------------------------------\n\n");
	
	struct contato ctt;
	printf("- Por favor insira as informações pedidas:\n");
	
	// limpando o buffer
	fflush(stdin);
	
	// coletando as informações
	printf("Nome: ");
	fgets(ctt.Nome,51,stdin);
	trata_gets(ctt.Nome);
	
	fflush(stdin);
	printf("Telefone: ");
	fgets(ctt.Telefone,21,stdin);
	trata_gets(ctt.Telefone);
	
	fflush(stdin);
	printf("e-mail: ");
	fgets(ctt.email,31,stdin);
	trata_gets(ctt.email);
	
	fflush(stdin);
	printf("RG: ");
	fgets(ctt.RG,17,stdin);
	trata_gets(ctt.RG);
	
	fflush(stdin);
	printf("CPF: ");
	fgets(ctt.CPF,21,stdin);
	trata_gets(ctt.CPF);
	
	fflush(stdin);
	printf("Tipo Sanguíneo: ");
	fgets(ctt.TSang,5,stdin);
	trata_gets(ctt.TSang);
	
	fflush(stdin);
	printf("Operadora do Convênio: ");
	fgets(ctt.Convenio,16,stdin);
	trata_gets(ctt.Convenio);
	
	fflush(stdin);
	printf("Religião: ");
	fgets(ctt.Religiao,11,stdin);
	trata_gets(ctt.Religiao);
	
	fflush(stdin);
	printf("Cidade: ");
	fgets(ctt.Cidade,21,stdin);
	trata_gets(ctt.Cidade);
	
	fflush(stdin);
	printf("Estado (2 letras): ");
	fgets(ctt.Estado,3,stdin);
	trata_gets(ctt.Estado);
		
	ag->contatos[ag->num_contatos] = ctt;
	ag->num_contatos++;

	printf("\n\n-------------------------------------------------------\n\n");

}

void remover_contato(struct agenda* ag){
	
	printf("\n\n-------------------------------------------------------\n\n");
	
	char del[50];
	fflush(stdin);
	printf("Por favor digite o nome do contato: ");
	gets(del);
	trata_gets(del);
	
	int idx = busca_contato(*ag,del);
	if (idx >= 0){
		ag->contatos[idx] = ag->contatos[(ag->num_contatos)-1];
		ag->num_contatos -= 1;
		printf("Contato excluido com sucesso!\n");
	} else {
		printf("\n\t\tERRO: CONTATO INEXISTENTE\n");
	}
	
	printf("\n\n-------------------------------------------------------\n\n");
	
}

void alterar_contato(struct agenda* ag){
	
	printf("\n\n-------------------------------------------------------\n\n");
	
	char cont[50];
	fflush(stdin);
	printf("Por favor digite o nome do contato: ");
	gets(cont);
	trata_gets(cont);
	
	int idx = busca_contato(*ag,cont);
	
	if (idx<0){
		printf("\n\n\t\tERRO: CONTATO INEXISTENTE\n");
		printf("\n\n-------------------------------------------------------\n\n");
		return;
	} else {
		// muda a referencia de ultimo contato para fazer a mudança e depois volta à posição correta
		int backup = ag->num_contatos;
		ag->num_contatos = idx;
		inserir_contato(ag);
		ag->num_contatos = backup;
		printf("\nContato modificado com sucesso\n");
		printf("\n\n-------------------------------------------------------\n\n");
	}
	
}

int main(int argc, char* argv[]){
	int option, sair = 0;
	
	// habilitando teclas pt-br
	setlocale(LC_ALL, "Portuguese");	
	
	// carregando a agenda ou criando nova
	printf("Carregar agenda (1) ou Criar uma nova (2): ");
	scanf("%d",&option);
	struct agenda ag;
	if (option == 2){
		// cria agenda:
		ag.num_contatos = 0;
	} else {
		; // ag = carrega arquivo com a agenda
	}
	
	// main loop
	while (sair == 0){ 
 
 		printf("               _____ ______ _   _ _____           \n");
		printf("         /\\   / ____|  ____| \\ | |  __ \\   /\\     \n");		
		printf("        /  \\ | |  __| |__  |  \\| | |  | | /  \\    \n");
		printf("       / /\\ \\| | |_ |  __| | . ` | |  | |/ /\\ \\   \n");
		printf("      / ____ \\ |__| | |____| |\\  | |__| / ____ \\  \n");
		printf("     /_/    \\_\\_____|______|_| \\_|_____/_/    \\_\\ \n\n");
		printf("\t(1) -> Adicionar Contato;\n");
		printf("\t(2) -> Remover Contato;\n");
		printf("\t(3) -> Imprimir todos os Contatos;\n");
		printf("\t(4) -> Informações de Contato;\n");
		printf("\t(5) -> Modificar informações de Contato;\n");
		printf("\t(6) -> Sair;\n");
		printf(">>> ");
		scanf("%d",&option);
		puts("");
		
		switch(option)
		{
			case 1 :
				inserir_contato(&ag);
			break;

			case 2:
				remover_contato(&ag);
			break;

			case 3:
				mostrar_agenda(ag);
			break;
			
			case 4:
				encontrar_contato(ag);	
			break;

			case 5:
				alterar_contato(&ag);
			break;

			case 6:
				printf("Saindo...\n\n");
				sair = 1;
			break;
			
			default:
				printf("\t\t\n\nERROR: CÓDIGO INVALIDO...\n\n");		
		}
	
	}
	
	system("pause");
	return 0;
}
