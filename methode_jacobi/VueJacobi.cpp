#include "VueJacobi.h"

VueJacobi::VueJacobi()
{
	afficheMenu();
}

VueJacobi::~VueJacobi()
{
}

void VueJacobi::afficheMenu() 
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+                                                    +" << std::endl;
	std::cout << "+          Calcul des valeurs et vecteurs            +" << std::endl;
	std::cout << "+             propres d'une matrice                  +" << std::endl;
	std::cout << "+               réelle symétrique                    +" << std::endl;
	std::cout << "+                                                    +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << std::endl;
	system("pause");
}

void VueJacobi::afficheSaisieOrdre()
{
	system("cls");
	std::cout << "Ordre de la matrice : " << std::endl;		
}

void VueJacobi::afficheSaisiePrecision()
{
	std::cout << "La précision desirée : " << std::endl;
}

void VueJacobi::afficheSaisieNbIte()
{
	std::cout << "Le nombre maximum d'itérations : " << std::endl;
}

void VueJacobi::afficheSaisieValues(int& i, int& j)
{
	std::cout << "Le " << j + 1 << " terme de la colonne " << i + 1 << " est : " << std::endl;
}

void VueJacobi::afficheResultats(boost::numeric::ublas::matrix<double> a, boost::numeric::ublas::matrix<double> u, int& it, double& pr)
{
	std::cout << std::endl;
	for (int i = 0; i < a.size1(); i++) 
	{
		std::cout << "Valeur propre : " << i + 1 << " = " << a(i, i) << std::endl;
		std::cout << "Vecteur propre correspondant : ";
		for (int j = 0; j < a.size1();j++) 
		{
			std::cout << u(j, i) << std::endl;
		}
	}
}

void VueJacobi::afficheTime(double& time)
{
	std::cout << std::endl;
	std::cout << "Temps d'éxecution : " << time << " s." << std::endl;
}

void VueJacobi::afficheErreurs(const char* message)
{
	std::cout << message << "\n" << std::endl;
	system("pause");
	HWND myConsole = GetConsoleWindow(); 
	ShowWindow(myConsole, 0);
}


