// This exercise will test your basic understanding of pointers
#include <stdio.h>

// prototype of function you are to implement below
void swap(int* const, int* const);

int sweep()
{
    int x = 10;
    int y = 20;

    // invoke swap function below this comment
	swap(&x, &y);

    // If you implemented swap() correctly below and invoked it correctly above, 
    //    x should have value 20 and y should have value 10 when you display them in the next statement.

    printf("x = %d and y = %d\n\n", x, y);
    return 0;

}

//Swap the values pointed to by the 2 pointers in the parameter list
void swap(int* const ptr1, int* const ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}