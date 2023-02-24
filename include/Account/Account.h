#pragma once
#include <string>
namespace account {

	enum class Type {
		payment,
		deposit,
		credit
	};

	class Account {
		
		Type _type;
		std::string _name;
		float _balance;
		float _percent;
	public:
		Account(Type type, std::string name, float balance, float percent);

		float get_balance() const;

		
		void update();

	};


}

