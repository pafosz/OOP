#include <account/account.h>

using namespace account;

Account::Account(Type type, std::string name, float balance, float percent):
	_type(type),
	_name(name),
	_balance(balance),
	_percent(percent){}

float Account::get_balance() const {
	return _balance;
}


void Account::update() {
	++_balance;
}
