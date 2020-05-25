#ifndef _FLUGLANDUNG_H_
#define _FLUGLANDUNG_H_

class 
fluglandungapp : public wxApp
{
public:
	virtual bool OnInit();
};

class 
fluglandungFrame : public wxFrame
{
public:
	fluglandungFrame(const wxString& title,
                const wxPoint& pos, const wxSize& size);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
    void Navigate(int, int&);
    void OnTimer(wxTimerEvent& event);
private:
    wxPanel *panel;
    wxTimer timer;
    wxSlider *Throttle;
    wxSlider *Ruder;
};

#endif // _FLUGLANDUNG_H_
