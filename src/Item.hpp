class Item {
  public:
    Item(std::string name, std::string sellerName, std::string buyerName, std::string days, std::string bid);
    std::string getName();
    std::string getSeller();
    std::string getBuyer();
    std::string getDaysLeft();
    std::string getBid();
  private:
    std::string itemName;
    std::string seller;
    std::string buyer;
    std::string daysLeft;
    std::string currentBid;
};
