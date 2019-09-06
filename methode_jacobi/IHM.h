#pragma once
#include <string>
class IHM
{
public:
	virtual ~IHM();
	virtual void afficheMenu() = 0;
	virtual void afficheSaisies() = 0;
	virtual void afficheResultats() = 0;
	virtual void afficheErreurs(std::string message) = 0;
};

