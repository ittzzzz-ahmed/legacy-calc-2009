#include<iostream>

using namespace std;

int main(){
    long double loan_amount,interest_rate,number_of_years,total_amount,monthly_amount;

	cout<<"Enter the loan amount: ";
	cin>>loan_amount;
	cout<<endl;
	cout<<"Enter the interest rate: ";
	cin>>interest_rate;
	cout<<endl;
	cout<<"The number of years: ";
	cin>>number_of_years;
	cout<<endl;

	 if(loan_amount<0) 
	 {
        cout<<"Error:Cannot be negative"<<endl;
        return 0;
	}

    if (interest_rate < 0)
	{
        cout<<"Error:Cannot be negative"<<endl;
        return 0;
    }

    if (number_of_years<=0) 
	{
        cout<<"Error Number of years must be greater than zero"<<endl;
        return 0;
    }
	total_amount=(number_of_years*loan_amount)+(number_of_years*loan_amount*(interest_rate/100.00));
	monthly_amount=total_amount/(number_of_years*12);

	cout<<"Total amount to be paid: "<<total_amount<<endl;
	cout<<"Total interest: "<<total_amount-(number_of_years*loan_amount)<<endl;
	cout<<"Monthly amount to be paid: "<<monthly_amount<<endl;

	return 0;
}
