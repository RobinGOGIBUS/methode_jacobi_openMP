#include "program.h"

Program::Program() : vuejacobi(new VueJacobi), n(0), er(0), im(0)
{
	
}

Program::~Program()
{
}

void Program::Run()
{
	try {
		boost::numeric::ublas::matrix<int> a = Saisies();
		boost::numeric::ublas::matrix<int> u(n,n);
		std::unique_ptr<Jacobi> jacobi(new Jacobi( a, er, im, n, u));
	}
	catch (std::exception e) {
		vuejacobi->afficheErreurs(e.what());
	}
	
}

boost::numeric::ublas::matrix<int> Program::Saisies()
{
	bool ok = false;
	std::string ordre = "";

	// ordre de la matrice
	std::string regexp = "^(0|[1-9][0-9]*)$";
	std::regex pattern(regexp);
	while (n == 0)
	{
		vuejacobi->afficheSaisieOrdre();
		std::cin >> ordre;
		if (std::regex_match(ordre, pattern))
		{
			if (std::stoi(ordre) > 1)
			{
				n = std::stoi(ordre);
			}
		}

	}

	boost::numeric::ublas::matrix<int> a(n, n);

	// valeurs de la matrice
	std::string value = "";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vuejacobi->afficheSaisieValues(i, j);
			std::cin >> value;
			if (std::regex_match(value, pattern))
			{
				a(j, i) = std::stoi(value);
			}
			else {
				a(j, i) = 0;
			}
		
		}
	}

	// précision désirée
	std::string precision = "";
	while (er == 0) 
	{
		vuejacobi->afficheSaisiePrecision();
		std::cin >> precision;
		if (std::regex_match(precision, pattern))
		{
			if (std::stoi(precision) > 1)
			{
				er = std::stoi(precision);
			}
		}
	}

	// nb max itérations
	std::string NbIte = "";
	while (im == 0)
	{
		vuejacobi->afficheSaisieNbIte();
		std::cin >> NbIte;
		if (std::regex_match(NbIte, pattern))
		{
			if (std::stoi(NbIte) > 1)
			{
				im = std::stoi(NbIte);
			}
		}
	}

	return a;

}
