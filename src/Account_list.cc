#include "Account/account.h"


using namespace account;
using namespace std;

Users::Users() : _size(0) { }



Users::Users(const Users& copy)
{
	
};

void Users::swap(Users& rhs)
{
	int rhs_size(rhs.get_size());
	Account* rhs_list(rhs.get_list());

	std::swap(_size, rhs_size);
	std::swap(*_list, rhs_list);
}

Users& Users::operator=(const Users& rhs)
{
	Users copy(rhs);
	Users::swap(copy);
	return *this;
}

Users::~Users()
{
	for (int i = 0; i < _size; ++i) {
		delete _list[i];
	}
	delete[] _list;
}

int Users::get_size() const {
	return _size;
}

const Account& Users::operator[](int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::operator[](const)]Invalid index");
	return _list[index];
}

Account& Users::operator[](int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::operator[]]Invalid index");
	return _list[index];
}

void Users::add(Account User) {
	if (CAPACITY == _size)
		throw runtime_error("[Users::add]Going outside the array");

	_list[_size] = User;
	++_size;
}

void Users::insert(Account User, int index) {
	if (CAPACITY <= _size || _size <= 0)
		throw runtime_error("[Users::insert]Going outside the array");
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::insert]Invalid index");

	for (int i = _size; i > index; --i)
		_list[i] = _list[i - 1];
	_list[index] = User;
	++_size;
}

void Users::remove(int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::remove]Invalid index");

	--_size;
	for (int i = index; i < _size; ++i)
		_list[i] = _list[i + 1];
}

const Account& Users::get_item(int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::get_item]Invalid index");
	return _list[index];
}

int Users::index_of_max_balance() const {

	int first_index = -1;
	float max_balance = 0;

	for (int i = 0; i < get_size(); ++i) {

		auto balance = _list[i].get_balance();

		if ((first_index == -1) || (max_balance < balance)) {
			first_index = i;
			max_balance = balance;
		}
	}
	return first_index;
}


