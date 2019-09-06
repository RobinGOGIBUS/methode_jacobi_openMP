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
	void afficheSaisies();
	void afficheResultats();
	void afficheErreurs(std::string message);


};

