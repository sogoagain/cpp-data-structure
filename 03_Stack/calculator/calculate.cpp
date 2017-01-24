//
//  calculate.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 24..
//

#include <stdio.h>
#include "ExpressionConverter.hpp"
#include "PostfixCalculator.hpp"

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: [%s] [\"exp\"] \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    ExpressionConverter converter(argv[1]);
    converter.convertInfixToPostfix();
    
    PostfixCalculator calculator(converter.getPostfix());
    calculator.calculate();
    
    printf("%lf\n", calculator.getResult());
}
