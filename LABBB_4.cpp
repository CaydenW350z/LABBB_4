#include <iomanip>
#include <iostream>
#include <string>

int main() {
    char itemCode = 'A';
    int itemQuantity = 0;
    double itemPrice = 0.0;
    double totalPrice = 0.0;
    char isMember = 'n';
    std::string itemSize;
    std::string itemName;
    std::string note;

    std::cout << "--------------------- Menu ---------------------\n";
    std::cout << std::setw(12) << "Drinks" << std::setw(15) << "Small(S)" << std::setw(15)
        << "Medium(M)" << std::setw(15) << "Large(L)" << std::setw(10) << "XXL\n";
    std::cout << std::setw(12) << "Water (W)" << std::setw(15) << "$0.25" << std::setw(15)
        << "$0.50" << std::setw(15) << "$0.99" << std::setw(10) << "$1.49\n";
    std::cout << std::setw(12) << "Lean (L)" << std::setw(15) << "$9.99" << std::setw(15)
        << "$14.99" << std::setw(15) << "$19.99" << std::setw(10) << "$29.99\n";
    std::cout << std::setw(12) << "Soda (S)" << std::setw(15) << "$0.99" << std::setw(15)
        << "$1.49" << std::setw(15) << "$2.19" << std::setw(10) << "$2.99\n";
    std::cout << std::setw(12) << "Sprite (D)" << std::setw(15) << "$1.19" << std::setw(15)
        << "$1.89" << std::setw(15) << "$2.49" << std::setw(10) << "$3.15\n\n";

    std::cout << "Please make your selection using the item codes (W, L, S, D): ";
    std::cin >> itemCode;
    std::cout << "Please choose your size (S, M, L, XXL): ";
    std::cin >> itemSize;
    std::cout << "Is the customer a member? (y for yes, n for no): ";
    std::cin >> isMember;
    std::cout << "Enter the quantity of the item: ";
    std::cin >> itemQuantity;

    if (itemCode == 'W' || itemCode == 'w') {
        if (itemSize == "S" || itemSize == "s") itemPrice = 0.25;
        else if (itemSize == "M" || itemSize == "m") itemPrice = 0.50;
        else if (itemSize == "L" || itemSize == "l") itemPrice = 0.99;
        else if (itemSize == "XXL" || itemSize == "xxl") itemPrice = 1.49;
    }
    else if (itemCode == 'L' || itemCode == 'l') {
        if (itemSize == "S" || itemSize == "s") itemPrice = 9.99;
        else if (itemSize == "M" || itemSize == "m") itemPrice = 14.99;
        else if (itemSize == "L" || itemSize == "l") itemPrice = 19.99;
        else if (itemSize == "XXL" || itemSize == "xxl") itemPrice = 29.99;
    }
    else if (itemCode == 'S' || itemCode == 's') {
        if (itemSize == "S" || itemSize == "s") itemPrice = 0.99;
        else if (itemSize == "M" || itemSize == "m") itemPrice = 1.49;
        else if (itemSize == "L" || itemSize == "l") itemPrice = 2.19;
        else if (itemSize == "XXL" || itemSize == "xxl") itemPrice = 2.99;
    }
    else if (itemCode == 'D' || itemCode == 'd') {
        if (itemSize == "S" || itemSize == "s") itemPrice = 1.19;
        else if (itemSize == "M" || itemSize == "m") itemPrice = 1.89;
        else if (itemSize == "L" || itemSize == "l") itemPrice = 2.49;
        else if (itemSize == "XXL" || itemSize == "xxl") itemPrice = 3.15;
    }

    totalPrice = itemQuantity * itemPrice;

    std::cout << "Enter Cashier Note: ";
    std::cin.ignore();
    std::getline(std::cin, note);

    if (itemCode == 'W' || itemCode == 'w') {
        itemName = "Water";
    }
    else if (itemCode == 'L' || itemCode == 'l') {
        itemName = "Lean";
    }
    else if (itemCode == 'S' || itemCode == 's') {
        itemName = "Soda";
    }
    else if (itemCode == 'D' || itemCode == 'd') {
        itemName = "McDonald's Sprite";
    }

    std::cout << "\n-------------------- Store Receipt --------------------\n";
    std::cout << std::setw(12) << "Item" << std::setw(15) << "Qty" << std::setw(15)
        << "Unit Price" << std::setw(15) << "Total" << std::setw(10) << "Code\n";
    std::cout << std::setw(12) << itemName << std::setw(15) << itemQuantity << std::setw(15)
        << "$" << std::fixed << std::setprecision(2) << itemPrice << std::setw(5)
        << "$" << totalPrice << std::setw(10) << itemCode << '\n';

    if (isMember == 'y' || isMember == 'Y') {
        const double discount = 0.10;
        const double discountedPrice = totalPrice * (1.0 - discount);
        std::cout << "Member discount applied: 10%\n";
        std::cout << "Discounted price: $" << std::fixed << std::setprecision(2) << discountedPrice << '\n';
    }
    else {
        std::cout << "Total price: $" << std::fixed << std::setprecision(2) << totalPrice << '\n';
    }

    const double arkansas_state_tax = 6.5;
    const double faulkner_county_tax = 0.5;
    const double Conway_municipal_tax = 2.125;
    
    std::cout << "Cashier Note: " << note << "\n";
    std::cout << "--------------------- End of Receipt ---------------------\n";
    return 0;
}