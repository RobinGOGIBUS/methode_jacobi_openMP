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
	std::cout << "Appuyez sur une touche pour commencer." << std::endl;
}

void VueJacobi::afficheSaisies()
{

}

void VueJacobi::afficheResultats()
{

}

void VueJacobi::afficheErreurs(std::string message)
{
	std::cout << message << "\n" << std::endl;
	system("pause");
	HWND myConsole = GetConsoleWindow(); 
	ShowWindow(myConsole, 0);
}


