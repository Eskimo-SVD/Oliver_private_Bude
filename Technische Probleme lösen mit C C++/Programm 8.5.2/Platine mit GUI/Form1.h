#pragma once

#include "C_Platine.h"
#include <iostream> // für namespace std

namespace PlatinemitGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices; // for class Marshal
	using namespace std;

	C_Platine neuePlatine;

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
	private: System::Windows::Forms::TextBox^  tB_Bezeichnung;
	protected: 
	private: System::Windows::Forms::Label^  lb_Bezeichnung;
	private: System::Windows::Forms::Label^  lb_Abmessungen;
	private: System::Windows::Forms::Button^  bt_Breite_minus;
	private: System::Windows::Forms::Button^  bt_Breite_plus;
	private: System::Windows::Forms::Label^  lb_Breite;
	private: System::Windows::Forms::TextBox^  tB_Breite;
	private: System::Windows::Forms::Button^  bt_Länge_minus;
	private: System::Windows::Forms::Button^  bt_Länge_plus;


	private: System::Windows::Forms::Label^  lb_Länge;
	private: System::Windows::Forms::TextBox^  tB_Länge;
	private: System::Windows::Forms::TextBox^  tB_Gurtmaß;
	private: System::Windows::Forms::TextBox^  tB_Fläche;
	private: System::Windows::Forms::Label^  lb_Gurtmaß;
	private: System::Windows::Forms::Label^  lb_Fläche;
	private: System::Windows::Forms::Label^  lb_Fl_Dim;
	private: System::Windows::Forms::Label^  lb_Gurt_Dim;
	private: System::Windows::Forms::Label^  lb_Ber_Fla;
	private: System::Windows::Forms::Label^  lb_Ber_Gurt;



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
			this->tB_Bezeichnung = (gcnew System::Windows::Forms::TextBox());
			this->lb_Bezeichnung = (gcnew System::Windows::Forms::Label());
			this->lb_Abmessungen = (gcnew System::Windows::Forms::Label());
			this->bt_Breite_minus = (gcnew System::Windows::Forms::Button());
			this->bt_Breite_plus = (gcnew System::Windows::Forms::Button());
			this->lb_Breite = (gcnew System::Windows::Forms::Label());
			this->tB_Breite = (gcnew System::Windows::Forms::TextBox());
			this->bt_Länge_minus = (gcnew System::Windows::Forms::Button());
			this->bt_Länge_plus = (gcnew System::Windows::Forms::Button());
			this->lb_Länge = (gcnew System::Windows::Forms::Label());
			this->tB_Länge = (gcnew System::Windows::Forms::TextBox());
			this->tB_Gurtmaß = (gcnew System::Windows::Forms::TextBox());
			this->tB_Fläche = (gcnew System::Windows::Forms::TextBox());
			this->lb_Gurtmaß = (gcnew System::Windows::Forms::Label());
			this->lb_Fläche = (gcnew System::Windows::Forms::Label());
			this->lb_Fl_Dim = (gcnew System::Windows::Forms::Label());
			this->lb_Gurt_Dim = (gcnew System::Windows::Forms::Label());
			this->lb_Ber_Fla = (gcnew System::Windows::Forms::Label());
			this->lb_Ber_Gurt = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tB_Bezeichnung
			// 
			this->tB_Bezeichnung->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tB_Bezeichnung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Bezeichnung->Location = System::Drawing::Point(165, 74);
			this->tB_Bezeichnung->Name = L"tB_Bezeichnung";
			this->tB_Bezeichnung->Size = System::Drawing::Size(300, 26);
			this->tB_Bezeichnung->TabIndex = 29;
			// 
			// lb_Bezeichnung
			// 
			this->lb_Bezeichnung->AutoSize = true;
			this->lb_Bezeichnung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Bezeichnung->Location = System::Drawing::Point(28, 77);
			this->lb_Bezeichnung->Name = L"lb_Bezeichnung";
			this->lb_Bezeichnung->Size = System::Drawing::Size(102, 20);
			this->lb_Bezeichnung->TabIndex = 28;
			this->lb_Bezeichnung->Text = L"Bezeichnung";
			// 
			// lb_Abmessungen
			// 
			this->lb_Abmessungen->AutoSize = true;
			this->lb_Abmessungen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Abmessungen->Location = System::Drawing::Point(28, 25);
			this->lb_Abmessungen->Name = L"lb_Abmessungen";
			this->lb_Abmessungen->Size = System::Drawing::Size(252, 20);
			this->lb_Abmessungen->TabIndex = 27;
			this->lb_Abmessungen->Text = L"Abmessungen einer neuen Platine";
			// 
			// bt_Breite_minus
			// 
			this->bt_Breite_minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_Breite_minus->Location = System::Drawing::Point(165, 129);
			this->bt_Breite_minus->Name = L"bt_Breite_minus";
			this->bt_Breite_minus->Size = System::Drawing::Size(30, 30);
			this->bt_Breite_minus->TabIndex = 26;
			this->bt_Breite_minus->Text = L"-";
			this->bt_Breite_minus->UseVisualStyleBackColor = true;
			this->bt_Breite_minus->Click += gcnew System::EventHandler(this, &Form1::bt_Breite_minus_Click);
			// 
			// bt_Breite_plus
			// 
			this->bt_Breite_plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_Breite_plus->Location = System::Drawing::Point(319, 129);
			this->bt_Breite_plus->Name = L"bt_Breite_plus";
			this->bt_Breite_plus->Size = System::Drawing::Size(30, 30);
			this->bt_Breite_plus->TabIndex = 25;
			this->bt_Breite_plus->Text = L"+";
			this->bt_Breite_plus->UseVisualStyleBackColor = true;
			this->bt_Breite_plus->Click += gcnew System::EventHandler(this, &Form1::bt_Breite_plus_Click);
			// 
			// lb_Breite
			// 
			this->lb_Breite->AutoSize = true;
			this->lb_Breite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Breite->Location = System::Drawing::Point(28, 132);
			this->lb_Breite->Name = L"lb_Breite";
			this->lb_Breite->Size = System::Drawing::Size(89, 20);
			this->lb_Breite->TabIndex = 24;
			this->lb_Breite->Text = L"Breite [mm]";
			// 
			// tB_Breite
			// 
			this->tB_Breite->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tB_Breite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Breite->Location = System::Drawing::Point(207, 131);
			this->tB_Breite->Name = L"tB_Breite";
			this->tB_Breite->ReadOnly = true;
			this->tB_Breite->Size = System::Drawing::Size(100, 26);
			this->tB_Breite->TabIndex = 23;
			// 
			// bt_Länge_minus
			// 
			this->bt_Länge_minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_Länge_minus->Location = System::Drawing::Point(165, 172);
			this->bt_Länge_minus->Name = L"bt_Länge_minus";
			this->bt_Länge_minus->Size = System::Drawing::Size(30, 30);
			this->bt_Länge_minus->TabIndex = 33;
			this->bt_Länge_minus->Text = L"-";
			this->bt_Länge_minus->UseVisualStyleBackColor = true;
			this->bt_Länge_minus->Click += gcnew System::EventHandler(this, &Form1::bt_Länge_minus_Click);
			// 
			// bt_Länge_plus
			// 
			this->bt_Länge_plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_Länge_plus->Location = System::Drawing::Point(319, 172);
			this->bt_Länge_plus->Name = L"bt_Länge_plus";
			this->bt_Länge_plus->Size = System::Drawing::Size(30, 30);
			this->bt_Länge_plus->TabIndex = 32;
			this->bt_Länge_plus->Text = L"+";
			this->bt_Länge_plus->UseVisualStyleBackColor = true;
			this->bt_Länge_plus->Click += gcnew System::EventHandler(this, &Form1::bt_Länge_plus_Click);
			// 
			// lb_Länge
			// 
			this->lb_Länge->AutoSize = true;
			this->lb_Länge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Länge->Location = System::Drawing::Point(28, 175);
			this->lb_Länge->Name = L"lb_Länge";
			this->lb_Länge->Size = System::Drawing::Size(92, 20);
			this->lb_Länge->TabIndex = 31;
			this->lb_Länge->Text = L"Länge [mm]";
			// 
			// tB_Länge
			// 
			this->tB_Länge->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tB_Länge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Länge->Location = System::Drawing::Point(207, 174);
			this->tB_Länge->Name = L"tB_Länge";
			this->tB_Länge->ReadOnly = true;
			this->tB_Länge->Size = System::Drawing::Size(100, 26);
			this->tB_Länge->TabIndex = 30;
			// 
			// tB_Gurtmaß
			// 
			this->tB_Gurtmaß->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tB_Gurtmaß->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Gurtmaß->Location = System::Drawing::Point(165, 278);
			this->tB_Gurtmaß->Name = L"tB_Gurtmaß";
			this->tB_Gurtmaß->ReadOnly = true;
			this->tB_Gurtmaß->Size = System::Drawing::Size(200, 26);
			this->tB_Gurtmaß->TabIndex = 37;
			// 
			// tB_Fläche
			// 
			this->tB_Fläche->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tB_Fläche->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Fläche->Location = System::Drawing::Point(165, 230);
			this->tB_Fläche->Name = L"tB_Fläche";
			this->tB_Fläche->ReadOnly = true;
			this->tB_Fläche->Size = System::Drawing::Size(200, 26);
			this->tB_Fläche->TabIndex = 36;
			// 
			// lb_Gurtmaß
			// 
			this->lb_Gurtmaß->AutoSize = true;
			this->lb_Gurtmaß->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Gurtmaß->Location = System::Drawing::Point(28, 278);
			this->lb_Gurtmaß->Name = L"lb_Gurtmaß";
			this->lb_Gurtmaß->Size = System::Drawing::Size(73, 20);
			this->lb_Gurtmaß->TabIndex = 35;
			this->lb_Gurtmaß->Text = L"Gurtmaß";
			// 
			// lb_Fläche
			// 
			this->lb_Fläche->AutoSize = true;
			this->lb_Fläche->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Fläche->Location = System::Drawing::Point(28, 230);
			this->lb_Fläche->Name = L"lb_Fläche";
			this->lb_Fläche->Size = System::Drawing::Size(57, 20);
			this->lb_Fläche->TabIndex = 34;
			this->lb_Fläche->Text = L"Fläche";
			// 
			// lb_Fl_Dim
			// 
			this->lb_Fl_Dim->AutoSize = true;
			this->lb_Fl_Dim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Fl_Dim->Location = System::Drawing::Point(102, 230);
			this->lb_Fl_Dim->Name = L"lb_Fl_Dim";
			this->lb_Fl_Dim->Size = System::Drawing::Size(48, 20);
			this->lb_Fl_Dim->TabIndex = 38;
			this->lb_Fl_Dim->Text = L"[mm²]";
			// 
			// lb_Gurt_Dim
			// 
			this->lb_Gurt_Dim->AutoSize = true;
			this->lb_Gurt_Dim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Gurt_Dim->Location = System::Drawing::Point(102, 278);
			this->lb_Gurt_Dim->Name = L"lb_Gurt_Dim";
			this->lb_Gurt_Dim->Size = System::Drawing::Size(48, 20);
			this->lb_Gurt_Dim->TabIndex = 39;
			this->lb_Gurt_Dim->Text = L"[mm²]";
			// 
			// lb_Ber_Fla
			// 
			this->lb_Ber_Fla->AutoSize = true;
			this->lb_Ber_Fla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Ber_Fla->Location = System::Drawing::Point(371, 230);
			this->lb_Ber_Fla->Name = L"lb_Ber_Fla";
			this->lb_Ber_Fla->Size = System::Drawing::Size(111, 20);
			this->lb_Ber_Fla->TabIndex = 40;
			this->lb_Ber_Fla->Text = L"Breite x Länge";
			// 
			// lb_Ber_Gurt
			// 
			this->lb_Ber_Gurt->AutoSize = true;
			this->lb_Ber_Gurt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Ber_Gurt->Location = System::Drawing::Point(371, 278);
			this->lb_Ber_Gurt->Name = L"lb_Ber_Gurt";
			this->lb_Ber_Gurt->Size = System::Drawing::Size(182, 20);
			this->lb_Ber_Gurt->TabIndex = 41;
			this->lb_Ber_Gurt->Text = L"(Breite + 20) x 2 + Länge";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(573, 349);
			this->Controls->Add(this->lb_Ber_Gurt);
			this->Controls->Add(this->lb_Ber_Fla);
			this->Controls->Add(this->lb_Gurt_Dim);
			this->Controls->Add(this->lb_Fl_Dim);
			this->Controls->Add(this->tB_Gurtmaß);
			this->Controls->Add(this->tB_Fläche);
			this->Controls->Add(this->lb_Gurtmaß);
			this->Controls->Add(this->lb_Fläche);
			this->Controls->Add(this->bt_Länge_minus);
			this->Controls->Add(this->bt_Länge_plus);
			this->Controls->Add(this->lb_Länge);
			this->Controls->Add(this->tB_Länge);
			this->Controls->Add(this->tB_Bezeichnung);
			this->Controls->Add(this->lb_Bezeichnung);
			this->Controls->Add(this->lb_Abmessungen);
			this->Controls->Add(this->bt_Breite_minus);
			this->Controls->Add(this->bt_Breite_plus);
			this->Controls->Add(this->lb_Breite);
			this->Controls->Add(this->tB_Breite);
			this->Name = L"Form1";
			this->Text = L"Platinendimensionierung";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 // Initialisierung des Objektes neuePlatine
				 neuePlatine.setBezeichnung("bitte eine neue Bezeichnung eingeben!");
				 neuePlatine.setLaenge(300);
				 neuePlatine.setBreite(200);
				 // Übernahme der Bezeichnung des Objektes in die grafische Oberfläche
				 string cs = neuePlatine.getBezeichnung();
				 String^ str2 = gcnew String(cs.c_str());
				 this->tB_Bezeichnung->Text = str2;
				 // Übernahme der Geometrie des Objektes in die grafische Oberfläche
				 this->tB_Länge->Text       = Convert::ToString(neuePlatine.getLaenge());
				 this->tB_Breite->Text      = Convert::ToString(neuePlatine.getBreite());
				 this->tB_Fläche->Text      = Convert::ToString(neuePlatine.berechneFläche());
				 this->tB_Gurtmaß->Text     = Convert::ToString(neuePlatine.berechneGurtmaß());
			 }
