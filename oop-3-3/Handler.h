#pragma once

#include "Book.h"
#include "Backpack.h"

using namespace std;

class Handler {
private:
	Backpack* bag;
	Book myBooks[6];

public:
	Handler();
	~Handler();
};