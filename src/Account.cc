#include "Account/account.h"

using namespace account;
using namespace std;

Account::Account() : _name(""),	_balance(0) {}
Account::Account(const std::string& name, double balance) : _name(name), _balance(balance) {}

std::string Account::get_name() const {
	return _name; 
}
double Account::get_balance() const {
	return _balance; 
}


Payment::Payment() : Account() {}
Payment::Payment(const std::string& name, double balance) : Account(name, balance) {
	if (balance < 0) {
		throw runtime_error("Баланас расчётного счёта не может быть отрицательным");
	}
}
void Payment::print() const {
	cout << "Тип счёта: расчётный\n   ФИО: " << _name 
	<< "\n   Баланс: " << _balance << "р." << endl;
}
shared_ptr<Account> Payment::clone() const { 
	return make_shared<Payment>(_name, _balance); 
}

double Payment::accrual() { 
	return _balance; 
}

Deposit::Deposit() : Account(), _percent(0) {}
Deposit::Deposit(const std::string& name, double balance, double percent) : Account(name, balance), _percent(percent) {
	if (balance < 0) {
		throw runtime_error("Баланас депозитного счёта не может быть отрицательным");
	}
}
double Deposit::get_percent() const { 
	return _percent; 
}
void Deposit::print() const {
	cout << "Тип счёта: депозитный\n   ФИО: " << _name
		<< "\n   Баланс: " << _balance 
		<< "р.\n   Процент: " << _percent << "%" << endl; 
}
shared_ptr<Account> Deposit::clone() const {
	return make_shared<Deposit>(_name, _balance, _percent); 
}
double Deposit::accrual() { 
	_balance += _balance / 100 * _percent / 12;
	return _balance;
}

Credit::Credit() : Account(), _percent(0) {}
Credit::Credit(const std::string& name, double balance, double percent) : Account(name, balance), _percent(percent) {
	if (balance > 0) {
		throw runtime_error("Баланас кредита должен быть отрицательным");
	}
}
double Credit::get_percent() const { 
	return _percent; 
}
void Credit::print() const { 
	cout << "Тип счёта: кредитный\n   ФИО: " << _name 
		<< "\n   Баланс: " << _balance 
		<< "р.\n   Процент: " << _percent << "%" << endl; }
shared_ptr<Account> Credit::clone() const { 
	return make_shared<Credit>(_name, _balance, _percent); 
}
double Credit::accrual() { 
	_balance -= abs(_balance) / 100 * _percent / 12;
	return _balance; 
}




