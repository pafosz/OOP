#include "Account/account.h"
//#include <Account/account.h>

using namespace account;

Account::Account() {
	_balance = 0;
	Type::payment;
}

Account::Account(Type type, std::string name, float balance, float percent) :
	_type(type),
	_name(name),
	_balance(balance),
	_percent(percent) {}

Type Account::get_type() const {
	return _type;
}

std::string Account::get_name() const {
	return _name;
}

float Account::get_balance() const {
	return _balance;
}

float Account::get_percent() const {
	return _percent;
}


void Account::accrual(Type _type, float _balance, float _percent) {
	switch (_type)
	{
	case Type::payment:
		{
			
		break;
		}
	case Type::deposit:
	{
		float positive_balance;
		positive_balance = _balance;
		if (positive_balance > 0) {
			_balance += _balance / 100 * _percent / 12; //начисление на _balance процентов на депозит за мес€ц по ставке _percent
		}
		break;
	}
	case Type::credit:
	{
		float negative_balance;
		negative_balance = _balance;
		if (negative_balance < 0) {
			_balance -= abs(_balance) / 100 * _percent / 12; //начисление на _balance процентов на кредит за мес€ц по ставке _percent
		}
		break;
	}
	}
}
