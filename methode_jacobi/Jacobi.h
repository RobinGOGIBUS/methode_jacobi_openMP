#pragma once
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

class Jacobi
{
public :
	Jacobi(matrix<int> matrice);
	~Jacobi();

private : 
	matrix<int> matrice;

};

