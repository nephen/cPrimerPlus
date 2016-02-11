#include <iostream>

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main(int argc, char const *argv[])
{
	using namespace std;
	inflatable guest[2] =
	{
		{"nephen", 0.5, 21.99},
		{"wenwen", 2000, 343.232}
	};

	cout << "The guest " << guest[0].name << " and " << guest[1].name
	     << "\nhave a combined volume of "
	     << guest[0].volume + guest[1].volume << " cubic feet.\n";
	return 0;
}