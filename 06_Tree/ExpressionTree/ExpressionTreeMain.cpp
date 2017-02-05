//
//  ExpressionTree.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 5..
//

#include "ExpressionTree.hpp"
#include "../../03_Stack/calculator/ExpressionConverter.hpp"

int main(int argc, char** argv) {
    /*
     if(argc != 2) {
     fprintf(stderr, "Usage: [%s] [\"exp\"] \n", argv[0]);
     exit(EXIT_FAILURE);
     }
     */
    
    //ExpressionConverter converter(argv[1]);
    ExpressionConverter converter("(1.2 + 3.2)*4 - 12");
    converter.convertInfixToPostfix();
    
    ExpressionTree expressionTree(converter.getPostfix());
    
    expressionTree.printPrefixExpression();
    printf("\n");
    
    expressionTree.printInfixExpression();
    printf("\n");
    
    expressionTree.printPostfixExpression();
    printf("\n");
    
    return 0;
}
