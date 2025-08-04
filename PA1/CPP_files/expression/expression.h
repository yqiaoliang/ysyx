#include <string>
#include <utility>
#include <iostream>

int get_expression_result(std::string & expression); // 输出表达式的值
bool check_parentheses(int p, int q, std::string & expression); // 检查两边是否有括号
bool func_of_check_parentheses(int p, int q, std::string & expression); // 判断表达式括号是否匹配
std::pair<int, int> remove_empty(int p, int q, std::string & expression); // 移除表达式的两边空白字符
bool is_digital(char &s); // 判断字符是否是int类型
int eval(int p, int q, std::string & expression); // 计算表达式截取p ， q两边的值
