#pragma once
#include "Transformation.h"
#include <math.h>

namespace Programm814 {

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
	private: System::Windows::Forms::Label^  lb_f;
	private: System::Windows::Forms::TextBox^  tB_a;
	private: System::Windows::Forms::Label^  lbQuadrat;


	internal: System::Windows::Forms::TextBox^  tB_b;
	private: System::Windows::Forms::Label^  lbLinear;
	internal: 
	private: 



	private: System::Windows::Forms::TextBox^  tB_c;
	private: System::Windows::Forms::Button^  bt_zeichne;


	private: System::Windows::Forms::GroupBox^  gB_welt;
	private: System::Windows::Forms::TextBox^  tB_schrittweite;
	private: System::Windows::Forms::Label^  lb_xwa;
	private: System::Windows::Forms::Label^  lb_schrittweite;
	private: System::Windows::Forms::TextBox^  tB_xwa;
	private: System::Windows::Forms::Label^  lb_xwe;
	private: System::Windows::Forms::TextBox^  tB_xwe;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	protected: 

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
			this->lb_f = (gcnew System::Windows::Forms::Label());
			this->tB_a = (gcnew System::Windows::Forms::TextBox());
			this->lbQuadrat = (gcnew System::Windows::Forms::Label());
			this->tB_b = (gcnew System::Windows::Forms::TextBox());
			this->lbLinear = (gcnew System::Windows::Forms::Label());
			this->tB_c = (gcnew System::Windows::Forms::TextBox());
			this->bt_zeichne = (gcnew System::Windows::Forms::Button());
			this->gB_welt = (gcnew System::Windows::Forms::GroupBox());
			this->tB_schrittweite = (gcnew System::Windows::Forms::TextBox());
			this->lb_xwa = (gcnew System::Windows::Forms::Label());
			this->lb_schrittweite = (gcnew System::Windows::Forms::Label());
			this->tB_xwa = (gcnew System::Windows::Forms::TextBox());
			this->lb_xwe = (gcnew System::Windows::Forms::Label());
			this->tB_xwe = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->gB_welt->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
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
			// tB_a
			// 
			this->tB_a->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_a->Location = System::Drawing::Point(58, 30);
			this->tB_a->Name = L"tB_a";
			this->tB_a->Size = System::Drawing::Size(40, 30);
			this->tB_a->TabIndex = 1;
			// 
			// lbQuadrat
			// 
			this->lbQuadrat->AutoSize = true;
			this->lbQuadrat->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbQuadrat->Location = System::Drawing::Point(100, 33);
			this->lbQuadrat->Name = L"lbQuadrat";
			this->lbQuadrat->Size = System::Drawing::Size(47, 23);
			this->lbQuadrat->TabIndex = 12;
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
			// lbLinear
			// 
			this->lbLinear->AutoSize = true;
			this->lbLinear->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbLinear->Location = System::Drawing::Point(192, 33);
			this->lbLinear->Name = L"lbLinear";
			this->lbLinear->Size = System::Drawing::Size(37, 23);
			this->lbLinear->TabIndex = 14;
			this->lbLinear->Text = L"x + ";
			// 
			// tB_c
			// 
			this->tB_c->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_c->Location = System::Drawing::Point(230, 30);
			this->tB_c->Name = L"tB_c";
			this->tB_c->Size = System::Drawing::Size(40, 30);
			this->tB_c->TabIndex = 3;
			// 
			// bt_zeichne
			// 
			this->bt_zeichne->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_zeichne->Location = System::Drawing::Point(18, 96);
			this->bt_zeichne->Name = L"bt_zeichne";
			this->bt_zeichne->Size = System::Drawing::Size(74, 33);
			this->bt_zeichne->TabIndex = 7;
			this->bt_zeichne->Text = L"zeichne";
			this->bt_zeichne->UseVisualStyleBackColor = true;
			this->bt_zeichne->Click += gcnew System::EventHandler(this, &Form1::bt_zeichne_Click);
			// 
			// gB_welt
			// 
			this->gB_welt->Controls->Add(this->tB_schrittweite);
			this->gB_welt->Controls->Add(this->lb_xwa);
			this->gB_welt->Controls->Add(this->lb_schrittweite);
			this->gB_welt->Controls->Add(this->tB_xwa);
			this->gB_welt->Controls->Add(this->lb_xwe);
			this->gB_welt->Controls->Add(this->tB_xwe);
			this->gB_welt->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_welt->Location = System::Drawing::Point(320, 10);
			this->gB_welt->Name = L"gB_welt";
			this->gB_welt->Size = System::Drawing::Size(320, 80);
			this->gB_welt->TabIndex = 22;
			this->gB_welt->TabStop = false;
			this->gB_welt->Text = L"Weltkoordinaten";
			// 
			// tB_schrittweite
			// 
			this->tB_schrittweite->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_schrittweite->Location = System::Drawing::Point(271, 30);
			this->tB_schrittweite->Name = L"tB_schrittweite";
			this->tB_schrittweite->Size = System::Drawing::Size(40, 26);
			this->tB_schrittweite->TabIndex = 6;
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
			// lb_schrittweite
			// 
			this->lb_schrittweite->AutoSize = true;
			this->lb_schrittweite->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_schrittweite->Location = System::Drawing::Point(184, 33);
			this->lb_schrittweite->Name = L"lb_schrittweite";
			this->lb_schrittweite->Size = System::Drawing::Size(84, 18);
			this->lb_schrittweite->TabIndex = 19;
			this->lb_schrittweite->Text = L"Schrittweite";
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tB_c);
			this->groupBox1->Controls->Add(this->lbLinear);
			this->groupBox1->Controls->Add(this->tB_b);
			this->groupBox1->Controls->Add(this->lbQuadrat);
			this->groupBox1->Controls->Add(this->tB_a);
			this->groupBox1->Controls->Add(this->lb_f);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(10, 10);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(300, 80);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Funktionsdefinition";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(652, 562);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->gB_welt);
			this->Controls->Add(this->bt_zeichne);
			this->Name = L"Form1";
			this->Text = L"Zeichnung quadratischer Parablen";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->gB_welt->ResumeLayout(false);
			this->gB_welt->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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
                 this->tB_schrittweite->Text = "0,01";
                 // Group "Funktion"
                 this->tB_a->Text = "1";
                 this->tB_b->Text = "2";
                 this->tB_c->Text = "3";
			 }
