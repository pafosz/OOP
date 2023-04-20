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
	cout << " | 7 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

int menu::get_key()
{
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55))	
		return key;	
}


Account menu::create_account()
{
	Account user;
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
	if ((AccountType)type == credit && balance > 0)
		throw runtime_error(" редит не может иметь положительный баланс");
	if ((AccountType)type == payment) {
		user = { (AccountType)type, name, balance };		
	}
	else {
		cout << "¬ведите процент: ";
		cin >> percent;
		user = { (AccountType)type, name, balance, percent };
		
	}
	return user;
}


