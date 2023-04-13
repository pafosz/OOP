#pragma once
#include <string>
#include <stdexcept>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <iostream>

namespace account {

	enum AccountType {
		payment = 1,
		deposit,
		credit
	};

	class Account {

		AccountType _type;
		std::string _name;
		float _balance;
		float _percent;

	public:

		Account();
		Account(AccountType type, std::string name, float balance);
		Account(AccountType type, std::string name, float balance, float percent);

		std::string get_type() const;
		std::string get_name() const;
		float get_balance() const;
		float get_percent() const;

		

		float accrual();

	};

	std::ostream& operator<<(std::ostream& stream, const Account& c);

	class Users 
	{
	private:

		Account** _list;
		int _size;

	public:

		Users();

		Users(const Users& copy);

		void swap(Users& rhs) noexcept;

		Users& operator=(Users copy);

		~Users();

		int get_size() const;

		const Account& operator[](int index) const;
		Account& operator[](int index);

		void add(const Account& user);

		void insert(Account user, int index);

		void remove(int index);

		void clear();

		const Account& get_item(int index) const;



		int index_of_max_balance() const;

	};

	std::ostream& operator<<(std::ostream& stream, const Users& list);

}

