#include <stdio.h>

// Structure to store customer account information
struct Account {
    int accountNumber;
    float balance;
};

// Function to create a new account
void createAccount(struct Account accounts[], int *numAccounts) {
    if (*numAccounts >= 100) {
        printf("Cannot create more accounts.\n");
        return;
    }

    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    accounts[*numAccounts] = newAccount;
    (*numAccounts)++;

    printf("Account created successfully.\n");
}

// Function to deposit money into an account
void deposit(struct Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw(struct Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to view account balance
void viewBalance(struct Account accounts[], int numAccounts) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    struct Account accounts[100];
    int numAccounts = 0;
    int choice;

    do {
        printf("Bank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Balance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                viewBalance(accounts, numAccounts);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}