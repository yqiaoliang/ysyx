#include <string>
#include <utility>
#include <iostream>
#include <cassert>
#include "expression.h"


Expression::Expression(std::string & expression_) : expression(expression_) {}

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

// std::pair<bool, int> Expression::solve_op_behind_digital(int p, int q){
//     int last_op_pos = -1, first_non_op_pos = -1;
//     int sub = 0, l = p;
//     bool tag = false;
//     int match = 0;

//     for (; l <= q; l++){
//         if ((expression[l] == '+' or expression[l] == ' ' or expression[l] == '-' or expression[l] == '*' or expression[l] == '/') and match == 0){
//             last_op_pos = l;
//             if (expression[l] == '-') sub += 1;
//             if (!tag and (expression[l] == '*' or expression[l] == '/')) tag = true;
//         }
//         else {
//             if (first_non_op_pos == -1) first_non_op_pos = 1;
//             if(expression[l] == '(') match += 1;
//             else if (expression[l] == ')') match -= 1;
//         }
//     }

    
    
//     if (last_op_pos >= first_non_op_pos) return {false, 0};
//     if (tag) {
//         // std::cout << "exist * or / behind expression: " << expression[last_op_pos] << " ,position is " << last_op_pos << std::endl << std::endl;
//         std::cout << expression.substr(p, q-p+1) << std::endl << std::endl;
//         std::cout << last_op_pos << " " << first_non_op_pos << std::endl << std::endl;
//         assert(0);
//     }

//     std::string num_str = expression.substr(first_non_op_pos, q - first_non_op_pos + 1);
//     if (sub & 1) return {true, std::stoi(num_str)};
//     else return {true, -std::stoi(num_str)};
    
// }

int Expression::solve_op_behind_digital(int p, int q){
    int l = p, sub = 0;

    for (;l <= q; l++){
        if (expression[l] == '-') sub += 1;
        else if (expression[l] == ' ' or expression[l] == '+') continue;
        else if (expression[l] == '*' or expression[l] == '/'){
            std::cout << expression.substr(p, q-p+1) << std::endl << std::endl;
            // std::cout << last_op_pos << " " << first_non_op_pos << std::endl << std::endl;
            assert(0);
        }
        else break;
    }

    int new_p = l, match = 0;
    for (; new_p <= q; new_p++){
        if (expression[new_p] == '(') match += 1;
        else if (expression[new_p] == ')') match -= 1;
        else if ((expression[new_p] == '+' or expression[new_p] == '-') and match == 0) break;
    }

    // std::cout<< l << "  " << new_p << std::endl << std::endl;

    if (expression[new_p] == '+') {
        if (sub % 2 == 0)  eval(l, new_p-1) + eval(new_p+1, q);
        else return -eval(l, new_p-1) + eval(new_p+1, q);
    }
    else if (expression[new_p] == '-'){
        if (sub % 2 == 0)  eval(l, new_p-1) - eval(new_p+1, q);
        else return -eval(l, new_p-1) - eval(new_p+1, q);
    }
    else if (new_p >= q){
        if (sub % 2 == 0)  eval(l, q);
        else return -eval(l, q);
    }
}

int Expression::eval(int p, int q){
    // std::cout << "eval: " << p << " " << q << std::endl << std::endl;

    if (p > q) assert(0);



    auto[new_p, new_q] = remove_empty(p, q);
    p = new_p; q = new_q;

    if (expression[p] == '-' or expression[p] == '+') return solve_op_behind_digital(p, q);

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

