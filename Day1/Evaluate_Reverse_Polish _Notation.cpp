// 150. Evaluate Reverse Polish Notation

#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;

        for(string st: tokens){
            if(st == "+"){
                int firstNum = s.top();
                s.pop();
                int secondNum = s.top();
                s.pop();
                s.push(firstNum + secondNum);
            }
            else if(st == "*"){
                int firstNum = s.top();
                s.pop();
                int secondNum = s.top();
                s.pop();
                s.push(firstNum * secondNum);
            }
            else if(st == "-"){
                int firstNum = s.top();
                s.pop();
                int secondNum = s.top();
                s.pop();
                s.push(secondNum - firstNum);
            }
            else if(st == "/"){
                int firstNum = s.top();
                s.pop();
                int secondNum = s.top();
                s.pop();
                s.push(secondNum / firstNum);
            }
            else s.push(stoi(st));
        }
        return s.top();
    }
};