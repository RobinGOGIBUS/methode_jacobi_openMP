#pragma once
#include "IHM.h"
#include <string>
#include <iostream>
#include <Windows.h>

class VueJacobi : public IHM
{
public: 
	VueJacobi();
	~VueJacobi();

	void afficheMenu();
	void afficheSaisieOrdre();
	void afficheSaisiePrecision();
	void afficheSaisieNbIte();
	void afficheSaisieValues(int& i, int& j);
	void afficheResultats();
	void afficheErreurs(const char*);


};

