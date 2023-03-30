#include <account/account_menu.h>
using namespace menu;
using namespace std;


void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // �������� ��������� �������
	structCursorInfo.dwSize = size;   // �������� ������ �������
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}


