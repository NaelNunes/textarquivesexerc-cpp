#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

void CriaArqMaisculo(FILE *Ptr)
{
	FILE *Ptr1 = fopen("Arquivo2.txt","w");
	
	char string[70];
	
	
	while(!feof(Ptr))
	{
		fscanf(Ptr, "%s", string);
		string[0] = toupper(string[0]);
		fputs(string,Ptr1);
		fputc(' ',Ptr1);
	}
	fclose(Ptr1);	
	fclose(Ptr);
};

void ExibeArqMais(void)
{
	FILE *Ptr = fopen("Arquivo2.txt","r");
	
	char caractere;
	
	caractere = fgetc(Ptr);
	while(!feof(Ptr))
	{
		printf("%c", caractere);	
		Sleep(50);
		caractere = fgetc(Ptr);
	}	
	getch();
	fclose(Ptr);		
}

int main(void)
{
	FILE *Ptr = fopen("Arquivo1.txt","r");	
	CriaArqMaisculo(Ptr);
	ExibeArqMais();	
	return 0;
}
