#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "Sender.h"
using namespace std;
using Satoshi = uint64_t;
using Address = uint64_t;
//The amount of money created every block and given to the block's miner
#define MONEY_CREATED_FOR_THE_MINER_EACH_BLOCK 1000
#define MAX_ENTRIES_IN_BLOCK 10
#define SIG_LENGTH 32

struct Transaction{
//creator of transaction and sender of funds
    Address from;
//transaction destination
    Address to;
//amount of money to send to the destination
    Satoshi amount;
//amount of fee is offered by the creator to the miner to add this transaction to the blockchain
    Satoshi fee;
//creation time, written by the transaction creator
    time_t creationTime;
//signing {from,amount,to,fee,creation time}
    uint8_t signature[SIG_LENGTH];
};

struct Block{
    //holds up to 10 transactions
    std::vector <Transaction> trans;
    //the miner that added the block to the blockchain
    Address miner;
    //next block within the blockchain
    Block *next;
};

class BlockChain{

public:
    //not null
    Block *m_firstBlock;
    //assumption firstBlock is not null
    BlockChain (Block * firstBlock):m_firstBlock (firstBlock){}
    //Assumption: all the transaction in the blockchain ("firstBlock linked-list") are valid
    //return whether or not the new transaction is valid, given this blockchain
    //No need to validate the crypto signature
    bool isValid (const Transaction & newTransaction) const;
    bool checkForSignificantFunds(const struct Transaction & newTransaction)const;
    bool checkIfNotInBlockChain(const struct Transaction & newTransaction,const struct Transaction & currentTransAction)const;
};
Block* createGenesisBlock();

int main (){
    std::cout<<"Hello Blockchain! Very nice to meet you! My name is main();"<<std::endl;
    Block *genisBlock = createGenesisBlock();
    BlockChain *bc = new BlockChain(genisBlock);
    //creates a valid transaction
    Transaction validTransAction{2,1,2,1,6};
    //invalid duplicate transaction
    Transaction duplicateTransaction{1,2,100,30,5};
    //not enough funds transaction
    Transaction notEnoughFundsTransaction{2,1,1000,1000,7};
    //transaction used to for another block
    Transaction transaction2{2,1,2,5,5};
    //creates block
    Block *b = new Block();
    //adds block to blockchain
    bc->m_firstBlock->next=b;
    //adds transaction to blockchain
    b->trans.push_back(transaction2);
    // valid transaction
    std::cout<<"This is an example of a valid Transaction "<<bc->isValid(validTransAction)<<std::endl;
    // not enough funds transaction
    std::cout<<"This is an invalid Transaction due to the user not having enough funds "<<bc->isValid(notEnoughFundsTransaction)<<endl;
    // invalid transaction due to the risk of replay attack
    std::cout<<"This is an invalid Transaction due to a potential replay attack "<<bc->isValid(duplicateTransaction)<<endl;
    return 0;
}
/**
 * @return genesisBlock the head of the blockchain
 * Description:
 * This will create and return the head of the blockchain.
 */
Block* createGenesisBlock(){
    Block *genesisBlock = new Block();
    Transaction trans1{
            1,2,100,30,5
    };
    genesisBlock->trans.push_back(trans1);
    Transaction trans2{
            2,1,10,10,2
    };
    genesisBlock->trans.push_back(trans2);
    return genesisBlock;
}

/**
 * @param newTransaction the new transaction being verified
 * @param currentTransAction the newTransaction will compare with this transaction
 * Description:
 * This function is a helper function which will check if the new transaction has already occurred within
 * the block chain. We assume that any user can not send two transaction or more at the same time.
 * They can only receive and send at the same time.
 * Thus we have to check the address of all transaction from where it came from and their time stamps.
 * If there already exists a transaction that has the same sender and the same time stamp as the new transaction
 * we know that the new transaction is a fraudulent transaction.
 */
