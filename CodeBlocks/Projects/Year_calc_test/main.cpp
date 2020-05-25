#include <iostream>
using namespace std;
#include <time.h>

int main()
{
    time_t Zeitstempel;
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);
    cout << nun->tm_mday << '.' << nun->tm_mon+1 << '.'
        << nun->tm_year+1900 << " - " << nun->tm_hour
        << ':' << nun->tm_min << endl;
}