private: System::Void bt_Breite_minus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			// Reduzierung der Breite
			this->tB_Breite->Text=Convert::ToString(Convert::ToInt32(this->tB_Breite->Text)-1);
			// Übernahme der aktuellen Breite in die Klasse
			neuePlatine.setBreite(Convert::ToInt32(this->tB_Breite->Text));
			// Übername des Textes der Bezeichnung in die Klasse - muss an jeder Stelle möglich sein
			char*chars=(char*)(Marshal::StringToHGlobalAnsi(this->tB_Bezeichnung->Text)).ToPointer();
			neuePlatine.setBezeichnung(chars);
			// Berechnung
			this->tB_Fläche->Text  = Convert::ToString(neuePlatine.berechneFläche());
			this->tB_Gurtmaß->Text = Convert::ToString(neuePlatine.berechneGurtmaß());
			
		 }
private: System::Void bt_Breite_plus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			// Erhöhung der Breite
			this->tB_Breite->Text=Convert::ToString(Convert::ToInt32(this->tB_Breite->Text)+1);
			// Übernahme der aktuellen Breite in die Klasse
			neuePlatine.setBreite(Convert::ToInt32(this->tB_Breite->Text));
			// Übername des Textes der Bezeichnung - muss an jeder Stelle möglich sein
			char*chars=(char*)(Marshal::StringToHGlobalAnsi(this->tB_Bezeichnung->Text)).ToPointer();
			neuePlatine.setBezeichnung(chars);
			// Berechnung
			this->tB_Fläche->Text  = Convert::ToString(neuePlatine.berechneFläche());
			this->tB_Gurtmaß->Text = Convert::ToString(neuePlatine.berechneGurtmaß());
		 }
