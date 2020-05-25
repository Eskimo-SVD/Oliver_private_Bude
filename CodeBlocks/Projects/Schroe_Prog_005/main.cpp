#include <iostream>
#include <limits>
using namespace std;

int main()
{
  // Einfache Aufgabe:
  cout << numeric_limits<int>::max() << endl;
  cout << numeric_limits<int>::min() << endl;
  cout << numeric_limits<char>::digits << endl;
  cout << sizeof(char) << endl;
  // Schwierige Aufgabe:
  bool vorzeichen = numeric_limits<char>::is_signed;
  if( vorzeichen == true ) {
    cout << "char ist als signed implementiert\n";
  }
  else {
    cout << "char ist als unsigned implementiert\n";
  }
  return 0;
}
