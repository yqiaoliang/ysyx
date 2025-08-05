#include <string>
#include <utility>
#include <iostream>
#include <cassert>
#include "expression.h"


int get_expression_result(std::string & expression){
    Expression exp(expression);
    return exp.get_result();
}

int Expression::get_result(){
    int p = 0, q = static_cast<int>(expression.size()) - 1;
    if (!func_of_check_parentheses(p, q)) {
        std::cout << "parentheses unmatch" << std::endl << std::endl;
        assert(0);
    }
    auto [l, r] = remove_empty(p, q);
    return eval(l, r);
}

bool Expression::check_parentheses(int p, int q){
    if (expression[p] == '(' and expression[q] == ')') return true;
    return false;
}


bool Expression::func_of_check_parentheses(int p, int q){
    int match = 0;
    for (int i = p; i <= q; i++){
        if (expression[i] == '(') match += 1;
        else if (expression[i] == ')') match -= 1;
        if (match < 0) return false;
    }

    return match == 0;
}


std::pair<int, int> Expression::remove_empty(int p, int q) {
    int l, r;
    for (l = p; l <= q; l++){
        if (expression[l] != ' ') break;
    }

    for (r = q; r >= l; r--){
        if (expression[r] != ' ') break;
    }

    return {l, r};
}

bool Expression::is_digital(char &s){
    return int(s) >= int('0') and int(s) <= int('9');
}

std::pair<bool, int> Expression::solve_op_behind_digital(int p, int q){
    int last_op_pos = -1, first_non_op_pos = -1;
    int sub = 0, l = p;
    bool tag = false;

    for (; l <= q; l++){
        if (expression[l] == '+' or expression[l] == ' ' or expression[l] == '-' or expression[l] == '*' or expression[l] == '/'){
            last_op_pos = l;
            if (expression[l] == '-') sub += 1;
            if (!tag and (expression[i] == '*' or expression[i] == '/')) tag = true;
        }
        else if (first_non_op_pos == -1) first_non_op_pos = l;
    }

    
    
    if (last_op_pos <= first_non_op_pos) return {false, 0};
    if (tag) {
        std::cout << "exist * or / behind expression: " << expression[last_op_pos] << " ,position is " << last_op_pos << std::endl << std::endl;
        assert(0);
    }
    if (sub & 1) return {true, expression.stoi(first_non_op_pos, q - first_non_op_pos + 1)};
    else return {true, -expression.stoi(first_non_op_pos, q - first_non_op_pos + 1)};
    
}

int Expression::eval(int p, int q){
    if (p > q) assert(0);

    auto [tag, result] = solve_op_behind_digital(p, q);
    if (tag) return result;

    auto[new_p, new_q] = remove_empty(p, q);
    p = new_p; q = new_q;

    if (p == q) {
        if (is_digital(expression[p])) return int(expression[p]) - int('0');
        std:: cout << "p == q: non-digital : " << expression[p] << " ,position is :" << p << std::endl << std::endl;
        assert(0);
    }

    else if(check_parentheses(p, q)) {
        return eval(p+1, q-1);
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
        
        if (expression[op_pos] == '+') return eval(p, op_pos-1) + eval(op_pos+1, q);
        if (expression[op_pos] == '-') return eval(p, op_pos-1) - eval(op_pos+1, q);
        if (expression[op_pos] == '*') return eval(p, op_pos-1) * eval(op_pos+1, q);
        if (expression[op_pos] == '/') return eval(p, op_pos-1) / eval(op_pos+1, q);

    }

}

