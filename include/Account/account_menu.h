#pragma once

#include "Account/account.h"

#include <iostream>
#include <conio.h>
#include <cstdio>

namespace menu
{
	void text_menu();
	int get_key();
	account::Account create_account();
}