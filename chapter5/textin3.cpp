#include <iostream>

/**
 * using EOF to end read
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[])
{
	using namespace std;
	char ch;
	int count = 0;
	cin.get(ch);
	while (cin.fail() == false)
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
	return 0;
}