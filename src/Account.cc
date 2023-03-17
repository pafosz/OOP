#include "Account/account.h"
#include <stdexcept>


using namespace account;
using namespace std;

Account::Account() {}

Account::Account(AccountType type, std::string name, float balance, float percent) :
	_type(type),
	_name(name),
	_balance(balance),
	_percent(percent) {}

std::string Account::get_type() const {
	switch (_type)
	{
	case AccountType::payment:
		return "Payment";

	case AccountType::deposit:
		return "Deposit";
	case AccountType::credit:
		return "Credit";
	default:
		throw runtime_error("Unknown type");
	}
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


float Account::accrual() {
	switch (_type)
	{
	case AccountType::payment: break;

	case AccountType::deposit:

		if (_balance > 0)
			_balance += _balance / 100 * _percent / 12; //начисление на _balance процентов на депозит за мес€ц по ставке _percent
		break;


	case AccountType::credit:

		if (_balance < 0)
			_balance -= abs(_balance) / 100 * _percent / 12; //начисление на _balance процентов на кредит за мес€ц по ставке _percent		
		break;

	default:
		throw runtime_error("[Account::accrual]Invalid type");
		break;
	}
	return _balance;
}
