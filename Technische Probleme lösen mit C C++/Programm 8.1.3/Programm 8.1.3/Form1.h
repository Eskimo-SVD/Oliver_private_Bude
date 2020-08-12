#include "Transformation.h"
#include "math.h"

#pragma once


namespace Programm813 {

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
    private: System::Windows::Forms::GroupBox^  gB_welt;
	private: System::Windows::Forms::Label^     lb_xwa;
	private: System::Windows::Forms::TextBox^   tB_xwa;
	private: System::Windows::Forms::Label^     lb_xwe;
	private: System::Windows::Forms::TextBox^   tB_xwe;
	private: System::Windows::Forms::Label^     lb_ywa;
	private: System::Windows::Forms::TextBox^   tB_ywa;
	private: System::Windows::Forms::Label^     lb_ywe;
	private: System::Windows::Forms::TextBox^   tB_ywe;
	private: System::Windows::Forms::Label^     lb_schrittweite;
	private: System::Windows::Forms::TextBox^   tB_schrittweite;
	// GroupBox "Screenkoordinaten	
	private: System::Windows::Forms::GroupBox^  gB_screen;
	private: System::Windows::Forms::Label^     lb_xsa;
    private: System::Windows::Forms::TextBox^   tB_xsa;
    private: System::Windows::Forms::Label^     lb_xse;
    private: System::Windows::Forms::TextBox^   tB_xse;
    private: System::Windows::Forms::Label^     lb_ysa;
	private: System::Windows::Forms::TextBox^   tB_ysa;
	private: System::Windows::Forms::Label^     lb_yse;
	private: System::Windows::Forms::TextBox^   tB_yse;
    // Button "Zeichne"
	private: System::Windows::Forms::Button^   bt_zeichne;

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
			this->gB_welt = (gcnew System::Windows::Forms::GroupBox());
			this->lb_ywe = (gcnew System::Windows::Forms::Label());
			this->tB_schrittweite = (gcnew System::Windows::Forms::TextBox());
			this->lb_xwa = (gcnew System::Windows::Forms::Label());
			this->lb_schrittweite = (gcnew System::Windows::Forms::Label());
			this->lb_ywa = (gcnew System::Windows::Forms::Label());
			this->tB_xwa = (gcnew System::Windows::Forms::TextBox());
			this->tB_ywa = (gcnew System::Windows::Forms::TextBox());
			this->lb_xwe = (gcnew System::Windows::Forms::Label());
			this->tB_xwe = (gcnew System::Windows::Forms::TextBox());
			this->tB_ywe = (gcnew System::Windows::Forms::TextBox());
			this->gB_screen = (gcnew System::Windows::Forms::GroupBox());
			this->lb_yse = (gcnew System::Windows::Forms::Label());
			this->lb_xsa = (gcnew System::Windows::Forms::Label());
			this->lb_ysa = (gcnew System::Windows::Forms::Label());
			this->tB_xsa = (gcnew System::Windows::Forms::TextBox());
			this->tB_ysa = (gcnew System::Windows::Forms::TextBox());
			this->lb_xse = (gcnew System::Windows::Forms::Label());
			this->tB_xse = (gcnew System::Windows::Forms::TextBox());
			this->tB_yse = (gcnew System::Windows::Forms::TextBox());
			this->bt_zeichne = (gcnew System::Windows::Forms::Button());
			this->gB_welt->SuspendLayout();
			this->gB_screen->SuspendLayout();
			this->SuspendLayout();
			// 
			// lb_Ueberschrift
			// 
			this->lb_Ueberschrift->AutoSize = true;
			this->lb_Ueberschrift->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Ueberschrift->Location = System::Drawing::Point(12, 23);
			this->lb_Ueberschrift->Name = L"lb_Ueberschrift";
			this->lb_Ueberschrift->Size = System::Drawing::Size(782, 26);
			this->lb_Ueberschrift->TabIndex = 0;
			this->lb_Ueberschrift->Text = L"Programm zur Darstellung der Koordiantentransformation \"Welt- in Screenkoordinate" 
				L"n\"";
			// 
			// gB_welt
			// 
			this->gB_welt->Controls->Add(this->lb_ywe);
			this->gB_welt->Controls->Add(this->tB_schrittweite);
			this->gB_welt->Controls->Add(this->lb_xwa);
			this->gB_welt->Controls->Add(this->lb_schrittweite);
			this->gB_welt->Controls->Add(this->lb_ywa);
			this->gB_welt->Controls->Add(this->tB_xwa);
			this->gB_welt->Controls->Add(this->tB_ywa);
			this->gB_welt->Controls->Add(this->lb_xwe);
			this->gB_welt->Controls->Add(this->tB_xwe);
			this->gB_welt->Controls->Add(this->tB_ywe);
			this->gB_welt->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_welt->Location = System::Drawing::Point(16, 73);
			this->gB_welt->Name = L"gB_welt";
			this->gB_welt->Size = System::Drawing::Size(300, 170);
			this->gB_welt->TabIndex = 21;
			this->gB_welt->TabStop = false;
			this->gB_welt->Text = L"Weltkoordinaten";
			// 
			// lb_ywe
			// 
			this->lb_ywe->AutoSize = true;
			this->lb_ywe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_ywe->Location = System::Drawing::Point(165, 87);
			this->lb_ywe->Name = L"lb_ywe";
			this->lb_ywe->Size = System::Drawing::Size(37, 18);
			this->lb_ywe->TabIndex = 8;
			this->lb_ywe->Text = L"y bis";
			// 
			// tB_schrittweite
			// 
			this->tB_schrittweite->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_schrittweite->Location = System::Drawing::Point(224, 126);
			this->tB_schrittweite->Name = L"tB_schrittweite";
			this->tB_schrittweite->Size = System::Drawing::Size(50, 26);
			this->tB_schrittweite->TabIndex = 5;
			// 
			// lb_xwa
			// 
			this->lb_xwa->AutoSize = true;
			this->lb_xwa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_xwa->Location = System::Drawing::Point(22, 40);
			this->lb_xwa->Name = L"lb_xwa";
			this->lb_xwa->Size = System::Drawing::Size(40, 18);
			this->lb_xwa->TabIndex = 3;
			this->lb_xwa->Text = L"x von";
			// 
			// lb_schrittweite
			// 
			this->lb_schrittweite->AutoSize = true;
			this->lb_schrittweite->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_schrittweite->Location = System::Drawing::Point(120, 134);
			this->lb_schrittweite->Name = L"lb_schrittweite";
			this->lb_schrittweite->Size = System::Drawing::Size(84, 18);
			this->lb_schrittweite->TabIndex = 19;
			this->lb_schrittweite->Text = L"Schrittweite";
			// 
			// lb_ywa
			// 
			this->lb_ywa->AutoSize = true;
			this->lb_ywa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_ywa->Location = System::Drawing::Point(22, 87);
			this->lb_ywa->Name = L"lb_ywa";
			this->lb_ywa->Size = System::Drawing::Size(39, 18);
			this->lb_ywa->TabIndex = 4;
			this->lb_ywa->Text = L"y von";
			// 
			// tB_xwa
			// 
			this->tB_xwa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_xwa->Location = System::Drawing::Point(85, 32);
			this->tB_xwa->Name = L"tB_xwa";
			this->tB_xwa->Size = System::Drawing::Size(50, 26);
			this->tB_xwa->TabIndex = 1;
			// 
			// tB_ywa
			// 
			this->tB_ywa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_ywa->Location = System::Drawing::Point(85, 79);
			this->tB_ywa->Name = L"tB_ywa";
			this->tB_ywa->Size = System::Drawing::Size(50, 26);
			this->tB_ywa->TabIndex = 3;
			// 
			// lb_xwe
			// 
			this->lb_xwe->AutoSize = true;
			this->lb_xwe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_xwe->Location = System::Drawing::Point(163, 40);
			this->lb_xwe->Name = L"lb_xwe";
			this->lb_xwe->Size = System::Drawing::Size(38, 18);
			this->lb_xwe->TabIndex = 7;
			this->lb_xwe->Text = L"x bis";
			// 
			// tB_xwe
			// 
			this->tB_xwe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_xwe->Location = System::Drawing::Point(224, 32);
			this->tB_xwe->Name = L"tB_xwe";
			this->tB_xwe->Size = System::Drawing::Size(50, 26);
			this->tB_xwe->TabIndex = 2;
			// 
			// tB_ywe
			// 
			this->tB_ywe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_ywe->Location = System::Drawing::Point(224, 79);
			this->tB_ywe->Name = L"tB_ywe";
			this->tB_ywe->Size = System::Drawing::Size(50, 26);
			this->tB_ywe->TabIndex = 4;
			// 
			// gB_screen
			// 
			this->gB_screen->Controls->Add(this->lb_yse);
			this->gB_screen->Controls->Add(this->lb_xsa);
			this->gB_screen->Controls->Add(this->lb_ysa);
			this->gB_screen->Controls->Add(this->tB_xsa);
			this->gB_screen->Controls->Add(this->tB_ysa);
			this->gB_screen->Controls->Add(this->lb_xse);
			this->gB_screen->Controls->Add(this->tB_xse);
			this->gB_screen->Controls->Add(this->tB_yse);
			this->gB_screen->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_screen->Location = System::Drawing::Point(341, 73);
			this->gB_screen->Name = L"gB_screen";
			this->gB_screen->Size = System::Drawing::Size(300, 170);
			this->gB_screen->TabIndex = 22;
			this->gB_screen->TabStop = false;
			this->gB_screen->Text = L"Screenkoordinaten";
			// 
			// lb_yse
			// 
			this->lb_yse->AutoSize = true;
			this->lb_yse->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_yse->Location = System::Drawing::Point(165, 87);
			this->lb_yse->Name = L"lb_yse";
			this->lb_yse->Size = System::Drawing::Size(37, 18);
			this->lb_yse->TabIndex = 8;
			this->lb_yse->Text = L"y bis";
			// 
			// lb_xsa
			// 
			this->lb_xsa->AutoSize = true;
			this->lb_xsa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_xsa->Location = System::Drawing::Point(22, 40);
			this->lb_xsa->Name = L"lb_xsa";
			this->lb_xsa->Size = System::Drawing::Size(40, 18);
			this->lb_xsa->TabIndex = 3;
			this->lb_xsa->Text = L"x von";
			// 
			// lb_ysa
			// 
			this->lb_ysa->AutoSize = true;
			this->lb_ysa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_ysa->Location = System::Drawing::Point(22, 87);
			this->lb_ysa->Name = L"lb_ysa";
			this->lb_ysa->Size = System::Drawing::Size(39, 18);
			this->lb_ysa->TabIndex = 4;
			this->lb_ysa->Text = L"y von";
			// 
			// tB_xsa
			// 
			this->tB_xsa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_xsa->Location = System::Drawing::Point(85, 32);
			this->tB_xsa->Name = L"tB_xsa";
			this->tB_xsa->Size = System::Drawing::Size(50, 26);
			this->tB_xsa->TabIndex = 6;
			// 
			// tB_ysa
			// 
			this->tB_ysa->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_ysa->Location = System::Drawing::Point(85, 79);
			this->tB_ysa->Name = L"tB_ysa";
			this->tB_ysa->Size = System::Drawing::Size(50, 26);
			this->tB_ysa->TabIndex = 8;
			// 
			// lb_xse
			// 
			this->lb_xse->AutoSize = true;
			this->lb_xse->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_xse->Location = System::Drawing::Point(163, 40);
			this->lb_xse->Name = L"lb_xse";
			this->lb_xse->Size = System::Drawing::Size(38, 18);
			this->lb_xse->TabIndex = 7;
			this->lb_xse->Text = L"x bis";
			// 
			// tB_xse
			// 
			this->tB_xse->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_xse->Location = System::Drawing::Point(224, 32);
			this->tB_xse->Name = L"tB_xse";
			this->tB_xse->Size = System::Drawing::Size(50, 26);
			this->tB_xse->TabIndex = 7;
			// 
			// tB_yse
			// 
			this->tB_yse->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_yse->Location = System::Drawing::Point(224, 79);
			this->tB_yse->Name = L"tB_yse";
			this->tB_yse->Size = System::Drawing::Size(50, 26);
			this->tB_yse->TabIndex = 9;
			// 
			// bt_zeichne
			// 
			this->bt_zeichne->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_zeichne->Location = System::Drawing::Point(675, 105);
			this->bt_zeichne->Name = L"bt_zeichne";
			this->bt_zeichne->Size = System::Drawing::Size(119, 113);
			this->bt_zeichne->TabIndex = 23;
			this->bt_zeichne->Text = L"Zeichne\r\n\r\nSinus-\r\n\r\nKurve";
			this->bt_zeichne->UseVisualStyleBackColor = true;
			this->bt_zeichne->Click += gcnew System::EventHandler(this, &Form1::bt_zeichne_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(842, 616);
			this->Controls->Add(this->bt_zeichne);
			this->Controls->Add(this->gB_screen);
			this->Controls->Add(this->gB_welt);
			this->Controls->Add(this->lb_Ueberschrift);
			this->Name = L"Form1";
			this->Text = L"Programm 8.1.3";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->gB_welt->ResumeLayout(false);
			this->gB_welt->PerformLayout();
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
				 // Group "Weltkoordinaten"
				 this->tB_xwa->Text = "-4,0";
                 this->tB_xwe->Text = "6,0";
                 this->tB_ywa->Text = "-2,0";
                 this->tB_ywe->Text = "3,0";
				 this->tB_schrittweite->Text = "0,001";
                 // Group "Screenkoordinaten"
                 this->tB_xsa->Text = "100";
                 this->tB_xse->Text = "700";
                 this->tB_ysa->Text = "500";
                 this->tB_yse->Text = "300";
			 }
private: System::Void bt_zeichne_Click(System::Object^  sender, System::EventArgs^  e) 
         {
			 // Diese Methode wird aufgerufen, wenn der Button "Zeichne ..." geclickt wird
			 // Deklaration der lokalen Variablen
			 int    xsa;   // x-Richtung, Screen, Anfang
			 int    xse;   // x-Richtung, Screen, Ende
			 int    ysa;   // y-Richtung, Screen, Anfang
			 int    yse;   // y-Richtung, Screen, Ende
             double xwa;   // x-Richtung, Welt, Anfang
			 double xwe;   // x-Richtung, Welt, Ende
			 double ywa;   // y-Richtung, Welt, Anfang
			 double ywe;   // y-Richtung, Welt, Ende
             double schrittweite;
			 int    x1;    // x-Koordinate des ersten Punktes einer Linie
			 int    y1;    // y-Koordinate des ersten Punktes einer Linie
			 int    x2;    // x-Koordinate des zweiten Punktes einer Linie
			 int    y2;    // y-Koordinate des zweiten Punktes einer Linie
			 double xlauf;

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
				// Auslesen der Screen-Koordinaten, textBox ==> int
			    xsa = Convert::ToInt32(tB_xsa->Text);
			    xse = Convert::ToInt32(tB_xse->Text);
			    ysa = Convert::ToInt32(tB_ysa->Text);
			    yse = Convert::ToInt32(tB_yse->Text);
                // Auslesen der Welt-Koordinaten, textBox ==> double
			    xwa = Convert::ToDouble(tB_xwa->Text);
			    xwe = Convert::ToDouble(tB_xwe->Text);
			    ywa = Convert::ToDouble(tB_ywa->Text);
			    ywe = Convert::ToDouble(tB_ywe->Text);
                // Auslesen der Schrittweite, textBox ==> double
			    schrittweite = Convert::ToDouble(tB_schrittweite->Text);
			 
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
             
			    // Konstruktion des Graphen

			    for (xlauf = xwa + schrittweite; xlauf <= xwe; xlauf = xlauf + schrittweite)
                {
	               x1 = trans(xsa,xse,xwa,xwe,xlauf-schrittweite);
				   y1 = trans(ysa,yse,ywa,ywe,sin(xlauf-schrittweite));
				   x2 = trans(xsa,xse,xwa,xwe,xlauf);
				   y2 = trans(ysa,yse,ywa,ywe,sin(xlauf));
				   g->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
			    }
			 }
			 catch (Exception ^e)
			 {
				 MessageBox::Show("Eingabe nicht numerisch - bitte korrigieren!","Eingabefehler");
			 }
			 
		 } // Ende bt_zeichne_Click

   }; // Ende class

}  // Ende namespace
