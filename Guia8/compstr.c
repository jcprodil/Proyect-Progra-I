#include <stdio.h>

int compstr(char p1[], char p2[], int charcnt, int charcnt2)
{

	int a;
	int b=0;

	for(a=0;a<charcnt;a++)						//creo el loop para comparar las letras
	{
		while(p2[b]==p1[a]||p2[b]==(p1[a]+32)||p2[b]==(p1[a]-32)) 	//si son iguales incremento la posicion del arreglo
								        	//con los "or" no distingue entre mayusculas y minusculas
		{
		while(b<charcnt2)					//sigo con la siguiente letra hasta terminar la palabra
		b++;
		a=0;
		}
	}
}
