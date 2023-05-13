#pragma once

#include "Account/account.h"

#include <iostream>
#include <conio.h>
#include <cstdio>

using namespace account;

namespace menu
{
	void text_menu();
	int get_key();
	std::shared_ptr<Account> create_account();
}