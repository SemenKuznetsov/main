#include <iostream>
#include<fstream>
#include "functions.h"
#include<string>



int main()
{
	setlocale(LC_ALL, "rus");
	std::string coef; //база с открытием файла и выяснение: сколько в файле записано мн-в, путем подсчета кол-ва строк
	std::ifstream input_file("1.txt");

	//ввод н мн-в
	int count_of_pol = 0;
	while (!input_file.eof())
	{
		std::getline(input_file, coef);
		if (coef != "")
			count_of_pol++;
	}
	count_of_pol++;
	Polinom *pol = new Polinom[count_of_pol-1];
	//Polinom *pol = new Polinom[count_of_pol];
	input_file.seekg(0); // переход в начало файла


	for (int i = 0; i < count_of_pol; ++i)
	{
		pol[i] = input(input_file);
	}
	//std::cout << pol[2].coef[2];
	// до сюда

	std::cout << "Добрый день. :) Вы запустили программу для работы с многочленами.\n";
	std::cout << "Для начала давайте разберемся: выполнение какой операции Вас интересует?\nИ так, вот список возможных функций:\n";
	std::cout << "\n";
	std::cout << "(1)\tввод мн-на в память\n";
	std::cout << "(2)\tвывод мн-на в файл\n";
	std::cout << "(3)\tвычисление производной \n";
	std::cout << "(4)\tвычисление значения в точке\n";
	std::cout << "(5)\tвычисление значения производной в точке\n";
	std::cout << "(6)\tсложение 2-х многочленов\n";
	std::cout << "(7)\tвычитание 2-х многочленов\n";
	std::cout << "(8)\tумножение 2-х многочленов\n";
	std::cout << "(9)\tделение одного многочлена на другой\n";
	std::cout << "\n";
	std::cout << "чтобы выбрать необходимую операцию, введите соответствующий этой операции номер, который указан в скобках\n";
	int NUMBER_OF_OPERATION;
	std::cin >> NUMBER_OF_OPERATION;
	//if (NUMBER_OF_OPERATION != 1)
	//{
	//	std::cout << "перед выбором операции, убедитесь, что Вы ввели все необходимые мн-ны в память, при помощи операции (1),\n если Вы уже это сделали, пожалуйста, продублируйте номер своей операции.\n";
	//	std::cin >> NUMBER_OF_OPERATION;
	//}
	//else
	//{
	//	//while (!input_file.eof())
	//	//{
	//	//	std::getline(input_file, coef);
	//	//	if (coef != "")
	//	//		count_of_pol++;
	//	//}
	//	//count_of_pol++;
	//	//Polinom* pol = new Polinom[count_of_pol];
	//	//input_file.seekg(0); // переход в начало файла


	//	//for (int i = 0; i < count_of_pol; ++i)
	//	//{
	//	//	pol[i] = input(input_file);
	//	//}
	//}
	if (NUMBER_OF_OPERATION == 1)
	{
		std::cout << "!рекомендую прочитать всю информацию, изложенную ниже!\nВ противном случае есть возможность получения невенрых результатов.";
		std::cout << "для общего удобства операция ввода мн-в в память производится автоматически.\nВам остается лишь ввести все необходимые коэффициенты в файл с именем '1.txt', а после этого перезапустить программу вновь.\n";
		std::cout << "по-поводу того, как вводить мн-ны в файл: ";
		std::cout << "(1)\tмн-н вводится путем ввода коэффициентов\n";
		std::cout << "(2)\tкоэффициенты вводятся от старшего к младшему\n";
		std::cout << "(3)\tввод в файл количества мн-в и их старших степеней не нужен, программа сама подсчитает и степень и количество\n";
		std::cout << "(4)\tво всех дальнейших операциях при необходимости ввода номера мн-на следует помнить, что НУМЕРАЦИЯ НАЧИНАЕТСЯ С 0\n";
		std::cout << "(~)\tдля тех, кто недавно закончил js) res->2\n";
	}
	else if (NUMBER_OF_OPERATION == 2)
	{
		std::cout << "(~)\tищи ответ у улучшенного салата ->3\n";
		int num_of_pol;
		std::cout << "Вы выбрали операцию возврата одного из записанных в памяти мн-в в файл с именем 'out.txt'\n перед выполнением операции укажите номер мн-на, который необходимо вывести(нумерация идет с 0):\n";
		std::cin >> num_of_pol;
		if (num_of_pol >= count_of_pol-1)
		{
			std::cout << "в памяти не обнаружено мн-на с таким номером. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			output(output_file, pol[num_of_pol]);
		}
	}
	else if (NUMBER_OF_OPERATION == 3)
	{
		std::cout << "(~)\tищи ответ у улучшенного салата ->3\n";
		int num_of_pol;
		std::cout << "Вы выбрали операцию вычисление производной одного из записанных в памяти мн-в.\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номер мн-на, у которого необходимо посчитать производную(нумерация идет с 0):\n";
		std::cin >> num_of_pol;
		if (num_of_pol >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-на с таким номером. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			proizv_of_polinom(output_file, pol[num_of_pol]);
		}
	}
	else if (NUMBER_OF_OPERATION == 4)
	{
		int num_of_pol;
		int point;
		std::cout << "Вы выбрали операцию вычисление значения одного из записанных в памяти мн-в в точке.\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номер мн-на, у которого необходимо посчитать значение в точке и саму точку(нумерация идет с 0):\n";
		std::cin >> num_of_pol;
		std::cin >> point;
		if (num_of_pol >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-на с таким номером. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			ans_in_point(output_file, pol[num_of_pol], point);
		}
	}
	else if (NUMBER_OF_OPERATION == 5)
	{
		int num_of_pol;
		int point;
		std::cout << "Вы выбрали операцию вычисление значения производной одного из записанных в памяти мн-в в точке.\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номер мн-на, у которого необходимо посчитать значение производной в точке и саму точку(нумерация идет с 0):\n";
		std::cin >> num_of_pol;
		std::cin >> point;
		if (num_of_pol >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-на с таким номером. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			proizv_ans_in_point(output_file, pol[num_of_pol], point);
		}
	}
	else if (NUMBER_OF_OPERATION == 6)
	{
		int num_of_pol_1;
		int num_of_pol_2;
		std::cout << "Вы выбрали операцию суммы двух мн-в.\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номера мн-нов, сумму которых необходимо посчитать(нумерация идет с 0):\n";
		std::cin >> num_of_pol_1;
		std::cin >> num_of_pol_2;
		if (num_of_pol_1 || num_of_pol_2 >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-нов с такими номерами. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			sum_of_pol(output_file, pol[num_of_pol_1], pol[num_of_pol_2]);
		}
	}
	else if (NUMBER_OF_OPERATION == 7)
	{
		int num_of_pol_1;
		int num_of_pol_2;
		std::cout << "Вы выбрали операцию разности двух мн-в(мн-н, номер которго будет введем вторым, будет вычитаться из мн-на, номер которго был введем первым).\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номера мн-нов, разность которых необходимо посчитать(нумерация идет с 0):\n";
		std::cin >> num_of_pol_1;
		std::cin >> num_of_pol_2;
		if (num_of_pol_1 || num_of_pol_2 >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-нов с такими номерами. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			razn_of_pol(output_file, pol[num_of_pol_1], pol[num_of_pol_2]);
		}
	}
	else if (NUMBER_OF_OPERATION == 8)
	{
		int num_of_pol_1;
		int num_of_pol_2;
		std::cout << "Вы выбрали операцию произведения двух мн-в.\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номера мн-нов, произведение которых необходимо посчитать(нумерация идет с 0):\n";
		std::cin >> num_of_pol_1;
		std::cin >> num_of_pol_2;
		if (num_of_pol_1 || num_of_pol_2 >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-нов с такими номерами. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			std::ofstream output_file("out.txt");
			proizved_of_pol(output_file, pol[num_of_pol_1], pol[num_of_pol_2]);
		}
	}
	else if (NUMBER_OF_OPERATION == 9)
	{
		int num_of_pol_1;
		int num_of_pol_2;
		std::cout << "Вы выбрали операцию деления одного мн-на на другой(мн-н, номер которго будет введем первым, будет делиться из мн-на, номер которго был введем вторым).\nРезультат будет записан в файл с именем 'out.txt'\nперед выполнением операции укажите номера мн-нов, частное которых необходимо посчитать(нумерация идет с 0):\n";
		std::cin >> num_of_pol_1;
		std::cin >> num_of_pol_2;
		if (num_of_pol_1 >= count_of_pol - 1 || num_of_pol_2 >= count_of_pol - 1)
		{
			std::cout << "в памяти не обнаружено мн-нов с такими номерами. Рекомендую Вам ещё раз проверить первоначальный файл\n";
		}
		else
		{
			//std::ofstream output_file("out2.txt");
			//chast_of_pol(output_file, pol[num_of_pol_1], pol[num_of_pol_2]);

			Polinom& d1 = pol[num_of_pol_1];
			Polinom& d2 = pol[num_of_pol_2];
			std::cout << "(";
			for (int i = 0; i < d2.deGree; ++i)
			{
				std::cout << d2.coef[i] << " ";
			}
			std::cout << ")";
			std::cout << " * (";
			double ch = 0;
			for (int i = 0; i < d2.deGree; ++i)
			{
				ch = d1.coef[i] / d2.coef[0];
				for (int j = i; j < d2.deGree + i; ++j)
					d1.coef[j] = d1.coef[j] - d2.coef[j - i] * ch;
				std::cout << ch << " " << " ";
			}
			std::cout << ")";

			//ost
			std::cout << " + (";
			for (int i = 0; i < d1.deGree; ++i)
			{
				if (d1.coef[i] != 0)
				{
					std::cout << d1.coef[i] << " ";
				}
			}
			std::cout << ")";
			std::cout << "\n";
		}
	}
}

	////вывод одного мн-на из массива введенных мн-в

			/*std::string path = "out.txt";
			std::ofstream output_file;						если надо сохр. предыдущие записи в файле
			output_file.open(path,std::ofstream::app);*/

	/*std::ofstream output_file("out.txt");
	output(output_file, pol[0]);*/

	////конец вывода




	//вычисление производной

	/*std::ofstream output_file("out.txt");
	proizv_of_polinom(output_file, pol[0]);*/

	//конец произв


	// вычисление значения в точке

	/*std::ofstream output_file("out.txt");
	ans_in_point(output_file, pol[0],9284);*/

	//знач.

	// вычисление значения в точке

	/*std::ofstream output_file("out.txt");
	proizv_ans_in_point(output_file, pol[0], 9284);*/

	//знач.


	//сумма 2-х многочленов

	/*std::ofstream output_file("out.txt");
	sum_of_pol(output_file, pol[0], pol[1]);*/

	//конец сумм.


	//разн 2-х многочленов

	/*std::ofstream output_file("out.txt");
	razn_of_pol(output_file, pol[0], pol[1]);*/

	//конец разн.


	//произвед 2-х многочленов

	/*std::ofstream output_file("out.txt");
	proizved_of_pol(output_file, pol[0], pol[1]);*/

	//конец произвед.



	//деление мн-в

	/*std::ofstream output_file("out.txt");
	chast_of_pol(output_file, pol[0], pol[1]);*/

	//конец дел.

