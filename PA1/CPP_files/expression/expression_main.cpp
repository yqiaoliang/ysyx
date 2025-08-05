#include "expression.h"
#include <random>
#include <string>
#include <iostream>


std::string generate_expression(){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist0(0, 9);
    std::uniform_int_distribution<int> dist1(0, 20);
    std::uniform_int_distribution<int> dist2(4, 8);

    std::string expression;

    int length = dist2(gen);
    for (int i = 0; i < length; i++){
        switch(dist1(gen)) { 
            case 0 : expression += '+'; break; 
            case 1 : expression += '-'; break;
            case 2 : expression += '*'; break;
            case 3 : expression += '/'; break;
            case 4 : expression += ' '; break;
            case 5 : expression += '('; break;
            case 6 : expression += ')'; break;
            default : expression += char('0' + dist0(gen)); break; 
        }
        
    }

    return expression;


}



int main(){


    std::string expression = generate_expression();
    std::cout<< expression << " --- ";
    
    std::string a = "+-++- 4 + 6 * 7 -(-8)";

    int result = get_expression_result(a);
    std::cout<< "result = " << result << std::endl << std::endl;

    return 0;
}