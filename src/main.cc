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
	Users list;
	Account user;

	menu::text_menu();

	while (true)
	{
		int choice = menu::get_key();		
		int index = 0;		

		system("cls");
		menu::text_menu();

		
		if (choice == 55) {
			list.clear();
			break;
		}

		switch (choice)
		{
		case 49:
			list.add(create_account());
			break;
		case 50:
			cout << "������� ������ ��� �������: ";
			cin >> index;
			
			list.insert(create_account(), index);
			break;
		case 51:
			cout << "������� ������ �����, ������� ������ �������: ";
			cin >> index;
			list.remove(index);
			break;
		case 52:
			cout << list;
			break;
		case 53:
			cout << "������� ������ �����, ������� ������ ����������: ";
			cin >> index;
			list[index].accrual();
			cout << list[index].get_balance();
			break;

		case 54:
			cout << "������ ����� � ������������ ��������: " << list.index_of_max_balance() << endl;
			break;
		
		}
	}
	return 0;
}