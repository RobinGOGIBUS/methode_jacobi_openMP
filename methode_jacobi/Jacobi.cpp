#include "Jacobi.h"


Jacobi::Jacobi(boost::numeric::ublas::matrix<int> matrice, int er, int im, int n, boost::numeric::ublas::matrix<int> u) : a(matrice), er(er), im(im), n(n), u(u), nd(0), st(0), na(0)
{

}

Jacobi::~Jacobi()
{

}

void Jacobi::Calcul()
{
	Init();
}

void Jacobi::Init()
{
	for (int i = 0; i < n;i++) 
	{
		u(i, i) = 0;
		nd = nd + pow(a(i, i), 2);
		if (i < n-1) 
		{
			for (int j = i + 1; j < n; j++)
			{
				st = st + pow(a(i, j), 2);
				u(i, j) = 0;
				u(j, i) = 0;
			}
		}	
		
	}
}
