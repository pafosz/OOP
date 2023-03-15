#include "Account/account.h"
#include <stdexcept>

using namespace account;
using namespace std;

Users::Users(int size) : _size(size) { }

int Users::get_size() const {
	return _size;
}

Account Users::operator[](int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::operator[](const)]Invalid index");
	return _list[index];
}

Account& Users::operator[](int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::operator[]]Invalid index");
	return _list[index];
}

void Users::insert(Account User, int index) {
	if(CAPACITY <= _size || _size <= 0)
		throw runtime_error("[Users::insert]Going outside the array");
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::insert]Invalid index");

	for (int i = _size; i > index; --i)
		_list[i] = _list[i - 1];
	_list[index] = User;
	++_size;
}

void Users::remove(int index) {
	if (CAPACITY <= _size || _size <= 0)
		throw runtime_error("[Users::remove]Going outside the array");
	if(index<0 || _size <= index)
		throw runtime_error("[Users::remove]Invalid index");
	--_size;
	for (int i = index; i < _size; ++i)
		_list[i] = _list[i + 1];
}

Account Users::get_item(int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::get_item]Invalid index");
	return _list[index];
}

int Users::index_of_max_balance(const Users& users) const {

	int max_index = -1;
	float max_balance = 0;

	const auto n = users.get_size();

	for (int i = 0; i < n; ++i) {
		auto value = users[i].get_balance();

		if (max_index == -1 || max_balance < value) {
			max_index = i;
			max_balance = value;
		}
	}
	
}


