#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

void leNome(char Arq[70])
{
	printf("Digite o nome do Arquivo:\n");
	fflush(stdin);
	gets(Arq);
}

void verificaArquivo(char Arq[70])
{
	FILE *Ptr = fopen(Arq,"r");
	if(Ptr == NULL)
	{
		printf("Arquivo nao existe, deseja cria-lo? (s/n)\n");
		if(toupper(getche() == 'S'))
		{
			Ptr = fopen(Arq,"w");
			fclose(Ptr);
			printf("Arquivo de Texto criado!\n");
		}
	}
	else
	{
		printf("Arquivo valido!\n");
		fclose(Ptr);
	}
	Sleep(1000);
}

void LeTextoChar(char Arq[70])
{
	FILE *Ptr = fopen(Arq,"a");
	char caractere;
	clrscr();
	printf("Nome do arquivo: %s\n", Arq);
	printf("Digite o texto e pressione ESC para finalizar!\n");
	
	caractere = getche();
	while(caractere!=27)
	{
		if(caractere == 13)
		{
			fputc('\n',Ptr);
			printf("\n");
		}
		else
		{
			fputc(caractere,Ptr);
		}
		caractere = getche();		
	}
	fclose(Ptr);
}

void ExibeTextoChar(char Arq[70])
{
	FILE *Ptr = fopen(Arq,"r");
	char caractere;
	int contChar = 0;
	int contEsp = 0;
	int contLin = 1;
	clrscr();
	printf("Nome do arquivo: %s\n", Arq);
	caractere = fgetc(Ptr);
	while(!feof(Ptr))
	{	
		if(caractere == '\n')
		{
			contLin++;
		} 
		else if (caractere == ' ')
		{
			contEsp++;
		} 
		else {
			contChar++;
		}
		caractere = fgetc(Ptr);		
	}
	printf("O texto tem %d linha(s), %d caractere(s) e %d espaco(s)!\n", contLin, contChar, contEsp);
	Sleep(50);
	getch();
	fclose(Ptr);
}

int main(void)
{
	char Arquivo[70];
	
	leNome(Arquivo);
	verificaArquivo(Arquivo);
	LeTextoChar(Arquivo);
	ExibeTextoChar(Arquivo);
	return 0;
}












