#pragma once
#include <string>
#include <stdexcept>
#include <cstdio>
namespace account {

	enum class Type {
		payment = 1,
		deposit,
		credit
	};

	class Account {

		Type _type;
		std::string _name;
		float _balance;
		float _percent;

	public:

		Account();
		Account(Type type, std::string name, float balance, float percent);

		std::string get_type() const;
		std::string get_name() const;
		float get_balance() const;
		float get_percent() const;

		void accrual();

	};

	class Users {
	public:

		static const int CAPACITY = 10;

	private:

		Account _list[CAPACITY];
		int _size;

	public:

		Users(int size);

		int get_size() const;

		Account operator[](int index) const;
		Account& operator[](int index);

		void insert(Account User, int index);

		void remove(int index);

		Account get_item(int index) const;

		int index_of_max_balance(const Users& users) const;

	};


}

