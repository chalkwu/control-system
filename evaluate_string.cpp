
#include <iostream>
#include "evaluate_string.h"
#include <string>
#include "math.h"

using namespace std;


string ReplaceString(string subject, string search, string replace)
{
    int pos = 0;
    pos = subject.find(search);

    while (pos != -1)
    {
        // Get the next occurrence from the current position
        subject.replace(pos, search.length(), replace);

        pos = subject.find(search);
        // Add position to the vector
    }
    return subject;
}

string sub_with_num(string subject_allnum, double* x, double* u, int lenX, int lenU)
{
    string xi;
    if (lenX == 1)
    {
        xi = "x";
        subject_allnum = ReplaceString(subject_allnum, xi, to_string(*x));
    }
    else if (lenX > 1)
    {
        for (int i = 1; i <= lenX; i++)
        {
            xi = "x" + to_string(i);
            subject_allnum = ReplaceString(subject_allnum, xi, to_string(x[i - 1]));

        }
    }

    string ui;
    if (lenU == 1)
    {
        ui = "u";
        subject_allnum = ReplaceString(subject_allnum, ui, to_string(*u));
    }
    else if (lenU > 1)
    {
        for (int i = 1; i <= lenU; i++)
        {
            ui = "u" + to_string(i);
            subject_allnum = ReplaceString(subject_allnum, ui, to_string(u[i - 1]));

        }
    }

    return subject_allnum;

}


string uniary_operator_sin(string str_sin_x)
{
    string tosearch = "sin";
    string::size_type sz;

    double num;
    string sin_value;
    int pos = 0;
    //int pos_opr;

    pos = str_sin_x.find(tosearch);


    while (pos != -1)
    {
        //pos_opr = remain_first_operator(str_sin_x.substr(pos), pos);
        num = stod(str_sin_x.substr(pos + tosearch.length()), &sz);

        sin_value = to_string(sin(num));

        str_sin_x.replace(pos, tosearch.length() + sz, sin_value);

        pos = str_sin_x.find(tosearch);
        //pos_opr = remain_first_operator(str_sin_x.substr(pos));
    }

    return str_sin_x;

}

string uniary_operator_cos(string str_cos_x)
{
    string tosearch = "cos";
    string::size_type sz;

    double num;
    string cos_value;
    int pos = 0;
    //int pos_opr;

    pos = str_cos_x.find(tosearch);


    while (pos != -1)
    {
        //pos_opr = remain_first_operator(str_cos_x.substr(pos), pos);
        num = stod(str_cos_x.substr(pos + tosearch.length()), &sz);

        cos_value = to_string(cos(num));

        str_cos_x.replace(pos, tosearch.length() + sz, cos_value);

        pos = str_cos_x.find(tosearch);
        //pos_opr = remain_first_operator(str_sin_x.substr(pos));
    }

    return str_cos_x;

}

string uniary_operator_exp(string str_exp_x)
{
    string tosearch = "exp";
    string::size_type sz;

    double num;
    string exp_value;
    int pos = 0;
    //int pos_opr;

    pos = str_exp_x.find(tosearch);

    while (pos != -1)
    {
        //pos_opr = remain_first_operator(str_exp_x.substr(pos), pos);
        num = stod(str_exp_x.substr(pos + tosearch.length()), &sz);

        exp_value = to_string(exp(num));

        str_exp_x.replace(pos, tosearch.length() + sz, exp_value);

        pos = str_exp_x.find(tosearch);
        //pos_opr = remain_first_operator(str_sin_x.substr(pos));
    }

    return str_exp_x;

}

int assign_bigger(int p_plus, int p_minus, int p_multipy, int p_divide)
{
    int res = 0;
    if (p_plus > res)
    {
        res = p_plus;
    }
    if (p_minus > res)
    {
        res = p_minus;
    }
    if (p_multipy > res)
    {
        res = p_multipy;
    }
    if (p_divide > res)
    {
        res = p_divide;
    }

    return res;

}

int find_last_symbol(string str)
{
    int res = 0;
    int pre_last_plus = int(str.find_last_of("+") != string::npos) ? str.find_last_of("+") : 0;
    int pre_last_minus = int(str.find_last_of("-") != string::npos) ? str.find_last_of("-") : 0;
    int pre_last_multipy = int(str.find_last_of("*") != string::npos) ? str.find_last_of("*") : 0;
    int pre_last_divide = int(str.find_last_of("/") != string::npos) ? str.find_last_of("/") : 0;

    res = assign_bigger(pre_last_plus, pre_last_minus, pre_last_multipy, pre_last_divide);

    return res;
}

bool any_num(string str, int len)
{
    bool ck = false;
    int a2d;
    for (int i = 0; i < len; i++)
    {
        a2d = int(str.at(i));
        if (a2d >= 48 && a2d <= 57)
        {
            ck = true;
            break;
        }
    }

    return ck;
}

