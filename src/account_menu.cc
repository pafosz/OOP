#include <account/account_menu.h>

using namespace std;
using namespace account;

void menu::text_menu()
{
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ћеню                               |" << endl;
	cout << " Ч-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить счЄт                                                 |" << endl;
	cout << " | 2 - вставить новый счЄт по индексу                                |" << endl;
	cout << " | 3 - удалить счЄт по индексу                                       |" << endl;
	cout << " | 4 - вывести список счетов                                         |" << endl;
	cout << " | 5 - рассчитать баланс счЄта по индексу после начислени€ процентов |" << endl;
	cout << " | 6 - поиск первого счЄта с наибольшим балансом                     |" << endl;
	cout << " | 7 - очистить список                                               |" << endl;
	cout << " | 8 - выйти из системы                                              |" << endl;
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

	cout << "¬ведите тип счЄта(1 - рассчЄтный, 2 - вклад, 3 - кредит): ";
	cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Ќе знаю такого типа");
	cout << "¬ведите им€ пользовател€: ";
	getline(cin >> ws, name);
	cout << "¬ведите баланс: ";
	cin >> balance;
	if (type == 3 && balance > 0)
		throw runtime_error("Ѕаланс кредита не может быть положительным");

	switch (type)
	{
	case 1:
		return make_shared<Payment>(name, balance);
	case 2:
		cout << "¬ведите процент: ";
		cin >> percent;
		return make_shared<Deposit>(name, balance, percent);
	case 3:
		cout << "¬ведите процент: ";
		cin >> percent;
		return make_shared<Credit>(name, balance, percent);
	}
}

