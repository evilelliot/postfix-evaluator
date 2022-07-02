/*
* File: Evaluator.hpp
* Author: Alberto Ocaranza
* Project: postfix evaluator.
* Function: header file, contains postfix project logic.
*/
#ifndef Evaluator_hpp
#define Evaluator_hpp
#include <string>
#include <stack>
#include <sstream>
#include <math.h>

namespace Eval{
class Evaluator{
    public:
        static float eval(std::string e){
            std::stack<float> s;
            float num = 0, num1 = 0, num2 = 0;

            std::istringstream token_stream(e);
            std::string token;

            while(token_stream >> token){
                if(token.size() == 1 && isOperand(token[0])){
                char operand = token[0];
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                num = operation(num1, num2, operand);
                s.push(num);
                }else{
                    std::istringstream number_stream(token); 
                    if(number_stream >> num) {
                        s.push(num);
                    }
                }
            }
            num = s.top();
            s.pop();

            return num;
        }
    private:
        static bool isDigit(char c){
            return c >= '0' && c <= '9' ? true : false;
        }
        static bool isOperand(char c){
            switch (c) {
                case '+' :
                case '-' :
                case '*' :
                case '/' :
                case '^' : return 1;
                default  : return 0;
            }
        }
        static float operation(float a, float b, char sym){
            float ans;
            switch (sym) {
                case '+' : ans = a + b;
                break;
                case '-' : ans = a - b;
                break;
                case '*' : ans = a * b;
                break;
                case '/' : ans = a / b;
                break;
                case '^' : ans = pow(a, b);
                break;
                default  : break;
            }
            return ans;
        }
        
};
};
#endif