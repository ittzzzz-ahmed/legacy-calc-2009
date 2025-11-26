#include "Loan.h"
#include <cmath>   // for pow()
using namespace std;

Loan::Loan(long double amount, long double rate, long double years) {
    loanAmount = amount;
    interestRate = rate;
    numberOfYears = years;
}

bool Loan::isValid() {
    return (loanAmount > 0 &&
            interestRate >= 0 &&
            numberOfYears > 0);
}

long double Loan::calculateTotalAmount() {
    return calculateMonthlyAmount() * (numberOfYears * 12.0L);
}

long double Loan::calculateMonthlyAmount() {
    long double monthlyRate = interestRate / 100.0L / 12.0L;
    long double numberOfPayments = numberOfYears * 12.0L;

    if (monthlyRate == 0) {
        return loanAmount / numberOfPayments;
    }

    long double factor = pow(1 + monthlyRate, numberOfPayments);

    return loanAmount * (monthlyRate * factor)/(factor - 1);
}

long double Loan::calculateTotalInterest() 
{
    return calculateTotalAmount() - loanAmount;
}

