#pragma once

#include <account/account.h>
#define ESC 27
#define UP 72
#define DOWN 80


namespace menu {

	const char ESCAPE = 27;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������
	
	// ��������� ������ � ����� x,y 
	void GoToXY(short x, short y) {};

	void ConsoleCursorVisible(bool show, short size) {};
	


}