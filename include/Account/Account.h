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
		double _balance;
	
	public:
		Account();
		Account(const std::string& name, double balance);
		Account(const Account&) = default;
		Account& operator=(const Account&) = default;
		std::string get_name() const;
		double get_balance() const;

		virtual void print() const = 0;
		virtual std::shared_ptr<Account> clone() const = 0;

		virtual double accrual() = 0;
		
	};
		
	class Payment : public Account {
	public:
		Payment();
		Payment(const std::string& name, double balance);

		void print() const override;
		std::shared_ptr<Account> clone() const override;

		double accrual() override;
	};

	class Deposit : public Account {

		double _percent;

	public:
		Deposit();
		Deposit(const std::string& name, double balance, double percent);

		double get_percent() const;

		void print() const override;
		std::shared_ptr<Account> clone() const override;

		double accrual() override;
	};

	class Credit : public Account {

		double _percent;

	public:
		Credit();
		Credit(const std::string& name, double balance, double percent);

		double get_percent() const;

		void print() const override;
		std::shared_ptr<Account> clone() const override;

		double accrual() override;
	};

	using AccountPtr = std::shared_ptr<Account>;

	class AccountList
	{
	private:
		std::vector<AccountPtr> _list;
	public:

		AccountList() = default;
		AccountList(const AccountList& list);
		AccountList& operator=(AccountList list);

		void swap(AccountList& list) noexcept;
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

