class Transcation {
public:
    bool valid = false;
private:
    std::map<std::string, std::string> transactionTypeMap = {
        {"login", "10"},
        {"logout", "00"},
        {"advertise", "03"},
        {"bid", "04"},
        {"refund", "05"},
        {"addcredit", "06"},
        {"delete", "02"},
        {"create", "01"}
    };
    
    std::string transactionType = -1;
}
