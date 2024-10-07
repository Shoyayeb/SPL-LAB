#include<stdio.h>
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;
void menu() {
    printf("\n--- Bank Account Management System ---\n");
    printf("1. Create a new account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Display account details\n");
    printf("5. Exit\n");
}

void createAccount(Account accounts[], int *totalAccounts){
    Account newAccount;
    newAccount.accountNumber = *totalAccounts + 1;
    printf("Enter Account Holder Name: ");
    scanf("%s",newAccount.name);
    newAccount.balance = 0.0;
    accounts[*totalAccounts] = newAccount;
    (*totalAccounts)++;
    printf("New account created successfully. \nAccount Number is: %d",newAccount.accountNumber);
}
void depositMoney(Account accounts[],int totalAccounts){
    int accountNumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    if(accountNumber <=0 || accountNumber > totalAccounts){
        printf("Invalid account number");
        return;
    }
    printf("Enter amount to deposit:");
    scanf("%f", &amount);
    if(amount <= 0){
        printf("Invalid amount");
        return;
    }
    accounts[accountNumber-1].balance += amount;
    printf("Amount deposited successfully! New balance: %f",accounts[accountNumber-1].balance)
}
void withdrawMoney(Account accounts[],int totalAccounts){

}
void main(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
    case 1:

    }
}
