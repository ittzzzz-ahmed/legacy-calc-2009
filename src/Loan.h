#ifndef LOAN_H
#define LOAN_H

#include <iostream>
using namespace std;

class Loan {
private:
    long double loanAmount;
    long double interestRate;
    long double numberOfYears;

public:
    Loan(long double amount, long double rate, long double years);

    bool isValid();
    long double calculateTotalAmount();
    long double calculateMonthlyAmount();
    long double calculateTotalInterest();
};

#endif

