//
//  BankSimulation.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 2..
//

#include <stdio.h>
#include <unistd.h>
#include "../ListBaseQueue/ListBaseQueue.hpp"
#include "Customer.hpp"

#define SIMULATION_TIME 60
#define ARRIVING_CUSTOMERS_PER_UNIT_TIME 0.4

bool isCustomerArrived(void) {
    if(rand()/(double)RAND_MAX <= ARRIVING_CUSTOMERS_PER_UNIT_TIME) {
        return true;
    }
    
    return false;
}

int main(int argc, char** argv) {
    Queue<Customer*> queue;
    Customer* receivingCustomer = NULL;
    int totalCustomers = 0, waitingCustomers = 0, servedCustomers = 0;
    int totalWaitingTime = 0;
    
    srand(time(NULL));
    
    for(int i = 0; i < SIMULATION_TIME; i++) {
        // 손님 도착!
        if(isCustomerArrived()) {
            queue.offer(new Customer(i));
        }
        
        // 상담 고객이 없다면 대기열 손님중 먼저온 손님을 응대
        // 상담 고객이 있다면 상담 시간이 끝날때 까지 상담.
        if((receivingCustomer == NULL) && !(queue.isEmpty())) {
            receivingCustomer = queue.poll();
            receivingCustomer->welcomeCustomer(i);
            totalWaitingTime += receivingCustomer->getWaitedTime();
            servedCustomers = receivingCustomer->getID();
        } else if(receivingCustomer != NULL) {
            if(receivingCustomer->isFinish()) {
                delete receivingCustomer;
                receivingCustomer = NULL;
            } else {
                receivingCustomer->receiveCustomer();
            }
        }
        
        sleep(1);
    }
    
    printf("----------영업 종료----------\n");
    printf("죄송하지만 기다리시던 고객님들은 다음에 와주세요!\n\n");
    waitingCustomers = queue.getSize();
    while(!queue.isEmpty()) {
        delete queue.poll();
    }
    

    printf("\t오늘의 통계치\n");
    printf("전체 방문 고객 수: %d\n", Customer::count);
    printf("응대 받은 고객 수: %d\n", servedCustomers);
    printf("대기중인 고객 수: %d\n", waitingCustomers);
    printf("1인당 평균 대기 시간: %lf\n", (double)totalWaitingTime/servedCustomers);
    
    
    
    return 0;
}
