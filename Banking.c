#include <stdio.h>
#include <stdlib.h>

// Creating a structure to hold information of accounts.
struct Account
{
    int accNum;
    char accname[100];
    float balance;
};

// function declarations.
void createAccount();
void displayAccount();
void deposit();
void withdraw();
void balanceEnquiry();
int menu();

// Function to create new accounts.
void createAccount()
{
    FILE *records;
    struct Account Acc;

    records = fopen("accounts.dat", "ab");

    if (records == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }

    printf("\n=-=-=-= Create Account =-=-=-=\n");

    printf("Enter Account Number: ");
    scanf("%d", &Acc.accNum);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]%*c", Acc.accname); // %[^\n]%*c Reads string with spaces

    printf("Enter Initial Balance: ");
    scanf("%f", &Acc.balance);

    fwrite(&Acc, sizeof(Acc), 1, records);

    fclose(records);

    printf("\nAccount Created Successfully!!!\n");

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

// function to display all accounts.
void displayAccount()
{
    FILE *records;
    struct Account Acc;

    records = fopen("accounts.dat", "rb");

    if (records == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n=-=-=-=-=-=-=-=-= Account Records =-=-=-=-=-=-=-=-=\n");
    printf("%-15s %-25s %-15s", "Account Number", "Customer Name", "Balance");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    while (fread(&Acc, sizeof(Acc), 1, records))
    {
        printf("%-15d %-25s %.2f\n", Acc.accNum, Acc.accname, Acc.balance);
    }

    fclose(records);
}

// function to display main menu.
int menu()
{
    int choice;

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("        Bank Management System         \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Balance Enquiry\n");
    printf("5. Display all accounts\n");
    printf("6. Exit\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// function to deposit money in account.
void deposit()
{
    FILE *records, *temp;
    struct Account Acc;
    int accNum, found = 0;
    float amount;

    printf("\n=-=-=-= Deposit Money =-=-=-=\n");
    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    records = fopen("accounts.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (records == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    while (fread(&Acc, sizeof(Acc), 1, records))
    {
        if (Acc.accNum == accNum)
        {
            Acc.balance += amount;
            found = 1;
            printf("\nAmount Deposited Successfully!!!\n");
            printf("\nUpdated Balance: %.2f\n", Acc.balance);
        }
        fwrite(&Acc, sizeof(Acc), 1, temp);
    }

    fclose(records);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (!found)
    {
        printf("\nAccount Number %d not found!\n", accNum);
    }
}

// function to withdraw money from account.
void withdraw()
{
    FILE *records, *temp;
    struct Account Acc;
    int accNum, found = 0;
    float amount;

    printf("\n=-=-=-= Withdraw Money =-=-=-=\n");
    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    printf("Enter Witdraw Amount: ");
    scanf("%f", &amount);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    records = fopen("accounts.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (records == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    while (fread(&Acc, sizeof(Acc), 1, records))
    {
        if (Acc.accNum == accNum)
        {
            found = 1;

            if (amount <= Acc.balance)
            {
                Acc.balance -= amount;
                printf("\nWithdraw Successful!\n");
                printf("Remaining Balance: %.2f\n", Acc.balance);
            }
            else
            {
                printf("\nInsufficient Balance!\n");
            }
        }
        fwrite(&Acc, sizeof(Acc), 1, temp);
    }

    fclose(records);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (!found)
    {
        printf("Account not found!");
    }
    // try adding current and saving accounts.
}

// function for balance enquiry.
void balanceEnquiry()
{
    FILE *records;
    struct Account Acc;
    int accNum, found = 0;

    printf("\n=-=-=-= Balance Enquiry =-=-=-=\n");
    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    records = fopen("accounts.dat", "rb");

    if (records == NULL)
    {
        printf("No account records found.\n");
        return;
    }

    while (fread(&Acc, sizeof(Acc), 1, records))
    {
        if (Acc.accNum == accNum)
        {
            printf("Account Number : %d\n", Acc.accNum);
            printf("Customer Name : %s\n", Acc.accname);
            printf("Current Balance : %.2f\n", Acc.balance);

            found = 1;
            break;
        }
    }
    fclose(records);

    if (!found)
    {
        printf("Account Number %d not found!\n", accNum);
    }
}

// Main function.
int main()
{
    int choice;

    while (1)
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            deposit();
            break;

        case 3:
            withdraw();
            break;

        case 4:
            balanceEnquiry();
            break;

        case 5:
            displayAccount();
            break;

        case 6:
            printf("\nThanks for using Bank Management System!\n");
            printf("\nExiting...\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}