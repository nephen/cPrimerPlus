#include <iostream>

long double prohability(unsigned number, unsigned picks);

int main(int argc, char const *argv[])
{
	using namespace std;
	double total, choices;
	cout << "Enter the total number of choices on the game card and\n"
	     "the number of picks allowed:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << prohability(total, choices);
		cout << " of winning.\n";
		cout << "Next two number (q to quit): ";
	}
	cout << "bye\n";
	return 0;
}

long double prohability(unsigned number, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n = number, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}