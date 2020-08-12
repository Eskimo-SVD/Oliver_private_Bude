#pragma once

#include <math.h>
#include "Transformation.h"

namespace Programm91 {

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

	protected: 
	private: System::Windows::Forms::Label^  lb_xwa;
	private: System::Windows::Forms::GroupBox^  gB_Funktion;

	private: System::Windows::Forms::TextBox^  tB_c;
	private: System::Windows::Forms::Label^  lbQuadrat;

	internal: System::Windows::Forms::TextBox^  tB_b;
	private: System::Windows::Forms::Label^  lbKubik;
	internal: 
	private: 

	internal: 
	private: System::Windows::Forms::TextBox^  tB_a;
	private: System::Windows::Forms::Label^  lb_f;

	private: System::Windows::Forms::TextBox^  tB_xwa;
	private: System::Windows::Forms::Label^  lb_xwe;
	private: System::Windows::Forms::TextBox^  tB_xwe;
	private: System::Windows::Forms::GroupBox^  gB_welt;
	private: System::Windows::Forms::Button^  bt_Auswertung;

	private: System::Windows::Forms::Label^  lbLinear;
	private: System::Windows::Forms::TextBox^  tB_d;
	private: System::Windows::Forms::GroupBox^  gB_Ableitungen;
	private: System::Windows::Forms::Label^  lb_f1s;
	private: System::Windows::Forms::Label^  lb_f2s;
	private: System::Windows::Forms::Label^  lb_f3s;








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
			this->lb_xwa = (gcnew System::Windows::Forms::Label());
			this->gB_Funktion = (gcnew System::Windows::Forms::GroupBox());
			this->lbLinear = (gcnew System::Windows::Forms::Label());
			this->tB_d = (gcnew System::Windows::Forms::TextBox());
			this->tB_c = (gcnew System::Windows::Forms::TextBox());
			this->lbQuadrat = (gcnew System::Windows::Forms::Label());
			this->tB_b = (gcnew System::Windows::Forms::TextBox());
			this->lbKubik = (gcnew System::Windows::Forms::Label());
			this->tB_a = (gcnew System::Windows::Forms::TextBox());
			this->lb_f = (gcnew System::Windows::Forms::Label());
			this->tB_xwa = (gcnew System::Windows::Forms::TextBox());
			this->lb_xwe = (gcnew System::Windows::Forms::Label());
			this->tB_xwe = (gcnew System::Windows::Forms::TextBox());
			this->gB_welt = (gcnew System::Windows::Forms::GroupBox());
			this->bt_Auswertung = (gcnew System::Windows::Forms::Button());
			this->gB_Ableitungen = (gcnew System::Windows::Forms::GroupBox());
			this->lb_f3s = (gcnew System::Windows::Forms::Label());
			this->lb_f1s = (gcnew System::Windows::Forms::Label());
			this->lb_f2s = (gcnew System::Windows::Forms::Label());
			this->gB_Funktion->SuspendLayout();
			this->gB_welt->SuspendLayout();
			this->gB_Ableitungen->SuspendLayout();
			this->SuspendLayout();
			// 
			// lb_xwa
			// 
			this->lb_xwa->AutoSize = true;
			this->lb_xwa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_xwa->Location = System::Drawing::Point(16, 33);
			this->lb_xwa->Name = L"lb_xwa";
			this->lb_xwa->Size = System::Drawing::Size(40, 18);
			this->lb_xwa->TabIndex = 23;
			this->lb_xwa->Text = L"x von";
			// 
			// gB_Funktion
			// 
			this->gB_Funktion->Controls->Add(this->lbLinear);
			this->gB_Funktion->Controls->Add(this->tB_d);
			this->gB_Funktion->Controls->Add(this->tB_c);
			this->gB_Funktion->Controls->Add(this->lbQuadrat);
			this->gB_Funktion->Controls->Add(this->tB_b);
			this->gB_Funktion->Controls->Add(this->lbKubik);
			this->gB_Funktion->Controls->Add(this->tB_a);
			this->gB_Funktion->Controls->Add(this->lb_f);
			this->gB_Funktion->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_Funktion->Location = System::Drawing::Point(10, 31);
			this->gB_Funktion->Name = L"gB_Funktion";
			this->gB_Funktion->Size = System::Drawing::Size(380, 80);
			this->gB_Funktion->TabIndex = 26;
			this->gB_Funktion->TabStop = false;
			this->gB_Funktion->Text = L"Funktionsdefinition";
			// 
			// lbLinear
			// 
			this->lbLinear->AutoSize = true;
			this->lbLinear->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbLinear->Location = System::Drawing::Point(283, 33);
			this->lbLinear->Name = L"lbLinear";
			this->lbLinear->Size = System::Drawing::Size(37, 23);
			this->lbLinear->TabIndex = 16;
			this->lbLinear->Text = L"x + ";
			// 
			// tB_d
			// 
			this->tB_d->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_d->Location = System::Drawing::Point(322, 30);
			this->tB_d->Name = L"tB_d";
			this->tB_d->Size = System::Drawing::Size(40, 30);
			this->tB_d->TabIndex = 15;
			// 
			// tB_c
			// 
			this->tB_c->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_c->Location = System::Drawing::Point(241, 30);
			this->tB_c->Name = L"tB_c";
			this->tB_c->Size = System::Drawing::Size(40, 30);
			this->tB_c->TabIndex = 3;
			// 
			// lbQuadrat
			// 
			this->lbQuadrat->AutoSize = true;
			this->lbQuadrat->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbQuadrat->Location = System::Drawing::Point(192, 33);
			this->lbQuadrat->Name = L"lbQuadrat";
			this->lbQuadrat->Size = System::Drawing::Size(47, 23);
			this->lbQuadrat->TabIndex = 14;
			this->lbQuadrat->Text = L"x² + ";
			// 
			// tB_b
			// 
			this->tB_b->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_b->Location = System::Drawing::Point(150, 30);
			this->tB_b->Name = L"tB_b";
			this->tB_b->Size = System::Drawing::Size(40, 30);
			this->tB_b->TabIndex = 2;
			// 
			// lbKubik
			// 
			this->lbKubik->AutoSize = true;
			this->lbKubik->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbKubik->Location = System::Drawing::Point(100, 33);
			this->lbKubik->Name = L"lbKubik";
			this->lbKubik->Size = System::Drawing::Size(47, 23);
			this->lbKubik->TabIndex = 12;
			this->lbKubik->Text = L"x³ + ";
			// 
			// tB_a
			// 
			this->tB_a->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_a->Location = System::Drawing::Point(58, 30);
			this->tB_a->Name = L"tB_a";
			this->tB_a->Size = System::Drawing::Size(40, 30);
			this->tB_a->TabIndex = 1;
			// 
			// lb_f
			// 
			this->lb_f->AutoSize = true;
			this->lb_f->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_f->Location = System::Drawing::Point(4, 33);
			this->lb_f->Name = L"lb_f";
			this->lb_f->Size = System::Drawing::Size(57, 23);
			this->lb_f->TabIndex = 0;
			this->lb_f->Text = L"f(x) = ";
			// 
			// tB_xwa
			// 
			this->tB_xwa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_xwa->Location = System::Drawing::Point(59, 30);
			this->tB_xwa->Name = L"tB_xwa";
			this->tB_xwa->Size = System::Drawing::Size(40, 26);
			this->tB_xwa->TabIndex = 4;
			// 
			// lb_xwe
			// 
			this->lb_xwe->AutoSize = true;
			this->lb_xwe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_xwe->Location = System::Drawing::Point(101, 33);
			this->lb_xwe->Name = L"lb_xwe";
			this->lb_xwe->Size = System::Drawing::Size(38, 18);
			this->lb_xwe->TabIndex = 27;
			this->lb_xwe->Text = L"x bis";
			// 
			// tB_xwe
			// 
			this->tB_xwe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_xwe->Location = System::Drawing::Point(142, 30);
			this->tB_xwe->Name = L"tB_xwe";
			this->tB_xwe->Size = System::Drawing::Size(40, 26);
			this->tB_xwe->TabIndex = 5;
			// 
			// gB_welt
			// 
			this->gB_welt->Controls->Add(this->lb_xwa);
			this->gB_welt->Controls->Add(this->tB_xwa);
			this->gB_welt->Controls->Add(this->lb_xwe);
			this->gB_welt->Controls->Add(this->tB_xwe);
			this->gB_welt->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_welt->Location = System::Drawing::Point(396, 31);
			this->gB_welt->Name = L"gB_welt";
			this->gB_welt->Size = System::Drawing::Size(200, 80);
			this->gB_welt->TabIndex = 25;
			this->gB_welt->TabStop = false;
			this->gB_welt->Text = L"Weltkoordinaten";
			// 
			// bt_Auswertung
			// 
			this->bt_Auswertung->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_Auswertung->Location = System::Drawing::Point(610, 58);
			this->bt_Auswertung->Name = L"bt_Auswertung";
			this->bt_Auswertung->Size = System::Drawing::Size(110, 33);
			this->bt_Auswertung->TabIndex = 24;
			this->bt_Auswertung->Text = L"Auswertung";
			this->bt_Auswertung->UseVisualStyleBackColor = true;
			this->bt_Auswertung->Click += gcnew System::EventHandler(this, &Form1::bt_Auswertung_Click);
			// 
			// gB_Ableitungen
			// 
			this->gB_Ableitungen->Controls->Add(this->lb_f3s);
			this->gB_Ableitungen->Controls->Add(this->lb_f1s);
			this->gB_Ableitungen->Controls->Add(this->lb_f2s);
			this->gB_Ableitungen->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_Ableitungen->Location = System::Drawing::Point(520, 132);
			this->gB_Ableitungen->Name = L"gB_Ableitungen";
			this->gB_Ableitungen->Size = System::Drawing::Size(200, 149);
			this->gB_Ableitungen->TabIndex = 28;
			this->gB_Ableitungen->TabStop = false;
			this->gB_Ableitungen->Text = L"Ableitungen";
			// 
			// lb_f3s
			// 
			this->lb_f3s->AutoSize = true;
			this->lb_f3s->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_f3s->Location = System::Drawing::Point(16, 107);
			this->lb_f3s->Name = L"lb_f3s";
			this->lb_f3s->Size = System::Drawing::Size(59, 18);
			this->lb_f3s->TabIndex = 28;
			this->lb_f3s->Text = L"f\'\'\'(x) =";
			// 
			// lb_f1s
			// 
			this->lb_f1s->AutoSize = true;
			this->lb_f1s->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_f1s->Location = System::Drawing::Point(16, 33);
			this->lb_f1s->Name = L"lb_f1s";
			this->lb_f1s->Size = System::Drawing::Size(49, 18);
			this->lb_f1s->TabIndex = 23;
			this->lb_f1s->Text = L"f\'(x) =";
			// 
			// lb_f2s
			// 
			this->lb_f2s->AutoSize = true;
			this->lb_f2s->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_f2s->Location = System::Drawing::Point(16, 70);
			this->lb_f2s->Name = L"lb_f2s";
			this->lb_f2s->Size = System::Drawing::Size(54, 18);
			this->lb_f2s->TabIndex = 27;
			this->lb_f2s->Text = L"f\'\'(x) =";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 562);
			this->Controls->Add(this->gB_Ableitungen);
			this->Controls->Add(this->gB_Funktion);
			this->Controls->Add(this->gB_welt);
			this->Controls->Add(this->bt_Auswertung);
			this->Name = L"Form1";
			this->Text = L"Kurvendiskussion";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->gB_Funktion->ResumeLayout(false);
			this->gB_Funktion->PerformLayout();
			this->gB_welt->ResumeLayout(false);
			this->gB_welt->PerformLayout();
			this->gB_Ableitungen->ResumeLayout(false);
			this->gB_Ableitungen->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 // Diese Methode wird beim Load der Maske aufgerufen
				 // Versorgung der Koordinatenfelder mit Anfangswerten (Defaults)
				 // Group "Weltkoordinaten"
				 this->tB_xwa->Text = "-5,0";
                 this->tB_xwe->Text = "5,0";
                 // Group "Funktion"
                 this->tB_a->Text = "1";
                 this->tB_b->Text = "2";
                 this->tB_c->Text = "3";
				 this->tB_d->Text = "4";
			 }
