#include <iostream>

/**
 * [main description]
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[])
{
	using namespace std;
	int carrots;
	cout << "How many carrots do you have?" << endl;
	cin >> carrots;
	cout << "Here are two more.\n";
	carrots = carrots + 2;
	cout << "Now you have " << carrots << " carrots" << endl;
	return 0;
}