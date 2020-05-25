#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {


    cout << "Addition der Werte: " << 10 + 32 << endl;

    cout << "als String: " << endl;

    string a = "10";
    string b = "32";
    string c;

    cout << a + b << endl;
    c = a + b;

    cout << "c ist gleich: " << c << endl;

    cout << endl << endl << "Greeting in String und Long." << endl;

    string greeting = "1234";
    cout << greeting << endl;

    long greetingLong = 12345678;
    cout << greetingLong << endl;
 // -------------------------------------------------------------------------

    cout << endl << endl << "Als Zahlen: ";
    double summand_a = 10;
    double summand_b = 32;
    double summand_c;

    cout << summand_a + summand_b << endl;
    summand_c = summand_a + summand_b;

    cout << "Die Addition c ist gleich: " << summand_c << endl;

    return 0;
}
