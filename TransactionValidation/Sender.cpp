//
// Created by vitor mouzinho on 12/5/19.
//

#include "Sender.h"
/**
 * @param moneyToAdd the money to add to current balance
 * description:
 * This function will add money to the senders current balance.
 */
void Sender::addToBalance(Satoshi moneyToAdd) {
    if(moneyToAdd > 0){
        this->currentBalance += moneyToAdd;
    }
}
/**
 * @return discard money to remove from current balance
 * description:
 * This function will remove money from the current balance.
 */
void Sender::subTractFromBalance(Satoshi discard){
    if(discard > 0){
        this->currentBalance  -= discard;
    }
}
/**
 * @return currentBalance will return the current balance
 * description:
 * This function will return the current balance of the sender
 */
Satoshi Sender::getCurrentBalance(){
    return this->currentBalance;
}
