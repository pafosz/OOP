#include <Account/account_menu.h>
#include "Account/account.h"

using namespace account;
using namespace std;
using namespace menu;

int main()
{
	SetConsoleTitle("Accounts");

	system("CLS");

	setlocale(0, "Rus");
	ConsoleCursorVisible(false, 100);

	Users list;
	string name;
	int type;
	int index;
	double balance;
	double percent;

	char ch;
	while (true)
	{
		print_menu(Menu);
		ch = _getch();
		if (ch == -32) ch = _getch(); // ����������� ���������
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
				cout << "������� ��� �����(1 - ����������, 2 - �����, 3 - ������): ";
				cin >> type;
				cout << "������� ��� ������������: ";
				getline(cin >> ws, name);
				cout << "������� ������: ";
				cin >> balance;
				if ((AccountType)type == payment) {
					list.add({ (AccountType)type, name, balance });
				}
				else {
					cout << "������� �������: ";
					cin >> percent;
					list.add({ (AccountType)type, name, balance, percent });
				}
				cout << list;
				break;

			case 1:
				cout << "������� ������ ��� �������: ";
				cin >> index;
				cout << "������� ��� �����(1 - ����������, 2 - �����, 3 - ������): ";
				cin >> type;
				cout << "������� ��� ������������: ";
				getline(cin >> ws, name);
				cout << "������� ������: ";
				cin >> balance;
				if ((AccountType)type == payment) {
					list.insert({ (AccountType)type, name, balance }, index);
				}
				else {
					cout << "������� �������: ";
					cin >> percent;
					list.insert({ (AccountType)type, name, balance, percent }, index);
				}
				cout << list;
				break;
			case 2:
				cout << "������� ������ ��� ��������: ";
				cin >> index;
				list.remove(index);
				cout << list;
				break;
			case 3:
				cout << list;
				break;
			case 4:
				cout << "������� ������ �����, ������� ������� ������ ����������: ";
				cin >> index;
				list[index].accrual();
				cout << list[index].get_balance();
				break;
			case 5:
				cout << "������ ����� � ������������ ��������: " << list.index_of_max_balance() << endl;
				cout << list;
				break;
			case 6:
				exit(0);
			}

		/*default:
			cout << "��� " << (int)ch << endl;*/
		}

	}



	return 0;
}