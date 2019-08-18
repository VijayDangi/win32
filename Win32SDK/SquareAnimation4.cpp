//header file
#include <Windows.h>

#define MY_TIMER_ID 101

//declare callback window procedure
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR iCmdLine, int iCmdShow)
{
	//local variables
	WNDCLASSEX wndclass;
	MSG msg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("SquareAnimation1");
	
	//initialize window class
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.hInstance = hInstance;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
	
	//register class
	RegisterClassEx(&wndclass);
	
	//create window in memory
	hwnd = CreateWindow(
				szAppName,
				TEXT("SQUARE ANIMATION - 1"),
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				NULL,
				NULL,
				hInstance,
				NULL
			);
			
	//show Window
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	
	//message loop
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return ((int)msg.wParam);
}

//defining window callback procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rect,rectTemp;
	static int iPaintFlag = 0;
	HDC hdc;
	static HBRUSH hBrush = NULL;
	PAINTSTRUCT ps;
	static BOOL flag = FALSE;
	TCHAR str[255];
	
	switch(iMsg)
	{
		case WM_CREATE:
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SetTimer(hwnd, MY_TIMER_ID, 20, NULL);
			break;
		
		
		
		case WM_TIMER:
			KillTimer(hwnd, MY_TIMER_ID);
			
			iPaintFlag++;
			if(iPaintFlag > 100)
			{
				if(flag){
					flag = FALSE;
				}else{
					flag = TRUE;
				}
				iPaintFlag = 0;
			}
			InvalidateRect(hwnd, NULL, TRUE);
			SetTimer(hwnd, MY_TIMER_ID, 20, NULL);
			break;
		
		
		
		case WM_PAINT:
			GetClientRect(hwnd, &rect);
			hdc = BeginPaint(hwnd, &ps);
			
			if(flag){
				
				rectTemp.top = rect.bottom - (iPaintFlag * rect.bottom/100);
				rectTemp.bottom = rect.bottom ;
				rectTemp.left = rect.left;
				rectTemp.right = rect.left + (iPaintFlag * rect.right/100);
				//wsprintf(str, TEXT("%d %d %d %d"), rectTemp.left, rectTemp.top, rectTemp.right, rectTemp.bottom);
				//MessageBox(hwnd, str, TEXT("left top right bottom"), MB_OK);
			}
			else{
				rectTemp.top = rect.top + (iPaintFlag * rect.bottom/100);
				rectTemp.bottom = rect.bottom ;
				rectTemp.left = rect.left;
				rectTemp.right = rect.right - (iPaintFlag * rect.right/100);
			}
			
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rectTemp, hBrush);
			
			EndPaint(hwnd, &ps);
			break;
		
		
		
		
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
