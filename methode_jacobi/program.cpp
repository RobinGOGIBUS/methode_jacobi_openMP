#include "program.h"
#include "omp.h"

Program::Program() : vuejacobi(new VueJacobi), n(0), er(0), im(0)
{
	
}

Program::~Program()
{
}

void Program::Run()
{
	try {
		boost::numeric::ublas::matrix<double> a = Saisies();
		double start = omp_get_wtime();
		boost::numeric::ublas::matrix<double> u(n,n);
		std::unique_ptr<Jacobi> jacobi(new Jacobi( a, er, im, n, u));
		jacobi->Calcul();
		vuejacobi->afficheResultats(jacobi->getA(), jacobi->getU(), jacobi->getIt(), jacobi->getPr());
		double end = omp_get_wtime();
		double time = end - start;
		vuejacobi->afficheTime(time);
	}
	catch (std::exception e) {
		vuejacobi->afficheErreurs(e.what());
	}
	
}

boost::numeric::ublas::matrix<double> Program::Saisies()
{
	bool ok = false;
	std::string ordre = "";

	// ordre de la matrice
	std::string regexp = "^(0|[1-9][0-9]*)$";
	std::string regexp2 = "(^([+-]?(?:[[:d:]]+\.?|[[:d:]]*\.[[:d:]]+))(?:[Ee][+-]?[[:d:]]+)?$)";
	std::regex pattern(regexp);
	std::regex pattern2(regexp2);
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

	boost::numeric::ublas::matrix<double> a(n, n);

	// valeurs de la matrice
	std::string value = "";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			vuejacobi->afficheSaisieValues(i, j);
			std::cin >> value;
			if (std::regex_match(value, pattern2))
			{
				a(j, i) = std::stod(value);
			}
			else {
				a(j, i) = 0.0;
			}
		
		}
	}

	// précision désirée
	std::string precision = "";
	while (er == 0) 
	{
		vuejacobi->afficheSaisiePrecision();
		std::cin >> precision;
		if (std::regex_match(precision, pattern2))
		{
			if (std::stod(precision) > 0.0)
			{
				er = std::stod(precision);
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
