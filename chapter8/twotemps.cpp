#include <iostream>
template <class Any>	//or typename Any
void Swap(Any &a, Any &b);

template <typename Any>
void Swap(Any *a, Any *b, int n);

void show(int a[]);
const int Lim = 8;

int main(int argc, char const *argv[])
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i. j = " << i << ". " << j << ".\n";
	cout << "Using compiler-generated in swapper:\n";
	Swap(i, j);
	cout << "Now i. j = " << i << ". " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x. y = " << x << ". " << y << ".\n";
	cout << "Using compiler-generated in swapper:\n";
	Swap(x, y);
	cout << "Now x. y = " << x << ". " << y << ".\n";

	int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
	int d2[Lim] = {0, 6, 2, 0, 1, 9, 6, 9};
	cout << "Original arrays:\n";
	show(d1);
	show(d2);
	Swap(d1, d2, Lim);
	cout << "Swap arrays:\n";
	show(d1);
	show(d2);
	return 0;
}

template <class Any>
void Swap(Any &a, Any &b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename Any>
void Swap(Any *a, Any *b, int n)
{
	Any temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}