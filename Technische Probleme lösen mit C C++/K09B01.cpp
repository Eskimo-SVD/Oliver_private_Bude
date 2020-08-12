void bt_Auswertung_Click(System::Object^ send,System::EventArgs^ e)
{
   // Diese Methode wird aufgerufen, wenn der Button "Auswertung"
      geclickt wird
   // Deklaration der lokalen Variablen
   int    xsa = 10;   // x-Richtung, Screen, Anfang
   int    xse = 510;  // x-Richtung, Screen, Ende
   int    ysa = 550;  // y-Richtung, Screen, Anfang
   int    yse = 130;  // y-Richtung, Screen, Ende
   double xwa;        // x-Richtung, Welt, Anfang aus Maske
   double xwe;        // x-Richtung, Welt, Ende   aus Maske
   double ywa = -1.;  // y-Richtung, Welt, Anfang
   double ywe = 1.;   // y-Richtung, Welt, Ende
   double sw = 0.001; // Schrittweite zur Zeichnungserstellung
   int    x1;         // x-Koordinate des 1.Punktes einer Linie
   int    y1;         // y-Koordinate des 1.Punktes einer Linie
   int    x2;         // x-Koordinate des 2.Punktes einer Linie
   int    y2;         // y-Koordinate des 2.Punktes einer Linie
   double xlauf, ylauf, xtemp, ytemp; // Hilfsvariablen
   double a, b, c, d;       // Koeffizienten in
                               f(x) = ax³ + bx² + cx + d
   double af1s, bf1s, cf1s; // Koeffizienten der 1.Ableitung
                               f'(x) = 3ax² + 2bx + c
   double af2s, bf2s;       // Koeffizienten der 2.Ableitung
                               f''(x) = 6ax + 2b
   double af3s;             // Koeffizienten der 3.Ableitung
                               f'''(x) = 6a
   int ssw;           //Skalierungs-Schritt-Weite
   // Create font and brush.
   System::Drawing::Font^ dF1 = gcnew System::Drawing::
                                Font("Arial",6);
   System::Drawing::Font^ dF2 = gcnew System::Drawing::
                                Font("Arial",10);
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
      this->lb_f1s->Text = "f'(x) = "+System::Convert::
                           ToString(af1s)+"x²";
      if (bf1s >= 0.0)
      {
         this->lb_f1s->Text += " + "+System::Convert::
                               ToString(bf1s)+"x";
      }
      else
      {
         this->lb_f1s->Text += " "+System::Convert::
                               ToString(bf1s)+"x";
      }
      if (cf1s >= 0.0)
      {
         this->lb_f1s->Text += " + "+System::Convert::
                               ToString(cf1s);
      }
      else
      {
         this->lb_f1s->Text += " "+System::Convert::
                               ToString(cf1s);
      }
      // Label für f''(x)
      this->lb_f2s->ForeColor = Color::Brown;
      this->lb_f2s->Text = "f''(x) = "+System::Convert::
                           ToString(af2s)+"x";
      if (bf2s >= 0.0)
      {
         this->lb_f2s->Text += " + "+System::Convert::
                               ToString(bf2s);
      }
      else
      {
         this->lb_f2s->Text += " "+System::Convert::ToString(bf2s);
      }
      // Label für f'''(x)
      this->lb_f3s->ForeColor = Color::Green;
      this->lb_f3s->Text = "f'''(x) = "+System::Convert::
                           ToString(af3s);
      // Errechnung der max. und min. Werte für y aus f(x), f'(x),
         f''(x) und f'''(x)
      for (xlauf = xwa; xlauf <= xwe; xlauf += sw)
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
      g->DrawRectangle(gcnew Pen(Color::Blue),xsa,yse,xse-xsa,
                                              ysa-yse);
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
      for (xlauf=(int)(xwa+0.99);xlauf<=(int)(xwe-0.99);
           xlauf+=ssw)
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
      for (xlauf = xwa + sw; xlauf <= xwe; xlauf = xlauf + sw)
      {
         x1 = trans(xsa,xse,xwa,xwe,xlauf-sw);
         xtemp = xlauf-sw;
         ytemp = a*pow(xtemp,3) + b*pow(xtemp,2) + c*xtemp + d;
         y1 = trans(ysa,yse,ywa,ywe,ytemp);
         x2 = trans(xsa,xse,xwa,xwe,xlauf);
         ytemp = a*pow(xlauf,3) + b*pow(xlauf,2) + c*xlauf + d;
         y2 = trans(ysa,yse,ywa,ywe,ytemp);
         g->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
      }
      // 2. f'(x)
      for (xlauf = xwa + sw; xlauf <= xwe; xlauf = xlauf + sw)
      {
         x1 = trans(xsa,xse,xwa,xwe,xlauf-sw);
         xtemp = xlauf-sw;
         ytemp = af1s*pow(xtemp,2) + bf1s*xtemp + cf1s;
         y1 = trans(ysa,yse,ywa,ywe,ytemp);
         x2 = trans(xsa,xse,xwa,xwe,xlauf);
         ytemp = af1s*pow(xlauf,2) + bf1s*xlauf + cf1s;
         y2 = trans(ysa,yse,ywa,ywe,ytemp);
         g->DrawLine(gcnew Pen(Color::Blue), x1, y1, x2, y2);
      }
      // 3. f''(x)
      for (xlauf = xwa + sw; xlauf <= xwe; xlauf = xlauf + sw)
      {
         x1 = trans(xsa,xse,xwa,xwe,xlauf-sw);
         xtemp = xlauf-sw;
         ytemp = af2s*xtemp + bf2s;
         y1 = trans(ysa,yse,ywa,ywe,ytemp);
         x2 = trans(xsa,xse,xwa,xwe,xlauf);
         ytemp = af2s*xlauf + bf2s;
         y2 = trans(ysa,yse,ywa,ywe,ytemp);
         g->DrawLine(gcnew Pen(Color::Brown), x1, y1, x2, y2);
      }
      // 4. f''(x)
      for (xlauf = xwa + sw; xlauf <= xwe; xlauf = xlauf + sw)
      {
         x1 = trans(xsa,xse,xwa,xwe,xlauf-sw);
         xtemp = xlauf-sw;
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
         MessageBox::Show("Eingabe nicht numerisch - bitte
                           korrigieren!","Eingabefehler");
      }
   }
}