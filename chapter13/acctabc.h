#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <cstring>
using std::cout;
using std::ios_base;
using std::endl;

class AcctABC
{
private:
	enum {MAX = 35};
	char fullName[MAX];
	long acctNum;
	double balance;
protected:
	const char * FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	std::ios_base::fmtflags SetFormat() const;
public:
	AcctABC(const char *s = "Nullbody", long an = -1,
	        double bal = 0.0);
	void Despoit(double amt);
	virtual void Withdraw(double amt) = 0;
	double Balance() const { return balance; }
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC() {}
};

class Brass: public AcctABC
{
public:
	Brass(const char *s = "Nullbody", long an = -1,
	      double bal = 0.0) : AcctABC(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	~Brass() {}
};

class BrassPlus: public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const char *s = "Nullbody", long an = -1,
	          double bal = 0.0, double ml = 500,
	          double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.10);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetRate(double r) { rate = r; }
	void ResetMax(double m) { maxLoan = m; }
	void ResetOwes() { owesBank = 0; }
};

#endif