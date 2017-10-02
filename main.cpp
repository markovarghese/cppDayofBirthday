#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int b_year, b_month, b_day;
    cout << "Hello user!" << endl;
    cout << "Please input the year of your birth" << endl;
    cin >> b_year;
    cout << "Please input the month (1-12) of your birth" << endl;
    cin >> b_month;
    cout << "Please input the day (1-31) of your birth" << endl;
    cin >> b_day;
    cout << "The date " << b_year << "-" << b_month << "-" << b_day << " falls on ";

    //code courtesy of https://stackoverflow.com/questions/40517192/c-day-of-week-for-given-date
    tm time_in = { 0, 0, 0, // second, minute, hour
        b_day, b_month - 1, b_year - 1900 }; // 1-based day, 0-based month, year since 1900
  
    time_t time_temp = mktime(&time_in);
  
    //Note: Return value of localtime is not threadsafe, because it might be
    // (and will be) reused in subsequent calls to std::localtime!
    const tm * time_out = localtime(&time_temp);
  
    //Sunday == 0, Monday == 1, and so on ...
    cout << time_out->tm_wday << endl;
    cout << "(Sunday is 0, Monday is 1, and so on...)" << endl;
    return 0;
}