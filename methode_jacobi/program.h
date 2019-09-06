#pragma once
#include "VueJacobi.h"
#include <iostream>
#include <memory>

class Program
{
public:
	Program();
	~Program();
	void Run();

private:
	std::unique_ptr<IHM> vuejacobi;


};

