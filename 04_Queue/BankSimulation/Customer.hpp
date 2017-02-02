//
//  Customer.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 2..
//

#ifndef Customer_hpp
#define Customer_hpp

#include <stdlib.h>

class Customer {
    
private:
    static const int MAX_SERVICE_TIME = 10;
    int id;
    int arrivalTime;
    int serviceTime;
    int waitedTime;
    
public:
    static int count;
    Customer(int time) : arrivalTime(time) {
        count++;
        id = count;
        serviceTime = rand()%MAX_SERVICE_TIME + 1;
        printf("!입장 %d고객. 필요업무시간: %d\n", id, serviceTime);
    }
    ~Customer() {
        printf("!퇴장 %d고객.\n", id);
    }
    int getServiceTime() {
        return serviceTime;
    }
    int getID() {
        return id;
    }
    int getWaitedTime() {
        return waitedTime;
    }
    void welcomeCustomer(int time) {
        waitedTime = time - arrivalTime;
        printf("\t***%d분 기다리셨군요! %d고객님***\n", waitedTime, id);
    }
    void receiveCustomer() {
        printf("\t---%d고객 응대중...---\n", id);
        serviceTime--;
    }
    bool isFinish() {
        return serviceTime == 0;
    }
    
};

int Customer::count = 0;

#endif /* Customer_hpp */
