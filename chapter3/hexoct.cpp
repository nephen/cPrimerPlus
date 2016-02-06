#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "chest = " << chest << endl;
	cout << hex;
	cout << "waist = " << waist << endl;
	cout << oct;
	cout << "inseam = " << inseam << endl;
	return 0;
}