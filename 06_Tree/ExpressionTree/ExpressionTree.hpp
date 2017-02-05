//
//  ExpressionTree.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 5..
//

#ifndef ExpressionTree_hpp
#define ExpressionTree_hpp

#include "../BinaryTree/BinaryTree.hpp"
#include "../../03_Stack/ListBaseStack/ListBaseStack.hpp"

class ExpressionTree : public BinaryTree<double> {
    
private:
    char oper;
    
    bool isDigit(char*);
    void printData(void);
    ExpressionTree(double number, int oper);
    
public:
    ExpressionTree(char*);
    double evaluate(void);
    
    void printPrefixExpression(void);
    void printInfixExpression(void);
    void printPostfixExpression(void);
    
};

bool ExpressionTree::isDigit(char* token) {
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

void ExpressionTree::printData(void) {
    if(oper != 0) {
        printf("%c ", oper);
    } else {
        printf("%.2lf ", data);
    }
}

ExpressionTree::ExpressionTree(double number, int oper) : BinaryTree<double>(number) {
    this->oper = oper;
}

ExpressionTree::ExpressionTree(char* postfix) {
    
    Stack<ExpressionTree*> stack;
    char* token = postfix;
    
    while((token = strtok(token, " ")) != NULL) {
        if(isDigit(token)) {
            stack.push(new ExpressionTree(atof(token), 0));
        } else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'){
            ExpressionTree* oper = new ExpressionTree(0, token[0]);
            oper->connectRightSubTree(stack.pop());
            oper->connectLeftSubTree(stack.pop());
            
            stack.push(oper);
        } else {
            fprintf(stderr, "수식에 알 수 없는 기호가 포함되어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        token = NULL;
    }
    
    ExpressionTree* root = stack.pop();
    left = root->left;
    right = root->right;
    oper = root->oper;
    data = root->data;
}

double ExpressionTree::evaluate(void) {
    double op1, op2;
    
    if(left == NULL && right == NULL) {
        return data;
    }
    
    op1 = ((ExpressionTree*)left)->evaluate();
    op2 = ((ExpressionTree*)right)->evaluate();
    
    switch(oper) {
        case'+':
            return op1 + op2;
            break;
        case'-':
            return op1 - op2;
            break;
        case'*':
            return op1 * op2;
            break;
        case'/':
            if(op2 == 0) {
                fprintf(stderr, "0으로 나눌 수 없습니다.\n");
                exit(EXIT_FAILURE);
            }
            return op1 / op2;
            break;
        default:
            break;
            
    }
    return 0;
}

void ExpressionTree::printPrefixExpression(void) {
    printData();
    
    if(left != NULL) {
        ((ExpressionTree*)left)->printPrefixExpression();
    }
    
    if(right != NULL) {
        ((ExpressionTree*)right)->printPrefixExpression();
    }
}

void ExpressionTree::printInfixExpression(void) {
    if(left != NULL) {
        printf("(");
        ((ExpressionTree*)left)->printInfixExpression();
    }
    
    printData();
    
    if(right != NULL) {
        ((ExpressionTree*)right)->printInfixExpression();
        printf(")");
    }
}

void ExpressionTree::printPostfixExpression(void) {
    if(left != NULL) {
        ((ExpressionTree*)left)->printPostfixExpression();
    }
    
    if(right != NULL) {
        ((ExpressionTree*)right)->printPostfixExpression();
    }
    
    printData();
}

#endif /* ExpressionTree_hpp */
