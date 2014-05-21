#include <stdio.h>
#include <stdlib.h>

float takenum (char arr[]);						/* Prototipos de funciones  */
float Operate(float a, float b);
float  errorlook(float t,float h,float resultfinal);

void main (void)
{
float resultfinal='e';							/* Creo la variable resultado final y le asigno el valor "e"*/

while(resultfinal=='e')							/*para que se ejecute el programa la primera vez y cada vez que haya errores*/ 
{
float t=0,h=0;
									/*Creo las variables en las que guardare los numeros*/
printf("Ingrese el primer numero que desea operar\n Operando 1: ");
char arr[100];								/*Creo un arreglo , donde guardare los ASCII ingresados por teclado*/
t=takenum(arr);								/*Llamo a la funcion "takenum" que transforma el arreglo en un float*/

printf("\nIngrese el segundo numero que desea operar\n Operando 2: ");
char arr1[100];								/*Lo mismo con el siguiente numero*/
h=takenum(arr1);

printf("\nIngrese una de las operaciones propias de la calculadora\n Suma (+)\n Resta(-)\n Multiplicacion(*)\n Division(/)\n And(&)\n Or(|)\nXor(^)\n");
printf("Los ultimos 3 operadores funcionan SOLO para enteros\n\n");
printf("Operador: ");

resultfinal=errorlook(t,h,resultfinal);						//Llamo a la funcion que hara la operacion, verificara el error y creara loop
}									//en caso de ser deseado

printf("\nGracias por utilizar la calculadora! Vuelva pronto!\n");

}




float takenum (char arr[])						/*Funcion que transforma un arreglo a float*/
{
float d;								/*Defino variables*/
char c,x=0,p=0;
int i=0;
while((c=getchar())!='\n')
{									/*Mientras que no ingrese ENTER, los caracteres ingresados se guardaran*/
*(arr+i)=c;								/*como elementos del arreglo uno por uno*/
i++;
}

d=atof(arr);								/*Paso la direccion del primer elemento del arreglo a la funcion "atof",*/
									/*que trasnformara el areglo en un numero y lo guardo en un float*/
while(*(arr+p)=='0')							/*Como la funcion atof devuelve 0, si el valor no valido, creo*/
{									/*un contador. Si todos los elementos del arreglo  son 0*/
p++;
}									/*Y el valor de "d" lo es, entonces se devolvera el error*/

if((d==0)&&(p!=i))							
{d='e';
return d;
}
else
return d;								/*En cualquier otro caso, se devolvera el valor verdadero*/
}






float Operate(float a, float b)						/*Esta funcion, detecta un operador y opera los dos numeros*/
{
float result1;
char oper=getchar();							/*Recibo el operador*/
char n;

switch(oper)								/*Genero un switch para cada una de las operaciones que quiero realizar*/
{
	case'+':							/*Suma los operandos y los devuelve*/
	result1=a+b;
	break;
	case'-':							/*Resta los operandos y los devuelve*/
	result1=a-b;
	break;
	case '*':							/*Multiplica los operandos y los devuelve*/
	result1=a*b;
	break;
	case'/':							/*Divide los operandos. En caso de que el segundo numero sea 0*/
	if(b==0)
	{printf("La division de un numero por 0 no esta definida. Ingrese nuevamente los numeros.\n El programa se reiniciara\n\n");
									/*devuelve la letra "e" y el programa se ejecuta de nuevo*/
	result1='e';
	n=getchar();							/*Uso este getchar para  que cuando reinicie el programa, no me tome el \n*/
	}
	else
	result1=a/b;							/*Si no es 0, hace la division y la devuelve*/
	break;
	case '&':							/*Hace un AND (bitwise) casteado a int y lo devuelve*/
	result1=((int)a&(int)b);
	break;
	case '|':							/*Hace un OR (bitwise) casteado a int y lo devuelve*/
	result1=((int)a|(int)b);
	break;
	case '^':							/*Hace un XOR, pero como el XOR para floats no esta definido,*/
	result1=((int)a^(int)b);					/*lo castea a int y lo devuelve*/
	break;
	default:
	printf("Operacion no valida o existente. Ingrese nuevamente los numeros.\n El programa se reiniciara\n\n");
	result1='e';							/*En caso de que no este la operacion, o no existe, devuelve "e"(Error)*/
	n=getchar();
	break;
}
return result1;								/*Devuelvo el resultado final de la operacion */
}

float errorlook(float t, float h, float resultfinal)			/*Esta funcion verifica errores, y llama a la funcion de Operaciones*/
{
char letra,nad=0,nad2=0;
if((t=='e')||(h=='e'))                                                  /*Si alguno de los operadores tuvo error, el programa se reiniciara*/
{printf("\nUno de los numeros ingresados no es valido. El programa se reiniciara\n");
resultfinal='e';
return resultfinal;
}
else
{resultfinal=Operate(t,h);                                              /*Si los numeros no tuvieron error, iran a la funcion Operate*/
if(resultfinal!='e')
{printf("El resultado es: %g\n ",resultfinal);				/*Si le restultado es coherente, se imprimira*/
return resultfinal;
}
else
resultfinal='e';
return resultfinal;
}
}

