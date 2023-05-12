
#include "Account/account.h"

using namespace std;
using namespace account;


AccountList::AccountList() : _list(nullptr), _size(0) { }

AccountList::AccountList(const AccountList& copy) :
	_list(new Account* [copy._size]),
	_size(copy._size) 
{
	for (int i = 0; i < _size; ++i)
		_list[i] = new Account(*copy._list[i]);
};

void AccountList::swap(AccountList& rhs) noexcept
{
	std::swap(_size, rhs._size);
	std::swap(_list, rhs._list);
}

AccountList& AccountList::operator=(AccountList copy)
{
	swap(copy);
	return *this;
}

AccountList::~AccountList()
{	
	clear();
}
void AccountList::clear() {
	if (_list == nullptr)
		return;

	for (int i = 0; i < _size; ++i)
		delete _list[i];
	_size = 0;
	delete[] _list;
	_list = nullptr;
}



int AccountList::get_size() const {
	return _size;
}

const Account& AccountList::operator[](int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[AccountList::operator[](const)]Invalid index");
	return *_list[index];
}

Account& AccountList::operator[](int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[AccountList::operator[]]Invalid index");
	return *_list[index];
}

void AccountList::add(const Account& user) {
			
	auto list = new Account * [_size + 1];
	for (int i = 0; i < _size; ++i)
		list[i] = _list[i];
	list[_size] = new Account(user);

	delete[] _list;

	_list = list;
	++_size;
}

void AccountList::insert(Account user, int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[AccountList::insert]Invalid index");

	auto list = new Account * [_size + 1];
	
	for (int i = 0; i < _size; ++i)
		list[i] = _list[i];

	for (int i = _size; i > index; --i)
		list[i] = list[i - 1];
	list[index] = new Account(user);

	delete[] _list;

	_list = list;
	++_size;
}

void AccountList::remove(int index) {
	if (index < 0 || _size <= index)
		throw runtime_error("[AccountList::remove]Invalid index");
		
	delete _list[index];
	for (int i = index; i < _size - 1; ++i)
		_list[i] = _list[i + 1];
	--_size;
}


const Account& AccountList::get_item(int index) const {
	if (index < 0 || _size <= index)
		throw runtime_error("[AccountList::get_item]Invalid index");
	return *_list[index];
}


std::ostream& account::operator<<(std::ostream& stream, const AccountList& list) {
	stream << list.get_size() << " accounts: " << endl;
	for (int i = 0; i < list.get_size(); ++i)
		cout << "  " << i + 1 << ") " << list.get_item(i);
	return stream;
}


int AccountList::index_of_max_balance() const {

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


