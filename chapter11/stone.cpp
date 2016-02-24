#include <iostream>
#include "stonewt.h"
using std::cout;

void display(const Stonewt & st, int n);

int main(int argc, char const *argv[])
{
	Stonewt pavarotti = 260;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "The tenor weighed ";
	pavarotti.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	pavarotti = 265.8;
	taft = 325;
	cout << "After dinner, the tenor weighed ";
	pavarotti.show_stn();
	cout << "Afer dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

	double p_wt = pavarotti;
	cout << "Convert to double => ";
	cout << "pavarotti : " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "pavarotti: " << int(pavarotti) << " pavarotti.\n";

	return 0;
}

void display(const Stonewt &st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}
}