#include <iostream>
#include <fstream>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string.hpp>
#include <iomanip>

#include "fileout.hpp"

Fileout::Fileout(){
  
}

void typeOne(std::ofstream& out, Transaction transaction) {
    std::string username = transaction.currentUser.username;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << transaction.currentUser.credits << std::flush;
    std::string s = stream.str();

    std::cout << transaction.currentUser.credits << " " + transaction.currentUser.type << std::endl;

    // boost::erase_all(s, ".");
    // boost::erase_all(s, "\n");

    out << transaction.transactionCode 
        << " " << std::left
        << std::setfill(' ') << std::setw(16)
        << username
        << std::setw(2) << transaction.currentUser.type << " " << std::flush
        << std::right << std::setfill('0') << std::setw(9)
        << s << std::endl;

    // std::cout << std::endl;
    // std::cout << s << std::endl;

    return;
}

void refund(std::ofstream& out, Transaction transaction) {
    std::string username = transaction.currentUser.username;
    std::string seller = transaction.seller.username;
    std::string buyer = transaction.buyer.username;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << transaction.credit;
    std::string s = stream.str();

    // boost::erase_all(s, ".");

    out << transaction.transactionCode 
        << " " << std::left << std::setfill(' ') << std::setw(16) << std::endl
        << buyer << std::setw(16)
        << seller
        << std::setw(0) << transaction.currentUser.type << " "
        << std::right << std::setw(7) << std::setfill('0')
        << s << std::endl;

    return;
}

void advertise(std::ofstream& out, Transaction transaction) {
    std::string username = transaction.currentUser.username;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << transaction.minBid;
    std::string s = stream.str();

    // boost::erase_all(s, ".");

    out << transaction.transactionCode 
        << " " << std::left << std::setfill(' ') << std::setw(26)
        << transaction.item.itemName
        << std::setfill(' ') << std::setw(16)
        << username
        << std::setfill('0') << std::setw(3) << transaction.daysToExpiry
        << " "
        << std::right << std::setw(7) << " "
        << s << std::endl;

    return;
}

void bid(std::ofstream& out, Transaction transaction) {
    std::string username = transaction.currentUser.username;
    std::string seller = transaction.seller.username;
    std::string buyer = transaction.buyer.username;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << transaction.minBid;
    std::string s = stream.str();

    // boost::erase_all(s, ".");

    out << transaction.transactionCode 
        << " " << std::left << std::setfill(' ') << std::setw(26) 
        << transaction.item.itemName
        << std::setfill(' ') << std::setw(16)
        << seller << std::setw(16)
        << username
        << std::right << std::setfill('0') << std::setw(7)
        << s << std::endl;

    return;
}

void Fileout::writeTransactions(std::vector<Transaction> transactions) {
    std::ofstream out("output.fout", std::ios_base::app);

    for (auto trans : transactions) {
        if (trans.transactionCode == "10" || trans.transactionCode == "00" ||
            trans.transactionCode == "01" || trans.transactionCode == "02" ||
            trans.transactionCode == "06")
            typeOne(out, trans);
        
        if (trans.transactionCode == "05")
            refund(out, trans);

        if (trans.transactionCode == "03")
            advertise(out, trans);

        if (trans.transactionCode == "04")
            bid(out, trans);
    }

    return;
}
