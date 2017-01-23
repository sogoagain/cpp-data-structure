//
//  InfixToPostfixTest.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 23..
//

#include <stdio.h>
#include "ExpressionConverter.hpp"

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: [%s] [EXPRESSION] \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    ExpressionConverter converter(argv[1]);
    converter.convertInfixToPostfix();
    
    printf("%s의 후위 표기식은 %s입니다.\n",converter.getInfix(), converter.getPostfix());
}
