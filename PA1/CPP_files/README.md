### expression.cpp
    * `int get_expression_result(std::string & expression)`
        1. 这个函数是求出表达式的值，如果表达式不符合规定，有assert；目前支持int类型

    *  `bool check_parentheses(int p, int q, std::string & expression)`
        1. 查看`expression[p:q+1]`（左关右开）的两端是否为“（）”

    * `bool func_of_check_parentheses(int p, int q, std::string & expression);`
        1. 判断表达式的"(" 和 ")" 是否合法

    * `std::pair<int, int> remove_empty(int p, int q, std::string & expression);`
        1. 移除`expression[p:q+1]` 两边的空白字符，并返回一个两边没有空白字符的位置

    * `bool is_digital(char &s);`
        判断这个字符串是否是 ‘0 - 9’

    * `int eval(int p, int q, std::string & expression)`
        计算`expression[p:q+1]` 这个表达式的值


### expression_main.cpp
    * `std::string generate_expression()`
        1. 产生随机表达式，有合法的，也有非法的

    * `int main()`
        1. 将随机表达传入`int get_expression_result(std::string & expression)` 进行值的求解


### test.py
    1. 对expression_main.cpp的for循环测试
    2. 可以用命令：`python3 test.py > test.txt`将输出结果导入test.txt

    