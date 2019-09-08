#pragma once
#include <string>
class IHM
{
public:
	virtual ~IHM();
	virtual void afficheMenu() = 0;
	virtual void afficheResultats() = 0;
	virtual void afficheErreurs(const char*) = 0;
};

