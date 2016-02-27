#include <iostream>
using std::cout;
#include "strngbad.h"
#include <cstdlib>
#include <ctime>

void callme1(StringBad &);
void callme2(StringBad);

const int ArSize = 10;
const int Maxlen = 81;

int main(int argc, char const *argv[])
{
	using std::endl;
	StringBad headline1("Celery Stalks at Midnight");
	StringBad headline2("Lettuce Prey");
	StringBad sports("Spinach Leaves Bow1 for Dollars");
	cout << "headline1: " << headline1 << endl;
	cout << "headline2: " << headline2 << endl;
	cout << "sports: " << sports << endl << endl;
	callme1(headline1);
	cout << "headline1: " << headline1 << endl;
	callme2(headline2);
	cout << "headline2: " << headline2 << endl << endl;
	cout << "Initialize one object to another:\n";
	StringBad sailor = sports;
	cout << "sailor: " << sailor << endl << endl;
	cout << "Assign one object to another:\n";
	StringBad knot;
	knot = headline1;
	cout << "knot: " << knot << endl;
	cout << "End of main()\n\n";

	cout << "Test good String!\n";
	using std::cin;
	StringBad name;
	cout << "Hi, what's your name?\n>> ";
	cin >> name;
	cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
	StringBad sayings[ArSize];
	char temp[Maxlen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, Maxlen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	cout << "here are your sayings:\n";
	for (i = 0; i < total; i++)
		cout << sayings[i][0] << ": " << sayings[i] << endl;

	int shortest = 0;
	int first = 0;
	for (i = 1; i < total; i++)
	{
		if (sayings[i].length() < sayings[shortest].length())
			shortest = i;
		if (sayings[i] < sayings[first])
			first = i;
	}
	cout << "Shortest sayings:\n" << sayings[shortest] << endl;
	cout << "First alphabetically:\n" << sayings[first] << endl;
	cout << "This program used:\n" << StringBad::HowMany() << " String object. Bye.\n\n";

	cout << "Test object point!\n";
	srand(time(0));
	int choice = rand() % total;
	StringBad * favorite = new StringBad(sayings[choice]);
	cout << "My favorite saying: \n" << *favorite << endl;
	delete favorite;

	return 0;
}

void callme1(StringBad &rsb)
{
	cout << "String passed by reference: \n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "String passed by value: \n";
	cout << "	\"" << sb << "\"\n";
}
