#pragma once

#include <account/account.h>
#define ESC 27
#define UP 72
#define DOWN 80


namespace menu {

	const char ESCAPE = 27;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
	
	// Текстовый курсор в точку x,y 
	void GoToXY(short x, short y) {};

	void ConsoleCursorVisible(bool show, short size) {};
	


}