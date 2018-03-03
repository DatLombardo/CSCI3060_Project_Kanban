/*
    Kanban

    This class will handle file output given a list of valid transactions.
*/

#pragma once
#include "transaction.hpp"

class Fileout {
public:
    Fileout();
    void writeTransactions(std::vector<Transaction> transactions);
};
