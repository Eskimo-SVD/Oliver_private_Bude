#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

namespace Programm936 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse ändern, müssen Sie auch
	///          die Ressourcendateiname-Eigenschaft für das Tool zur Kompilierung verwalteter Ressourcen ändern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abhängt.
	///          Anderenfalls können die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bt_zeichne;
	protected: 
	private: System::Windows::Forms::Label^  lb_ueberschrift;
	private: System::Windows::Forms::Label^  lb_q1;
	private: System::Windows::Forms::Label^  lb_q2;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bt_zeichne = (gcnew System::Windows::Forms::Button());
			this->lb_ueberschrift = (gcnew System::Windows::Forms::Label());
			this->lb_q1 = (gcnew System::Windows::Forms::Label());
			this->lb_q2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bt_zeichne
			// 
			this->bt_zeichne->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_zeichne->Location = System::Drawing::Point(610, 20);
			this->bt_zeichne->Name = L"bt_zeichne";
			this->bt_zeichne->Size = System::Drawing::Size(161, 58);
			this->bt_zeichne->TabIndex = 0;
			this->bt_zeichne->Text = L"Zeichne\r\nImpulsdiagramm";
			this->bt_zeichne->UseVisualStyleBackColor = true;
			this->bt_zeichne->Click += gcnew System::EventHandler(this, &Form1::bt_zeichne_Click);
			// 
			// lb_ueberschrift
			// 
			this->lb_ueberschrift->AutoSize = true;
			this->lb_ueberschrift->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_ueberschrift->Location = System::Drawing::Point(12, 20);
			this->lb_ueberschrift->Name = L"lb_ueberschrift";
			this->lb_ueberschrift->Size = System::Drawing::Size(72, 18);
			this->lb_ueberschrift->TabIndex = 1;
			this->lb_ueberschrift->Text = L"Schaltung:";
			// 
			// lb_q1
			// 
			this->lb_q1->AutoSize = true;
			this->lb_q1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_q1->Location = System::Drawing::Point(90, 20);
			this->lb_q1->Name = L"lb_q1";
			this->lb_q1->Size = System::Drawing::Size(21, 18);
			this->lb_q1->TabIndex = 2;
			this->lb_q1->Text = L"q1";
			// 
			// lb_q2
			// 
			this->lb_q2->AutoSize = true;
			this->lb_q2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_q2->Location = System::Drawing::Point(90, 60);
			this->lb_q2->Name = L"lb_q2";
			this->lb_q2->Size = System::Drawing::Size(23, 18);
			this->lb_q2->TabIndex = 3;
			this->lb_q2->Text = L"q2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 562);
			this->Controls->Add(this->lb_q2);
			this->Controls->Add(this->lb_q1);
			this->Controls->Add(this->lb_ueberschrift);
			this->Controls->Add(this->bt_zeichne);
			this->Name = L"Form1";
			this->Text = L"Impulsdiagramm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
   private: 
   System::Void bt_zeichne_Click(System::Object^  sender, System::EventArgs^  e) 
   {
      // Versorgung der Label
	  // Für die Darstellung eines logischen UND muss &&&& angegeben werden!
	  this->lb_q1->Text = "Q1 = (A&&&&B&&&&C)||(A&&&&!B&&&&!C)||(!A&&&&B&&&&!C)||(!A&&&&!B&&&&C)";
	  this->lb_q2->Text = "Q2 = (A&&&&B&&&&C)||(A&&&&B&&&&!C) ||(A&&&&!B&&&&C) ||(!A&&&&B&&&&C)";
	  //this->lb_q1->Text = "Q1 = ( A || !B ) &&&& C";
	  //this->lb_q2->Text = "";
	  int anzE;          // Anzahl der Eingänge
      int anzA;          // Anzahl der Eingänge
      short int a;       // Wert Eingang A
      short int b;       // Wert Eingang B
      short int c;       // Wert Eingang C
      int anz_zeile;     // Anzahl der Zeilen in den Arrays
      int anz_spalteE;   // Anzahl der Spalten im Array Eingänge
      int anz_spalteA;   // Anzahl der Spalten im Array Ausgänge
	  int anz_spalteZ;   // Anzahl der Spalten im Array ztab
      int i;             // Hilfsvariable
      short int ** dual; // zweidimensionales Array der Eingänge
      short int ** q;    // zweidimensionales Array der Ausgänge
	  short int ** ztab; // zweidimensionales Array Impulsdiagramm
      // Anzahl der Eingänge setzen
      anzE = 3;
      // Anzahl der Ausgänge setzen
      anzA = 2;
	  //anzA = 1;
      // dynamisches Allocieren dreier zweidimensionaler Arrays
      anz_zeile   = (int)pow(2.,anzE) + 1;
      anz_spalteE = anzE + 1;
      anz_spalteA = anzA + 1;
	  anz_spalteZ = anzE + anzA + 1;
      dual = (short int **)malloc(anz_zeile * sizeof(short int *));
      if (dual == NULL)
      {
         System::Windows::Forms::MessageBox::Show("Kein RAM mehr vorhanden für dual !","Fehler!!");
      }
      q = (short int **)malloc(anz_zeile * sizeof(short int *));
      if (q == NULL)
      {
         System::Windows::Forms::MessageBox::Show("Kein RAM mehr vorhanden für q !","Fehler!!");
      }
	  ztab = (short int **)malloc(anz_zeile * sizeof(short int *));
      if (ztab == NULL)
      {
         System::Windows::Forms::MessageBox::Show("Kein RAM mehr vorhanden für ztab !","Fehler!!");
      }
      for(i = 0; i < anz_zeile; i++) 
      {
         dual[i] = (short int *)malloc(anz_spalteE * sizeof(short int));
         if (dual[i] == NULL) 
	     {
	        System::Windows::Forms::MessageBox::Show("Kein RAM mehr vorhanden für Zeile in dual !","Fehler!!");   
         }
	     q[i] = (short int *)malloc(anz_spalteA * sizeof(short int));
         if (q[i] == NULL) 
	     {
		    System::Windows::Forms::MessageBox::Show("Kein RAM mehr vorhanden für Zeile in q !","Fehler!!");
         }
		 ztab[i] = (short int *)malloc(anz_spalteZ * sizeof(short int));
         if (ztab[i] == NULL) 
	     {
		    System::Windows::Forms::MessageBox::Show("Kein RAM mehr vorhanden für Zeile in ztab !","Fehler!!");
         }
      }
      // Aufruf der Belegungsfunktion für die Dualzahlentabelle
      dualtabelle(anzE,dual);
      // Erstellung der Wahrheitstabelle
      for (i = 1; i < anz_zeile; i++)
      {
	     // Belegung der Eingänge aus der Dualzahlentabelle
	     a = dual[i][1];
	     b = dual[i][2];
	     c = dual[i][3];
	     // Ermittlung der Ausgänge
	     q[i][1] = q1(a,b,c);
		 if (anzA > 1) q[i][2] = q2(a,b,c);
      }
	  // Erstellung von ztab nach "Gedankenmodell"
	  for (i = 1; i < anz_zeile; i++)
      {
	     ztab[i][1] = dual[i][1];
		 ztab[i][2] = dual[i][2];
		 ztab[i][3] = dual[i][3];
		 ztab[i][4] =    q[i][1];
		 if (anzA > 1) ztab[i][5] =    q[i][2];
      }
	  // Erstellung der Zeichnung
	  // Erzeugung eines neuen Grafik-Objektes
      Graphics ^g = this->CreateGraphics();
	  // Font und Brush
	  System::Drawing::Font^ dF = gcnew System::Drawing::Font("Arial",10);
      SolidBrush^ dB = gcnew SolidBrush(Color::Black);
	  // Festlegung der Zeichenfläche
	  //int xsa = 100;
	  //int xse = 700;
	  //int ysa = 100;
	  //int yse = 500;
	  int xsa = 100;
	  int xse = 400;
	  int ysa = 100;
	  int yse = 300;
	  // Steuerungsgrößen für die Zeichnung
	  int ib       = (int)( (xse-xsa) / pow(2.,anzE) );
	  int ih_stern = (int)( (yse-ysa) / (anzE+anzA) );
	  int ih       = (int)( ih_stern / 2. );
	  int spalte;
	  int zeile;
	  short int vo, na;
	  int xs, ys;
	  for (spalte = 1; spalte <= anzE + anzA; spalte++)
	  {
		 vo = 0;
		 xs = xsa;
		 ys = ysa + spalte * ih_stern;
		 // Beschriftung
		 if (spalte == 1) g->DrawString("A",dF,dB,xs-20,ys);
		 if (spalte == 2) g->DrawString("B",dF,dB,xs-20,ys);
		 if (spalte == 3) g->DrawString("C",dF,dB,xs-20,ys);
		 if (spalte == 4) g->DrawString("Q1",dF,dB,xs-20,ys);
		 if (spalte == 5) g->DrawString("Q2",dF,dB,xs-20,ys);
		 for (zeile = 1; zeile < anz_zeile; zeile++)
		 {
			na = ztab[zeile][spalte];
			int xakt = xs + (zeile-1) * ib; // aktuelle x-Koordinate
			// senkrechte Striche nicht zu Beginn!
			// Achtung: y-Koordinaten!!
			if (zeile != 1)
			{
			   if (vo < na)
			   {
                  // Strich nach unten
			      g->DrawLine(gcnew Pen(Color::Black), xakt, ys, xakt, ys-ih);
                  ys -= ih;
			   }
			   else if (vo > na)
			   {
                  // Strich nach oben
                  g->DrawLine(gcnew Pen(Color::Black), xakt, ys, xakt, ys+ih);
                  ys += ih;
			   }
			}
			// Strich der Breite ib
            g->DrawLine(gcnew Pen(Color::Black), xakt, ys, xakt + ib, ys);
            vo = na;
		 }
	  }
   }
   void dualtabelle(int anz, short int** dual)
   {
      int anz_zeile;  // Anzahl der Zeilen im Array
      int i, j, k;    // Hilfsvariablen
      anz_zeile  = (int)pow(2.,anz);
      float s = 0.5;
      i = 0;
      for (j = anz; j >= 1; j--) // Schliefe über Spalten
      {
	     s*=2.;
	     do                     // Schleife über Zeilen
	     {
		    for (k = 1; k <=s; k++)
	        {
		       i++;
			   dual[i][j] = 0;
	        }
	        for (k = 1; k <= s; k++)
	        {
			   i++;
		       dual[i][j] = 1;
	        }
	     } while (i < anz_zeile);
	     i = 0;
      }
   }
   short int q1(short int a, short int b, short int c)
   {
      return (a && b && c) || (a && !b && !c) || (!a && b && !c) || (!a && !b && c);
	  //return (a || !b) && c;
   }
   short int q2(short int a, short int b, short int c)
   {
      return (a && b && c) || (a && b && !c) || (a && !b && c) || (!a && b && c);
   }
};
}

