#pragma once


namespace Programm61GUI {

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
	
	private: System::Windows::Forms::Label^        lb_Temperatur;
    private: System::Windows::Forms::TextBox^      tB_Eingabe;
	private: System::Windows::Forms::GroupBox^     gB_von;


	private: System::Windows::Forms::RadioButton^  rB_von_C;
	private: System::Windows::Forms::RadioButton^  rB_von_F;
	private: System::Windows::Forms::RadioButton^  rB_von_K;
	
	private: System::Windows::Forms::GroupBox^     gB_nach;
	private: System::Windows::Forms::RadioButton^  rB_nach_C;
	private: System::Windows::Forms::RadioButton^  rB_nach_F;
	private: System::Windows::Forms::RadioButton^  rB_nach_K;
	
	private: System::Windows::Forms::Button^       bt_Rechnung;
	
	private: System::Windows::Forms::TextBox^      tB_Ergebnis;

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
			this->tB_Eingabe = (gcnew System::Windows::Forms::TextBox());
			this->lb_Temperatur = (gcnew System::Windows::Forms::Label());
			this->gB_von = (gcnew System::Windows::Forms::GroupBox());
			this->rB_von_K = (gcnew System::Windows::Forms::RadioButton());
			this->rB_von_F = (gcnew System::Windows::Forms::RadioButton());
			this->rB_von_C = (gcnew System::Windows::Forms::RadioButton());
			this->bt_Rechnung = (gcnew System::Windows::Forms::Button());
			this->rB_nach_C = (gcnew System::Windows::Forms::RadioButton());
			this->rB_nach_F = (gcnew System::Windows::Forms::RadioButton());
			this->rB_nach_K = (gcnew System::Windows::Forms::RadioButton());
			this->gB_nach = (gcnew System::Windows::Forms::GroupBox());
			this->tB_Ergebnis = (gcnew System::Windows::Forms::TextBox());
			this->gB_von->SuspendLayout();
			this->gB_nach->SuspendLayout();
			this->SuspendLayout();
			// 
			// tB_Eingabe
			// 
			this->tB_Eingabe->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Eingabe->Location = System::Drawing::Point(41, 50);
			this->tB_Eingabe->Name = L"tB_Eingabe";
			this->tB_Eingabe->Size = System::Drawing::Size(75, 26);
			this->tB_Eingabe->TabIndex = 0;
			// 
			// lb_Temperatur
			// 
			this->lb_Temperatur->AutoSize = true;
			this->lb_Temperatur->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_Temperatur->Location = System::Drawing::Point(38, 20);
			this->lb_Temperatur->Name = L"lb_Temperatur";
			this->lb_Temperatur->Size = System::Drawing::Size(78, 18);
			this->lb_Temperatur->TabIndex = 1;
			this->lb_Temperatur->Text = L"Temperatur";
			// 
			// gB_von
			// 
			this->gB_von->Controls->Add(this->rB_von_K);
			this->gB_von->Controls->Add(this->rB_von_F);
			this->gB_von->Controls->Add(this->rB_von_C);
			this->gB_von->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_von->Location = System::Drawing::Point(136, 20);
			this->gB_von->Name = L"gB_von";
			this->gB_von->Size = System::Drawing::Size(60, 120);
			this->gB_von->TabIndex = 5;
			this->gB_von->TabStop = false;
			this->gB_von->Text = L"von";
			// 
			// rB_von_K
			// 
			this->rB_von_K->AutoSize = true;
			this->rB_von_K->Location = System::Drawing::Point(15, 90);
			this->rB_von_K->Name = L"rB_von_K";
			this->rB_von_K->Size = System::Drawing::Size(34, 22);
			this->rB_von_K->TabIndex = 2;
			this->rB_von_K->Text = L"K";
			this->rB_von_K->UseVisualStyleBackColor = true;
			// 
			// rB_von_F
			// 
			this->rB_von_F->AutoSize = true;
			this->rB_von_F->Location = System::Drawing::Point(15, 62);
			this->rB_von_F->Name = L"rB_von_F";
			this->rB_von_F->Size = System::Drawing::Size(39, 22);
			this->rB_von_F->TabIndex = 1;
			this->rB_von_F->Text = L"°F";
			this->rB_von_F->UseVisualStyleBackColor = true;
			// 
			// rB_von_C
			// 
			this->rB_von_C->AutoSize = true;
			this->rB_von_C->Checked = true;
			this->rB_von_C->Location = System::Drawing::Point(15, 34);
			this->rB_von_C->Name = L"rB_von_C";
			this->rB_von_C->Size = System::Drawing::Size(39, 22);
			this->rB_von_C->TabIndex = 0;
			this->rB_von_C->TabStop = true;
			this->rB_von_C->Text = L"°C";
			this->rB_von_C->UseVisualStyleBackColor = true;
			// 
			// bt_Rechnung
			// 
			this->bt_Rechnung->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_Rechnung->Location = System::Drawing::Point(282, 103);
			this->bt_Rechnung->Name = L"bt_Rechnung";
			this->bt_Rechnung->Size = System::Drawing::Size(100, 36);
			this->bt_Rechnung->TabIndex = 8;
			this->bt_Rechnung->Text = L"Berechnung";
			this->bt_Rechnung->UseVisualStyleBackColor = true;
			this->bt_Rechnung->Click += gcnew System::EventHandler(this, &Form1::bt_Rechnung_Click);
			// 
			// rB_nach_C
			// 
			this->rB_nach_C->AutoSize = true;
			this->rB_nach_C->Location = System::Drawing::Point(15, 34);
			this->rB_nach_C->Name = L"rB_nach_C";
			this->rB_nach_C->Size = System::Drawing::Size(39, 22);
			this->rB_nach_C->TabIndex = 0;
			this->rB_nach_C->Text = L"°C";
			this->rB_nach_C->UseVisualStyleBackColor = true;
			// 
			// rB_nach_F
			// 
			this->rB_nach_F->AutoSize = true;
			this->rB_nach_F->Checked = true;
			this->rB_nach_F->Location = System::Drawing::Point(15, 62);
			this->rB_nach_F->Name = L"rB_nach_F";
			this->rB_nach_F->Size = System::Drawing::Size(39, 22);
			this->rB_nach_F->TabIndex = 1;
			this->rB_nach_F->TabStop = true;
			this->rB_nach_F->Text = L"°F";
			this->rB_nach_F->UseVisualStyleBackColor = true;
			// 
			// rB_nach_K
			// 
			this->rB_nach_K->AutoSize = true;
			this->rB_nach_K->Location = System::Drawing::Point(15, 90);
			this->rB_nach_K->Name = L"rB_nach_K";
			this->rB_nach_K->Size = System::Drawing::Size(34, 22);
			this->rB_nach_K->TabIndex = 2;
			this->rB_nach_K->Text = L"K";
			this->rB_nach_K->UseVisualStyleBackColor = true;
			// 
			// gB_nach
			// 
			this->gB_nach->Controls->Add(this->rB_nach_K);
			this->gB_nach->Controls->Add(this->rB_nach_F);
			this->gB_nach->Controls->Add(this->rB_nach_C);
			this->gB_nach->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gB_nach->Location = System::Drawing::Point(205, 20);
			this->gB_nach->Name = L"gB_nach";
			this->gB_nach->Size = System::Drawing::Size(60, 120);
			this->gB_nach->TabIndex = 7;
			this->gB_nach->TabStop = false;
			this->gB_nach->Text = L"nach";
			// 
			// tB_Ergebnis
			// 
			this->tB_Ergebnis->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_Ergebnis->ForeColor = System::Drawing::Color::Red;
			this->tB_Ergebnis->Location = System::Drawing::Point(41, 161);
			this->tB_Ergebnis->Name = L"tB_Ergebnis";
			this->tB_Ergebnis->ReadOnly = true;
			this->tB_Ergebnis->Size = System::Drawing::Size(341, 30);
			this->tB_Ergebnis->TabIndex = 9;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(422, 212);
			this->Controls->Add(this->tB_Ergebnis);
			this->Controls->Add(this->bt_Rechnung);
			this->Controls->Add(this->gB_nach);
			this->Controls->Add(this->gB_von);
			this->Controls->Add(this->lb_Temperatur);
			this->Controls->Add(this->tB_Eingabe);
			this->Name = L"Form1";
			this->Text = L"Temperaturrechner";
			this->gB_von->ResumeLayout(false);
			this->gB_von->PerformLayout();
			this->gB_nach->ResumeLayout(false);
			this->gB_nach->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	System::Void bt_Rechnung_Click(System::Object^  sender, System::EventArgs^  e) 
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
	   this->tB_Ergebnis->Text = this->tB_Eingabe->Text;
	   if (systemEin == 1) this->tB_Ergebnis->Text += "°C = ";
	   if (systemEin == 2) this->tB_Ergebnis->Text += "°F = ";
	   if (systemEin == 3) this->tB_Ergebnis->Text += "K = ";
	   this->tB_Ergebnis->Text += System::Convert::ToString(tempAus);
	   if (systemAus == 1) this->tB_Ergebnis->Text += "°C";
	   if (systemAus == 2) this->tB_Ergebnis->Text += "°F";
	   if (systemAus == 3) this->tB_Ergebnis->Text += "K";
   }
};
}