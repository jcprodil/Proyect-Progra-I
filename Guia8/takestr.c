#include <stdio.h>

int takestr(char p[])
{
	int charcnt=0;				//El contador de letras de la palabra
	int c;					//Variable temporal para registrar el teclado
	while((c=getchar())!='\n')		//Tomo lo que escribe el teclado
	{
		p[charcnt]=c;			//Y lo guardo en el arreglo(string)
		charcnt++;			//Y aumento el contador
	}
	return charcnt;				//Finalmente retorno la cantidad de letras de la palabra
}
