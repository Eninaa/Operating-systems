#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <codecvt>
using namespace std;

char cc(char a) {
	if (a == '0') { return system("color 07"); }
	if (a == '1') { return system("color 17"); }
	if (a == '2') { return system("color 27"); }
	if (a == '3') { return system("color 37"); }
	if (a == '4') { return system("color 47"); }
	if (a == '5') { return system("color 57"); }
	if (a == '6') { return system("color 67"); }
	if (a == '7') { return system("color 77"); }
	if (a == '8') { return system("color 87"); }
	if (a == '9') { return system("color 97"); }
	if (a == 'A') { return system("color A7"); }
	if (a == 'B') { return system("color B7"); }
	if (a == 'C') { return system("color C7"); }
	if (a == 'D') { return system("color D7"); }
	if (a == 'E') { return system("color E7"); }
	if (a == 'F') { return system("color F7"); }
}
int main()
{
	setlocale(LC_ALL, "rus");
	bool connect = WaitNamedPipe("\\\\.\\pipe\\demo_pipe", NMPWAIT_WAIT_FOREVER);
	DWORD dwBytes;
	char a;
	HANDLE hNp;
	hNp = CreateFile(
		"\\\\.\\pipe\\demo_pipe", // ��� ������
		GENERIC_WRITE | GENERIC_READ, // ���������� � �����
		FILE_SHARE_READ, // ��������� ������ ������ � �����
		(LPSECURITY_ATTRIBUTES)NULL, // ������ �� ���������
		OPEN_EXISTING, // ��������� ������������ �����
		0, // �������� �� ���������
		(HANDLE)NULL // �������������� ��������� ���
	);
	if (hNp == INVALID_HANDLE_VALUE)
	{
		cout << "������ ��� ����������� � �������" << endl
			<< "��� ������: " << GetLastError() << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "������ �����������" << endl;
	}

	while (true) {
		
		if (!ReadFile(
			hNp,				//	���������� ������
			&a,					//	���� ����������
			255,				//	������������ ���������� ����������� ������ 
			&dwBytes,			//	� ���� ���������� ���������� ��������� ����������� ������
			NULL)				//	��������, ��������� ���������� (������ ���� ���� ������ �������� ����������)
			) {
			cout << "������ ��� ������ ������ � �������" << endl;
			system("pause");
			return 0;
		}
		cc(a);
		system("pause");
		system("cls");
	}
	CloseHandle(hNp);
	system("pause");
	return 0;
}
