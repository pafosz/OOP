#pragma once
#include <algorithm>
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <windows.h>

namespace account {

	class Account {
	protected:

		std::string _name;
		float _balance;

	public:
		Account();
		Account(std::string name, float balance);

		std::string get_name() const;
		float get_balance() const;

		virtual void print() const = 0;
		virtual std::shared_ptr<Account> clone() const = 0;

		virtual float accrual() const = 0;
	};

	class Payment : public Account {
	public:
		Payment();
		Payment(std::string name, float balance);

		void print() const override;
		std::shared_ptr<Account> clone() const override;

		float accrual() const override;
	};

	class Deposit : public Account {
		
		float _percent;

	public:
		Deposit();
		Deposit(std::string name, float balance, float percent);
		
		float get_percent() const;

		void print() const override;
		std::shared_ptr<Account> clone() const override;

		float accrual() const override;
	};

	class Credit : public Account {

		float _percent;

	public:
		Credit();
		Credit(std::string name, float balance, float percent);
		
		float get_percent() const;

		void print() const override;
		std::shared_ptr<Account> clone() const override;

		float accrual() const override;
	};

	using AccountPtr = std::shared_ptr<Account>;

	class AccountList
	{
	private:

		std::vector<AccountPtr> _list;

	public:
		AccountList() = default;
		AccountList(const AccountList& list);
		void swap(AccountList& list) noexcept;
		AccountList& operator=(AccountList list);
		const AccountPtr operator[](size_t index) const;
		AccountPtr operator[](size_t index);		
		size_t get_size() const;
		void add(AccountPtr account);
		void insert(AccountPtr account, int index);
		void remove(int index);
		void print() const;
		void clear();
		int index_of_max_balance() const;
	};
}

