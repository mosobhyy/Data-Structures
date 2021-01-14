#include <iostream>
#include<stack>
using namespace std;

int GetOperatorWeight(char op);
bool HasHigherPrecedence(char op1, char op2);
string InfixToPostfix(string expression);

int main() {
    string expression;
    cout << "Enter Infix Expression \n";
    getline(cin, expression);
    string postfix = InfixToPostfix(expression);
    cout << "Output = " << postfix << "\n";
    return 0;
}

int GetOperatorWeight(char op)
{
    int weight = 0;
    switch(op)
    {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
    }
    return weight;
}

bool HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    if(op1 >= op2)
        return true;
    return false;
}

string InfixToPostfix(string expression)
{
    string postfix  = "";
    stack<char> s;
    for(size_t i=0 ; i<expression.size() ; i++)
    {
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/'|| expression[i]=='(')
        {
            while (!s.empty() && s.top() != '(' && HasHigherPrecedence(expression[i], s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
        else if(expression[i] == ')')
        {
            while(s.top()!='(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
            postfix += expression[i];
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
