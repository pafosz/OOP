#pragma once

#include <string>
#include <stdexcept>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <iostream>

#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13


namespace menu {

	const char ESCAPE = 27;

	int active_menu = 0;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
	
	// Текстовый курсор в точку x,y 
	void GoToXY(short x, short y) {};

	void ConsoleCursorVisible(bool show, short size) {};

	string Menu[] = { "Новая игра", "Загрузить", "Настройки", "Выход" };
	
	void print_menu(const std::string menu);

}