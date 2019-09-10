#include "Jacobi.h"

Jacobi::Jacobi(boost::numeric::ublas::matrix<double> matrice, double er, int im, int n, boost::numeric::ublas::matrix<double> u) : a(matrice), er(er), im(im), n(n), u(u), nd(0), st(0), na(0), te(0), ni(0), nj(0), b(0), c(0), q(0), s(0), p(0), it(0), pr(0)
{

}

Jacobi::~Jacobi()
{

}

void Jacobi::Calcul()
{
	Init();
	na = nd + 2 * st; // norme de a(i,j)
	pr = er + 1;
	while (it <= im && pr >= er) 
	{
		// recherche de l'élément hors diagonal le plus grand en valeur absolue
		rechercheEltHorsDiag();

		// calcul des paramètres de la rotation à effectuer
		calculParamsRotation();

		// actualisation de la matrice u 
		majU();

		// transformation de la matrice a
		transformationA();

		// actualisation de nd
		nd = nd + 2 * (a(ni, nj) * a(ni, nj));

		st = a(ni, ni);
		a(ni, ni) = c * c * st + 2 * s * c * a(ni, nj) + s * s * a(nj, nj);
		a(nj, nj) = c * c * a(nj, nj) + s * s * st - 2 * s * c * a(ni, nj);
		a(ni, nj) = 0;
		it++;
		pr = abs(1.0 - (na / nd)); // calcul de la précision
	}

}

void Jacobi::Init()
{
	for (int i = 0; i < n;i++) 
	{
		u(i, i) = 1.0;
		nd = nd + (a(i, i) * a(i, i));
		if (i != n-1) 
		{
			for (int j = i + 1; j < n; j++)
			{
				st = st + (a(i, j) * a(i, j));
				u(i, j) = 0.0;
				u(j, i) = 0.0;
			}
		}	
		
	}
}

void Jacobi::rechercheEltHorsDiag()
{
	st = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			te = abs(a(i, j));
			if (te > st)
			{
				st = te;
				ni = i;
				nj = j;
			}
		}
	}
}

void Jacobi::calculParamsRotation()
{
	b = a(ni, ni) - a(nj, nj);
	if (b == 0)
	{
		c = 1 / sqrt(2);
		s = c * sgn(a(ni, nj));
	}
	else {
		q = abs(b);
		p = 2 * a(ni, nj) * sgn(b);
		st = sqrt(p * p + q * q);
		c = sqrt((1 + q / st) * 0.5);
		s = p / (2 * st * c);
	}
}

void Jacobi::majU()
{
	for (int k = 0; k < n; k++)
	{
		st = u(k,ni);
		u(k, ni) = c * st + s * u(k, nj);
		u(k, nj) = c * u(k, nj) - s * st;
	}
}

void Jacobi::transformationA()
{
	if (ni != 0) 
	{
		for (int k = 0; k <= (ni - 1);k++) 
		{
			st = a(k,ni);
			a(k, ni) = c * st + s * a(k, nj);
			a(k, nj) = c * a(k, nj) - s * st;
		}
	}
	if (nj != (ni + 1)) 
	{
		for (int k = ni + 1;k <= (nj - 1);k++)
		{
			st = a(ni, k);
			a(ni, k) = c * st + s * a(k, nj);
			a(k, nj) = c * a(k, nj) - s * st;
		}
	}
	if (nj != n) 
	{
		for (int k = (nj + 1);k < n;k++) 
		{
			st = a(ni,k);
			a(ni, k) = c * st + s * a(nj, k);
			a(nj, k) = c * a(nj, k) - s * st;
		}
	}
}

boost::numeric::ublas::matrix<double> Jacobi::getA()
{
	return a;
}

boost::numeric::ublas::matrix<double> Jacobi::getU()
{
	return u;
}

int& Jacobi::getIt()
{
	return it;
}

double& Jacobi::getPr()
{
	return pr;
}


