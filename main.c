#include <stdio.h>
#include "myBank.h"

int main(){
	char type=0;
	while(type!='E') {
		printf("please enter the transaction type:");
		scanf(" %c", &type);
		switch (type) {
			case 'O':
				{
				openTheAccount();
				
				}break;	
			case 'B':
				{
				checkBalance();
				break;
				}
			case 'D':
				{
				deposit();
				break;
				}
			case 'W':
				{
				withDrawal();
				break;
				}
			case 'C':
				{
				closeTheAccount();
				break;
				}
			case 'I':
				{
				addInterest();
				break;
				}
			case 'P':
				{
				printAll();
				break;
				}
			case 'E':
				{
				closeAll();
				break;
				}
			default:
				{
				printf(" your type is not valid\n");
				}	
		}
	}
	
	return 0;
}
