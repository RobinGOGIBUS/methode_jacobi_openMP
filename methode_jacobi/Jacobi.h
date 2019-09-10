#pragma once
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "templates.cpp"

class Jacobi
{
public :
	Jacobi(boost::numeric::ublas::matrix<double> matrice, double er, int im, int n, boost::numeric::ublas::matrix<double> u);
	~Jacobi();
	void Calcul();
	void Init();
	void rechercheEltHorsDiag();
	void calculParamsRotation();
	void majU();
	void transformationA();

	// accesseurs
	boost::numeric::ublas::matrix<double> getA();
	boost::numeric::ublas::matrix<double> getU();
	int& getIt();
	double& getPr();

private : 
	boost::numeric::ublas::matrix<double> a;
	boost::numeric::ublas::matrix<double> u;
	double er;
	int im;
	int n;
	double nd;
	double st;
	double na;
	double te;
	int ni;
	int nj;
	double b;
	double c;
	double q;
	double p;
	double s;
	int it;
	double pr;

};

