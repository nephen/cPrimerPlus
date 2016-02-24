#include <iostream>
#include "mytime0.h"

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	total = coding + fixing;
	cout << "coding + fixing = ";
	total.Show();
	cout << endl;

	total = coding * 2.0;
	cout << "coding * 2.0 = ";
	total.Show();
	cout << endl;

	total = 2.0 * coding;
	cout << "2.0 * coding = ";
	total.Show();
	cout << endl;

	cout << "cout << total like ";
	cout << total;
	cout << endl;

	return 0;
}