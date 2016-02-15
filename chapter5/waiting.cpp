#include <iostream>
#include <ctime>

int main(int argc, char const *argv[])
{
	using namespace std;
	cout << "Enter the delay time. in seconds: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << "starting\a\n";
	clock_t start = clock();
	while (clock() - start < delay)
	{
		if ((clock() - start) % CLOCKS_PER_SEC == 0)
		{
			cout << (clock() - start) / CLOCKS_PER_SEC << endl;
		}
	}
	cout << "done\a\n";
	return 0;
}