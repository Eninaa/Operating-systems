#include <windows.h>
#include <iostream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <codecvt>
using namespace std;

int main() {

	srand(time(NULL));
	int n = 3;
		//rand() % 3 + 1;
	setlocale(LC_ALL, "rus");
	char buf[256];
	DWORD dwBytes;
	STARTUPINFO* si = new STARTUPINFO[n];
	PROCESS_INFORMATION* pi = new PROCESS_INFORMATION[n];
	for (int i = 0; i < n; i++) {
		ZeroMemory(&si[i], sizeof(STARTUPINFO));
		ZeroMemory(&pi[i], sizeof(PROCESS_INFORMATION));
	}
	for (int i = 0; i < n
		&& CreateProcess("c:\\Users\\User\\source\\repos\\oss2\\Debug\\client.exe",
			NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si[i], &pi[i]); i++) {}
	for (int i = 0; i < n; i++) {
		HANDLE hNp = CreateNamedPipe("\\\\.\\pipe\\demo_pipe", PIPE_ACCESS_DUPLEX,
			PIPE_TYPE_MESSAGE | PIPE_WAIT, 1,
			0, 0,
			INFINITE, // клиент ждет св€зь бесконечно долго
			(LPSECURITY_ATTRIBUTES)NULL // защита по умолчанию
		);
		if (hNp == INVALID_HANDLE_VALUE)
		{
			cout << "ќшибка при создании канала" << endl
				<< " од ошибки: " << GetLastError() << endl;
			system("pause");
			return 0;
		}
		while (true) {
			cout << "ќжидаем подключение клиента" << endl;
			if (!ConnectNamedPipe(
				hNp, // дескриптор канала
				(LPOVERLAPPED)NULL // св€зь синхронна€
			))
			{
				cout << "Ќе удалось дождатьс€ клиента" << endl
					<< " од ошибки: " << GetLastError() << endl;
				CloseHandle(hNp);
				system("pause");
				return 0;
			}
			else {
				cout << " лиент подключилс€" << endl;
			}

			while (true) {
				cout << "¬ыберите цвет фона: " << endl << endl;
				cout << "0 Ч вернуть изначальный фон" << endl;
				cout << "1 Ч синий" << endl;
				cout << "2 Ч зеленый" << endl;
				cout << "3 Ч голубой" << endl;
				cout << "4 Ч красный" << endl;
				cout << "5 Ч лиловый" << endl;
				cout << "6 Ч желтый" << endl;
				cout << "7 Ч белый" << endl;
				cout << "8 Ч серый" << endl;
				cout << "9 Ч светло - синий" << endl;
				cout << "A Ч светло - зеленый" << endl;
				cout << "B Ч светло - голубой" << endl;
				cout << "— Ч светло - красный" << endl;
				cout << "D Ч €рко - розовый" << endl;
				cout << "E Ч светло - желтый" << endl;
				cout << "F Ч €рко - белый" << endl;
				cout << "e - завершить работу клиента" << endl;
				cin >> buf;

				while (!((buf[0] >= '0' && buf[0] <= '9') || (buf[0] >= 'A' && buf[0] <= 'F') || buf[0] == 'e' || (cin.peek() != '\n'))) {
					cout << "Error! Try again" << endl;
					cin.clear();
					while (cin.get() != '\n');
					cin >> buf;
				}
				if (!strcmp(buf, "e")) break;
				cout << buf;
				if (!WriteFile(hNp, &buf, 255, &dwBytes, NULL)) {
					cout << "ќшибка при передаче данных клиенту" << endl;
					system("pause");
					return 0;
				}
				system("cls");

			}
			DisconnectNamedPipe(hNp);
		}
		CloseHandle(hNp);
	}
	system("pause");
	return 0;
}
