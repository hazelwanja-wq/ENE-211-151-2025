#include <stdio.h>
#include <stdlib.h>

float balance = 1000;

// Login: 3 attempts allowed
int login()
{
    int pin, correctPin = 1234;
    int attempts;

    for (attempts = 1; attempts <= 3; attempts++)
    {
        printf("Enter your PIN: ");
        scanf("%d", &pin);

        if (pin == correctPin)
        {
            printf("\nLogin Successful!\n");
            return 1;
        }
        else
        {
            printf("Incorrect PIN! Attempts left: %d\n", 3 - attempts);
        }
    }

    printf("Maximum attempts exceeded. Access denied.\n");
    return 0;
}

void checkBalance()
{
    printf("Your balance is: %.2f\n", balance);
}

void deposit(float amount)
{
    if (amount > 0)
    {
        balance = balance + amount;
        printf("Deposit successful!\n");
        printf("New balance: %.2f\n", balance);
    }
    else
    {
        printf("Invalid amount!\n");
    }
}

void withdraw(float amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance = balance - amount;
        printf("Withdrawal successful!\n");
        printf("New balance: %.2f\n", balance);
    }
    else
    {
        printf("Insufficient balance or invalid amount!\n");
    }
}

int main()
{
    int choice;
    float amount;

    if (login() == 0)
    {
        exit(0);
    }

    do
    {
        // Display Menu
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkBalance();
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(amount);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(amount);
                break;

            case 4:
                printf("Thank you for using our ATM!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    while (choice != 4);

    return 0;
}
