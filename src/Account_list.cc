
#include "Account/account.h"

using namespace std;
using namespace account;

AccountList::AccountList(const AccountList& list) {
	for (int i = 0; i < _list.size(); ++i) {
		_list.push_back(list[i]->clone());
	}
};

AccountList& AccountList::operator=(AccountList list) {
	swap(list);
	return *this;
}

void AccountList::swap(AccountList& list) noexcept {
	_list.swap(list._list);
}

void AccountList::clear() {
	_list.clear();
}

const AccountPtr AccountList::operator[](size_t index) const {	
	return _list[index];
}

AccountPtr AccountList::operator[](size_t index) {
	
	return _list[index];
}

void AccountList::add(const AccountPtr account) {
	_list.push_back(account);		
}

size_t AccountList::get_size() const {
	return _list.size();
}

void AccountList::insert(AccountPtr account, int index) {
	if (index < 0 || _list.size() <= index)
		throw runtime_error("[AccountList::insert]Invalid index");

	_list.insert(_list.begin() + index, account);
}

void AccountList::remove(int index) {
	if (index < 0 || _list.size() <= index)
		throw runtime_error("[AccountList::remove]Invalid index");
		
	_list.erase(_list.begin() + index);
}

void AccountList::print() const {
	for (int i = 0; i < _list.size(); ++i) {
		cout << " " << i + 1 << ")";
		_list[i]->print();
	}
	cout << endl;
}

int AccountList::index_of_max_balance() const {

	int first_index = -1;
	float max_balance = 0;

	for (int i = 0; i < _list.size(); ++i) {

		auto balance = _list[i]->get_balance();

		if ((first_index == -1) || (max_balance < balance)) {
			first_index = i;
			max_balance = balance;
		}
	}
	return first_index;
}


