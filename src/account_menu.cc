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
	structCursorInfo.bVisible = show; // изменяем видимость курсора
	structCursorInfo.dwSize = size;   // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}


