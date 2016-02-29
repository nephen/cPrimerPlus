#include <iostream>
#include <cstring>
#include "brass.h"
using std::cout;
using std::ios_base;
using std::endl;

Brass::Brass(const char *s, long an, double bal)
{
	std::strncpy(fullName, s, MAX - 1);
	fullName[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}

void Brass::Despoit(double amt)
{
	if (amt < 0)
		cout << "Negative despoit not allowed: "
		     << "despoit is cancelled.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Withdrawal amount must be positive: "
		     << "withdrawal cancelled.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		     << " exceeds your balance.\n"
		     << "Withdrawal cancelled.\n";
}

double Brass:: Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	ios_base::fmtflags initialState =
	    cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << "Client: " << fullName << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	cout.setf(initialState);
}

BrassPlus::BrassPlus(const char *s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	ios_base::fmtflags initialState =
	    cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximun loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout << "Loan Rate: " << 100 * rate << endl;
	cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt)
{
	ios_base::fmtflags initialState =
	    cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Despoit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeds. Transaction cancelled.\n";
	cout.setf(initialState);
}