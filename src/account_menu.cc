#include <account/account_menu.h>

using namespace std;
using namespace account;

void menu::text_menu()
{
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ����                               |" << endl;
	cout << " �-------------------------------------------------------------------" << endl;
	cout << " | 1 - �������� ����                                                 |" << endl;
	cout << " | 2 - �������� ����� ���� �� �������                                |" << endl;
	cout << " | 3 - ������� ���� �� �������                                       |" << endl;
	cout << " | 4 - ������� ������ ������                                         |" << endl;
	cout << " | 5 - ���������� ������ ����� �� ������� ����� ���������� ��������� |" << endl;
	cout << " | 6 - ����� ������� ����� � ���������� ��������                     |" << endl;
	cout << " | 7 - �������� ������                                               |" << endl;
	cout << " | 8 - ����� �� �������                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

int menu::get_key()
{
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56))
		return key;	
}


shared_ptr<Account> menu::create_account()
{	
	std::string name;
	int type;
	float balance, percent;

	cout << "������� ��� �����(1 - ����������, 2 - �����, 3 - ������): ";
	cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("�� ���� ������ ����");
	cout << "������� ��� ������������: ";
	getline(cin >> ws, name);
	cout << "������� ������: ";
	cin >> balance;
	if (type == 3 && balance > 0)
		throw runtime_error("������ ������� �� ����� ���� �������������");

	switch (type)
	{
	case 1:
		return make_shared<Payment>(name, balance);
	case 2:
		cout << "������� �������: ";
		cin >> percent;
		return make_shared<Deposit>(name, balance, percent);
	case 3:
		cout << "������� �������: ";
		cin >> percent;
		return make_shared<Credit>(name, balance, percent);
	}
}

