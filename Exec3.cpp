#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <windows.h>

void comparaArquivos(void)
{
	FILE *Ptr1 = fopen("Arq1.txt","a+");
	FILE *Ptr2 = fopen("Arq2.txt","a+");
	
	char c1, c2;
	
	c1 = fgetc(Ptr1);
	c2 = fgetc(Ptr2);
	while(c1 == c2 && !feof(Ptr1))
	{
		c1 = fgetc(Ptr1);
		c2 = fgetc(Ptr2);
	}
	if(!feof(Ptr1))
	{
		printf("Os arquivos sao diferentes!\n");
	} else {
		printf("Os arquivos sao identicos!\n");
	}
	
	fclose(Ptr1);
	fclose(Ptr2);
	
	
	
}

int main(void)
{
	comparaArquivos();
	return 0;
}
