#include "Helper_Function.h"
#include "StdAfx.h"

/*
std::vector<double> & Get_Average(std::vector<double> input, int choice)
{
	std::vector<double> *average = new std::vector<double>;
	switch(choice)
	{
	case 3:
		{
			std::vector<double>::iterator iter1, iter2, iter3;
			for(iter1 = input.begin(); iter1 != input.end() - 2; iter1++)
				for(iter2 = iter1 + 1; iter2 != input.end() - 1; iter2++)
					for(iter3 = iter2 + 1; iter3 != input.end(); iter3++)
						average->push_back((*iter1 + *iter2 + *iter3) / 3);
		}
	case 4:
		{
			std::vector<double>::iterator iter1, iter2, iter3, iter4;
			for(iter1 = input.begin(); iter1 < input.end() - 3; iter1++)
				for(iter2 = iter1 + 1; iter2 < input.end() - 2; iter2++)
					for(iter3 = iter2 + 1; iter3 < input.end() - 1; iter3++)
						for(iter4 = iter3 + 1; iter4 < input.end(); iter4++)
							average->push_back((*iter1 + *iter2 + *iter3 + *iter4) / 4);
		}
	case 5:
		{
			std::vector<double>::iterator iter1, iter2, iter3, iter4, iter5;
			for(iter1 = input.begin(); iter1 < input.end() - 4; iter1++)
				for(iter2 = iter1 + 1; iter2 < input.end() - 3; iter2++)
					for(iter3 = iter2 + 1; iter3 < input.end() - 2; iter3++)
						for(iter4 = iter3 + 1; iter4 < input.end() - 1; iter4++)
							for(iter5 = iter4 + 1; iter5 < input.end(); iter5++)
								average->push_back((*iter1 + *iter2 + *iter3 + *iter4 + *iter5) / 5);
		}
	case 6:
		{
			std::vector<double>::iterator iter1, iter2, iter3, iter4, iter5, iter6;
			for(iter1 = input.begin(); iter1 < input.end() - 4; iter1++)
				for(iter2 = iter1 + 1; iter2 < input.end() - 3; iter2++)
					for(iter3 = iter2 + 1; iter3 < input.end() - 2; iter3++)
						for(iter4 = iter3 + 1; iter4 < input.end() - 1; iter4++)
							for(iter5 = iter4 + 1; iter5 < input.end() - 1; iter5++)
								for(iter6 = iter5 + 1; iter6 < input.end(); iter6++)
									average->push_back((*iter1 + *iter2 + *iter3 + *iter4 + *iter5+ *iter6) / 6);
		}
	case 7:
		{
			std::vector<double>::iterator iter1, iter2, iter3, iter4, iter5, iter6, iter7;
			for(iter1 = input.begin(); iter1 < input.end() - 4; iter1++)
				for(iter2 = iter1 + 1; iter2 < input.end() - 3; iter2++)
					for(iter3 = iter2 + 1; iter3 < input.end() - 2; iter3++)
						for(iter4 = iter3 + 1; iter4 < input.end() - 1; iter4++)
							for(iter5 = iter4 + 1; iter5 < input.end() - 1; iter5++)
								for(iter6 = iter5 + 1; iter6 < input.end() - 1; iter6++)
									for(iter7 = iter6 + 1; iter7 < input.end(); iter7++)
										average->push_back((*iter1 + *iter2 + *iter3 + *iter4 + *iter5+ *iter6 + *iter7) / 7);
		}
	case 8:
		{
		}
	default:
		{
		}
	}
	return *average;
}
*/

int cnm(int n, int m)//n>=m>=0
{
	int i, a;
	if (2 * m > n)
		m = n - m;//be faster
	for(i = 1, a = 1; i <= m; i++, n--)
		a = a * n / i;
	return a;
}

int round(double a)
{
	return int(a + 0.5);
}

double *Get_Average(double *input, int item, int choice)
{
	int output_num = cnm(item, choice);
	double *result = new(double[output_num]);

	switch(choice)
	{
	case 3:
		{
			int i1, i2, i3, i = 0;
			for( i1 = 0; i1 < item - 2; i1++)
				for( i2 = i1 + 1; i2 < item - 1; i2++)
					for( i3 = i2 + 1; i3 < item; i3++)
						result[i++] = (input[i1] + input[i2] + input[i3]) / choice;
		}
	case 4:
		{
			int i1, i2, i3, i4, i = 0;
			for( i1 = 0; i1 < item - 3; i1++)
				for( i2 = i1 + 1; i2 < item - 2; i2++)
					for( i3 = i2 + 1; i3 < item - 1; i3++)
						for( i4 = i3 + 1; i4 < item; i4++)
							result[i++] = (input[i1] + input[i2] + input[i3] + input[i4]) / choice;
		}
	case 5:
		{
		}
	case 6:
		{
		}
	case 7:
		{
		}
	case 8:
		{
		}
	default:
		{
		}
	}
	return result;
}

int Find_Winner(double *input, int input_size, double base, double up, double down)
{
	
	int score = 0;
	//double *score = new(double[input_size]);
	int i = 0, high_num;
	int high_score;
	/*
	for(i = 0; i < input_size; i++)
	{
		double diff = input[i] / base - 1;
		if (diff >= 0)
		{
			score[i] = 100 - 100 * diff * up;
		}
		else
		{
			score[i] = 100 + 100 * diff * down;
		}
		if (score[i] < 0)
			score[i] = 0;
		if (i == 0)
		{
			high_score = score[i];
			high_num = i;
		}
		else if (score[i] > high_score)
		{
			high_num = i;
			high_score = score[i];
		}
	}
	*/
	for(i = 0; i < input_size; i++)
	{
		double diff = input[i] / base - 1;
		if (diff >= 0)//up penalty
		{
			score = 100 - round(100 * diff * up);
		}
		else//lower penalty
		{
			score = 100 - round(-100 * diff * down);
		}
		if (score < 0)
			score = 0;
		if (i == 0)
		{
			high_score = score;
			high_num = i;
		}
		else if (score > high_score)
		{
			high_num = i;
			high_score = score;
		}
	}
	return high_num;
}

void Add_Win_time(double *choice, int *win_time, int choice_Num, int variance_num, double lower_Bound, double step, double *input, int item, double up_Penalty, double down_Penalty)
{
	double average = 0;
	for(int i = 0; i < choice_Num; i++)
		average += choice[i];
	average /= choice_Num;
	//double average = (input[i1] + input[i2] + input[i3]) / choice_Num;
	for(int j = 0; j < variance_num; j++)
	{
		double base = (lower_Bound + j * step) / 100 * average;
		int winner = Find_Winner(input, item, base, up_Penalty, down_Penalty);
		win_time[winner]++;
	}
}