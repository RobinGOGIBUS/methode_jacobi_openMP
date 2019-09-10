#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "program.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	std::unique_ptr<Program> p(new Program);
	p->Run();
	return 0;
}