bool BlockChain:: checkIfNotInBlockChain(const struct Transaction & newTransaction, const struct Transaction & currentTransAction)const{
    bool from = newTransaction.from == currentTransAction.from;
    bool creationTime = newTransaction.creationTime == currentTransAction.creationTime;
    return (from && creationTime);
}
/**
 * @param newTransaction is a new Transaction that is being verfied by the blockchain
 * @return returns true or false if the transaction is valid for this context
 * Description:
 * This function is responsible to iterate through the blockchain. The information that it will gather is
 * the funds of the current sender of the new transaction. since the blockchain contains a record of every transaction
 * ever made it will look for every instance of the address of the sender that occurs within the blockchain
 * since we are assuming that each block is a valid block with valid transactions we can calculate
 * the current funds of the sender. With this information we can determine if the sender has enough funds to
 * support the transaction being requested.
 */
bool BlockChain:: checkForSignificantFunds(const struct Transaction & newTransaction) const {
    //the genesis block of the blockchain
    Block *currentBlock = this->m_firstBlock;
    // instance of a sender object to calculate the senders
    Sender sender(0);
    while(currentBlock != NULL){
        /*checks if the sender was ever a miner and added a block to the chain
         * if so then it will add the current funds needed to the sender
         * */
        if(currentBlock->miner == newTransaction.from){
            sender.addToBalance(MONEY_CREATED_FOR_THE_MINER_EACH_BLOCK);
        }
        //goes through each transaction for the current block
        for (Transaction curTx:currentBlock->trans){
            //if the current transaction is from the sender we know to subtract money from the current balance
            if(curTx.from == newTransaction.from){
                sender.subTractFromBalance((curTx.amount+curTx.fee));
            }
            //if the current transaction is to the sender we know to add funds to the sender
            if(curTx.to == newTransaction.from){
                sender.addToBalance(curTx.amount);
            }
            /*if we ever find that the sender of the new transaction already sent a transaction at the same time
             * then we know it is a false transaction since users can not send two transaction at the same time
             * they can only receive and send at the same time.*/
            if(checkIfNotInBlockChain(newTransaction,curTx)){
                return false;
            }
        }
        // goes to next block within the chain
        currentBlock = currentBlock->next;
    }
    //the total amount that this transaction will cost the user
    Satoshi amountTransactionCost = newTransaction.amount + newTransaction.fee;
    //checks if the user has enough funds and also if the transaction is greater then 0
    return (sender.getCurrentBalance() >= amountTransactionCost) && amountTransactionCost > 0;
}
/**
 * @param newTransaction a new transaction that will be validated
 * @return returns a boolean stating if the transaction is a valid transaction or not
 * Description:
 * This function will tell whether or not a transaction is valid or not according to
 * the specifics of the directions within the test. Assumption that the blocks within the blockchain are valid
 * and its transactions. This function alongside its helper functions check various things.
 * 1.The function will test the times stamps if they are correct
 * 2. check if the parameters of the functions are correct
 * 3. check for the time stamps if two transactions by the same sender has been sent at the same time to avoid replay attacks
 * 4. check if the user who is sending this transaction has valid funds.
 * 5. check for negative and null values
 */
bool BlockChain::isValid(const struct Transaction & newTransaction) const {
    //check if the amount is greater than 0
    bool positiveValue = newTransaction.amount!= NULL && newTransaction.amount > 0 ;
    //check for null values for from/to and creationTime
    bool nullValues = newTransaction.from != NULL || newTransaction.to != NULL || newTransaction.creationTime != NULL;
    //checks if fee is greater then 0 and not equal to null
    bool fee = newTransaction.fee > 0 && newTransaction.fee!=NULL;
    //combines booleans
    bool basicChecks = nullValues && positiveValue && fee;
    //returns false if tests aren't true
    if(!basicChecks){
        return false;
    }
    //checks balance and makes sure no two sending transactions from this user happened at the same time
    return checkForSignificantFunds(newTransaction);
}