private: System::Void bt_zeichne_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Diese Methode wird aufgerufen, wenn der Button "Zeichne ..." geclickt wird
			 // Deklaration der lokalen Variablen
			 int    xsa = 50;   // x-Richtung, Screen, Anfang
			 int    xse = 610;  // x-Richtung, Screen, Ende
			 int    ysa = 550;  // y-Richtung, Screen, Anfang
			 int    yse = 150;  // y-Richtung, Screen, Ende
             double xwa;        // x-Richtung, Welt, Anfang aus Maske
			 double xwe;        // x-Richtung, Welt, Ende   aus Maske
			 double ywa = -1.;  // y-Richtung, Welt, Anfang
			 double ywe = 1.;   // y-Richtung, Welt, Ende
             double schrittweite;
			 int    x1;         // x-Koordinate des ersten Punktes einer Linie
			 int    y1;         // y-Koordinate des ersten Punktes einer Linie
			 int    x2;         // x-Koordinate des zweiten Punktes einer Linie
			 int    y2;         // y-Koordinate des zweiten Punktes einer Linie
			 double xlauf, ylauf, xtemp, ytemp;
			 double a, b, c;    // Koeffizienten in ax² + bx + c
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
                // Auslesen der Schrittweite, textBox ==> double
			    schrittweite = Convert::ToDouble(tB_schrittweite->Text);
				// Koeffizienten der Funktion f(x)
				a = Convert::ToDouble(tB_a->Text);
				b = Convert::ToDouble(tB_b->Text);
				c = Convert::ToDouble(tB_c->Text);
				// Errechnung der max. und min. Werte für y aus f(x)
                for (xlauf = xwa; xlauf <= xwe; xlauf += schrittweite)
                {
	               ytemp = a * pow(xlauf,2) + b*xlauf +c;
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
				if (ywe-ywa > 20.) ssw = 2;
				if (ywe-ywa > 50.) ssw = 5;
				for (ylauf = (int)(ywa+0.99); ylauf <= (int)(ywe-0.99); ylauf += ssw)
                {
	               x1 = trans(xsa,xse,xwa,xwe,0.);
				   y1 = trans(ysa,yse,ywa,ywe,ylauf);
				   g->DrawLine(gcnew Pen(Color::Black), x1-2, y1, x1+2, y1);
				   if (ylauf != 0.) g->DrawString(""+ylauf,dF1,dB,x1,y1);
			    }
				// Konstruktion des Graphen
			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf = xlauf + schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   xtemp = xlauf-schrittweite;
				   ytemp = a * pow(xtemp,2) + b*xtemp +c;
				   y1 = trans(ysa,yse,ywa,ywe,ytemp);
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   ytemp = a * pow(xlauf,2) + b*xlauf +c;
				   y2 = trans(ysa,yse,ywa,ywe,ytemp);
				   g->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
			    }  
			 }
			 catch (Exception ^e)
			 {
				 MessageBox::Show("Eingabe nicht numerisch - bitte korrigieren!","Eingabefehler");
			 }
		 }
};
}

