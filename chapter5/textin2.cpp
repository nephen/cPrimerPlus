#include <iostream>

/**
 * cin.get can get the blackspace and \n
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[])
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "Enter characters; Enter # to quit:\n";
	cin.get(ch);
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";
	return 0;
}