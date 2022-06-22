#include "SCOUT.h"
using namespace Sc;
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Sc::SCOUT form; //WinFormsTest - имя вашего проекта
	Application::Run(% form);
}
//
//Void SCOUT::MainF() {
//
//	HANDLE hStart = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"start");
//	HANDLE one = CreateEvent(NULL, TRUE, FALSE, L"one");
//	HANDLE two = CreateEvent(NULL, TRUE, FALSE, L"two");
//	
//	HANDLE s = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"s");
//	HANDLE hShow = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"SHOW");// Событие Show будет сообщать клиенту о печати сервером '*'
//
//	DWORD wait;
//	SetEvent(hStart);  // все создали засетили старт работаем
//		if (s == NULL) { textBox1->Text = L"error" + GetLastError(); } // прочекали работает ли семафор
//		wait = WaitForSingleObject(s, INFINITE);
//		if (wait != WAIT_TIMEOUT) {
//			tenB();
//		}
//
//}