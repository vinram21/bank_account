// BankInterest.cpp : By Vinodh Ramesh
//

#include <iostream>
#include <iomanip>

#include "BankInterest.h"

using namespace std;

/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void InterestOnly::printDetails(int year, double yearEndBalance, double interestEarned) {
    cout << year << "\t\t" << "$ ";
    cout << fixed << setprecision(2) << yearEndBalance << "\t\t" << "$ " << interestEarned << endl;
}


void InterestOnly::showTable(int years)
{
    double earned = 0;
    double projectedBalance = balance;
    double total = 0;

    showHeader();

    cout << "================================================================" << endl;
    cout << "\nYear\t\tYear End Balance\tYear End Interest Earned" << endl;
    cout << "================================================================" << endl;

    for (int year = 1; year <= years; year++) {
        for (int month = 0; month < 12; month++) {
            total += rate * projectedBalance;
            earned = monthlyUpdate(projectedBalance);
            projectedBalance += earned;
        }
        printDetails(year, projectedBalance, total);
    }
    cout << endl;
}

void InterestOnly::showHeader()
{
    cout << "Interest earned with interest only account." << endl;
}

double InterestOnly::monthlyUpdate(double balance) {
    return balance * rate;
}

void SaverAccount::showHeader()
{
    cout << "Interest earned with our reguler saver account." << endl;
}

double SaverAccount::monthlyUpdate(double balance) {
    return balance * rate + monthly;
}

int main()
{
    //InterestOnly interestAccount(1000, 5);
    //interestAccount.showTable(5);
    //SaverAccount saver(1000, 5, 100);
    //saver.showTable(5);

    cout << "Welcome to Vinodh's Bank.\n" << endl;

    int type = UNDEFINED;
    while (type != INTEREST && type != SAVER) {
        cout << "What type of account are you interested in 1) Interest Only, 2) Saver Account? ";
        cin >> type;
    }
    double balance;
    cout << "Enter initial balance: $ ";
    cin >> balance;
    double rate;
    cout << "Enter initial rate: % ";
    cin >> rate;
    double deposit = 0;

    InterestOnly* account = NULL;
    if (type == SAVER) {
        cout << "Enter monthly savings: $ ";
        cin >> deposit;
        account = new SaverAccount(balance, rate, deposit);
    }
    else {
        account = new InterestOnly(balance, rate);
    }

    int years;
    cout << "How many years do you wish to project? ";
    cin >> years;

    account->showTable(years);


}