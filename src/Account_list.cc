#include "Account/account.h"


using namespace account;
using namespace std;

Users::Users() : _list(nullptr), _size(0) { }

Users::Users(const Users& copy) :
	_list(new Account* [copy._size]),
	_size(copy._size){
	for (int i = 0; i < _size; ++i)
		_list[i] = new Account(*copy._list[i]);
};

void Users::swap(Users& rhs) noexcept
{
	std::swap(_size, rhs._size);
	std::swap(_list, rhs._list);
}

Users& Users::operator=(Users copy)
{
	this->swap(copy);
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
	return *_list[index];
}

Account& Users::operator[](int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::operator[]]Invalid index");
	return *_list[index];
}

void Users::add(Account* user) {

	auto list = new Account * [_size + 1];
	for (int i = 0; i < _size; ++i)
		list[i] = _list[i];
	list[_size] = user;

	delete[] _list;

	_list = list;
	++_size;
}

void Users::insert(Account* user, int index) {	
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::insert]Invalid index");

	for (int i = _size; i > index; --i)
		_list[i] = _list[i - 1];
	_list[index] = user;
	++_size;
}

void Users::remove(int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::remove]Invalid index");

	--_size;
	for (int i = index; i < _size; ++i)
		_list[i] = _list[i + 1];
}

void Users::clear() { _size = 0; }

const Account& Users::get_item(int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[Users::get_item]Invalid index");
	return *_list[index];}



ostream& operator<<(ostream& stream, const Account& c) {
	stream << c.get_type() << " " << c.get_name() << " " << c.get_balance() << " " << c.get_percent();	
	return stream;
}

int Users::index_of_max_balance() const {

	int first_index = -1;
	float max_balance = 0;

	for (int i = 0; i < get_size(); ++i) {

		auto balance = _list[i]->get_balance();

		if ((first_index == -1) || (max_balance < balance)) {
			first_index = i;
			max_balance = balance;
		}
	}
	return first_index;
}


