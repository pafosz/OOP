#include <Account/account_menu.h>

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
		ch = _getch();
		if (ch == -32) ch = _getch(); // ����������� ���������
		switch (ch)
		{
		case ESC:
			exit(0);
		case UP:
			cout << "Up, ��� " << (int)ch << endl;
			break;
		case DOWN:
			cout << "Down, ��� " << (int)ch << endl;
			break;
		
		default:
			cout << "��� " << (int)ch << endl;
		}

	}

	

	return 0;
}