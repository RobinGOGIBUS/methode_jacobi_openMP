// methode_jacobi.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <string>
#include <iostream>
#include "program.h"
#include <Windows.h>
#include <cstdio>
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	std::unique_ptr<Program> p(new Program);
	p->Run();
	return 0;
}

