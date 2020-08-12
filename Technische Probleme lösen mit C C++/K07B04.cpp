void InitializeComponent(void)
{
   this->tB_Eingabe    = (gcnew System::Windows::Forms::TextBox());
   this->lb_Temperatur = (gcnew System::Windows::Forms::Label());
   this->gB_von        = (gcnew System::Windows::Forms::GroupBox());
   this->rB_von_K      = (gcnew System::Windows::Forms::RadioButton());
   this->rB_von_F      = (gcnew System::Windows::Forms::RadioButton());
   this->rB_von_C      = (gcnew System::Windows::Forms::RadioButton());
   this->bt_Rechnung   = (gcnew System::Windows::Forms::Button());
   this->rB_nach_C     = (gcnew System::Windows::Forms::RadioButton());
   this->rB_nach_F     = (gcnew System::Windows::Forms::RadioButton());
   this->rB_nach_K     = (gcnew System::Windows::Forms::RadioButton());
   this->gB_nach       = (gcnew System::Windows::Forms::GroupBox());
   this->tB_Ergebnis   = (gcnew System::Windows::Forms::TextBox());
   this->gB_von->SuspendLayout();
   this->gB_nach->SuspendLayout();
   this->SuspendLayout();
   // 
   // tB_Eingabe
   // 
   this->tB_Eingabe->Font = (gcnew System::Drawing::Font(L"Comic Sans
                             MS",9.75F,System::Drawing::FontStyle::
                             Regular,System::Drawing::GraphicsUnit::
                             Point,static_cast<System::Byte>(0)));
   this->tB_Eingabe->Location = System::Drawing::Point(41, 50);
   this->tB_Eingabe->Name = L"tB_Eingabe";
   this->tB_Eingabe->Size = System::Drawing::Size(75, 26);
   this->tB_Eingabe->TabIndex = 0;
   // 
   // lb_Temperatur
   // 
   this->lb_Temperatur->AutoSize = true;
   this->lb_Temperatur->Font = (gcnew System::Drawing::Font(L"Comic
                                Sans MS",9.75F,System::Drawing::
                                FontStyle::Regular, System::Drawing::
                                GraphicsUnit::Point, 
                                static_cast<System::Byte>(0)));
   this->lb_Temperatur->Location = System::Drawing::Point(38, 20);
   this->lb_Temperatur->Name = L"lb_Temperatur";
   this->lb_Temperatur->Size = System::Drawing::Size(78, 18);
   this->lb_Temperatur->TabIndex = 1;
   this->lb_Temperatur->Text = L"Temperatur";
   // 
   // gB_von
   // 
   this->gB_von->Controls->Add(this->rB_von_C);
   this->gB_von->Controls->Add(this->rB_von_F);
   this->gB_von->Controls->Add(this->rB_von_K);
   this->gB_von->Font = (gcnew System::Drawing::Font(L"Comic Sans MS",
                         9.75F, System::Drawing::FontStyle::Regular, 
                         System::Drawing::GraphicsUnit::Point, 
                         static_cast<System::Byte>(0)));
   this->gB_von->Location = System::Drawing::Point(136, 20);
   this->gB_von->Name = L"gB_von";
   this->gB_von->Size = System::Drawing::Size(60, 120);
   this->gB_von->TabIndex = 5;
   this->gB_von->TabStop = false;
   this->gB_von->Text = L"von";
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
   this->bt_Rechnung->Font = (gcnew System::Drawing::Font(L"Comic Sans 
                              MS",9.75F,System::Drawing::FontStyle::
                              Regular,System::Drawing::GraphicsUnit::
                              Point,static_cast<System::Byte>(0)));
   this->bt_Rechnung->Location = System::Drawing::Point(282, 103);
   this->bt_Rechnung->Name = L"bt_Rechnung";
   this->bt_Rechnung->Size = System::Drawing::Size(100, 36);
   this->bt_Rechnung->TabIndex = 8;
   this->bt_Rechnung->Text = L"Berechnung";
   this->bt_Rechnung->UseVisualStyleBackColor = true;
   this->bt_Rechnung->Click += gcnew System::EventHandler(this,
                                      &Form1::bt_Rechnung_Click);
   // 
   // tB_Ergebnis
   // 
   this->tB_Ergebnis->Font = (gcnew System::Drawing::Font(L"Comic Sans 
                              MS",12,System::Drawing::FontStyle::
                              Regular,System::Drawing::GraphicsUnit::
                              Point,static_cast<System::Byte>(0)));
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