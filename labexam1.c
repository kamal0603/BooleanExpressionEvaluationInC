#include<stdio.h>
#include<string.h>
int main(){
	int var;
	char op[] = {'A','O','N','X','D','R'};
	/*
	A = AND
	O = OR
	N = NOT
	X = XOR
	D = NAND
	R = NOR
	*/
	
	
	// THIS PROGRAM DOES NOT HAVE XOR OPERATION AND ALSO NO PARANTHESIS.
	char expr[15];
	printf("Enter the expression\n. Expression should be TANF for TRUE AND NOT FALSE...etc");
	scanf("%s",expr);
	char arr[strlen(expr)];
	int len = strlen(expr);
	int i , j;
	for (i = 0 ; i < len ; i ++){
		arr[i] = expr[i];
	}
	
	// For NOT
	for (i = 0 ; i < len ; i ++){
		if (arr[i] == 'N'){
			if (arr[i+1] == 'T'){
				arr[i] = 'F';
				for (j = i+1 ; j < len  ; j ++){
					arr[j] = arr[j+1];
				}
				len --;
			}
			else if (arr[i+1] == 'F'){
				arr[i] = 'T';
				for (j = i+1 ; j < len  ; j ++){
					arr[j] = arr[j+1];
				}
				len --;
			}
		}
	}
	printf("Next expression is : \n");
	for (i = 0 ; i < len ; i ++)
	printf("%c",arr[i]);
	printf("\n");
	
	//For AND
	
	for (i = 1 ; i < len -1 ; i ++){
		if (arr[i] == 'A'){
	
			if (arr[i+1] == 'T' && arr[i-1] == 'T'){
				arr[i-1] = 'T';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
			else if (arr[i+1] == 'F' || arr[i-1] == 'F'){
				arr[i-1] = 'F';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
		}
	}
	
	printf("Next expression is : \n");
	for (i = 0 ; i < len ; i ++)
	printf("%c",arr[i]);
	printf("\n");
	
	//For NAND
	
	for (i = 1 ; i < len -1 ; i ++){
		if (arr[i] == 'D'){
	
			if (arr[i+1] == 'T' && arr[i-1] == 'T'){
				arr[i-1] = 'F';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
			else if (arr[i+1] == 'F' || arr[i-1] == 'F'){
				arr[i-1] = 'T';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
		}
	}
	
	
	printf("Next expression is : \n");
	for (i = 0 ; i < len ; i ++)
	printf("%c",arr[i]);
	printf("\n");
	// For OR
	
	for (i = 1 ; i < len -1 ; i ++){
		if (arr[i] == 'O'){
	
			if (arr[i+1] == 'T' || arr[i-1] == 'T'){
				arr[i-1] = 'T';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
			else if (arr[i+1] == 'F' && arr[i-1] == 'F'){
				arr[i-1] = 'F';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
		}
	}
	
	
	printf("Next expression is : \n");
	for (i = 0 ; i < len ; i ++)
	printf("%c",arr[i]);
	printf("\n");
	//For NOR
	
	for (i = 1 ; i < len -1 ; i ++){
		if (arr[i] == 'R'){
	
			if (arr[i+1] == 'T' || arr[i-1] == 'T'){
				arr[i-1] = 'F';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
			else if (arr[i+1] == 'F' && arr[i-1] == 'F'){
				arr[i-1] = 'T';
				for (j = i+1 ; j < len  ; j ++){
					arr[j-1] = arr[j+1];
				}
				len -= 2;
			}
		}
	}
	
	printf("The final output is : %c\n (T = True and F = False.)",arr[len-1]);
	return 0 ;
}
