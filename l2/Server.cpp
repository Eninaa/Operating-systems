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
			INFINITE, // ������ ���� ����� ���������� �����
			(LPSECURITY_ATTRIBUTES)NULL // ������ �� ���������
		);
		if (hNp == INVALID_HANDLE_VALUE)
		{
			cout << "������ ��� �������� ������" << endl
				<< "��� ������: " << GetLastError() << endl;
			system("pause");
			return 0;
		}
		while (true) {
			cout << "������� ����������� �������" << endl;
			if (!ConnectNamedPipe(
				hNp, // ���������� ������
				(LPOVERLAPPED)NULL // ����� ����������
			))
			{
				cout << "�� ������� ��������� �������" << endl
					<< "��� ������: " << GetLastError() << endl;
				CloseHandle(hNp);
				system("pause");
				return 0;
			}
			else {
				cout << "������ �����������" << endl;
			}

			while (true) {
				cout << "�������� ���� ����: " << endl << endl;
				cout << "0 � ������� ����������� ���" << endl;
				cout << "1 � �����" << endl;
				cout << "2 � �������" << endl;
				cout << "3 � �������" << endl;
				cout << "4 � �������" << endl;
				cout << "5 � �������" << endl;
				cout << "6 � ������" << endl;
				cout << "7 � �����" << endl;
				cout << "8 � �����" << endl;
				cout << "9 � ������ - �����" << endl;
				cout << "A � ������ - �������" << endl;
				cout << "B � ������ - �������" << endl;
				cout << "� � ������ - �������" << endl;
				cout << "D � ���� - �������" << endl;
				cout << "E � ������ - ������" << endl;
				cout << "F � ���� - �����" << endl;
				cout << "e - ��������� ������ �������" << endl;
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
					cout << "������ ��� �������� ������ �������" << endl;
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
