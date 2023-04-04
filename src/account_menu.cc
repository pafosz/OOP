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

void menu::print_menu(const string menu) 
{	
	short x = 50, y = 12;
	for (int i = 0; i < (sizeof(Menu) / sizeof(*Menu)); ++i)
	{
		if (i == active_menu) 	
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		else 	
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		menu::GoToXY(x, y++);
		cout << menu[i] << endl;
	}
}

