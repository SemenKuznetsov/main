#include<fstream>
#include<string>
#include<iostream>
#include"functions.h"



Polinom input(std::ifstream &input_file)
{
	Polinom in_pol;
	std::string coefic;
	std::getline(input_file, coefic);
	in_pol.deGree = 0;
	for (int i = 0; i < coefic.length(); ++i) // поиск степени
	{
		if (coefic[i] == ' ')
			in_pol.deGree++;
	}
	in_pol.deGree++;
	in_pol.coef = new int[in_pol.deGree];



	int i_cof = 0;
	int i_cof_number = 0;
	while(i_cof < coefic.length()) //ввод коэффициентов
	{
		std::string coef_pri_st;
		while (coefic[i_cof] != ' ' && i_cof < coefic.length())
		{
			/*std::cout << coefic[i_cof];*/
			coef_pri_st +=  coefic[i_cof];
			i_cof++;
		}
		in_pol.coef[i_cof_number] = stoi(coef_pri_st);
		//std::cout << coef_pri_st << "\n";
		i_cof_number++;
		i_cof++;
	}
	return in_pol;
}

void output(std::ofstream& out_file, Polinom& d1)//Коэффициент при наибольшей степени - первый
{
	out_file << d1.deGree - 1 << std::endl;
	for (int i = 0; i < d1.deGree; ++i) { //вывод полноценного мн-на
		d1.deGree - i - 1 ==0 ? out_file << d1.coef[i] << " " :
		out_file << d1.coef[i]<<"*X^"<< d1.deGree-i-1 << " +" << " ";
		//out_file << d1.coef[i]<< " ";
	}
	out_file << std::endl;
	for (int i = 0; i < d1.deGree; ++i) {//вывод коэфю мн-на
		//out_file << d1.coef[i] << "X^" << d1.deGree - i << " ";
		out_file << d1.coef[i] << " ";
	}
	out_file << std::endl;
}

void proizv_of_polinom(std::ofstream& out_file, Polinom& d1)//Коэффициент при наибольшей степени - первый
{
	out_file << d1.deGree-2 << std::endl;
	for (int i = 0; i < d1.deGree-1; ++i) { //вывод полноценного мн-на
		d1.deGree - i - 2 == 0 ? out_file << d1.coef[i] << " " :
			out_file << d1.coef[i] * (d1.deGree - i - 1) << "*X^" << d1.deGree - i - 2 << " +" << " ";
		//out_file << d1.coef[i]<< " ";
	}
	out_file << std::endl;
	for (int i = 0; i < d1.deGree-1; ++i) {//вывод коэфю мн-на
		//out_file << d1.coef[i] << "X^" << d1.deGree - i << " ";
		out_file << d1.coef[i] * (d1.deGree - i - 1) << " ";
	}
	out_file << std::endl;
}

void ans_in_point(std::ofstream& out_file, Polinom& d1,int point)
{
	int ans = 0;
	for (int i = 0; i < d1.deGree; ++i) {
		ans += d1.coef[i] * std::pow(point, (d1.deGree - 1 - i));
		//out_file << d1.coef[i]<< " ";
	}
	out_file << ans << std::endl;
}

void proizv_ans_in_point(std::ofstream& out_file, Polinom& d1, int point)
{
	int ans = 0;
	for (int i = 0; i < d1.deGree; ++i) {
		ans += d1.coef[i] * (d1.deGree - i - 1) * std::pow(point, (d1.deGree - 2 - i));
		//out_file << d1.coef[i]<< " ";
	}
	out_file << ans << std::endl;
}

void sum_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2)
{
	if (d1.deGree > d2.deGree)
	{
		for (int i = d1.deGree-1; i > d2.deGree-1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] << " ";
		}
		for (int i = d2.deGree-1; i > -1; --i)
		{
			out_file << d2.coef[d2.deGree - 1 - i] + d1.coef[d1.deGree - 1 - i] << " ";
		}

		out_file << std::endl;

		for (int i = d1.deGree - 1; i > d2.deGree - 1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] << "*X^" << i << " ";
		}
		for (int i = d2.deGree - 1; i > -1; --i)
		{
			i == 0 ? out_file << d2.coef[d2.deGree - 1 - i] + d1.coef[d1.deGree - 1 - i] << " " :
				out_file << d2.coef[d2.deGree - 1 - i] + d1.coef[d1.deGree - 1 - i] << "*X^" << i << " +";
		}
	}
	else
	{
		for (int i = d2.deGree-1; i > d1.deGree-1; --i)
		{
			out_file << d2.coef[d2.deGree - 1-i] << " ";
		}
		for (int i = d1.deGree-1; i > -1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] + d2.coef[d2.deGree - 1 - i] << " ";
		}

		out_file << std::endl;

		for (int i = d2.deGree - 1; i > d1.deGree - 1; --i)
		{
			out_file << d2.coef[d2.deGree - 1 - i] << "*X^" << i << " ";
		}
		for (int i = d1.deGree - 1; i > -1; --i)
		{
			i == 0 ? out_file << d1.coef[d1.deGree - 1 - i] + d2.coef[d2.deGree - 1 - i] << " " :
				out_file << d1.coef[d1.deGree - 1 - i] + d2.coef[d2.deGree - 1 - i] << "*X^" << i << " +";
		}
	}
}

