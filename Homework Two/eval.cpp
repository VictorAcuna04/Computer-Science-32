#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

bool is_operand(char c) {
    return c == 'T' || c == 'F';
}

int precedence(char c) {
    switch (c) {
        case '!':
            return 3;
        case '&':
            return 2;
        case '^':
            return 1;
        default:
            return 0;
    }
}

int evaluate(string infix, string& postfix, bool& result) {
    stack<char> opstack;
    postfix = "";
    result = false;
    int count_left = 0, count_right = 0;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c == ' ') {  // skip whitespace
            continue;
        }
        else if (is_operand(c)) {
            postfix += c;
        }
        else if (c == '(') {
            opstack.push(c);
            count_left++;
        }
        else if (c == ')') {
            while (!opstack.empty() && opstack.top() != '(') {
                postfix += opstack.top();
                opstack.pop();
            }
            if (opstack.empty()) {
                return 1;  // mismatched parentheses
            }
            opstack.pop();
            count_right++;
        }
        else { 
            while (!opstack.empty() && opstack.top() != '(' &&
                   precedence(c) <= precedence(opstack.top())) {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.push(c);
        }
    }
    
    if (count_left != count_right) {
        return 1; // mismatched parentheses
    }

    while (!opstack.empty()) {
        if (opstack.top() == '(') {
            return 1;  // mismatched parentheses
        }
        postfix += opstack.top();
        opstack.pop();
    }

    // Evaluate postfix expression
    stack<bool> valstack;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (is_operand(c)) {
            valstack.push(c == 'T');
        }
        else {  // c is operator
            if (valstack.size() < 2) {
                return 1;  // not enough operands
            }

            bool rhs = valstack.top();
            valstack.pop();
            bool lhs = valstack.top();
            valstack.pop();

            switch (c) {
                case '!':
                    valstack.push(!rhs);
                    break;
                case '&':
                    valstack.push(lhs && rhs);
                    break;
                case '^':
                    valstack.push(lhs != rhs);
                    break;
                default:
                    return 1;  // unknown operator
            }
        }
    }

    if (valstack.size() != 1) {
        return 1;  // too many operands
    }
    result = valstack.top();
    return 0;  // success
}

int main()
{
    string pf;
	bool answer;
	assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
	assert(evaluate("T^", pf, answer) == 1);
	assert(evaluate("F F", pf, answer) == 1);
	assert(evaluate("TF", pf, answer) == 1);
	assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
	assert(evaluate("T(F^T)", pf, answer) == 1);
	assert(evaluate("T(&T)", pf, answer) == 1);
	assert(evaluate("(T&(F^F)", pf, answer) == 1);
	assert(evaluate("T|F", pf, answer) == 1);
	assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0  &&  pf == "FF!TF&&^"  &&  !answer);
	assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
	assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
	cout << "Passed all tests" << endl;
}