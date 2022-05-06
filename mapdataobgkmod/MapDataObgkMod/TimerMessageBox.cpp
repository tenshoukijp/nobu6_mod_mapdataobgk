#include <windows.h>
#include "TimerMessageBox.h"





HWND g_hwndTimedOwner;
BOOL g_bTimedOut;

void CALLBACK MessageBoxTimer(HWND hwnd,
							  UINT uiMsg,
							  UINT idEvent,
							  DWORD dwTime)
{
	g_bTimedOut = TRUE;
	if (g_hwndTimedOwner)
		EnableWindow(g_hwndTimedOwner, TRUE);
	PostQuitMessage(0);
}


// 時間で自動的に閉じるメッセージボックス。ボタンを押しても反応するし、自動でも閉じる。
int TimedMessageBox(HWND hwndOwner,
					LPCTSTR pszMessage,
					LPCTSTR pszTitle,
					UINT flags,
					DWORD dwTimeout)
{
	UINT idTimer;
	int iResult;

	g_hwndTimedOwner = NULL;
	g_bTimedOut = FALSE;

	if (hwndOwner && IsWindowEnabled(hwndOwner))
		g_hwndTimedOwner = hwndOwner;

	//
	// タイマーセット
	idTimer = SetTimer(NULL, 0, dwTimeout, (TIMERPROC)MessageBoxTimer);

	iResult = MessageBox(hwndOwner, pszMessage, pszTitle, flags);

	//
	// タイマー削除
	KillTimer(NULL, idTimer);

	//
	// タイムアウトしてた場合に…
	if (g_bTimedOut) {
		MSG msg;
		PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
		iResult = -1;
	}

	return iResult;
}

