#include <iostream>
using namespace std;
struct sysop
{
	char name[26];
	char quote[64];
	int used;
};

const sysop & use(sysop & sysopref);

/*
Rick  "Fortran" Looper says:
I'm a goto kind of guy.
Looper: 1 use(s)
Rick  "Fortran" Looper says:
I'm a goto kind of guy.
Looper: 2 use(s)
Copycat: 2 use(s)
Rick  "Fortran" Looper says:
I'm a goto kind of guy.
use(looper): 3 use(s)
 */
int main(int argc, char const *argv[])
{
	sysop looper =
	{
		"Rick  \"Fortran\" Looper",
		"I'm a goto kind of guy.",
		0
	};
	use(looper);
	cout << "Looper: " << looper.used << " use(s)\n";
	sysop copycat;
	copycat = use(looper);
	cout << "Looper: " << looper.used << " use(s)\n";
	cout << "Copycat: " << copycat.used << " use(s)\n";
	cout << "use(looper): " << use(looper).used << " use(s)\n";

	return 0;
}

const sysop & use(sysop & sysopref)
{
	cout << sysopref.name << " says:\n";
	cout << sysopref.quote << endl;
	sysopref.used++;
	return sysopref;
}
