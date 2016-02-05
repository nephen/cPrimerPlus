#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
	using namespace std;
	double area;
	cout << "Enter area:";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << area << side << endl;
	return 0;
}