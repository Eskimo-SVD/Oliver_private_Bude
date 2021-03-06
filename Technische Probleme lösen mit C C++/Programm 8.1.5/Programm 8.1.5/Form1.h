#pragma once
#include "Transformation.h"
#include <math.h>
namespace Programm815 {

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
	private: System::Windows::Forms::TextBox^  tB_alpha;
	protected: 

	private: System::Windows::Forms::Label^  lbLinear;
	private: System::Windows::Forms::TextBox^  tB_schrittweite;
	private: System::Windows::Forms::Label^  lb_schrittweite;


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
			this->tB_alpha = (gcnew System::Windows::Forms::TextBox());
			this->lbLinear = (gcnew System::Windows::Forms::Label());
			this->tB_schrittweite = (gcnew System::Windows::Forms::TextBox());
			this->lb_schrittweite = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bt_zeichne
			// 
			this->bt_zeichne->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_zeichne->Location = System::Drawing::Point(421, 14);
			this->bt_zeichne->Name = L"bt_zeichne";
			this->bt_zeichne->Size = System::Drawing::Size(74, 33);
			this->bt_zeichne->TabIndex = 8;
			this->bt_zeichne->Text = L"zeichne";
			this->bt_zeichne->UseVisualStyleBackColor = true;
			this->bt_zeichne->Click += gcnew System::EventHandler(this, &Form1::bt_zeichne_Click);
			// 
			// tB_alpha
			// 
			this->tB_alpha->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_alpha->Location = System::Drawing::Point(58, 14);
			this->tB_alpha->Name = L"tB_alpha";
			this->tB_alpha->Size = System::Drawing::Size(40, 30);
			this->tB_alpha->TabIndex = 9;
			// 
			// lbLinear
			// 
			this->lbLinear->AutoSize = true;
			this->lbLinear->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbLinear->Location = System::Drawing::Point(14, 17);
			this->lbLinear->Name = L"lbLinear";
			this->lbLinear->Size = System::Drawing::Size(32, 23);
			this->lbLinear->TabIndex = 15;
			this->lbLinear->Text = L"α =";
			// 
			// tB_schrittweite
			// 
			this->tB_schrittweite->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_schrittweite->Location = System::Drawing::Point(198, 18);
			this->tB_schrittweite->Name = L"tB_schrittweite";
			this->tB_schrittweite->Size = System::Drawing::Size(60, 26);
			this->tB_schrittweite->TabIndex = 20;
			// 
			// lb_schrittweite
			// 
			this->lb_schrittweite->AutoSize = true;
			this->lb_schrittweite->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_schrittweite->Location = System::Drawing::Point(111, 21);
			this->lb_schrittweite->Name = L"lb_schrittweite";
			this->lb_schrittweite->Size = System::Drawing::Size(84, 18);
			this->lb_schrittweite->TabIndex = 21;
			this->lb_schrittweite->Text = L"Schrittweite";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(652, 566);
			this->Controls->Add(this->tB_schrittweite);
			this->Controls->Add(this->lb_schrittweite);
			this->Controls->Add(this->lbLinear);
			this->Controls->Add(this->tB_alpha);
			this->Controls->Add(this->bt_zeichne);
			this->Name = L"Form1";
			this->Text = L"Spannungsteilerkennlinien";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
			 private: System::Void bt_zeichne_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 // Diese Methode wird aufgerufen, wenn der Button "Zeichne ..." geclickt wird
				 // Deklaration der lokalen Variablen
				 int    xsa = 50;   // x-Richtung, Screen, Anfang
				 int    xse = 610;  // x-Richtung, Screen, Ende
				 int    ysa = 550;  // y-Richtung, Screen, Anfang
				 int    yse = 100;  // y-Richtung, Screen, Ende
				 double xwa = -0.05;// x-Richtung, Welt, Anfang
				 double xwe = 1.0;  // x-Richtung, Welt, Ende
				 double ywa = -0.05;// y-Richtung, Welt, Anfang
				 double ywe = 1.0;  // y-Richtung, Welt, Ende
				 double schrittweite;
				 int    x1;         // x-Koordinate des ersten Punktes einer Linie
				 int    y1;         // y-Koordinate des ersten Punktes einer Linie
				 int    x2;         // x-Koordinate des zweiten Punktes einer Linie
				 int    y2;         // y-Koordinate des zweiten Punktes einer Linie
				 double xlauf, ylauf, xtemp, ytemp;
				 double alpha;      // Koeffizient in f(x)
				 // Create font and brush.
				 System::Drawing::Font^ dF = gcnew System::Drawing::Font("Arial",10);
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
					// Auslesen der Schrittweite, textBox ==> double
					schrittweite = Convert::ToDouble(tB_schrittweite->Text);
					// Koeffizienten der Funktion f(x)
					alpha = Convert::ToDouble(tB_alpha->Text);
					// Überprüfung alpha >= 0.0
					if (alpha < 0.0)
					{
						MessageBox::Show("alpha muss positiv sein! - bitte korrigieren!","Eingabefehler");
					}
					else
					{
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
						g->DrawString("x",dF,dB,x1-10,y1-20);
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
						g->DrawString("y",dF,dB,x1+10,y1);
						// Skalierung der Achsen
						for (xlauf = 0.0; xlauf <= 0.9; xlauf += 0.1)
						{
						   x1 = trans(xsa,xse,xwa,xwe,xlauf);
						   y1 = trans(ysa,yse,ywa,ywe,0.);
						   g->DrawLine(gcnew Pen(Color::Black), x1, y1-2, x1, y1+2);
						   g->DrawString(""+xlauf,dF,dB,x1,y1);
						}
						// y-Achse
						for (ylauf = 0.0; ylauf <= 0.9; ylauf += 0.1)
						{
						   x1 = trans(xsa,xse,xwa,xwe,0.);
						   y1 = trans(ysa,yse,ywa,ywe,ylauf);
						   g->DrawLine(gcnew Pen(Color::Black), x1-2, y1, x1+2, y1);
						   if (ylauf != 0.) g->DrawString(""+ylauf,dF,dB,x1,y1);
						}
						// Konstruktion des Graphen
						for (xlauf = schrittweite; xlauf <= xwe; xlauf += schrittweite)
						{
						   x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
						   xtemp = xlauf-schrittweite;
						   ytemp = xtemp / ( 1 + alpha*xtemp - alpha*pow(xtemp,2));				   y1 = trans(ysa,yse,ywa,ywe,ytemp);
						   x2 = trans(xsa,xse,xwa,xwe,xlauf);
						   ytemp = xlauf / ( 1 + alpha*xlauf - alpha*pow(xlauf,2));
						   y2 = trans(ysa,yse,ywa,ywe,ytemp);
						   g->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
						} 
					}
				 }
				 catch (Exception ^e)
				 {
					 MessageBox::Show("Eingabe nicht numerisch - bitte korrigieren!","Eingabefehler");
				 }
			 }
			 private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->tB_alpha->Text = "2,5";
				 this->tB_schrittweite->Text = "0,001";
			 }
};
}