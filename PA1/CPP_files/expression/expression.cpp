#include <string>
#include <utility>
#include <iostream>
#include <cassert>
#include "expression.h"


// int get_expression_result(std::string & expression); // 输出表达式的值
// bool check_parentheses(int p, int q, std::string & expression); // 检查两边是否有括号
// bool func_of_check_parentheses(int p, int q, std::string & expression); // 判断表达式括号是否匹配
// std::pair<int, int> remove_empty(int p, int q, std::string & expression); // 移除表达式的两边空白字符
// bool is_digital(char &s); // 判断字符是否是int类型
// int eval(int p, int q, std::string & expression); // 计算表达式截取p ， q两边的值



int get_expression_result(std::string & expression){
    int p = 0, q = static_cast<int>(expression.size()) - 1;
    if (!func_of_check_parentheses(p, q, expression)) {
        std::cout << "parentheses unmatch" << std::endl << std::endl;
        assert(0);
    }
    auto [l, r] = remove_empty(p, q, expression);
    return eval(l, r, expression);
}

// 判断表达式两边是否是括号
bool check_parentheses(int p, int q, std::string & expression){
    if (expression[p] == '(' and expression[q] == ')') return true;
    return false;
}


// 判断括号是否匹配
bool func_of_check_parentheses(int p, int q, std::string & expression){
    int match = 0;
    for (int i = p; i <= q; i++){
        if (expression[i] == '(') match += 1;
        else if (expression[i] == ')') match -= 1;
        if (match < 0) return false;
    }

    return match == 0;
}


// 移除表达式的两边空白字符
std::pair<int, int> remove_empty(int p, int q, std::string & expression) {
    int l, r;
    for (l = p; l <= q; l++){
        if (expression[l] != ' ') break;
    }

    for (r = q; r >= l; r--){
        if (expression[r] != ' ') break;
    }

    return {l, r};
}

bool is_digital(char &s){
    return int(s) >= int('0') and int(s) <= int('9');
}

bool check_all_op_behind_digital(int p, int q, std::string & expression) {
    for (int i = p; i <= q; i++){
        if (expression[i] == '+' or expression[i] == '-' or expression[i] == ' ') continue;

        
    }
}

int eval(int p, int q, std::string & expression){
    if (p > q) assert(0);

    auto[new_p, new_q] = remove_empty(p, q, expression);
    p = new_p; q = new_q;


    if (p == q) {
        if (is_digital(expression[p])) return int(expression[p]) - int('0');
        std:: cout << "p == q: non-digital : " << expression[p] << " ,position is :" << p << std::endl << std::endl;
        assert(0);
    }

    else if(check_parentheses(p, q, expression)) {
        return eval(p+1, q-1, expression);
    }

    else {
        int match = 0;
        int op_pos = -1;
        for (int i = p; i <= q; i++){
            if (expression[i] == '(') match += 1;
            else if (expression[i] == ')') match -= 1;
            else if ((expression[i] == '+'  or expression[i] == '-') and match == 0) op_pos = i;  
        }

        if (op_pos == -1){
            match = 0;
            for (int i = p; i <= q; i++){
                if (expression[i] == '(') match += 1;
                else if (expression[i] == ')') match -= 1;
                else if ((expression[i] == '*'  or expression[i] == '/') and match == 0) op_pos = i;  
            }
        }

        if (op_pos == -1) {
            std::string num_str = "";
            for (int i = p; i <= q; i++){
                if (!is_digital(expression[i])) {
                    std::cout << "exist non-digital:" << expression[i] << " ,position is " << p << std::endl << std::endl;
                    assert(0);
                }
                num_str += expression[i];
            }

            return std::stoi(num_str);
        }
        
        if (expression[op_pos] == '+') return eval(p, op_pos-1, expression) + eval(op_pos+1, q, expression);
        if (expression[op_pos] == '-') return eval(p, op_pos-1, expression) - eval(op_pos+1, q, expression);
        if (expression[op_pos] == '*') return eval(p, op_pos-1, expression) * eval(op_pos+1, q, expression);
        if (expression[op_pos] == '/') return eval(p, op_pos-1, expression) / eval(op_pos+1, q, expression);

    }

}