private: System::Void bt_Länge_minus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Reduzierung der Länge
			 this->tB_Länge->Text=Convert::ToString(Convert::ToInt32(this->tB_Länge->Text)-1);
			 // Übernahme der aktuellen Länge in die Klasse
			 neuePlatine.setLaenge(Convert::ToInt32(this->tB_Länge->Text));
			 // Übername des Textes der Bezeichnung - muss an jeder Stelle möglich sein
			 char*chars=(char*)(Marshal::StringToHGlobalAnsi(this->tB_Bezeichnung->Text)).ToPointer();
			 neuePlatine.setBezeichnung(chars);
			 // Berechnung
			 this->tB_Fläche->Text  = Convert::ToString(neuePlatine.berechneFläche());
			 this->tB_Gurtmaß->Text = Convert::ToString(neuePlatine.berechneGurtmaß());
		 }
private: System::Void bt_Länge_plus_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Erhöhung der Länge
			 this->tB_Länge->Text=Convert::ToString(Convert::ToInt32(this->tB_Länge->Text)+1);
			 // Übernahme der aktuellen Länge in die Klasse
			 neuePlatine.setLaenge(Convert::ToInt32(this->tB_Länge->Text));
			 // Übername des Textes der Bezeichnung - muss an jeder Stelle möglich sein
			 char*chars=(char*)(Marshal::StringToHGlobalAnsi(this->tB_Bezeichnung->Text)).ToPointer();
			 neuePlatine.setBezeichnung(chars);
			 // Berechnung
			 this->tB_Fläche->Text  = Convert::ToString(neuePlatine.berechneFläche());
			 this->tB_Gurtmaß->Text = Convert::ToString(neuePlatine.berechneGurtmaß());
		 }
};
}

