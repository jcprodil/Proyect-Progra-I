void bitSet(int *p, int n)			//*p: Puntero al puerto, n: Índice del bit que queremos setear
{
	int x=*p;

	x |= 1<<n;
}

void bitClr(int *p, int n)			//Mismos parámetros
{
	int x=*p;

	x &= ~(1<<n);
}

void bitToggle(int *p, int n)			//Mismos parámetros
{
	int x=*p;

	x ^= 1<<n;
}

int bitGet(int *p, int n)			//Mismos parámetros
{
	int bit;
	int x=*p;

	bit = x & (1<<n);
	return bit;
}

void maskOnAB(int *p)				//*p: Puntero al puerto
{
	int x=*p;

	x ||= 0xFF;
}

void maskOnD(int *p)				//Mismos parámetros (Para el Acumulador D)
{
	int x=*p;

	x ||= 0xFFFF;
}

void maskOffAB(int *p)				//Mismos parámetros
{
	int x=*p;

	x &&= 0x00;
}

void maskOffD(int *p)				//Mismos parámetros (Para el Acumulador D)
{
	int x=*p;

	x &&= 0x0000
}

void maskToggleAB(int *p)			//Mismos parámetros
{
	int x=*p;

	x ^^= 0xFF;
}

void maskToggleD(int *p)			//Mismos parámetros (Para el Acumulador D)
{
	int x=*p;

	x ^^= 0xFFFF;
}