void razn_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2) // где d1 - уменьшаемое , а d2 - вычитаемое
{
	if (d1.deGree > d2.deGree)
	{
 		for (int i = d1.deGree - 1; i > d2.deGree - 1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] << " ";
		}
		for (int i = d2.deGree - 1; i > -1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] - d2.coef[d2.deGree - 1 - i] << " ";
		}

		out_file << std::endl;

		for (int i = d1.deGree - 1; i > d2.deGree - 1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] << "*X^" << i << " ";
		}
		for (int i = d2.deGree - 1; i > -1; --i)
		{
			i == 0 ? out_file << d1.coef[d1.deGree - 1 - i] - d2.coef[d2.deGree - 1 - i] << " " :
				out_file << d1.coef[d1.deGree - 1 - i] - d2.coef[d2.deGree - 1 - i] << "*X^" << i << " +";
		}
	}
	else
	{
		for (int i = d2.deGree - 1; i > d1.deGree - 1; --i)
		{
			out_file << -d2.coef[d2.deGree - 1 - i] << " ";
		}
		for (int i = d1.deGree - 1; i > -1; --i)
		{
			out_file << d1.coef[d1.deGree - 1 - i] - d2.coef[d2.deGree - 1 - i] << " ";
		}

		out_file << std::endl;

		for (int i = d2.deGree - 1; i > d1.deGree - 1; --i)
		{
			out_file << -d2.coef[d2.deGree - 1 - i] << "*X^" << i << " ";
		}
		for (int i = d1.deGree - 1; i > -1; --i)
		{
			i == 0 ? out_file << d1.coef[d1.deGree - 1 - i] - d2.coef[d2.deGree - 1 - i] << " " :
				out_file << d1.coef[d1.deGree - 1 - i] - d2.coef[d2.deGree - 1 - i] << "*X^" << i << "";
		}
	}
}

void proizved_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2)
{
	int* ans = new int(d1.deGree + d2.deGree -2);
	for (int i = 0; i < d1.deGree + d2.deGree - 1; ++i)
	{
		ans[i] = 0;
	}

	for (int i = 0; i < d1.deGree; ++i)
	{
		for (int j = 0; j < d2.deGree; ++j)
		{
			ans[i+j] += d1.coef[i]*d2.coef[j];
		}
	}
	for (int i = 0; i < d1.deGree + d2.deGree-1; ++i)
	{
		out_file << ans[i] << " ";
	}
	out_file << std::endl;
	for (int i = 0; i < d1.deGree + d2.deGree - 1; ++i)
	{
		d1.deGree + d2.deGree - 2 - i == 0 ? out_file << ans[i] << " " :
			out_file << ans[i] << "*X^" << d1.deGree + d2.deGree - 2 - i << " +";

		//out_file << ans[i] << "*X^" << d1.deGree + d2.deGree - 2 - i << " +";
	}
}

void chast_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2)
{	
	int degree_of_chast = d1.deGree - d2.deGree + 1;
	//int* ans = new int(degree_of_chast);
	//int* ans_ost = new int(degree_of_chast);
	if (d1.deGree < d2.deGree)
	{

		//out_file << degree_of_chast <<"\n";
		out_file << "0 * (";
		for (int i = 0; i < d2.deGree; ++i)
		{
			out_file << d2.coef[i] << " ";
		}
		out_file << ")";
		out_file << " + (";
		for (int i = 0; i < d1.deGree; ++i)
		{
			out_file << d1.coef[i] << " ";
		}
		out_file << ")";
		out_file << "\n";


		out_file << "0 * (";
		for (int i = 0; i < d2.deGree; ++i)
		{
			d2.deGree - i - 1 == 0 ? out_file << d2.coef[i] << " " :
				out_file << d2.coef[i] << "*X^" << d2.deGree - i-1 << " + ";

			//out_file << d2.coef[i] << " ";
		}
		out_file << ")";
		out_file << " + (";
		for (int i = 0; i < d1.deGree; ++i)
		{
			d1.deGree - i - 1 == 0 ? out_file << d1.coef[i] << " " :
				out_file << d1.coef[i] << "*X^" << d1.deGree - i -1 << " + ";

			//out_file << d1.coef[i] << " ";
		}
		out_file << ")";
	}
	else
	{

		out_file << degree_of_chast <<"\n";
		out_file << "(";

		for (int i = 0; i < d2.deGree; ++i)
		{
			out_file << d2.coef[i] << " ";
		}
		out_file << " * (";
		double ch = 0;
		for (int i = 0; i < d2.deGree; ++i)
		{
			ch = d1.coef[i] / d2.coef[0];
			for (int j = i; j < d2.deGree + i; ++j)
				d1.coef[j] = d1.coef[j] - d2.coef[j-i]*ch;
			out_file << ch << " ";
		}
		out_file << ")";
		//ost
		out_file << " + (";
		for (int i = 0; i < d1.deGree; ++i)
		{
			if(d1.coef[i] != 0)
			{
				out_file << d1.coef[i] << " ";
			}
		}
		out_file << ")";
		out_file << "\n";
	}


	//for (int i = 0; i < d1.deGree + d2.deGree - 1; ++i)
	//{
	//	ans[i] = 0;
	//}

	//for (int i = 0; i < d1.deGree; ++i)
	//{
	//	for (int j = 0; j < d2.deGree; ++j)
	//	{
	//		ans[i + j] += d1.coef[i] * d2.coef[j];
	//	}
	//}
	//for (int i = 0; i < d1.deGree + d2.deGree - 1; ++i)
	//{
	//	out_file << ans[i] << " ";
	//}
	//out_file << std::endl;
	//for (int i = 0; i < d1.deGree + d2.deGree - 1; ++i)
	//{
	//	d1.deGree + d2.deGree - 2 - i == 0 ? out_file << ans[i] << " " :
	//		out_file << ans[i] << "*X^" << d1.deGree + d2.deGree - 2 - i << " +";

	//	//out_file << ans[i] << "*X^" << d1.deGree + d2.deGree - 2 - i << " +";
	//}
}

//20x+2
