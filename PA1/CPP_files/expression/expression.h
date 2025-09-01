#include <string>
#include <utility>
#include <iostream>


class Expression{
public:
    Expression(std::string & expression);
    int get_result();
private:
    std::string expression;
    int eval(int p, int q);
    bool check_parentheses(int p, int q);
    bool func_of_check_parentheses(int p, int q);
    std::pair<int, int> remove_empty(int p, int q);
    bool is_digital(char &s);
    int solve_op_behind_digital(int p, int q);
};

int get_expression_result(std::string & expression);