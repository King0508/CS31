#include <iostream>
#include <string>
#include <cassert>
#include "Retailer.h"
#include "GiftCard.h"
using namespace std; 
int main()
{
    // sample test code working with GiftCard and Retailer
    GiftCard card("Amazon", 100.00);
    Retailer r("Apple Store");

    assert(std::to_string(card.getAmount()) == "100.000000");
    assert(card.getRetailer() == "Amazon");
    assert(card.isEmpty() == false);
    assert(card.canBeUsedToPurchase(200.00) == false);
    assert(card.canBeUsedToPurchase(10.00));
    card.empty();
    assert(card.canBeUsedToPurchase(10.00) == false);

    card.setAmount(100.00);
    assert(r.getName() == "Apple Store");
    assert(r.purchaseItem("Air Tags", 49.00, card) == false);
    assert(r.returnItem("Apple Pencil", 99.00, card) == false);
    GiftCard card1("Apple Store", 100.00);
    GiftCard card2("Apple Store", 100.00);

    assert(r.purchaseItem("Air Pods", 99.00, card1) == true);
    assert(std::to_string(card1.getAmount()) == "1.000000");
    assert(r.returnItem("Air Pods", 99.00, card1) == true);
    assert(std::to_string(card1.getAmount()) == "100.000000");
    assert(r.purchaseItem("Apple Watch", 189.00, card1, card2) == true);
    assert(card1.isEmpty());
    assert(std::to_string(card2.getAmount()) == "11.000000");

    cout << "all tests passed!" << endl;

    GiftCard card3("Apple", 200.0);
    Retailer r1("Apple"); 
    assert(std::to_string(card3.getAmount()) == "200.000000");
    assert(card3.getRetailer() == "Apple");
    assert(card3.isEmpty() == false);
    assert(card3.canBeUsedToPurchase(200.00) == true);
    assert(r1.purchaseItem("Air Pods", 99.00, card3) == true);
    assert(card3.getAmount() == 101.0);

    GiftCard test1("Amazon", 1000);
    Retailer rtest1("Apple");
    assert(std::to_string(test1.getAmount()) == "1000.000000");
    assert(test1.getRetailer() == "Amazon");
    assert(test1.isEmpty() == false);
    assert(test1.canBeUsedToPurchase(200.00) == true);
    assert(rtest1.purchaseItem("Air Pods", 99.00, test1) == false);
    assert((test1.getAmount() == 101.0) == false);

    GiftCard test2("target", 100);
    GiftCard test21("target", 200);
    Retailer rtest2("target");
    assert(rtest2.purchaseItem("cake", 99.00, test2) == true);
    assert(std::to_string(test2.getAmount()) == "1.000000");
    assert(rtest2.returnItem("Air Pods", 99.00, test2) == true);
    assert(std::to_string(test2.getAmount()) == "100.000000");
    assert(rtest2.purchaseItem("Apple Watch", 189.00, test2, test21) == true);
    assert(card1.isEmpty());
    assert(std::to_string(test21.getAmount()) == "111.000000");

    GiftCard test3("target", 100);
    GiftCard test31("target", 200);
    Retailer rtest3("Amazon"); 
    assert(rtest3.purchaseItem("cake", 99.00, test3) == false);
    assert(std::to_string(test3.getAmount()) == "100.000000");
    assert(rtest3.returnItem("Air Pods", 99.00, test3) == false);
    assert(std::to_string(test3.getAmount()) == "100.000000");
    assert(rtest3.purchaseItem("Apple Watch", 189.00, test3, test31) == false);
    assert(test3.isEmpty() == false);
    assert(std::to_string(test31.getAmount()) == "200.000000");
 
    assert(rtest2.purchaseItem("cake", -1.0, test3) == false); 
    assert(test3.getAmount() == 100);

    assert(rtest2.purchaseItem("cake", -1.0, test3, test31) == false);
    assert(test3.getAmount() == 100);
    assert(test31.getAmount() == 200); 


    return(0);
}

