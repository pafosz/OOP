#include "account.h"
#include "Account/account.h"

using namespace account;
using namespace std;

Account::Account() : _name(""),	_balance(0) {}
Account::Account(std::string name, float balance) :	_name(name), _balance(balance) {}
Account::Account(std::string name, float balance, float percent): _name(name), _balance(balance), _percent(percent){}
std::string Account::get_name() const { return _name; }
float Account::get_balance() const { return _balance; }
float Account::get_percent() const { return _percent; }


Payment::Payment() : Account() {}
Payment::Payment() : Account(_name, _balance) {}
void Payment::print() const { cout << "Тип счёта: расчётный\n ФИО: " << _name << "\n Баланс: " << _balance << endl; }
shared_ptr<Account> Payment::clone() const { return make_shared<Payment>(_name, _balance); }

Deposit::Deposit() : Account() {}
Deposit::Deposit() : Account(_name, _balance, _percent) {}
void Deposit::print() const { cout << "Тип счёта: депозитный\n ФИО: " << _name << "\n Баланс: " << _balance << "р.\n Процент: " << _percent << "%" << endl; }
shared_ptr<Account> Deposit::clone() const { return make_shared<Deposit>(_name, _balance, _percent); }
float Deposit::accrual() const { return _balance + (_balance / 100 * _percent / 12); }

Credit::Credit() : Account() {}
Credit::Credit() : Account(_name, _balance, _percent) {}
void Credit::print() const { cout << "Тип счёта: кредитный\n ФИО: " << _name << "\n Баланс: " << _balance << "р.\n Процент: " << _percent << "%" << endl; }
shared_ptr<Account> Credit::clone() const { return make_shared<Credit>(_name, _balance, _percent); }
float Credit::accrual() const { return _balance - (abs(_balance) / 100 * _percent / 12); }




