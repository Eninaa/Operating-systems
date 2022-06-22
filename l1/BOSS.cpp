#include "BOSS.h"
using namespace System::Threading;
using namespace ossen;
[STAThread]
void main(array<String^> ^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ossen::BOSS form; //WinFormsTest - им€ вашего проекта
	Application::Run(% form);
}

Void BOSS::MainF() {
	WaitForSingleObject(hStart, INFINITE);
	HANDLE one = OpenEvent(EVENT_ALL_ACCESS, true, L"one");
	HANDLE two = OpenEvent(EVENT_ALL_ACCESS, true, L"two");      // открываем событи€ означающие какой символ был напечатан
	HANDLE end = OpenEvent(EVENT_ALL_ACCESS, true, L"end");
	HANDLE close = OpenEvent(EVENT_ALL_ACCESS, true, L"cl");
	HANDLE hThread[3];                    // создаем массив потоков ??
	hThread[0] = one;
	hThread[1] = two;
	hThread[2] = end;
	bool f = true;
	String^ s = L" ";
	while (f) {
		int i = n - numcl + 1;
		WaitForMultipleObjects(3, hThread, FALSE, INFINITE);
		if (WaitForSingleObject(one, 0) == WAIT_OBJECT_0) { s += "1"; ResetEvent(one); }
		if (WaitForSingleObject(two, 0) == WAIT_OBJECT_0) { s += "2"; ResetEvent(two); }
		if (WaitForSingleObject(end, 0) == WAIT_OBJECT_0) { tlog(L" лиент " + i + ": " + s); SetEvent(hShow); s = " "; ResetEvent(end); }
		if (WaitForSingleObject(close, 0) == WAIT_OBJECT_0) { numcl--; s = " "; logFile(" лиент " + i + " завершил свою работу "); ResetEvent(close); }
		if (numcl == 0) { f = false; }
	}
}


