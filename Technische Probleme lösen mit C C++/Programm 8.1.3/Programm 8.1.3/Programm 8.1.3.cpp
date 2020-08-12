// Programm 8.1.3.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Form1.h"

using namespace Programm813;

[STAThreadAttribute]

int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew Form1());
	return 0;
}