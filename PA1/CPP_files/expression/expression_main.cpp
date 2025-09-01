#include "expression.h"
#include <random>
#include <string>
#include <iostream>


std::string generate_expression(){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist0(0, 9);
    std::uniform_int_distribution<int> dist1(0, 100);
    std::uniform_int_distribution<int> dist2(4, 8);

    std::string expression;

    int length = dist2(gen);
    // for (int i = 0; i < length; i++){
    //     switch(dist1(gen)) { 
    //         case 0 : expression += '+'; break; 
    //         case 1 : expression += '-'; break;
    //         case 2 : expression += '*'; break;
    //         case 3 : expression += '/'; break;
    //         case 4 : expression += ' '; break;
    //         case 5 : expression += '('; break;
    //         case 6 : expression += ')'; break;
    //         default : expression += char('0' + dist0(gen)); break; 
    //     }
        
    // }

    for (int i = 0; i < length; i++){
        int p = dist1(gen);
        if (0 <= p and p < 20 ) expression += '+';
        else if (40 <= p and p < 60 ) expression += '-';
        else if (20 <= p and p < 24 ) expression += '*';
        else if (24 <= p and p < 28 ) expression += '/';
        else if (28 <= p and p < 32 ) expression += '(';
        else if (32 <= p and p < 36 ) expression += ')';
        else if (36 <= p and p < 40 ) expression += ')';
        else expression += char('0' + dist0(gen));
        
    }



    return expression;


}



int main(){


    std::string expression = generate_expression();
    std::cout<< expression << " --- ";
    
    std::string a = "+-++- 4 + 6 * 7 -(-8)";

    int result = get_expression_result(expression);
    std::cout<< "result = " << result << std::endl << std::endl;

    return 0;
}