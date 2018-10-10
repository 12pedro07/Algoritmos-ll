#include <stdio.h>
#include <stdlib.h>

void append_string(char* s1, const char* s2){
	int i, aux = tamanho_string(s1);
	for (i=0 ; i < s2[i]!=0 ; i++)
		s1[aux+i] = s2[i];
	s1[tamanho_string(s1)+i] = '\0';
}

int compara_string(const char* s1, const char* s2){

	//////////////////////
	// > 0 -> igual		//
	// < 0 -> diferente	//
	//////////////////////

	int i;
	for ( i=0 ; s1[i] != '\0' ; i++){ // roda em todos os caracteres de s1
		if ( s1[i] != s2[i] ) // se um dos caracteres for diferente
			return -1;
	} 
	if (s2[i] != 0) // se s2 eh maior do que s1
		return -1;
	return 1; // se tudo deu certo
}

void encontra_troca(char* s, char find, char replace){
	int i;
	int tamanho = tamanho_string(s);
	for (i=0;i<tamanho;i++){
		if (s[i] == find)
			s[i] = replace;
	}
}

void exclui_caracter(char* s, char excluir){
	int i,j;
	int tamanho = tamanho_string(s);
	for (i=0;i<tamanho;i++){
		if (s[i]==excluir){
			for (j=i;j<tamanho;j++)
				s[j] = s[j+1];
		}
	}
}

void imprime_string(char* s){
	int i;
	for (i=0; s[i] != 0 ; i++){
		printf("%c",s[i]);
	}
	puts("");
}

void inverte_string(char* s){
	int i;
	char aux;
	int tamanho = tamanho_string(s)-1;
	for (i=0;i<tamanho/2;i++){
		aux = s[i];
		s[i] = s[tamanho-i];
		s[tamanho-i] = aux;
	}
}

void str2lower(char* s){
	int i;
	int tamanho = tamanho_string(s);
	for (i=0;i<tamanho;i++){
		if (s[i] >='A' && s[i] <='Z')
			s[i] = s[i] + ('a' - 'A');
	}
}

void str2upper(char* s){
	int i;
	int tamanho = tamanho_string(s);
	for (i=0;i<tamanho;i++){
		if (s[i] >='a' && s[i] <='z')
			s[i] = s[i] - ('a' - 'A');
	}
}

int tamanho_string(char* s){
	int i;
	for (i=0;s[i]!='\0';i++);
	return (i);
}

int main(int argc, char* argv[]){
	
	
	////////// REGIAO DE TESTES //////////
	char nome_arquivo[100] = "Arquivo_Teste";
	char nome_digitado[100];
	
	do{
		printf("nome do arquivo: ");
		gets(nome_digitado);
	} while(compara_string(nome_arquivo,nome_digitado) < 0);
	
	printf("Antes: %s\n",nome_arquivo);
	encontra_troca(nome_arquivo,'e','X');
	printf("Depois: %s\n",nome_arquivo);
	//////////////////////////////////////

	system("pause");
	return 0;
}
