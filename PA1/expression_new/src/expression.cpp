#include "expression.h"
#include <cassert>

Expression::Expression(std::string & str_) : expression(str_){}

void Expression::push_expression_into_data(){
    int match = 0, expression_length = static_cast<int>(expression.size());
    bool op_tag = false, num_tag = false;
    int pre_str_pos = 0, sub = 0;

    for (int i = 0; i < expression_length; i++){
        if (expression[i] == '(') match++;
        else if (expression[i] == ')') match--;


        if ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') && match == 0) {
            if (!op_tag and num_tag){
                op_tag = true;
                num_tag = false;
                data.push_back(std::make_tuple(9, pre_str_pos, i-1));
                pre_str_pos = i;
            }
            else if (!op_tag and !num_tag) {
                op_tag = true;
                num_tag = false;
            }
        }
        else {
            if (op_tag and !num_tag and expression[i] != ' ') {
                num_tag = true;
                op_tag = false;
                int op_type = check_operator_validity(pre_str_pos, i-1);
                data.push_back(std::make_tuple(op_type, pre_str_pos, i-1));
                pre_str_pos = i;
            }
            else if (!op_tag and !num_tag and expression[i] != ' ') {
                num_tag = true;
                op_tag = false;
            }

            else if (i == expression_length - 1) {
                if (op_tag){
                    std::cout << "Error: Operator at the end of expression." << std::endl;
                    assert(false);
                }

                data.push_back(std::make_tuple(9, pre_str_pos, i));
            }
        }
        


    }
}

int Expression::check_operator_validity(int l, int r){
    int Operators[4] = {0, 0, 0, 0}; // + - * /
    int first_op = -1;
    for (int i = l; i <= r; i++){
        if (expression[i] == ' ') continue;
        if (first_op == -1) first_op = i;
        if (expression[i] == '+') Operators[0]++;
        else if (expression[i] == '-') Operators[1]++;
        else if (expression[i] == '*') Operators[2]++;
        else if (expression[i] == '/') Operators[3]++;

    }

    if (Operators[2] > 1 || Operators[3] > 1) {
        std::cout << "Error: Multiple * or / operators in sequence." << std::endl;
        assert(false);
    }
    if (Operators[2] == 1 && Operators[3] == 1) {
        std::cout << "Error: Both * and / operators in sequence." << std::endl;
        assert(false);
    }
    if ((Operators[0] > 1 || Operators[1] > 1) and (Operators[2] == 1 || Operators[3] == 1)) {
        if (expression[first_op] == '*') {
            if (Operators[1] % 2 == 0) return 4; // *+
            else return 6; // *-
        }
        else if (expression[first_op] == '/') {
            if (Operators[1] % 2 == 0) return 5; // /+
            else return 7; // /-
        } 
        else {
            std::cout << "Error: Invalid operator sequence, * or / in + and - mid" << std::endl;
            assert(false);
        }
    }
    if (Operators[2] == 1) return 2; // *
    if (Operators[3] == 1) return 3; // /
    if (Operators[1] % 2 == 0) return 0; // +
    else return 1; // -
}

int Expression::get_part_expression_result(int l, int r) {
    if (l > r) {
        std::cout << "Error: Invalid range for expression evaluation, l > r" << std::endl;
        assert(false);
    }
    if (l == r) return get_block_expression_result(l);

    int operator_type = -1, operator_pos = -1;
    for (int i = l; i <= r; i++) {
        auto [type, start, end] = data[i];
        if (type == 0 or type == 1){
            operator_type = type;
            operator_pos = start;
        }
    }

    if (operator_type == -1) {
        for (int i = r; i >= l; i--) {
            auto [type, start, end] = data[i];
            if (type < 8) {
                operator_type = type;
                operator_pos = start;
                break;
            }
        }
    }

    switch(operator_type) {
        case 0: // +
            return get_expression_result(l, operator_pos - 1) + get_expression_result(operator_pos + 1, r);
        case 1: // -
            return -get_expression_result(l, operator_pos - 1) - get_expression_result(operator_pos + 1, r);
        case 2: // *
            return get_expression_result(l, operator_pos - 1) * get_expression_result(operator_pos + 1, r);
        case 3: // /
            return get_expression_result(l, operator_pos - 1) / get_expression_result(operator_pos + 1, r);
        case 4: // *+
            return get_expression_result(l, operator_pos - 1) * get_expression_result(operator_pos + 1, r);
        case 5: // /+
            return get_expression_result(l, operator_pos - 1) / get_expression_result(operator_pos + 1, r);
        case 6: // *-
            return -get_expression_result(l, operator_pos - 1) * (-get_expression_result(operator_pos + 1, r));
        case 7: // /-
            return -get_expression_result(l, operator_pos - 1) / (-get_expression_result(operator_pos + 1, r));
        default:
            // write soon;
    }

}

int Expression::get_block_expression_result(int pos) {
    auto [type, start, end] = data[pos];
    if (type != 8){
        std::cout << "Error: Invalid block expression type, expected number." << std::endl;
        assert(false);
    }
    
    auto[l, r] = move_expression_empty(start, end);
    if (l == r and expression[l] == " ") {
        std::cout << "Error: Empty expression segment." << std::endl;
        assert(false);
    }
    return std::stoi(expression.substr(l, r - l + 1));
}

std::pair<int, int> Expression::move_expression_empty(int l, int r) {
    while (l <= r && expression[l] == ' ') l++;
    while (r >= l && expression[r] == ' ') r--;
    return {l, r};
}


