#include <stdio.h>
#include <string.h>


int main()
{
	char option;
	double balance = 100000.00;


	/* Greeting message */
	printf("\nHello, Welcome to Mybank. With us, Banking has been  made easy. \n");


	/* Create an account - Implementing registration */
	char firstname[50], lastname[50];

	printf("Please create an account \nEnter your first and last names here: ");
	scanf("%s %s", firstname, lastname);

	char pass[20];
	char val[20];
	int value;
	int i = 3;
	int passwordCorrect = 0; //Flag var to track correct password validation.

	printf("Create a passowrd: ");
	scanf("%s", pass);

	printf("Confirm  passowrd: ");
	scanf("%s", val);

	value = strcmp(pass, val);

	if (value != 0)
		while (i >= 0)
		{
			printf("\n Your passwords dont match \n");
			printf("Try again, Re-enter password: ");
			scanf("%s", val);

			value = strcmp(pass, val);

			if ( value == 0)
			{
				passwordCorrect = 1;
				break;
			}
			if (i > 0)
				printf("Passwords dont match. You have %d more attempts \n", i);
			else
				printf("Sorry. You cant create an account");
			i--;
		}
	else
		passwordCorrect = 1;

	if (passwordCorrect)
	{
		printf("Welcome to instant banking with my bank. \nYou have a fixed amount of 50,000 \n \n");

		while(1)
		{
			printf("Menu: \n");
			printf("a) Transfer funds \n");
			printf("b) Deposit funds \n");
			printf("c) Check balance \n");
			printf("d) Quit the program \n");

			printf("Select an option: ");
			scanf(" %c", &option);

			switch (option)
			{
				case 'a':
					printf("Option a: Transfer Money\n");
					printf("Enter the amount you want to transfer: ");
					double amount;
					scanf("%lf", &amount);
					if (amount > balance)
						printf("Sorry, you dont have enough funds to transfer %lf \n", amount);
					else
						balance -= amount;
						printf("You have successfully transferred %lf \n", amount);
						printf("Your balance is %lf \n", balance);
					break;

				case 'b':
					printf("Option b: Deposit Money\n");
					printf("Enter the amount you want to deposit: ");
					double deposit;
					scanf("%lf", &deposit);
					balance += deposit;
					printf("You have successfully deposited %lf \n", deposit);
					printf("Your balance is %lf \n", balance);
					break;

				case 'c':
					printf("Option c: Check balance\n");
					printf("Your balance is %lf \n", balance);
					break;

				case 'd':
					printf("Option d: Quit the program\n");
					return 0;


			}	


		}

	}

	return 0;
}
