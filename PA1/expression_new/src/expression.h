#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <tuple>


class Expression{
public:
    Expression(std::string & expression);
    int get_result();
public:
    std::string expression;
    std::vector<std::tuple<int, int, int>> data; // 0:+ , 1:-; 2:*; 3:/; 4: *+; 5: /+; 6: *-; 7: /-; 8: number
    void push_expression_into_data();
    int check_operator_validity(int l, int r);
    int get_part_expression_result(int l, int r);
    int get_block_expression_result(int pos);
    std::pair<int, int> move_expression_empty(int l, int r);



};

int get_expression_result(std::string & expression);