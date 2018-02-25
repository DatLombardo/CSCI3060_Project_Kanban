transmap = { "advertise": 05, "bid": 2 };

transaction::transaction(std::string input) {
    // check and see if transaction input is valid
    
    if (transmap.contains(input)) // whatever
    
    // if it is, call respective transaction function to gather input
    
    if (input == "advertise") {
        createAdvertiseTrans();
        
        
    }
}

void createAdvertiseTransaction() {
    // gather input
}
