#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	fstream file("example.csv", ios::in);
	vector<double> vec;

	if (!file)
	{
		cerr << "Can't open file..." << endl;
		return 0;
	}

	while ( !file.eof() ) 	            // Einlesen bis Dateiende
	{
		string row;
		getline(file, row);          	// Einlesen einer Zeile

		if ( !row.empty() )             // Falls Zeile nicht leer
		{
			istringstream ss(row);		// StringStream zum zerlegen der Zeile
			string temp;

			getline(ss, temp, ';');		// Ersten Wert bis zum Trennzeichen
										// einlesen

			do
			{
				stringstream convert;	        // StringStream für die Konvertierung
				convert << temp;		        // Konvertierung
				double dtemp;		        	// des String
				convert >> dtemp;		        // nach double
				vec.push_back(dtemp);	        // und einfügen in den vector
				temp.clear();			        // String leeren
				getline(ss, temp, ';');	        // Nächsten Wert einlesen
			} while ( !temp.empty() );        	// Falls Temp Leer ist, gibt es keine
        }								        // neuen Werte in der aktuellen Zeile
	}
	file.close();

	for ( unsigned i=0; i<vec.size(); i++ )
		cout << vec[i] << " ";

	return 0;
}