int pre_num_pos(string all_num_str, string symbol_type)
{
    int res = 0;
    int found_m = all_num_str.find(symbol_type);
    // handle the minus sign
    int asci = int(symbol_type.at(0));
    if (asci == 45)
    {
        int found0 = all_num_str.find_first_not_of(" ");
        int found1 = all_num_str.substr(found0).find_first_not_of("-");
        found_m = all_num_str.substr(found0 + found1).find(symbol_type);
    }

    string pre_str;
    pre_str = all_num_str.substr(0, found_m);


    int pos = find_last_symbol(pre_str);
    int asc = int(pre_str.at(pos));

    if (pos != 0)
    {
        if (asc == 43 || asc == 42 || asc == 47)
        {
            res = pos + 1;
        }
        else if (asc == 45)
        {
            string pre_str_p = pre_str.substr(0, pos);
            int pos_p = find_last_symbol(pre_str_p);

            if (any_num(pre_str.substr(pos_p, pos - pos_p + 1), pos - pos_p + 1))
            {
                res = pos + 1;
            }
            else
            {
                res = pos;
            }
        }

    }

    return res;
}

int post_num_pos(string all_num_str, string symbol_type)
{
    int found_m = all_num_str.find(symbol_type);
    // handle the minus sign
    int asci = int(symbol_type.at(0));
    if (asci == 45)
    {
        int found0 = all_num_str.find_first_not_of(" ");
        int found1 = all_num_str.substr(found0).find_first_not_of("-");
        found_m = all_num_str.substr(found0 + found1).find(symbol_type) + found0 + found1;
    }
    return found_m + 1;
}

string binary_operator_pow(string str_num_only)
{
    string tosearch = "^";
    int pos = 0;
    int checkpresy;
    int checkpostsy;
    double pre_num;
    string::size_type sz;
    double post_num;
    double pow_value;
    string pow_value_str;

    pos = str_num_only.find(tosearch);


    while (pos != -1)
    {
        checkpresy = pre_num_pos(str_num_only, tosearch);
        checkpostsy = post_num_pos(str_num_only, tosearch);
        pre_num = stod(str_num_only.substr(checkpresy));
        post_num = stod(str_num_only.substr(checkpostsy), &sz);

        pow_value = pow(pre_num, post_num);
        pow_value_str = to_string(pow_value);

        str_num_only.replace(checkpresy, checkpostsy + sz - checkpresy, pow_value_str);

        pos = str_num_only.find(tosearch);
    }

    return str_num_only;
}

int find_first_symbol_mul_div(string str)
{
    int res = str.length();
    int first_multipy = int(str.find("*") != string::npos) ? str.find("*") : res;
    int first_divide = int(str.find("/") != string::npos) ? str.find("/") : res;

    res = (first_multipy < first_divide) ? first_multipy : first_divide;

    return res;
}

int find_first_symbol_add_sub_new(string str)
{
    int pos_no_space = str.find_first_not_of(" ");
    int pos_no_minus = str.substr(pos_no_space).find_first_not_of("-");
    int pos_start = pos_no_space + pos_no_minus;

    string str_start = str.substr(pos_start);

    int res = str_start.length();
    int first_add = int(str_start.find("+") != string::npos) ? str_start.find("+") : res;
    int first_sub = int(str_start.find("-") != string::npos) ? str_start.find("-") : res;

    res = (first_add < first_sub) ? first_add : first_sub;

    return res + pos_start;
}

string binary_operator_mul(string str_num_only)
{
    string tosearch = "*";
    int pos = 0;

    int checkpresy;
    int checkpostsy;
    double pre_num;
    string::size_type sz;
    double post_num;

    double mul_value;
    string mul_value_str;

    pos = str_num_only.find(tosearch);

    checkpresy = pre_num_pos(str_num_only, tosearch);
    checkpostsy = post_num_pos(str_num_only, tosearch);
    pre_num = stod(str_num_only.substr(checkpresy));
    post_num = stod(str_num_only.substr(checkpostsy), &sz);

    mul_value = pre_num * post_num;
    mul_value_str = to_string(mul_value);

    str_num_only.replace(checkpresy, checkpostsy + sz - checkpresy, mul_value_str);

    pos = str_num_only.find(tosearch);

    return str_num_only;
}

string binary_operator_div(string str_num_only)
{
    string tosearch = "/";
    int pos = 0;
    int checkpresy;
    int checkpostsy;
    double pre_num;
    string::size_type sz;
    double post_num;

    double div_value;
    string div_value_str;

    pos = str_num_only.find(tosearch);


    checkpresy = pre_num_pos(str_num_only, tosearch);
    checkpostsy = post_num_pos(str_num_only, tosearch);
    pre_num = stod(str_num_only.substr(checkpresy));
    post_num = stod(str_num_only.substr(checkpostsy), &sz);

    if (post_num != 0)
    {
        div_value = pre_num / post_num;
    }
    else
    {
        div_value = 1000000000;
    }

    div_value_str = to_string(div_value);
    str_num_only.replace(checkpresy, checkpostsy + sz - checkpresy, div_value_str);

    pos = str_num_only.find(tosearch);

    return str_num_only;
}

