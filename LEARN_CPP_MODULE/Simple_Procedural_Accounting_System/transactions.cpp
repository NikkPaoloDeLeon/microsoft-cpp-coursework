/// This is the matehmatical logic of the accounting system
/// Include header file for the transaction.h so that the forward declaration can be looked up
#include "transactions.h"

/// function to add a deposit to the balance of the user then would return the new amount
double processDeposit (double currentBalance, double currentDeposit) {
    return currentBalance + currentDeposit;
}

/// Function to deduct the withdrawed amount to the existing balance and would return the new amount
double processDebit (double currentBalance, double currentWithdrawal) {
    return currentBalance - currentWithdrawal;
}