#include <stdio.h>
#include "myBank.h"
#define CLOSEACCOUNT 0
#define OPENACCOUNT 1

double arrayAccount[50][2] = {0};


int checkIfOpen(int numAccount){
	int index = numAccount-901;
	if (index < 0 || index>49) {
		printf("the number account is incorrect!!\n");
		return CLOSEACCOUNT;
	}
	else if (arrayAccount[index][0]==OPENACCOUNT) 
		return OPENACCOUNT; // the account is open
	
	else 
		return CLOSEACCOUNT; // the account is not open
	

}
int indexForAccount(){
	for (int i = 0; i < 50; i++) {
			if (arrayAccount[i][0]==CLOSEACCOUNT) {	
				return i;
			}
	}
	return -1;
}

void openTheAccount(){
	int i=indexForAccount();
	if(i==-1){
		printf("the bank is full, there is no place for new account\n");
		return;
	}
	else{

		printf("please enter your initial deposit  ");
		double numDepodit;
		scanf(" %lf",&numDepodit);
		arrayAccount[i][1]=numDepodit;
		arrayAccount[i][0]=OPENACCOUNT;
		printf("your number account is %d \n", (i + 901));
		return;
		
	}
	
}

void checkBalance(){
	printf("please enter your account number: ");
	int numAccount;
	scanf(" %d", &numAccount);
	if (checkIfOpen (numAccount)==CLOSEACCOUNT) {
		printf("the account is not open\n");
	}
	else {
		int index=numAccount - 901;
		printf("your balance is %.2lf : \n", (arrayAccount[index][1]));
	}

}
void deposit(){
	printf("please enter your account number: ");
	int numAccount;
	scanf(" %d", &numAccount);
	if (checkIfOpen(numAccount)==CLOSEACCOUNT){
		printf("the account is not open  \n");
	}
	else {
		printf(" please enter your deposit  ");
		double deposit;
		scanf(" %lf", &deposit);
		int index = numAccount - 901;
		arrayAccount[index][1] += deposit;
		printf("your new balance is %.2lf  \n", (arrayAccount[index][1]));
	}
}

void withDrawal(){
	printf("please enter your account number: ");
	int numAccount;
	scanf(" %d", &numAccount);
	if (checkIfOpen(numAccount) == CLOSEACCOUNT) {
		printf("the account is not open  \n");
	}
	else {
		printf("how much do you want to draw?  ");
		double draw;
		scanf(" %lf", &draw);
		int index=numAccount-901;
		double afterDraw = arrayAccount[index][1] - draw;
		if (afterDraw < 0) {
			printf("there is not enough money in the 				account  \n");
		}
		else {
			arrayAccount[index][1] = afterDraw;
			printf(" your new balance is  %.2lf  \n", afterDraw);
		}
	}
}
	void closeTheAccount(){
		printf("please enter your account number:  ");
		int numAccount;
		scanf(" %d",&numAccount);
		if ((checkIfOpen(numAccount))==CLOSEACCOUNT) {
			printf("Error ; the account is not open  \n");
		}
		else {
			int index=numAccount-901;
			arrayAccount[index][0]=0;
			arrayAccount[index][1]=0;
			printf("the account is closed\n");
		}
	}
	void addInterest(){
		printf("please enter the interest rate : ");
		double interest;
		scanf(" %lf", &interest);
		for (int i = 0; i < 50; i++) {
			if (arrayAccount[i][0]==OPENACCOUNT) {
				double temp=((arrayAccount[i][1]) * interest)/100;
				arrayAccount[i][1] += temp;
			}
		}
	}
	void printAll(){
		for (int i = 0; i < 50; i++) {
			if (arrayAccount[i][0] ==OPENACCOUNT) {
				printf("number account is %d and it's balance is %.2lf \n", (i + 901), (arrayAccount[i][1]));

			}
		}
	}

	void closeAll(){
		for (int i = 0; i < 50; i++) {
			if (arrayAccount[i][0]==OPENACCOUNT) {
				arrayAccount[i][0]=CLOSEACCOUNT;

			}
		}
		

	}


