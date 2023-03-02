#pragma once
#include <string>
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

		Type get_type() const;
		std::string get_name() const;
		float get_balance() const;
		float get_percent() const;	
		
		void accrual(Type _type, float _balance, float _percent);

	};


}

