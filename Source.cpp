// Preparing for QUiZ
#include <iostream>
#include <string>
using namespace std;

class Clock
{
private:
	int hour, minutes, seconds;

public:
	Clock(int hour=0, int minutes=0, int seconds=0)
	{
		this->hour = hour;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	void settime(int hour, int minutes, int seconds)
	{
		if (seconds > 60)
		{
			int temp;
			temp = seconds / 60;
			seconds %= 60;
			minutes += temp;
			if (minutes > 60)
			{
				temp = minutes / 60;
				minutes %= 60;
				hour += temp;
				if (hour > 60)
				{
					hour = temp;
				}
			}
			
		}
		this->hour = hour;
		this->minutes = minutes;
		this->seconds = seconds;

	}
	string gettime() {
		cout << hour << " hours " << minutes << " minutes " <<seconds<<" seconds "<< endl;
	}
	void operator == (const Clock& c)
	{
		if (hour == c.hour && minutes == c.minutes && seconds == c.seconds)
		{
			cout << "These two times are equal." << endl;
		}
		else
		{
			cout<< "These two times are not equal." << endl;
		}
	}
	/*friend void operator ++ (Clock& c);
	friend void operator ++ (Clock& c);*/
	void operator ++ (int)
	{
		seconds++;
	}
	void operator ++ ()
	{
		++seconds;
	}
	friend ostream& operator << (ostream& out, const Clock& c);
	friend istream& operator >> (istream& in, Clock& c);
};
//void operator ++ (Clock& c) {
//	c.seconds++;
//}
//void operator ++ (Clock& c) {
//	++c.seconds;
//}
ostream& operator << (ostream& out, const Clock& c) {
	out<< c.hour << " hours " << c.minutes << " minutes " << c.seconds << " seconds " << endl;
	return out;
}
istream& operator >> (istream& in, Clock& c) {
	cout << "Enter the time: (hour/minute/second)" << endl;
	in >> c.hour >> c.minutes >> c.seconds;
	c.settime(c.hour, c.minutes, c.seconds);
	return in;
}
int main()
{
	Clock c1, c2;
	cin >> c1;
	// cin >> c2;
	// cout << c1;
	// c1 == c2;
	++c1;
	c1++;
	cout << c1;



	return 0;
}