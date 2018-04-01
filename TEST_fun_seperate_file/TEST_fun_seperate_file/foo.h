#pragma once
#ifndef __FOO_H_INCLUDED__
#define __FOO_H_INCLUDED__



#include <string>

using namespace std;


int mi(int num);
int Multiply(int num);

string ReplaceString(string subject, string search, string replace);

string sub_with_num(string subject_allnum, double* x, double* u, int lenX, int lenU);

string uniary_operator_sin(string str_sin_x);

string uniary_operator_cos(string str_cos_x);

string uniary_operator_exp(string str_exp_x);

int assign_bigger(int p_plus, int p_minus, int p_multipy, int p_divide);

int find_last_symbol(string str);

bool any_num(string str, int len);

int pre_num_pos(string all_num_str, string symbol_type);

int post_num_pos(string all_num_str, string symbol_type);

string binary_operator_pow(string str_num_only);

int find_first_symbol_mul_div(string str);

int find_first_symbol_add_sub_new(string str);

string binary_operator_mul(string str_num_only);

string binary_operator_div(string str_num_only);

string binary_operator_add(string str_num_only);

string binary_operator_subtract(string str_num_only);

string binary_operator_mul_div(string str_num_only_m_d_a_s);

string binary_operator_add_sub(string str_num_only_a_s);

string evaluate_num_str_within_paranp(string num_str);

string do_pranp(string str_with_pranp);

double evaluate_final(string str_only_numbers);

double evaluate_a_string(string str, double* x, double* u, int lenX, int lenU);

#endif // !__FOO_H_INCLUDED__