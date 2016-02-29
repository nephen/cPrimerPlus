#ifndef BRASS_H_
#define BRASS_H_

class Brass
{
private:
	enum {MAX = 35};
	char fullName[MAX];
	long acctNum;
	double balance;
public:
	Brass(const char *s = "Null body", long an = -1, double bal = 0.0);
	virtual ~Brass() {}

	void Despoit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
};

class BrassPlus: public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const char *s = "Null bodu", long an = -1,
	          double bal = 0.0, double ml = 500,
	          double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.10);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif