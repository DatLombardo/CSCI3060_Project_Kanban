class Item {
  public:
    Item(std::string name, std::string sellerName, std::string buyerName, int days, float bid);
    std::string getName();
    std::string getSeller();
    std::string getBuyer();
    int getDaysLeft();
    float getBid();

  private:
    std::string itemName;
    std::string seller;
    std::string buyer;
    int daysLeft;
    float currentBid;
};
