// JualianDateConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
string fnJulianDateToGregorian(string julianDate);
bool isLeapYear(int year);

int main()
{
    string julianDate;
    string gregorianDate;
	
    cout << "Hello World!\n";
    cout << "Julian Date: ";
    cin >> julianDate;
    gregorianDate = fnJulianDateToGregorian(julianDate);
    cout << "Gregorian Date: " << gregorianDate;
}

bool isLeapYear(int year)
{
    bool isLeapYear = false;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                isLeapYear = true;
            }
        }
        else isLeapYear = true;
    }
    return isLeapYear;
}

//YYYYDDD to YYYYMMDD
string fnJulianDateToGregorian(string julianDate)
{
	string gregorianDate;
    string year = julianDate.substr(0, 4);
    int days = stoi(julianDate.substr(4, 4));
	bool leapYear = isLeapYear(stoi(year));
    int february = leapYear ? 29 : 28;
    int months[] = {31, february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month;
	
	for (int i = 0; i < 12; i++)
	{
		if(days <= months[i])
		{
            month = i + 1;
			break;
		}
        else
        {
            days -= months[i];
        }
	}

    string sDay = (days >= 10 ? "" : "0") + to_string(days);
    string sMonth = (month >= 10 ? "" : "0") + to_string(month);
    gregorianDate = year + sMonth + sDay;
    return gregorianDate;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
