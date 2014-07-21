#ifndef __HELPER_FUNCTION__
#define __HELPER_FUNCTION__
#include "StdAfx.h"

//std::vector<double> & Get_Average(std::vector<double> input, int choice);
double *Get_Average(double *input, int item, int choice);
int cnm(int n, int m);
int round(double a);
int Find_Winner(double *input, int input_size, double base, double up, double down);
void Add_Win_time(double *choice, int *win_time, int choice_Num, int variance_num, double lower_Bound, double step, double *input, int item, double up_Penalty, double down_Penalty);

#endif