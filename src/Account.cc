#include "Account/account.h"

using namespace account;
using namespace std;

Account::Account() : _name(""),	_balance(0) {}
Account::Account(std::string name, float balance) :	_name(name), _balance(balance){}

std::string Account::get_name() const { return _name; }
float Account::get_balance() const { return _balance; }


Payment::Payment() : Account() {}
Payment::Payment(std::string name, float balance) : Account(_name, _balance) {}
void Payment::print() const { cout << "Тип счёта: расчётный\n ФИО: " << _name << "\n Баланс: " << _balance << endl; }
shared_ptr<Account> Payment::clone() const { return make_shared<Payment>(_name, _balance); }
float Payment::accrual() const { return _balance; }

Deposit::Deposit() : Account(), _percent(0) {}
Deposit::Deposit(std::string name, float balance, float percent) : Account(_name, _balance), _percent(percent) {}
float Deposit::get_percent() const { return _percent; }
void Deposit::print() const { cout << "Тип счёта: депозитный\n ФИО: " << _name << "\n Баланс: " << _balance << "р.\n Процент: " << _percent << "%" << endl; }
shared_ptr<Account> Deposit::clone() const { return make_shared<Deposit>(_name, _balance, _percent); }
float Deposit::accrual() const { return _balance + (_balance / 100 * _percent / 12); }

Credit::Credit() : Account(), _percent(0) {}
Credit::Credit(std::string name, float balance, float percent) : Account(_name, _balance), _percent(percent) {}
float Credit::get_percent() const { return _percent; }
void Credit::print() const { cout << "Тип счёта: кредитный\n ФИО: " << _name << "\n Баланс: " << _balance << "р.\n Процент: " << _percent << "%" << endl; }
shared_ptr<Account> Credit::clone() const { return make_shared<Credit>(_name, _balance, _percent); }
float Credit::accrual() const { return _balance - (abs(_balance) / 100 * _percent / 12); }




