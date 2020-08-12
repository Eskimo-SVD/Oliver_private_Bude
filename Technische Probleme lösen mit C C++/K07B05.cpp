System::Void bt_Rechnung_Click(System::Object^  sender,
                                   System::EventArgs^  e) 
{
   // Deklarationen
   float tempEin, tempAus;   // Temperaturen
   int rechnung; // Seuerungsvariable für die Berechnung
   int systemEin, systemAus; // Ein- und Ausgabesystem
   // Einlesen der Eingabe-Temperatur
   tempEin = System::Convert::ToDouble(this->tB_Eingabe->Text);
   // Steuerungsvariable Berechnung
   systemEin = 1;
   if (this->rB_von_F->Checked) systemEin = 2;
   if (this->rB_von_K->Checked) systemEin = 3;
   systemAus = 1;
   if (this->rB_nach_F->Checked) systemAus = 2;
   if (this->rB_nach_K->Checked) systemAus = 3;
   rechnung = systemEin * 10 + systemAus;
   switch(rechnung)
   {
      // °C ==> °C
      case 11: tempAus = tempEin;
               break;
      // °C ==> °F
      case 12: tempAus = tempEin * 1.8 + 32.0;
               break;
      // °C ==> K
      case 13: tempAus = tempEin + 273.15;
               break; 
      // °F ==> °C
      case 21: tempAus = (tempEin - 32.0) * 5.0 / 9.0;
               break;
      // °F ==> °F
      case 22: tempAus = tempEin;
               break;
      // °F ==> K
      case 23: tempAus = (tempEin + 459.67) * 5.0 / 9.0;
               break;
      // K ==> °C
      case 31: tempAus = tempEin - 273.15;
               break;
      // K ==> °F
      case 32: tempAus = tempEin * 1.8 - 459.67;
               break;
      // K ==> K
      case 33: tempAus = tempEin;
   }
   // Darstellung des Ergebnisses in der TextBox tB_Ergebnis
   this->tB_Ergebnis->Text = this->tB_Eingabe->Text;
   if (systemEin == 1) this->tB_Ergebnis->Text += "°C = ";
   if (systemEin == 2) this->tB_Ergebnis->Text += "°F = ";
   if (systemEin == 3) this->tB_Ergebnis->Text += "K = ";
   this->tB_Ergebnis->Text += System::Convert::ToString(tempAus);
   if (systemAus == 1) this->tB_Ergebnis->Text += "°C";
   if (systemAus == 2) this->tB_Ergebnis->Text += "°F";
   if (systemAus == 3) this->tB_Ergebnis->Text += "K";
}
