/// This module is incharge for all mathematical computations for the simple accounting system
/// Handles addition of a new deposit and the existing balance of the account.

/// Header guard to prevent duplication of header files
#ifndef TRANSACTION_H
#define TRANSACTION_H

/* 
* We use forward declaration so that we will make sure to have a prototype of the said function 
* The function wont show us undeclared function when we call it.
*/ 

double processDeposit (double currentBalance, double currentDeposit);
double processDebit (double currentBalance, double currentWithdrawal);

#endif
