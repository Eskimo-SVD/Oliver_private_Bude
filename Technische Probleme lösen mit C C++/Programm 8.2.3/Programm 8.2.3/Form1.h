#include "Transformation.h"
#include "math.h"

#pragma once


namespace Programm823 {

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
	// Objekte der Oberfläche
	// Überschrift
	private: System::Windows::Forms::Label^  lb_Ueberschrift;
	// GroupBox "Weltkoordinaten"











	// GroupBox "Screenkoordinaten	
	private: System::Windows::Forms::GroupBox^  gB_screen;








    // Button "Zeichne"
	private: System::Windows::Forms::Button^   bt_zeichne;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tB_Schritt;
	private: System::Windows::Forms::TextBox^  tB_Amplitude;
	private: System::Windows::Forms::TextBox^  tB_harmonisch;

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
			this->lb_Ueberschrift = (gcnew System::Windows::Forms::Label());
			this->gB_screen = (gcnew System::Windows::Forms::GroupBox());
			this->tB_Schritt = (gcnew System::Windows::Forms::TextBox());
			this->tB_Amplitude = (gcnew System::Windows::Forms::TextBox());
			this->tB_harmonisch = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bt_zeichne = (gcnew System::Windows::Forms::Button());
			this->gB_screen->SuspendLayout();
			this->SuspendLayout();
			// 
			// lb_Ueberschrift
			// 
			this->lb_Ueberschrift->AutoSize = true;
			this->lb_Ueberschrift->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Ueberschrift->Location = System::Drawing::Point(12, 9);
			this->lb_Ueberschrift->Name = L"lb_Ueberschrift";
			this->lb_Ueberschrift->Size = System::Drawing::Size(627, 26);
			this->lb_Ueberschrift->TabIndex = 0;
			this->lb_Ueberschrift->Text = L"Programm zur Darstellung der Fourierfunktion einer Rechteckfunktion";
			// 
			// gB_screen
			// 
			this->gB_screen->Controls->Add(this->tB_Schritt);
			this->gB_screen->Controls->Add(this->tB_Amplitude);
			this->gB_screen->Controls->Add(this->tB_harmonisch);
			this->gB_screen->Controls->Add(this->label3);
			this->gB_screen->Controls->Add(this->label2);
			this->gB_screen->Controls->Add(this->label1);
			this->gB_screen->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_screen->Location = System::Drawing::Point(17, 56);
			this->gB_screen->Name = L"gB_screen";
			this->gB_screen->Size = System::Drawing::Size(362, 139);
			this->gB_screen->TabIndex = 22;
			this->gB_screen->TabStop = false;
			this->gB_screen->Text = L"Angaben zur Fourierfunktion";
			// 
			// tB_Schritt
			// 
			this->tB_Schritt->Location = System::Drawing::Point(259, 100);
			this->tB_Schritt->Name = L"tB_Schritt";
			this->tB_Schritt->Size = System::Drawing::Size(66, 26);
			this->tB_Schritt->TabIndex = 5;
			// 
			// tB_Amplitude
			// 
			this->tB_Amplitude->Location = System::Drawing::Point(259, 70);
			this->tB_Amplitude->Name = L"tB_Amplitude";
			this->tB_Amplitude->Size = System::Drawing::Size(66, 26);
			this->tB_Amplitude->TabIndex = 4;
			// 
			// tB_harmonisch
			// 
			this->tB_harmonisch->Location = System::Drawing::Point(259, 40);
			this->tB_harmonisch->Name = L"tB_harmonisch";
			this->tB_harmonisch->Size = System::Drawing::Size(66, 26);
			this->tB_harmonisch->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Schrittweite [Grad]";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Höhe der Amplitude";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(247, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Anzahl der harmonischen Summanden";
			// 
			// bt_zeichne
			// 
			this->bt_zeichne->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_zeichne->Location = System::Drawing::Point(520, 81);
			this->bt_zeichne->Name = L"bt_zeichne";
			this->bt_zeichne->Size = System::Drawing::Size(119, 101);
			this->bt_zeichne->TabIndex = 23;
			this->bt_zeichne->Text = L"Zeichne\r\n\r\nFourier-\r\n\r\nFunktion";
			this->bt_zeichne->UseVisualStyleBackColor = true;
			this->bt_zeichne->Click += gcnew System::EventHandler(this, &Form1::bt_zeichne_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(674, 616);
			this->Controls->Add(this->bt_zeichne);
			this->Controls->Add(this->gB_screen);
			this->Controls->Add(this->lb_Ueberschrift);
			this->Name = L"Form1";
			this->Text = L"Programm 8.2.3";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->gB_screen->ResumeLayout(false);
			this->gB_screen->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 // Diese Methode wird beim Load der Maske aufgerufen
				 // Versorgung der Koordinatenfelder mit Anfangswerten (Defaults)
				 this->tB_Amplitude->Text  = "2,0";
				 this->tB_harmonisch->Text = "5";
				 this->tB_Schritt->Text    = "30,0";
			 }
private: System::Void bt_zeichne_Click(System::Object^  sender, System::EventArgs^  e) 
         {
			 // Diese Methode wird aufgerufen, wenn der Button "Zeichne ..." geclickt wird
			 // Deklaration der lokalen Variablen
			 int    xsa = 40;   // x-Richtung, Screen, Anfang
			 int    xse = 640;  // x-Richtung, Screen, Ende
			 int    ysa = 600;  // y-Richtung, Screen, Anfang
			 int    yse = 200;  // y-Richtung, Screen, Ende
             double xwa = 0.0;  // x-Richtung, Welt, Anfang
			 double xwe = 6.4; // x-Richtung, Welt, Ende
			 double ywa;   // y-Richtung, Welt, Anfang
			 double ywe;   // y-Richtung, Welt, Ende
             double schrittweite, schrittweiteG;
			 int    x1;    // x-Koordinate des ersten Punktes einer Linie
			 int    y1;    // y-Koordinate des ersten Punktes einer Linie
			 int    x2;    // x-Koordinate des zweiten Punktes einer Linie
			 int    y2;    // y-Koordinate des zweiten Punktes einer Linie
			 double xlauf;
			 int n;        // Anzahl der harmonischen Schwingungen
			 double a;     // Amplitude

			 // Erzeugung eines neuen Grafik-Objektes
			 Graphics ^g = this->CreateGraphics();
			 // Definition der Hintergrundfarbe durch R-G-B-Code
			 Color cl = Color::FromArgb(224,224,224);
			 // Bereinigen des Grafik-Objektes für Folgeaufruf
			 g->Clear(cl);
             
			 // Übernahme der Einträge aus den TextBoxen mit try - catch
			 // fehlerhafte Eingabe ==> MessageBox
			 try
			 {
				// Auslesen der Welt-Koordinaten, textBox ==> double
				ywa = -Convert::ToDouble(this->tB_Amplitude->Text)-0.5;
				ywe = -ywa;
                // Auslesen der Schrittweite, textBox ==> double
				schrittweiteG = Convert::ToDouble(this->tB_Schritt->Text);
				schrittweite = (xwe-xwa) / 360. * schrittweiteG;
				// Auslesen der harmonischen Schwingungen
				n = Convert::ToInt32(this->tB_harmonisch->Text);
				// Auslesen der Amplitude
				a = Convert::ToDouble(this->tB_Amplitude->Text);
			 
			    // Kontrollrahmen für die Zeichnungsfläche
			    g->DrawRectangle(gcnew Pen(Color::Aqua),xsa,yse,xse-xsa,ysa-yse);
   
                // Konstruktion des Koordinatensystems

                // x-Achse: Strich von (xwa,0) nach (xwe,0)
                x1 = trans(xsa,xse,xwa,xwe,xwa);
				y1 = trans(ysa,yse,ywa,ywe,0.);
				x2 = trans(xsa,xse,xwa,xwe,xwe);
				g->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y1);
             
			    // x-Achse: Pfeilspitze
				x1 = trans(xsa,xse,xwa,xwe,xwe);
				x2 = trans(xsa,xse,xwa,xwe,xwe)-5;
				y2 = trans(ysa,yse,ywa,ywe,0.)+5;
				g->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y2);
				y2 = trans(ysa,yse,ywa,ywe,0.)-5;
			    g->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y2);
             
