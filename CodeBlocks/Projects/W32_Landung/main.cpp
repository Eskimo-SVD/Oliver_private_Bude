#include <windows.h>
#include <commctrl.h>

#include <sstream>
using namespace std;

//#include "D:\LuVPortableApp\CodeBlocksPortable\Projects\W32_Landung\positionen.h"
// Die Positionen des Fensters als Konstanten
const int FensterBreite=660;
const int FensterHoehe=480;
const int ThrottleX=5;
const int SliderY=10;
const int RuderX=630;
const int SliderLaenge = 256;
const int XOffsetBahn = 30;
const int InstrY1=400;
const int InstrY2=414;
const int HoeheX = 20;
const int EntfX = 100;
const int GeschwX = 180;
const int SteigX = 240;


//#include "D:\LuVPortableApp\CodeBlocksPortable\Projects\W32_Landung\game.h"
#include "game.h"



/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "Win32Fluglandung";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "WIN32-Fluglandung",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           FensterBreite,       /* The programs width */
           FensterHoehe,        /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

const int TIMERTICK=250;
const int THROTTLE_ID=1;

/*  This function is called by the Windows function DispatchMessage()  */

string double2string(const double wert)
{
    ostringstream ostr;
    ostr << wert;
    string str = ostr.str();
    return str;
}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	Game *game;
	CREATESTRUCT *cs;
	static HWND hwndThrottle;
	int Throttle;
	static HWND hwndRuder;
	int Ruder;
    string str;

    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            SetTimer(hwnd, 1, TIMERTICK, 0);
            cs = (LPCREATESTRUCT)lParam;
            InitCommonControls();
            hwndThrottle = CreateWindow(
                TRACKBAR_CLASS, "", WS_CHILD|WS_VISIBLE|TBS_AUTOTICKS|TBS_VERT,
                ThrottleX,10,20,200, hwnd, (HMENU)THROTTLE_ID, cs->hInstance, NULL);
            SendMessage(hwndThrottle, TBM_SETRANGEMAX, FALSE, 255);
            hwndRuder = CreateWindow(
                TRACKBAR_CLASS, "", WS_CHILD|WS_VISIBLE|TBS_AUTOTICKS|TBS_VERT,
                RuderX,10,20,200, hwnd, (HMENU)THROTTLE_ID, cs->hInstance, NULL);
            SendMessage(hwndRuder, TBM_SETRANGEMAX, FALSE, 255);
            break;
        case WM_PAINT:
        	hdc=BeginPaint(hwnd, &ps);
            game = Game::getInstance();
            BahnKoord bahn = game->getBahnKoord();
            POINT PolyBahn[5];
            for(int i=0; i<4; i++) {
                PolyBahn[i].x = bahn.Bahn[i].x + 30;
                PolyBahn[i].y = bahn.Bahn[i].y;
            }
            PolyBahn[4].x = bahn.Bahn[0].x +30;
            PolyBahn[4].y = bahn.Bahn[0].y;
            Polyline(hdc, PolyBahn, 5);

            TextOut(hdc, HoeheX, HoeheY, "Höhe", 4);
            str = double2string(game->getHoehe());
            TextOut(hdc, 10, 420, str.c_str(), str.length());

            TextOut(hdc, 100, 400, "Entf", 4);
            str = double2string(game->getDistanz());
            TextOut(hdc, 100, 420, str.c_str(), str.length());

            TextOut(hdc, 200, 400, "Geschw", 6);
            str =double2string(game->getGeschwindigkeit());
            TextOut(hdc, 200, 420, str.c_str(), str.length());

            TextOut(hdc, 300, 400, "Steig.", 6);
            str = double2string(game->getAnstieg()*100);
            TextOut(hdc, 300, 420, str.c_str(), str.length());

    		EndPaint(hwnd, &ps);
	    	break;
        case WM_TIMER:
            game = Game::getInstance();
            Throttle = SendMessage(hwndThrottle, TBM_GETPOS, 0, 0);
            game->setThrottle(255-Throttle);
            Ruder = SendMessage(hwndRuder, TBM_GETPOS, 0, 0);
            game->setRuder(255-Ruder);
            if (!game->naechsterTick()) {
                KillTimer(hwnd, 1);
                MessageBox(hwnd, "Spielende", "Fluglandung", MB_OK);
                game->neuesSpiel();
                SetTimer(hwnd, 1, TIMERTICK, 0);
            }
            InvalidateRect(hwnd, 0, TRUE);
            break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
