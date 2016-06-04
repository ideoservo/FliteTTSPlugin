// tester.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "tester.h"

#include "../include/flite.h"

extern "C" {
cst_voice *register_cmu_us_rms(const char *voxdir);
void unregister_cmu_us_rms(cst_voice *v);
cst_voice *register_cmu_us_slt(const char *voxdir);
void unregister_cmu_us_slt(cst_voice *v);
}

#pragma comment(lib, "fliteDll.lib")
#pragma comment(lib, "cmu_us_rms.lib")
#pragma comment(lib, "cmu_us_slt.lib")

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

    flite_init();

    cst_voice *v1 = register_cmu_us_rms(NULL);
    cst_voice *v2 = register_cmu_us_slt(NULL);
	::Beep(1000, 800);
	//male us english
	flite_text_to_speech("Flite TTS Plugin for Unreal Engine is a great Talk to Speech library", v1, "play");
	//female us english
    flite_text_to_speech("Flite TTS Plugin for Unreal Engine is a great Talk to Speech library", v2, "play");
    ::Beep( 1000, 800);
    
}
