
#include <stdio.h>

int main() {

	/* We need to remember that array of certain elements is also pointer to its elements
	   We can assign other pointer to the same array that will help us in tranverse through the array.
	*/

	//This is called compound literals
	//    int *p = (int []) {3,0,6,4,8};
	 
	int a[] = { 3,0,6,4,8 };
	int *p, *q , i;
	
	int size = sizeof(a) / sizeof(a[0]);

	printf("\n");
	printf("/**********************Pointer for array processing********************************************/");
	printf("\n");
	//We can assign the pointre to array in differnt ways
	// Both of these cases the pointer is pointing to the first element in the element.
	 p = a; //This is only true when pointing only to the first element....
	// or
	//p = &a[0];
	 
	 //NOTE: we are pointing the arary to the size here but a[size] does not exit,but its safe bacause forloop does not attempt to examine a[size]
	for (p = a; p < &a[size]; p++){
		printf("%d ", *p);
	}



	printf("\n\n");
	printf("/********************** operators on the pointer array ********************************************/");
	printf("\n");

	 //re-Assign the value to a[0] 
	p = &a[0];
	*p = 5;

	//NOTE: when ever the pointer is pointing to array, in order to print the vlaues of array elements through pointer p, do not use (*p[0] WRONG!!)  but use p[0] or p[1] or p[4] etc.
	printf("The starting array values :  5,0,6,4,8 \n");
	printf("*p = %d\n", *p);
	printf("*p+2 = %d\n", *p+2);
	printf("*(p+2) = %d\n", *(p+2));
	printf("*p++ = %d\n", *p++);      //NOTE: the compiler will see this as *(p++)
	printf("*p = %d\n", *p);     //Also notice the pointer has been incremented to next element here not before.
	printf("*++p = %d\n", *++p);    //NOTE: the compiler will see this as *(++p)
	printf("*(p++) = %d\n", *(p++));
	printf("*p = %d\n", *p);  
	
	printf("\n");
	printf("(*p)++ = %d\n", (*p)++); //NOTE : (*p)++ is not equal to *(p++), because (*p)++ will increment the value in the array not index!! 
 	printf("*p = %d\n", *p); //NOTE : notice the value has incremented not the index.
	printf("++(*p) = %d\n", ++(*p)); // here it incemented 5 first then print the value
	printf("*p = %d\n", *p);
	//NOTE : notice its only cahnging the values of the same index and not incrementing the index value
	//a[] = { 5,0,6,6,8 }
	printf("Notice the array update: ");
	for (p = a; p < &a[size]; p++) {
		printf("%d ", *p);
	}


	printf("\n\n");
	printf("/**********************Arithmetic on pointers********************************************/");
	printf("\n");
	p = &a[4];
	q = p - 2;
	// take where ever the p is pointing to as the 0th element and go from there left or right
	printf("The q pointer will point to 2nd element with value %d \n", *q);

	// We can also treat the index values as normal number while doing only subraction but not addition regardless the pointer points wihtin the array element or not
	p = &a[7];  //NOTE: notice the array is pointing out of bound value but still successfully doing the subraction
	q = &a[1];
	i = p - q;
	printf("The value of i is %d\n", i);

	
	//Pointers contain addresses. Adding two addresses makes no sense, because you have no idea what you would point to. Subtracting two addresses lets you compute the offset between
	//these two addresses, which may be very useful in some situations.
	// this example is to calculate the midpoint value of array a[5].
	p = &a[0];
	q = &a[4];
	i = *p + (*q - *p) / 2; //NOTE: notice there is a plus+ sign in the arithmetic so therefore we cannot use just p and q only because addition requires the values the array is pointed at.
	printf("The midpoint of array a[5] is %d\n", i);




	printf("\n\n");
	printf("/************Lets look at the case of array itself is a pointer*************************************/");
	printf("\n");

	//a[] = { 5,0,6,6,8 }
	printf("the array itself is pointing to element value %d\n", *a);  // *a is pointing to a[0]
	printf("the array itself is pointing to element value %d\n", *(a+1));  // *a is pointing to a[1]
	printf("the array itself is pointing to element value %d\n", *a);
	printf("the array itself is pointing to element value %d\n", ++*a);  //incrementing the value at a[0] = 5 
	printf("the array itself is pointing to element value %d\n", *a);


	system("pause");
}
