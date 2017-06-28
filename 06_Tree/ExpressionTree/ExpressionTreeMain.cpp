//
//  ExpressionTree.cpp
//  DataStructure
//
//  Created by sogoagain on 2017. 2. 5..
//

#include "ExpressionTree.hpp"
#include "../../03_Stack/calculator/ExpressionConverter.hpp"

int main(int argc, char** argv) {
    
    if(argc != 2) {
        fprintf(stderr, "Usage: [%s] [\"exp\"] \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    
    ExpressionConverter converter(argv[1]);
    converter.convertInfixToPostfix();
    
    ExpressionTree expressionTree(converter.getPostfix());
    
    printf("전위 표기식: ");
    expressionTree.printPrefixExpression();
    printf("\n");
    
    printf("중위 표기식: ");
    expressionTree.printInfixExpression();
    printf("\n");
    
    printf("후위 표기식: ");
    expressionTree.printPostfixExpression();
    printf("\n");
    
    printf("계산 결과: %.2lf\n", expressionTree.evaluate());
    
    return 0;
}
