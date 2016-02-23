#include <iostream>
#include "stock1.h"

const int STKS = 4;

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::ios_base;
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "Using constructors to create new objects\n";
	Stock stock1("NanoSmart", 20, 12.50);
	stock1.show();
	Stock stock2("Boffo Objects", 2, 2.0);
	stock2.show();

	cout << "Assigning stock1 to stock2:\n";
	stock2 = stock1;
	cout << "Listing stock1 and stock2:\n";
	stock1.show();
	stock2.show();

	cout << "Using a constructor to reset an object\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);
	cout << "Revised stock1:\n";
	stock1.show();

	cout << "Using default constructors to create new objects\n";
	Stock stock3;
	stock3.show();
	cout << "Done\n";

	cout << "\nCreate stocks array\n";
	Stock stocks[STKS] = {
		Stock("NephenLetv", 12, 20.0),
		Stock("Kingchad", 200, 2.0),
		Stock("Pixhawk", 130, 3.25),
		Stock("APM", 60, 6.5)
	};

	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

	Stock top = stocks[0];
	for (st = 1; st < STKS; st++)
		top = top.topval(stocks[st]);
	cout << "\nMost valuable holding:\n";
	top.show();

	return 0;
}