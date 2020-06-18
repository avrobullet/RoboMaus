#include <asf.h>
#include <proj.h>

static stackT S1;
static stackT S2;

void LineProgram()
{
	int size = 9;
	int n[] = {3,3,3,-1, -2, -2,3,3,3,};
	int m[] = {3,3,3, 2,  2,  2,3,3,3,};

	StackInit(&S1, size);	//S1 = for motor 1
	StackInit(&S2, size);	//S2 = for motor 2

	//generateStack(n, &S1);
	for (int i = size; i > 0; i--)
	{
		StackPush(&S1, n[i]); //S1 = for motor 1
		StackPush(&S2, m[i]); //S2 = for motor 2
	}
	
}
void LineProgramRun()
{
	LineRun(&S1, &S2);
}
