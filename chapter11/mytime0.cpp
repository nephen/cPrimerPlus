#include <iostream>
#include "mytime0.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::Sum(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator +(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator *(double n) const
{
	Time result;
	long totalminutes = hours * n * 60 + minutes * n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator *(double m, const Time & t)
{
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream & operator <<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours. " << t.minutes << " minutes";
	return os;
}

void Time::Show() const
{
	std::cout << hours << " hours. " << minutes << " minutes";
}