#include <cstring>
#include "strngbad.h"
using std::cout;

int StringBad::num_strings = 0;

StringBad::StringBad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ":  \"" << str << "\" object created\n";
}

StringBad::StringBad(const StringBad & st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ": \"" << str << "\" object created\n";
}

char & StringBad::operator [](int i)
{
	return str[i];
}

/*
对于常规变量，只能读取数据
 */
const char & StringBad::operator [](int i) const
{
	return str[i];
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ":  \"" << str << "\" default object created\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete [] str;
}

bool operator <(const StringBad & st1, const StringBad  & st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator >(const StringBad & st1, const StringBad & st2)
{
	return st1.str < st2.str;
}

bool operator ==(const StringBad & st1, const StringBad & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

StringBad & StringBad::operator =(const StringBad & st)
{
	if (this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

StringBad & StringBad::operator =(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

std::ostream & operator <<(std::ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}

std::istream & operator >>(std::istream & is, StringBad & st)
{
	char temp[StringBad::CINLIM];
	is.get(temp, StringBad::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}