#pragma once
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

class Jacobi
{
public :
	Jacobi(boost::numeric::ublas::matrix<int> matrice, int er, int im, int n, boost::numeric::ublas::matrix<int> u);
	~Jacobi();
	void Calcul();
	void Init();

private : 
	boost::numeric::ublas::matrix<int> a;
	boost::numeric::ublas::matrix<int> u;
	int er;
	int im;
	int n;
	int nd;
	int st;
	int na; // norme de a(i,j)

};

