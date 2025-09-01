#include <iostream>
#include "expression.h"


int main(){
    

    std::string expression_str = "33920 +-+ -+ 5 * (232030 --+ 8)";
    
    Expression expr(expression_str);
    expr.push_expression_into_data();
    auto data = expr.data;
    auto expression = expr.expression;
    for (const auto &item : data) {
        int type = std::get<0>(item);
        int start = std::get<1>(item);
        int end = std::get<2>(item);
        std::string segment = expression.substr(start, end - start + 1);
        if (type == 0) {
            std::cout << "Operator: " << segment << std::endl;
        } 
        else {   
            std::cout << "Number: " << segment << std::endl;
        }
    }
    
    return 0;
}