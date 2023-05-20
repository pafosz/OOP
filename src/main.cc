#include <Account/account_menu.h>
#include "Account/account.h"
#include <Windows.h>


using namespace account;
using namespace menu;
using namespace std;

int main()
{
	SetConsoleTitle("Accounts");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	AccountList list;

	menu::text_menu();

	while (true)
	{
		int choice = menu::get_key();
		int index = 0;

		system("cls");
		menu::text_menu();
		try {
			if (choice == 56) {
				list.clear();
				cout << "Вы вышли из системы" << endl;
				break;
			}

			switch (choice)
			{
			case 49:
				list.add(create_account());
				break;
			case 50:
				cout << "Введите индекс для вставки: ";
				cin >> index;
				list.insert(create_account(), index);
				break;
			case 51:
				cout << "Введите индекс счёта, который хотите удалить: ";
				cin >> index;
				list.remove(index);
				break;
			case 52:
				list.print();
				break;
			case 53:
				cout << "Введите индекс счёта, который хотите рассчитать: ";
				cin >> index;
				list[index]->accrual();
				cout << list[index]->get_balance() << "р.";
				break;
			case 54:
				cout << "Индекс счёта с максимальным балансом: " << list.index_of_max_balance() << endl;
				break;
			case 55:
				list.clear();
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;
		}		
	}
	return 0;
}
