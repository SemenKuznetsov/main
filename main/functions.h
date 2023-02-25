#pragma once
//#include<fstream>
//#include<string>

struct Polinom
{
	//от старшего к младшего
	int* coef;
	int deGree;
};

Polinom input(std::ifstream & input_file);

void output(std::ofstream& FileStream, Polinom& d1);

void proizv_of_polinom(std::ofstream& out_file, Polinom& d1);

void ans_in_point(std::ofstream& out_file, Polinom& d1, int point);

void proizv_ans_in_point(std::ofstream& out_file, Polinom& d1, int point);

void sum_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2);

void razn_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2);

void proizved_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2);

void chast_of_pol(std::ofstream& out_file, Polinom& d1, Polinom& d2);