#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define FILE_NAME "accounts"

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

void saveAccounts(Account accounts[], int totalAccounts) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("\nError opening file for saving accounts.\n");
        return;
    }

    fwrite(&totalAccounts, sizeof(int), 1, file);
    fwrite(accounts, sizeof(Account), totalAccounts, file);

    fclose(file);
    printf("\nAccount data saved to file.\n");
}

void loadAccounts(Account accounts[], int *totalAccounts) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo existing account data found. Starting fresh.\n");
        return;
    }

    fread(totalAccounts, sizeof(int), 1, file);
    fread(accounts, sizeof(Account), *totalAccounts, file);

    fclose(file);
    printf("\nAccounts data loaded successfully from file.\n");
}

void createAccount(Account accounts[], int *totalAccounts) {
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("\nMaximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = *totalAccounts + 1;

    printf("\nEnter name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[*totalAccounts] = newAccount;
    (*totalAccounts)++;

    saveAccounts(accounts, *totalAccounts);
    printf("\nAccount created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney(Account accounts[], int totalAccounts) {
    int accountNumber;
    float amount;

    while (1) {
        printf("\nEnter account number (or 0 to cancel): ");
        scanf("%d", &accountNumber);

        if (accountNumber == 0) {
            printf("\nDeposit canceled.\n");
            return;
        }

        if (accountNumber > 0 && accountNumber <= totalAccounts) {
            break;
        }

        printf("\nInvalid account number! Please try again.\n");
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("\nInvalid deposit amount!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    saveAccounts(accounts, totalAccounts);
    printf("\nAmount deposited successfully! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawMoney(Account accounts[], int totalAccounts) {
    int accountNumber;
    float amount;

    while (1) {
        printf("\nEnter account number (or 0 to cancel): ");
        scanf("%d", &accountNumber);

        if (accountNumber == 0) {
            printf("\nWithdrawal canceled.\n");
            return;
        }

        if (accountNumber > 0 && accountNumber <= totalAccounts) {
            break;
        }

        printf("\nInvalid account number! Please try again.\n");
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("\nInvalid or insufficient balance for withdrawal!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    saveAccounts(accounts, totalAccounts);
    printf("\nAmount withdrawn successfully! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayAccount(Account accounts[], int totalAccounts) {
    int accountNumber;

    while (1) {
        printf("\nEnter account number (or 0 to cancel): ");
        scanf("%d", &accountNumber);

        if (accountNumber == 0) {
            printf("\nDisplay canceled.\n");
            return;
        }

        if (accountNumber > 0 && accountNumber <= totalAccounts) {
            break;
        }

        printf("\nInvalid account number! Please try again.\n");
    }

    Account account = accounts[accountNumber - 1];
    printf("\nAccount Number: %d", account.accountNumber);
    printf("\nName: %s", account.name);
    printf("\nBalance: %.2f\n", account.balance);
}

void main() {
    Account accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;

    loadAccounts(accounts, &totalAccounts);

    while (1) {
        printf("\n--- Bank Account Management System ---\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display account details\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &totalAccounts);
                break;
            case 2:
                depositMoney(accounts, totalAccounts);
                break;
            case 3:
                withdrawMoney(accounts, totalAccounts);
                break;
            case 4:
                displayAccount(accounts, totalAccounts);
                break;
            case 5:
                printf("\nExiting the program.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
