// Joe Noonan
// backgroundImageDeleter.cpp
// PURPOSE: This is the main file to run the application window and processes.
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <fstream>
#include <stdio.h>
#include "resource.h"

using namespace std;

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Background Image Deleter");

//Icon that the delete button will display
HWND button;
static HICON hIcon;
HINSTANCE hInstance = GetModuleHandle(NULL);

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Prototype for deleting a system file (background image in this case):
/*
BOOL WINAPI DeleteFile(
	_In_ LPCTSTR lpFileName
);
*/

//Prototype for finding the file path of the the cached background image:
string getFilepath();

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T(" "),
			NULL);

		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance;

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// 1407, 0: initial position (x, y) (top right of screen). Can't figure out how to put it in top right all the time.
	// 110, 130: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		1407, 0,
		110, 130,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T(" "),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("");//Could enter a user message here if desired.

	switch (message)
	{
	case WM_CREATE:
		button = CreateWindow(TEXT("button"), TEXT("DELETE"),
			WS_VISIBLE | WS_CHILD | BS_FLAT | BS_ICON,
			5, 5, 110, 80, hWnd, (HMENU) 1, NULL, NULL
		);
		hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)); //Find out how to have button fill the whole button space.
		SendMessage(button, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)hIcon);
	case WM_COMMAND:
		if (LOWORD(wParam) == 1) {
			//ADD THE CODE FOR DELETING THE PHOTO HERE:
			//Possible method for deletion using image comparison and cached image:
			//  Steps for method 1:
			//  #1)Use a vbs script that returns the file path for the currently displayed image.
			//  #2) Pass the file path to the DeleteFile function.
			//  #3) See if this works then see if Windows OS automaticall moves to the next image avaiable or if I have to write code for that transition.

			//Function call for DeleteFile function if the vbsa script gives us the file destination
		}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		//Prints a message to the screen if desired
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

//possibly include this becasue popen isnt working??? popen only works on Linux machines
FILE * _popen(const char * command, const char * mode)
{
	return nullptr;
}

string getFilepath()
{
	char *array = new char[500];
	for (int i = 0; i < 500; i++) {
		
	}
	//use popen()
	string command = "dir";
	FILE* pipe = popen(command.c_str(), "r");

	fgets(array, 500, pipe);

	string filePath(array);

	//Change the char array to a string

	return filePath;
}\

//instead of pipe i could use fork
