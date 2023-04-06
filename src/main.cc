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
		if (ch == -32) ch = _getch(); // ќтлавливаем стрелочки
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
				cout << "¬ведите тип счЄта(1 - рассчЄтный, 2 - вклад, 3 - кредит): ";
				cin >> type;
				cout << "¬ведите им€ пользовател€: ";
				getline(cin >> ws, name);
				cout << "¬ведите баланс: ";
				cin >> balance;
				if ((AccountType)type == payment) {
					list.add({ (AccountType)type, name, balance });
				}
				else {
					cout << "¬ведите процент: ";
					cin >> percent;
					list.add({ (AccountType)type, name, balance, percent });
				}
				cout << list;
				break;

			case 1:
				cout << "¬ведите индекс дл€ вставки: ";
				cin >> index;
				cout << "¬ведите тип счЄта(1 - рассчЄтный, 2 - вклад, 3 - кредит): ";
				cin >> type;
				cout << "¬ведите им€ пользовател€: ";
				getline(cin >> ws, name);
				cout << "¬ведите баланс: ";
				cin >> balance;
				if ((AccountType)type == payment) {
					list.insert({ (AccountType)type, name, balance }, index);
				}
				else {
					cout << "¬ведите процент: ";
					cin >> percent;
					list.insert({ (AccountType)type, name, balance, percent }, index);
				}
				cout << list;
				break;
			case 2:
				cout << "¬ведите индекс дл€ удалени€: ";
				cin >> index;
				list.remove(index);
				cout << list;
				break;
			case 3:
				cout << list;
				break;
			case 4:
				cout << "¬ведите индекс счЄта, который который хотите рассчитать: ";
				cin >> index;
				list[index].accrual();
				cout << list[index].get_balance();
				break;
			case 5:
				cout << "»ндекс счЄта с максимальным балансом: " << list.index_of_max_balance() << endl;
				cout << list;
				break;
			case 6:
				exit(0);
			}

		/*default:
			cout << " од " << (int)ch << endl;*/
		}

	}



	return 0;
}