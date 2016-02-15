#include <iostream>

const int Favo = 27;

int main(int argc, char const *argv[])
{
	using namespace std;
	int n;

	cout << "Enter a number in the range 1-100 to find ";
	cout << "my favorite number: ";
	do
	{
		cin >> n;
		if (n < Favo)
			cout << "Too low -- guess again: ";
		else if (n > Favo)
			cout << "Too high -- guess again: ";
		else
			cout << Favo << " is right !\n";
	} while (n != Favo);
	return 0;
}