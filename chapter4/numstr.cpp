#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	cout << "What year was your hourse build?\n";
	int year;
	cin >> year;
	cin.get();
	cout << "What is its street address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year build: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!";
	return 0;
}