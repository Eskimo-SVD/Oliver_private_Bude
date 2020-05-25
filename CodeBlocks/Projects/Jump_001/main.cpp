#include <iostream>

using namespace std;

                                      // What is X and Y Line?

int main ()
{
	for ( int x = 0; x < 10; ++x )
	{
		cout << '\t' << x << "X";            // \t represents a tab character, which will format our output nicely
	}

	cout << '\n';

	for ( int i = 0; i <= 10; ++i )
	{
		cout << i;                           // Ich weis was I ist !<< "I";

		for ( int j = 0; j <= 10; ++j )
		{
			cout << '\t' << i * j;           // Ausgabe jeder berechneten Zahl in der Matrix << "I * J";
		}
		cout << '\n';
	}
}
