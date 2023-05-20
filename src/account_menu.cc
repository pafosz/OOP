#include <account/account_menu.h>

using namespace std;
using namespace account;

void menu::text_menu()
{
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                Меню                               |" << endl;
	cout << " —-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить счёт                                                 |" << endl;
	cout << " | 2 - вставить новый счёт по индексу                                |" << endl;
	cout << " | 3 - удалить счёт по индексу                                       |" << endl;
	cout << " | 4 - вывести список счетов                                         |" << endl;
	cout << " | 5 - рассчитать баланс счёта по индексу после начисления процентов |" << endl;
	cout << " | 6 - поиск первого счёта с наибольшим балансом                     |" << endl;
	cout << " | 7 - очистить список                                               |" << endl;
	cout << " | 8 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

int menu::get_key()
{
	int key = _getch();	
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56)) 
		return key;
	//throw "Нет такого действия";
	return 0;
}


shared_ptr<Account> menu::create_account()
{	
	std::string name;
	int type;
	double balance, percent;

	cout << "Введите тип счёта(1 - рассчётный, 2 - вклад, 3 - кредит): ";
	cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Не знаю такого типа");
	cout << "Введите имя пользователя: ";
	getline(cin >> ws, name);
	cout << "Введите баланс: ";
	cin >> balance;
	
	switch (type)
	{
	case 1:
		return make_shared<Payment>(name, balance);
	case 2:
		cout << "Введите процент: ";
		cin >> percent;
		return make_shared<Deposit>(name, balance, percent);
	case 3:
		cout << "Введите процент: ";
		cin >> percent;
		return make_shared<Credit>(name, balance, percent);

	}
}

