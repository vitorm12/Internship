//
// Created by vitor mouzinho on 12/5/19.
//

#ifndef UNTITLED1_SENDER_H
#define UNTITLED1_SENDER_H


#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
using Satoshi = uint64_t;


using Satoshi = uint64_t;

class Sender {

private:
    // the current balance of the sender
    Satoshi currentBalance;
public:
    Sender(Satoshi startingBalance){
        this->currentBalance = startingBalance;
    }
    void addToBalance(Satoshi moneyToAdd);
    void subTractFromBalance(Satoshi discard);
    Satoshi getCurrentBalance();

};


#endif //UNTITLED1_SENDER_H

