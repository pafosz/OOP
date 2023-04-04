#include <Account/account_menu.h>
#include "Account/account.h"

using namespace std;
using namespace menu;

int main()
{
	SetConsoleTitle("Accounts");

	system("CLS");

	setlocale(0, "Rus");
	ConsoleCursorVisible(false, 100);
	char ch;
	while (true)
	{
		print_menu(Menu);
		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case ESC:
			exit(0);
		case UP:
			if (active_menu > 0)
				--active_menu;
			break;
		case DOWN:
			if (active_menu < (sizeof(Menu) / sizeof(*Menu)) - 1)
				++active_menu;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				break;
			case 1:
				break;
			default:
				break;
			}

		default:
			cout << "Код " << (int)ch << endl;
		}

	}



	return 0;
}