//
//  PostfixCalculator.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 24..
//

#ifndef PostfixCalculator_h
#define PostfixCalculator_h

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class PostfixCalculator {
private:
    char* postfix;
    double result;
    
    bool isDigit(char*);
    
public:
    PostfixCalculator(char* = NULL);
    ~PostfixCalculator();
    
    void setPostfix(char*);
    double calculate(void);
    double getResult(void);
};

bool PostfixCalculator::isDigit(char* token) {
    size_t length = strlen(token);
    
    for(size_t i = 0; i < length; i++) {
        if(isdigit(token[i]) || token[i] == '.') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

PostfixCalculator::PostfixCalculator(char* postfix) {
    if(postfix != NULL) {
        this->postfix = new char[strlen(postfix)+1];
        strcpy(this->postfix, postfix);
    } else {
        this->postfix = NULL;
    }
    
    result = 0;
}

PostfixCalculator::~PostfixCalculator() {
    if(postfix != NULL) {
        delete[] postfix;
    }
}

void PostfixCalculator::setPostfix(char* postfix) {
    if(postfix != NULL) {
        delete postfix;
    }
    
    this->postfix = new char[strlen(postfix)+1];
    strcpy(this->postfix, postfix);
}

double PostfixCalculator::calculate(void) {
    if(postfix == NULL) {
        fprintf(stderr, "후위 표기식이 지정되지 않았습니다.\n");
        exit(EXIT_FAILURE);
    }
    
    Stack<double> stack;
    char* token = postfix;
    
    while((token = strtok(token, " ")) != NULL) {
        if(isDigit(token)) {
            stack.push(atof(token));
        } else {
            double operand[2] = {0, };
            for(int i = 0; i < 2; i++) {
                operand[i] = stack.pop();
            }
            switch(token[0]) {
                case '+':
                    stack.push(operand[1] + operand[0]);
                    break;
                case '-':
                    stack.push(operand[1] - operand[0]);
                    break;
                case '*':
                    stack.push(operand[1] * operand[0]);
                    break;
                case '/':
                    stack.push(operand[1] / operand[0]);
                    break;
                default:
                    fprintf(stderr, "수식에 알 수 없는 기호가 포함되어있습니다.\n");
                    exit(EXIT_FAILURE);
                    break;
            }
        }
        token = NULL;
    }
    
    result = stack.pop();
    return result;
}

double PostfixCalculator::getResult(void) {
    return result;
}

#endif /* PostfixCalculator_h */
