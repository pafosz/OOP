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


		if (choice == 56) {
			list.clear();
			break;
		}

		switch (choice)
		{
		case 49:
			list.add(create_account());
			break;
		case 50:
			cout << "¬ведите индекс дл€ вставки: ";
			cin >> index;
			list.insert(create_account(), index);
			break;
		case 51:
			cout << "¬ведите индекс счЄта, который хотите удалить: ";
			cin >> index;
			list.remove(index);
			break;
		case 52:
			list.print();
			break;
		case 53:
			cout << "¬ведите индекс счЄта, который хотите рассчитать: ";
			cin >> index;
			if (typeid(list[index]) == typeid(Payment)) {
				cout << "ƒл€ обычного счЄта нельз€ рассчитать остаток по проценту";
				break;
				list[index]->accrual();
				cout << list[index]->get_balance();
				break;
		case 54:
			cout << "»ндекс счЄта с максимальным балансом: " << list.index_of_max_balance() << endl;
			break;
		case 55:
			list.clear();
			break;
			}
		}
	}
		return 0;
	
}