			    // y-Achse: Strich von (0,ywa) nach (0,ywe)
			    x1 = trans(xsa,xse,xwa,xwe,0.);
				y1 = trans(ysa,yse,ywa,ywe,ywa);
                y2 = trans(ysa,yse,ywa,ywe,ywe);
				g->DrawLine(gcnew Pen(Color::Black), x1, y1, x1, y2);
             
			    // y-Achse: Pfeilspitze
			    y1 = trans(ysa,yse,ywa,ywe,ywe),
				x2 = trans(xsa,xse,xwa,xwe,0.)-5;
				y2 = trans(ysa,yse,ywa,ywe,ywe)+5;
				g->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y2);
			    x2 = trans(xsa,xse,xwa,xwe,0.)+5;
				g->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y2);

				// Amplitude: Strich von (xwa,a) nach (xwe,a) und von (xwa,-a) bis (xwe,-a)
                x1 = trans(xsa,xse,xwa,xwe,xwa);
				y1 = trans(ysa,yse,ywa,ywe,a);
				x2 = trans(xsa,xse,xwa,xwe,xwe);
				y2 = trans(ysa,yse,ywa,ywe,-a);
				g->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y1);
				g->DrawLine(gcnew Pen(Color::Black), x1, y2, x2, y2);
				// Beschriftung
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",16 );
                SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				g->DrawString("A",drawFont,drawBrush,x1,y1);
				g->DrawString("-A",drawFont,drawBrush,x1,y2);
             
			    // Konstruktion des Graphen

			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf += schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   y1 = trans(ysa,yse,ywa,ywe,f(xlauf-schrittweite,n,a));
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   y2 = trans(ysa,yse,ywa,ywe,f(xlauf,n,a));
				   g->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
			    }
			 }
			 catch (Exception ^e)
			 {
				 MessageBox::Show("Eingabe nicht numerisch - bitte korrigieren!","Eingabefehler");
			 }
			 
		 } // Ende bt_zeichne_Click
		 // Rechteck-Funktion
		 float f(float x, int n, float a)
		 {
			 float s = 0.0;
			 int i, k;
			 for (i = 1; i <= n; i++)
			 {
				 k = 2 * i - 1;
				 s += 1./k * sin(k*x);
			 }
			 return 4*a/3.1415926*s;
		 }

   }; // Ende class

}  // Ende namespace
