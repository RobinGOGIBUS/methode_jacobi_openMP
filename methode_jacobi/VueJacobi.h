#pragma once
#include "IHM.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

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
	void afficheResultats(boost::numeric::ublas::matrix<double> a, boost::numeric::ublas::matrix<double> u, int& it, double& pr);
	void afficheTime(double& time);
	void afficheErreurs(const char*);


};

