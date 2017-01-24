//
//  ExpressionConverter.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 23..
//

#ifndef ExpressionConverter_h
#define ExpressionConverter_h

#include <iostream>
#include <string.h>
#include "../ListBaseStack/ListBaseStack.hpp"
using namespace std;

class ExpressionConverter {
private:
    char* infix;
    char* postfix;
    
    int getOperatorPrecedence(char);
    bool compareOperatorPrecedence(char, char);
    
public:
    ExpressionConverter(char* = NULL);
    ~ExpressionConverter();
    
    void convertInfixToPostfix(void);
    void setInfix(char*);
    char* getInfix(void);
    char* getPostfix(void);
};

int ExpressionConverter::getOperatorPrecedence(char op) {
    switch(op) {
        case'(': case')': return 0;
        case'+': case'-': return 1;
        case'*': case'/': return 2;
    }
    return -1;
}

bool ExpressionConverter::compareOperatorPrecedence(char op1, char op2) {
    int precedence[2];
    precedence[0] = getOperatorPrecedence(op1);
    precedence[1] = getOperatorPrecedence(op2);
    
    if(precedence[0] >= precedence[1]) {
        return true;
    } else {
        return false;
    }
}

ExpressionConverter::ExpressionConverter(char* infix) {
    if(infix != NULL) {
        this->infix = new char[strlen(infix)+1];
        strcpy(this->infix, infix);
    } else {
        infix = NULL;
    }
    
    postfix = NULL;
}

ExpressionConverter::~ExpressionConverter() {
    if(infix != NULL) {
        delete[] infix;
    }
    if(postfix != NULL) {
        delete[] postfix;
    }
}

void ExpressionConverter::convertInfixToPostfix(void) {
    if(infix == NULL) {
        fprintf(stderr, "중위 표기식이 지정되지 않았습니다.\n");
        exit(EXIT_FAILURE);
    }
    if(postfix != NULL) {
        delete postfix;
    }
    
    Stack<char> stack;
    size_t length = strlen(infix);
    postfix = new char[length + length/2 + 1];
    
    int j = 0;
    for(size_t i = 0; i < length; i++) {
        char token = infix[i];
        
        switch(token) {
            case '+': case'-': case'*': case'/':
                while(!stack.isEmpty() && compareOperatorPrecedence(stack.peek(), token)) {
                    postfix[j++] = ' ';
                    postfix[j++] = stack.pop();
                }
                postfix[j++] = ' ';
                stack.push(token);
                break;
            case '(':
                stack.push(token);
                break;
            case ')':
                while(!stack.isEmpty() && stack.peek() != '(') {
                    postfix[j++] = ' ';
                    postfix[j++] = stack.pop();
                }
                stack.pop();
                break;
            default:
                if(isdigit(token) || token == '.') {
                    postfix[j++] = token;
                } else {
                    fprintf(stderr, "수식에 알 수 없는 기호가 포함되어있습니다.\n");
                    exit(EXIT_FAILURE);
                    break;
                }
                break;
        }
    }
    
    while(!stack.isEmpty()) {
        postfix[j++] = ' ';
        postfix[j++] = stack.pop();
    }
}

void ExpressionConverter::setInfix(char* infix) {
    if(infix != NULL) {
        delete infix;
    }
    
    this->infix = new char[strlen(infix)+1];
    strcpy(this->infix, infix);
}

char* ExpressionConverter::getInfix() {
    return infix;
}

char* ExpressionConverter::getPostfix() {
    return postfix;
}

#endif /* ExpressionConverter_h */
