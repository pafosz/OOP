#pragma once
#include <string>
#include <stdexcept>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <memory>
#include <vector>

namespace account {	

	class Account {
	protected:

		std::string _name;
		float _balance;
		float _percent;
		

	public:
		Account();
		Account(std::string name, float balance);
		Account(std::string name, float balance, float percent);
		
		std::string get_name() const;
		float get_balance() const;
		float get_percent() const;


		virtual void print(std::ostream& stream) const = 0;

		virtual std::shared_ptr<Account> clone() const = 0;

		virtual float accrual() const = 0;
	};

	class Payment : public Account {
	public:

		Payment();
		Payment(std::string name, float balance);

		void print(std::ostream& stream) const override;
		std::shared_ptr<Account> clone() const override;

		
	};

	class Deposit : public Account {
	
	public:

		Deposit();
		Deposit(std::string name, float balance, float percent);

		void print(std::ostream& stream) const override;
		std::shared_ptr<Account> clone() const override;

		float accrual() const override;
	};

	class Credit : public Account {

	public:

		Credit();
		Credit(std::string name, float balance, float percent);

		void print(std::ostream& stream) const override;
		std::shared_ptr<Account> clone() const override;

		float accrual() const override;
	};

	

	
	
	class AccountList 
	{
	private:

		Account** _list;
		int _size;

	public:

		AccountList();

		AccountList(const AccountList& copy);

		void swap(AccountList& rhs) noexcept;

		AccountList& operator=(AccountList copy);

		~AccountList();

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

	std::ostream& operator<<(std::ostream& stream, const AccountList& list);

}

