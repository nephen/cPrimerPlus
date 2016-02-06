#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	float a = 2.34E+22f;
	float b = a + 1.0f;

	cout << "a =" << a << endl;
	/*
	float类型只能表示数字的前6位或7位，故b-a=0。
	 */
	cout << "b - a = " << b - a << endl;
	return 0;
}