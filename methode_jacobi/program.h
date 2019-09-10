#pragma once
#include "VueJacobi.h"
#include "Jacobi.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <memory>
#include <regex>
#include <omp.h>

class Program
{
public:
	Program();
	~Program();
	void Run();
	boost::numeric::ublas::matrix<double> Saisies();
private:
	std::unique_ptr<VueJacobi> vuejacobi;
	int n;
	double er;
	int im;



};