string binary_operator_add(string str_num_only)
{
    string tosearch = "+";
    int pos = 0;
    int checkpresy;
    int checkpostsy;
    double pre_num;
    string::size_type sz;
    double post_num;

    double add_value;
    string add_value_str;

    pos = str_num_only.find(tosearch);

    checkpresy = pre_num_pos(str_num_only, tosearch);
    checkpostsy = post_num_pos(str_num_only, tosearch);
    pre_num = stod(str_num_only.substr(checkpresy));
    post_num = stod(str_num_only.substr(checkpostsy), &sz);

    add_value = pre_num + post_num;
    add_value_str = to_string(add_value);

    str_num_only.replace(checkpresy, checkpostsy + sz - checkpresy, add_value_str);

    return str_num_only;
}

string binary_operator_subtract(string str_num_only)
{
    string tosearch = "-";
    //int pos = 0;
    int checkpresy;
    int checkpostsy;
    double pre_num;
    string::size_type sz;
    double post_num;

    double subtract_value;
    string subtract_value_str;

    //pos = str_start.find(tosearch);

    checkpresy = pre_num_pos(str_num_only, tosearch);
    checkpostsy = post_num_pos(str_num_only, tosearch);
    pre_num = stod(str_num_only.substr(checkpresy));
    post_num = stod(str_num_only.substr(checkpostsy), &sz);

    subtract_value = pre_num - post_num;
    subtract_value_str = to_string(subtract_value);

    str_num_only.replace(checkpresy, checkpostsy + sz - checkpresy, subtract_value_str);

    return str_num_only;
}

string binary_operator_mul_div(string str_num_only_m_d_a_s)
{
    int first_mul_div_pos = find_first_symbol_mul_div(str_num_only_m_d_a_s);
    //string update_str;
    int asc;

    while (first_mul_div_pos != str_num_only_m_d_a_s.length())  // no more mul or div symbol
    {
        asc = int(str_num_only_m_d_a_s.at(first_mul_div_pos));
        if (asc == 42)  // if find * firstly
        {
            str_num_only_m_d_a_s = binary_operator_mul(str_num_only_m_d_a_s);
        }
        else if (asc == 47) // if find / firstly
        {
            str_num_only_m_d_a_s = binary_operator_div(str_num_only_m_d_a_s);
        }

        first_mul_div_pos = find_first_symbol_mul_div(str_num_only_m_d_a_s);
    }

    return str_num_only_m_d_a_s;
}

string binary_operator_add_sub(string str_num_only_a_s)
{
    int first_add_sub_pos = find_first_symbol_add_sub_new(str_num_only_a_s);
    //string update_str;
    int asc;

    while (first_add_sub_pos != str_num_only_a_s.length())  // no more mul or div symbol
    {
        asc = int(str_num_only_a_s.at(first_add_sub_pos));
        if (asc == 43)  // if find + firstly
        {
            str_num_only_a_s = binary_operator_add(str_num_only_a_s);
        }
        else if (asc == 45) // if find - firstly
        {
            str_num_only_a_s = binary_operator_subtract(str_num_only_a_s);
        }

        first_add_sub_pos = find_first_symbol_add_sub_new(str_num_only_a_s);
    }

    return str_num_only_a_s;
}

string evaluate_num_str_within_paranp(string num_str)
{
    string no_sin = uniary_operator_sin(num_str);

    string no_cos = uniary_operator_cos(no_sin);

    string no_exp = uniary_operator_exp(no_cos);

    string no_pow = binary_operator_pow(no_exp);

    string no_m_d = binary_operator_mul_div(no_pow);

    string res = binary_operator_add_sub(no_m_d);

    return res;
}

string do_pranp(string str_with_pranp)
{
    int ps_pre_pran = str_with_pranp.find_last_of("(");

    while (ps_pre_pran != -1)
    {
        int ps_cop_pran = str_with_pranp.substr(ps_pre_pran).find(")");

        string num_in_paranp = evaluate_num_str_within_paranp(str_with_pranp.substr(ps_pre_pran + 1, ps_cop_pran - 1));

        str_with_pranp.replace(ps_pre_pran, ps_cop_pran + 1, num_in_paranp);

        ps_pre_pran = str_with_pranp.find_last_of("(");

    }

    return str_with_pranp;
}

double evaluate_final(string str_only_numbers)
{
    string a_number = evaluate_num_str_within_paranp(str_only_numbers);

    return stod(a_number);
}

double evaluate_a_string(string str, double* x, double* u, int lenX, int lenU)
{
    string str_after_sub = sub_with_num(str, x, u, lenX, lenU);

    string str_no_pranp = do_pranp(str_after_sub);

    double res = evaluate_final(str_no_pranp);

    return res;
}
