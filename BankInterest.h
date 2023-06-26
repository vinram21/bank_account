#ifndef BANK_INTEREST_H
#define BANK_INTEREST_H

#define APR 1200	// 12 months in a year and 100 to convert percentage to actual rate

class InterestOnly {
public:
	//The APR converts from 8% to 0.08 and then by 12 for the monthly value
	InterestOnly(double balance, double rate) : balance(balance), rate(rate / APR) {};
	void setBalance(double balance) { this->balance = balance; }
	void setRate(double rate) { this->rate = rate; }
	void showTable(int years);
protected:
	double balance;
	double rate;	//Monthly interest rate, 
	virtual void showHeader();
	virtual double monthlyUpdate(double balance);
private:
	void printDetails(int year, double yearEndBalance, double interestEarned);

};

class SaverAccount : public InterestOnly {
public:
	SaverAccount(double balance, double rate, double monthly) : InterestOnly(balance, rate), monthly(monthly) {};
protected:
	double monthly;
	virtual void showHeader();
	virtual double monthlyUpdate(double balance);
};

#define UNDEFINED 0
#define INTEREST 1
#define SAVER 2

#endif //BANK_INTEREST_H
