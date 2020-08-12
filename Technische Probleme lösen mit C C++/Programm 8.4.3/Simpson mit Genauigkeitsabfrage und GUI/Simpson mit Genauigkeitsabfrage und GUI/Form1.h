#pragma once
#include <math.h>


namespace SimpsonmitGenauigkeitsabfrageundGUI {

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
	private: System::Windows::Forms::GroupBox^  gB_Eingabe;
	protected: 

	private: System::Windows::Forms::Label^  lb_a;
	private: System::Windows::Forms::TextBox^  tB_a;
	private: System::Windows::Forms::Label^  lb_b;
	private: System::Windows::Forms::TextBox^  tB_b;
	private: System::Windows::Forms::Label^  lb_epsilon;
	private: System::Windows::Forms::TextBox^  tB_epsilon;
	private: System::Windows::Forms::Button^  bt_rechne;
	private: System::Windows::Forms::GroupBox^  gB_Ergebnis;
	private: System::Windows::Forms::TextBox^  tB_n;
	private: System::Windows::Forms::TextBox^  tB_aN;
	private: System::Windows::Forms::Label^  lb_n;
	private: System::Windows::Forms::Label^  lb_aN;
	private: System::Windows::Forms::Label^  lb_FE;
	private: System::Windows::Forms::GroupBox^  gB_f;
	private: System::Windows::Forms::Label^  lb_f;



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
			this->gB_Eingabe = (gcnew System::Windows::Forms::GroupBox());
			this->lb_b = (gcnew System::Windows::Forms::Label());
			this->tB_b = (gcnew System::Windows::Forms::TextBox());
			this->lb_a = (gcnew System::Windows::Forms::Label());
			this->tB_a = (gcnew System::Windows::Forms::TextBox());
			this->lb_epsilon = (gcnew System::Windows::Forms::Label());
			this->tB_epsilon = (gcnew System::Windows::Forms::TextBox());
			this->bt_rechne = (gcnew System::Windows::Forms::Button());
			this->gB_Ergebnis = (gcnew System::Windows::Forms::GroupBox());
			this->lb_FE = (gcnew System::Windows::Forms::Label());
			this->tB_n = (gcnew System::Windows::Forms::TextBox());
			this->tB_aN = (gcnew System::Windows::Forms::TextBox());
			this->lb_n = (gcnew System::Windows::Forms::Label());
			this->lb_aN = (gcnew System::Windows::Forms::Label());
			this->gB_f = (gcnew System::Windows::Forms::GroupBox());
			this->lb_f = (gcnew System::Windows::Forms::Label());
			this->gB_Eingabe->SuspendLayout();
			this->gB_Ergebnis->SuspendLayout();
			this->gB_f->SuspendLayout();
			this->SuspendLayout();
			// 
			// gB_Eingabe
			// 
			this->gB_Eingabe->Controls->Add(this->lb_b);
			this->gB_Eingabe->Controls->Add(this->tB_b);
			this->gB_Eingabe->Controls->Add(this->lb_a);
			this->gB_Eingabe->Controls->Add(this->tB_a);
			this->gB_Eingabe->Location = System::Drawing::Point(10, 20);
			this->gB_Eingabe->Name = L"gB_Eingabe";
			this->gB_Eingabe->Size = System::Drawing::Size(350, 130);
			this->gB_Eingabe->TabIndex = 0;
			this->gB_Eingabe->TabStop = false;
			this->gB_Eingabe->Text = L"Eingabe";
			// 
			// lb_b
			// 
			this->lb_b->AutoSize = true;
			this->lb_b->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_b->Location = System::Drawing::Point(20, 64);
			this->lb_b->Name = L"lb_b";
			this->lb_b->Size = System::Drawing::Size(153, 18);
			this->lb_b->TabIndex = 3;
			this->lb_b->Text = L"obere Intervallgrenze b";
			// 
			// tB_b
			// 
			this->tB_b->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_b->Location = System::Drawing::Point(220, 60);
			this->tB_b->Name = L"tB_b";
			this->tB_b->Size = System::Drawing::Size(60, 26);
			this->tB_b->TabIndex = 2;
			// 
			// lb_a
			// 
			this->lb_a->AutoSize = true;
			this->lb_a->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_a->Location = System::Drawing::Point(20, 34);
			this->lb_a->Name = L"lb_a";
			this->lb_a->Size = System::Drawing::Size(156, 18);
			this->lb_a->TabIndex = 1;
			this->lb_a->Text = L"untere Intervallgrenze a";
			// 
			// tB_a
			// 
			this->tB_a->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_a->Location = System::Drawing::Point(220, 30);
			this->tB_a->Name = L"tB_a";
			this->tB_a->Size = System::Drawing::Size(60, 26);
			this->tB_a->TabIndex = 0;
			// 
			// lb_epsilon
			// 
			this->lb_epsilon->AutoSize = true;
			this->lb_epsilon->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_epsilon->Location = System::Drawing::Point(30, 114);
			this->lb_epsilon->Name = L"lb_epsilon";
			this->lb_epsilon->Size = System::Drawing::Size(199, 18);
			this->lb_epsilon->TabIndex = 3;
			this->lb_epsilon->Text = L"gewünschte Genauigkeit epsilon";
			// 
			// tB_epsilon
			// 
			this->tB_epsilon->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_epsilon->Location = System::Drawing::Point(230, 110);
			this->tB_epsilon->Name = L"tB_epsilon";
			this->tB_epsilon->Size = System::Drawing::Size(120, 26);
			this->tB_epsilon->TabIndex = 2;
			// 
			// bt_rechne
			// 
			this->bt_rechne->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bt_rechne->Location = System::Drawing::Point(351, 174);
			this->bt_rechne->Name = L"bt_rechne";
			this->bt_rechne->Size = System::Drawing::Size(100, 33);
			this->bt_rechne->TabIndex = 4;
			this->bt_rechne->Text = L"Berechnung";
			this->bt_rechne->UseVisualStyleBackColor = true;
			this->bt_rechne->Click += gcnew System::EventHandler(this, &Form1::bt_rechne_Click);
			// 
			// gB_Ergebnis
			// 
			this->gB_Ergebnis->Controls->Add(this->lb_FE);
			this->gB_Ergebnis->Controls->Add(this->tB_n);
			this->gB_Ergebnis->Controls->Add(this->tB_aN);
			this->gB_Ergebnis->Controls->Add(this->lb_n);
			this->gB_Ergebnis->Controls->Add(this->lb_aN);
			this->gB_Ergebnis->Location = System::Drawing::Point(10, 230);
			this->gB_Ergebnis->Name = L"gB_Ergebnis";
			this->gB_Ergebnis->Size = System::Drawing::Size(350, 100);
			this->gB_Ergebnis->TabIndex = 5;
			this->gB_Ergebnis->TabStop = false;
			this->gB_Ergebnis->Text = L"Ergebnisse";
			// 
			// lb_FE
			// 
			this->lb_FE->AutoSize = true;
			this->lb_FE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_FE->Location = System::Drawing::Point(315, 34);
			this->lb_FE->Name = L"lb_FE";
			this->lb_FE->Size = System::Drawing::Size(24, 18);
			this->lb_FE->TabIndex = 4;
			this->lb_FE->Text = L"FE";
			// 
			// tB_n
			// 
			this->tB_n->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_n->Location = System::Drawing::Point(161, 60);
			this->tB_n->Name = L"tB_n";
			this->tB_n->ReadOnly = true;
			this->tB_n->Size = System::Drawing::Size(60, 26);
			this->tB_n->TabIndex = 3;
			// 
			// tB_aN
			// 
			this->tB_aN->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tB_aN->Location = System::Drawing::Point(161, 30);
			this->tB_aN->Name = L"tB_aN";
			this->tB_aN->ReadOnly = true;
			this->tB_aN->Size = System::Drawing::Size(150, 26);
			this->tB_aN->TabIndex = 2;
			// 
			// lb_n
			// 
			this->lb_n->AutoSize = true;
			this->lb_n->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_n->Location = System::Drawing::Point(20, 64);
			this->lb_n->Name = L"lb_n";
			this->lb_n->Size = System::Drawing::Size(134, 18);
			this->lb_n->TabIndex = 1;
			this->lb_n->Text = L"Anzahl Teilintervalle";
			// 
			// lb_aN
			// 
			this->lb_aN->AutoSize = true;
			this->lb_aN->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_aN->Location = System::Drawing::Point(20, 34);
			this->lb_aN->Name = L"lb_aN";
			this->lb_aN->Size = System::Drawing::Size(48, 18);
			this->lb_aN->TabIndex = 0;
			this->lb_aN->Text = L"Fläche";
			// 
			// gB_f
			// 
			this->gB_f->Controls->Add(this->lb_f);
			this->gB_f->Location = System::Drawing::Point(10, 160);
			this->gB_f->Name = L"gB_f";
			this->gB_f->Size = System::Drawing::Size(320, 60);
			this->gB_f->TabIndex = 6;
			this->gB_f->TabStop = false;
			this->gB_f->Text = L"Funktion";
			// 
			// lb_f
			// 
			this->lb_f->AutoSize = true;
			this->lb_f->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_f->Location = System::Drawing::Point(10, 30);
			this->lb_f->Name = L"lb_f";
			this->lb_f->Size = System::Drawing::Size(44, 18);
			this->lb_f->TabIndex = 0;
			this->lb_f->Text = L"f(x) =";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 342);
			this->Controls->Add(this->gB_f);
			this->Controls->Add(this->gB_Ergebnis);
			this->Controls->Add(this->bt_rechne);
			this->Controls->Add(this->lb_epsilon);
			this->Controls->Add(this->tB_epsilon);
			this->Controls->Add(this->gB_Eingabe);
			this->Name = L"Form1";
			this->Text = L"Simpson Regel mit Genauigkeitsabfrage";
			this->gB_Eingabe->ResumeLayout(false);
			this->gB_Eingabe->PerformLayout();
			this->gB_Ergebnis->ResumeLayout(false);
			this->gB_Ergebnis->PerformLayout();
			this->gB_f->ResumeLayout(false);
			this->gB_f->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
   private: System::Void bt_rechne_Click(System::Object^  sender, System::EventArgs^  e) 
   {
      // Flächenberechnung (numerische Integration)
      // nach der Simpsonschen Regel
      // Autor: Heiderich / Meyer
      // ------------------------------------------
	  // Deklaration der Variablen
	  int k;          // Iterationsvariable
	  int n;          // Anzahl Teilintervalle
	  double a;       // untere Intervallgrenze
	  double b;       // obere Intervallgrenze
	  double epsilon; // gewünschte Genauigkeit
	  double delta_x; // Breite der Teilintervalle
	  double xi;      // i. Stützwert
	  double s;       // Summe
	  double aA;      // "alte" Fläche aus Summe
	  double aN;      // "neue" Fläche aus Summe
	  int iaus = 1;   // Steuervariable zur Dokumentation von f(x)
	  int i;          // Zählersteuerungsvariable (for-Schleifen)
      // Auslesen der TextBoxen
	  a       = System::Convert::ToDouble(this->tB_a->Text);
	  b       = System::Convert::ToDouble(this->tB_b->Text);
	  epsilon = System::Convert::ToDouble(this->tB_epsilon->Text);
	  // Initialisierung "alte Fläche"
	  aA = 0.0;
	  // Zähler für Anzahl Iterationen
	  k = 0;
	  do
	  {
	     // aktueller Zähler für Iterationen hochsetzen
		 k++;
		 // Umspeichern der Ergebnisse
		 aA = aN;
		 // Initialisierung der Summenvariable
	     s = 0.0;
		 // Anzahl Intervalle
		 n = 2* k;
         // Breite der Teilintervalle
		 delta_x = (b - a) / n;
	     // Berechnung der Summe der Funktionswerte
	     for (i = 0; i <= n; i++)
	     {
		    xi = a + i * delta_x;
		    if (i == 0 || i == n) s += f(xi,iaus);
		    else
		    {
		       if (i / 2 * 2 != i) s += 4.0 * f(xi,iaus);
		       else                s += 2.0 * f(xi,iaus);
		    }
	     }
	     // Berechnung der Fläche aus der Summe
	     aN = delta_x / 3. * s;
      }while ( abs( aA - aN ) > epsilon);
	  // Ergebnisse anzeigen
	  this->tB_n->Text  = System::Convert::ToString(n);
	  this->tB_aN->Text = System::Convert::ToString(aN);
   }
   // Funktion f(x)
   // Rückgabe Funktionswert an der Stelle x
   // aus steuert die Dokumentation der Funktion: 0 - keine Ausgabe, 1 - Ausgabe
   // Autor: Heiderich / Meyer
   // --------------------------------------------------------------------------
   float f(float x, int& aus)
   {
      float y = 4.*sqrt(1-pow(x,2));
	  if (aus == 1)
	  {
         this->lb_f->Text = "f(x) = 4.0 * sqrt ( 1.0 - x² )";
         aus = 0;
      }
      return y;
   }
};
}