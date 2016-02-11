#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	int* pt = new int;
	*pt = 1001;

	cout << "int ";
	cout << "value = " << *pt << " location = " << pt << endl;

	double* pd = new double;
	*pd = 19000003.2;

	cout << "double ";
	cout << "value = " << *pd << " location = " << pd << endl;

	cout << "size of pt = " << sizeof(pt) << endl;
	cout << "size of *pt = " << sizeof *pt << endl;
	cout << "size of pd = " << sizeof(pd) << endl;
	cout << "size of *pd = " << sizeof *pd << endl;

	return 0;
}