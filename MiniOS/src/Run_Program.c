#include <asf.h>
#include <proj.h>

static int pop1;
static int pop2;

void LineRun(stackT *S1, stackT *S2)
{
	while(StackIsEmpty(S1) != NULL)
	{
		pop1 = StackPop(S1);
		pop2 = StackPop(S2);
		check_values(pop1, pop2);
	}
}
