#include <iostream>
#include <climits>

/**
 * [main description]
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[])
{
	using namespace std;
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;

	cout << "int is " << sizeof(int) << " bytes.\n";
	cout << "short is " << sizeof(short) << " bytes.\n";
	cout << "long is " << sizeof(long) << " bytes.\n";

	cout << "Maximun values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;

	cout << "Minimun int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	return 0;
}