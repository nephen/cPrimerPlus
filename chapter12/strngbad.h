#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	StringBad(const char * s);
	StringBad(const StringBad & st);
	StringBad & operator =(const StringBad & st);
	StringBad & operator =(const char * s);
	StringBad();
	~StringBad();
	int length() const { return len; }

	friend bool operator <(const StringBad & st1, const StringBad & st2);
	friend bool operator >(const StringBad & st1, const StringBad & st2);
	friend bool operator ==(const StringBad & st1, const StringBad & st2);
	friend std::istream & operator >>(std::istream & is, StringBad &st);
	char & operator [](int i);
	const char & operator [](int i) const;
	static int HowMany() { return num_strings; }
	friend std::ostream & operator <<(std::ostream & os, const StringBad & st);
};

#endif