private: System::Void bt_Auswertung_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Diese Methode wird aufgerufen, wenn der Button "Auswertung" geclickt wird
			 // Deklaration der lokalen Variablen
			 int    xsa = 10;   // x-Richtung, Screen, Anfang
			 int    xse = 510;  // x-Richtung, Screen, Ende
			 int    ysa = 550;  // y-Richtung, Screen, Anfang
			 int    yse = 130;  // y-Richtung, Screen, Ende
             double xwa;        // x-Richtung, Welt, Anfang aus Maske
			 double xwe;        // x-Richtung, Welt, Ende   aus Maske
			 double ywa = -1.;  // y-Richtung, Welt, Anfang
			 double ywe = 1.;   // y-Richtung, Welt, Ende
             double schrittweite = 0.001; // Schrittweite zur Zeichnungserstellung
			 int    x1;         // x-Koordinate des ersten Punktes einer Linie
			 int    y1;         // y-Koordinate des ersten Punktes einer Linie
			 int    x2;         // x-Koordinate des zweiten Punktes einer Linie
			 int    y2;         // y-Koordinate des zweiten Punktes einer Linie
			 double xlauf, ylauf, xtemp, ytemp; // Hilfsvariablen
			 double a, b, c, d;       // Koeffizienten in f(x) = ax³ + bx² + cx + d
			 double af1s, bf1s, cf1s; // Koeffizienten der 1.Ableitung f'(x) = 3ax² + 2bx + c
			 double af2s, bf2s;       // Koeffizienten der 2.Ableitung f''(x) = 6ax + 2b
			 double af3s;             // Koeffizienten der 3.Ableitung f'''(x) = 6a
			 int ssw;           //Skalierungs-Schritt-Weite
             // Create font and brush.
             System::Drawing::Font^ dF1 = gcnew System::Drawing::Font("Arial",6);
			 System::Drawing::Font^ dF2 = gcnew System::Drawing::Font("Arial",10);
             SolidBrush^ dB = gcnew SolidBrush( Color::Black );
			 // Erzeugung eines neuen Grafik-Objektes
			 Graphics ^g = this->CreateGraphics();
			 // Definition der Hintergrundfarbe durch R-G-B-Code
			 Color cl = Control::BackColor;
			 // Bereinigen des Grafik-Objektes für Folgeaufruf
			 g->Clear(cl);
             
			 // Übernahme der Einträge aus den TextBoxen mit try - catch
			 // fehlerhafte Eingabe ==> MessageBox
			 try
			 {
                // Auslesen der Welt-Koordinaten, textBox ==> double
			    xwa = Convert::ToDouble(tB_xwa->Text);
			    xwe = Convert::ToDouble(tB_xwe->Text);
				// Koeffizienten der Funktion f(x)
				a = Convert::ToDouble(tB_a->Text);
				b = Convert::ToDouble(tB_b->Text);
				c = Convert::ToDouble(tB_c->Text);
				d = Convert::ToDouble(tB_d->Text);
				// Berechnung der Ableitungen
				af1s = 3.*a;
				bf1s = 2.*b;
                cf1s = c;
				af2s = 6.*a;
				bf2s = bf1s;
				af3s = af2s;
				// Label für f'(x)
				this->lb_f1s->ForeColor = Color::Blue;
				this->lb_f1s->Text = "f'(x) = "+System::Convert::ToString(af1s)+"x²";
				if (bf1s >= 0.0) 
				{
					this->lb_f1s->Text += " + "+System::Convert::ToString(bf1s)+"x";
				}
				else
				{
					this->lb_f1s->Text += " "+System::Convert::ToString(bf1s)+"x";
				}
				if (cf1s >= 0.0) 
				{
					this->lb_f1s->Text += " + "+System::Convert::ToString(cf1s);
				}
				else
				{
					this->lb_f1s->Text += " "+System::Convert::ToString(cf1s);
				}
				// Label für f''(x)
				this->lb_f2s->ForeColor = Color::Brown;
				this->lb_f2s->Text = "f''(x) = "+System::Convert::ToString(af2s)+"x";
				if (bf2s >= 0.0) 
				{
					this->lb_f2s->Text += " + "+System::Convert::ToString(bf2s);
				}
				else
				{
					this->lb_f2s->Text += " "+System::Convert::ToString(bf2s);
				}
				// Label für f'''(x)
				this->lb_f3s->ForeColor = Color::Green;
				this->lb_f3s->Text = "f'''(x) = "+System::Convert::ToString(af3s);
				// Errechnung der max. und min. Werte für y aus f(x), f'(x), f''(x) und f'''(x)
                for (xlauf = xwa; xlauf <= xwe; xlauf += schrittweite)
                {
	               ytemp = a*pow(xlauf,3) + b*pow(xlauf,2) + c*xlauf + d;
				   if (ytemp < ywa) ywa = ytemp;
				   if (ytemp > ywe) ywe = ytemp;
				   ytemp = af1s*pow(xlauf,2) + bf1s*xlauf + cf1s;
				   if (ytemp < ywa) ywa = ytemp;
				   if (ytemp > ywe) ywe = ytemp;
				   ytemp = af2s*xlauf + bf2s;
				   if (ytemp < ywa) ywa = ytemp;
				   if (ytemp > ywe) ywe = ytemp;
				   ytemp = af3s;
				   if (ytemp < ywa) ywa = ytemp;
				   if (ytemp > ywe) ywe = ytemp;
			    }
				// "Glätten" der Werte
				ywa = (float)((int)(ywa - 0.99));
				ywe = (float)((int)(ywe + 0.99));
			    // Kontrollrahmen für die Zeichnungsfläche
				g->DrawRectangle(gcnew Pen(Color::Blue),xsa,yse,xse-xsa,ysa-yse);
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
				// Beschriftung
				g->DrawString("x",dF2,dB,x1-10,y1-20);
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
				// Beschriftung
				g->DrawString("y",dF2,dB,x1+10,y1);
			    // Skalierung der Achsen
				// x-Achse
				ssw = 1;
				if (xwe-xwa > 20.) ssw = 2;
				if (xwe-xwa > 50.) ssw = 5;
				for (xlauf = (int)(xwa+0.99); xlauf <= (int)(xwe-0.99); xlauf += ssw)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf);
				   y1 = trans(ysa,yse,ywa,ywe,0.);
				   g->DrawLine(gcnew Pen(Color::Black), x1, y1-2, x1, y1+2);
				   g->DrawString(""+xlauf,dF1,dB,x1,y1);
			    }
				// y-Achse
				ssw = 1;
				if (ywe-ywa > 20.)  ssw = 2;
				if (ywe-ywa > 50.)  ssw = 5;
				if (ywe-ywa > 100.) ssw = 10;
				// positive y-Achse (von 0 ausgehend)
				for (ylauf = 0; ylauf <= (int)(ywe-0.99); ylauf += ssw)
                {
	               x1 = trans(xsa,xse,xwa,xwe,0.);
				   y1 = trans(ysa,yse,ywa,ywe,ylauf);
				   g->DrawLine(gcnew Pen(Color::Black), x1-2, y1, x1+2, y1);
				   if (ylauf != 0.) g->DrawString(""+ylauf,dF1,dB,x1,y1);
			    }
				// negative y-Achse (von 0 ausgehend)
				for (ylauf = 0; ylauf >= (int)(ywa+0.99); ylauf -= ssw)
                {
	               x1 = trans(xsa,xse,xwa,xwe,0.);
				   y1 = trans(ysa,yse,ywa,ywe,ylauf);
				   g->DrawLine(gcnew Pen(Color::Black), x1-2, y1, x1+2, y1);
				   if (ylauf != 0.) g->DrawString(""+ylauf,dF1,dB,x1,y1);
			    }
				// Konstruktion der Graphen
				// 1. f(x) 
			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf = xlauf + schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   xtemp = xlauf-schrittweite;
				   ytemp = a*pow(xtemp,3) + b*pow(xtemp,2) + c*xtemp + d;
				   y1 = trans(ysa,yse,ywa,ywe,ytemp);
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   ytemp = a*pow(xlauf,3) + b*pow(xlauf,2) + c*xlauf + d;
				   y2 = trans(ysa,yse,ywa,ywe,ytemp);
				   g->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
			    } 
				// 2. f'(x) 
			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf = xlauf + schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   xtemp = xlauf-schrittweite;
				   ytemp = af1s*pow(xtemp,2) + bf1s*xtemp + cf1s;
				   y1 = trans(ysa,yse,ywa,ywe,ytemp);
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   ytemp = af1s*pow(xlauf,2) + bf1s*xlauf + cf1s;
				   y2 = trans(ysa,yse,ywa,ywe,ytemp);
				   g->DrawLine(gcnew Pen(Color::Blue), x1, y1, x2, y2);
			    } 
				// 3. f''(x) 
			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf = xlauf + schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   xtemp = xlauf-schrittweite;
				   ytemp = af2s*xtemp + bf2s;
				   y1 = trans(ysa,yse,ywa,ywe,ytemp);
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   ytemp = af2s*xlauf + bf2s;
				   y2 = trans(ysa,yse,ywa,ywe,ytemp);
				   g->DrawLine(gcnew Pen(Color::Brown), x1, y1, x2, y2);
			    } 
				// 4. f''(x) 
			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf = xlauf + schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   xtemp = xlauf-schrittweite;
				   ytemp = af3s;
				   y1 = trans(ysa,yse,ywa,ywe,ytemp);
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   ytemp = af3s;
				   y2 = trans(ysa,yse,ywa,ywe,ytemp);
				   g->DrawLine(gcnew Pen(Color::Green), x1, y1, x2, y2);
			    } 
			 }
			 catch (Exception ^e)
			 {
				 MessageBox::Show("Eingabe nicht numerisch - bitte korrigieren!","Eingabefehler");
			 }
		 }
};
}

