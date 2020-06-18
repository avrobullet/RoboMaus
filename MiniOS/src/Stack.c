#include <stdio.h>
#include <stdlib.h>  /* for dynamic allocation */
#include "Stack.h"

/************************ Function Definitions **********************/

void StackInit(stackT *stackP, int maxSize)
{
	stackElementT *newContents;

	/* Allocate a new array to hold the contents. */

	newContents = (int *)malloc(sizeof(int) * maxSize);

	if (newContents == NULL) {
		fprintf(stderr, "Insufficient memory to initialize stack.\n");
		exit(1);  /* Exit, returning error code. */
	}

	stackP->contents = newContents;
	stackP->maxSize = maxSize;
	stackP->top = -1;  /* I.e., empty */
}

void StackDestroy(stackT *stackP)
{
	/* Get rid of array. */
	free(stackP->contents);

	stackP->contents = NULL;
	stackP->maxSize = 0;
	stackP->top = -1;  /* I.e., empty */
}

void StackPush(stackT *stackP, int element)
{
	if (StackIsFull(stackP)) {
		fprintf(stderr, "Can't push element on stack: stack is full.\n");
		exit(1);  /* Exit, returning error code. */
	}

	/* Put information in array; update top. */

	stackP->contents[++stackP->top] = element;
}

stackElementT StackPop(stackT *stackP)
{
	if (StackIsEmpty(stackP)) {
		fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
		exit(1);  /* Exit, returning error code. */
	}

	return stackP->contents[stackP->top--];
}

int StackIsEmpty(stackT *stackP)
{
	if(stackP->top <= 0)
	{
		return NULL;
	}
	return stackP->top < 0;
}

int StackIsFull(stackT *stackP)
{
	return stackP->top >= stackP->maxSize - 1;
}
