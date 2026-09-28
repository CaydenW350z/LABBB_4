#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char itemCode = 'A';
    int itemQuantity = 0;
    double itemPrice = 0.0;
    double totalPrice = 0.0;
    char isMember = 'n';
    std::string itemSize;
    std::string itemName;
    std::string note;
    double taxedTotal = 0.0;
    double tenpercent = 0.0;

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

        const double arkansasStateTax = discountedPrice * 0.065;
        const double faulknerCountyTax = discountedPrice * 0.005;
        const double conwayMunicipaltax = discountedPrice * 0.02125;
        taxedTotal = discountedPrice + arkansasStateTax + faulknerCountyTax + conwayMunicipaltax;

        std::cout << "Member discount applied: 10%\n";
        std::cout << "Discounted price: $" << std::fixed << std::setprecision(2) << discountedPrice << '\n';
        std::cout << "State tax $" << arkansasStateTax << std::endl;
        std::cout << "County tax  $" << faulknerCountyTax << std::endl;
        std::cout << "Conway City tax $" << conwayMunicipaltax << std::endl;
        std::cout << "Total after taxes $" << taxedTotal << std::endl;
    }
    else {
        const double arkansasStateTax = totalPrice * 0.065;
        const double faulknerCountyTax = totalPrice * 0.005;
        const double conwayMunicipaltax = totalPrice * 0.02125;
        taxedTotal = totalPrice + arkansasStateTax + faulknerCountyTax + conwayMunicipaltax;

        std::cout << "State tax - " << arkansasStateTax << std::endl;
        std::cout << "County tax - " << faulknerCountyTax << std::endl;
        std::cout << "Conway City tax - " << conwayMunicipaltax << std::endl;
        std::cout << "Total after taxes $" << std::fixed << std::setprecision(2) << taxedTotal << '\n';
    }

    int tip;
    cout << "\nHow much would you like to tip?" << std::endl;
    cout << "1. 10%, 2. 15% 3. 25% 4. Custom Amount" << endl;
    cin >> tip;

    switch (tip) {
    case 1:
        tenpercent = taxedTotal * 0.1;
        cout << "10% Tip : $" << std::fixed << std::setprecision(2) << tenpercent << endl;
        cout << "Total with tip: $" << (taxedTotal + tenpercent) << endl;
        break;
    case 2:
        tenpercent = taxedTotal * 0.15;
        cout << "15% Tip : $" << std::fixed << std::setprecision(2) << tenpercent << endl;
        cout << "Total with tip: $" << (taxedTotal + tenpercent) << endl;
        break;
    case 3:
        tenpercent = taxedTotal * 0.25;
        cout << "25% Tip : $" << std::fixed << std::setprecision(2) << tenpercent << endl;
        cout << "Total with tip: $" << (taxedTotal + tenpercent) << endl;
        break;
    case 4: {
        double customTip = 0.0;
        cout << "Enter custom tip amount: $";
        cin >> customTip;
        tenpercent = customTip;
        cout << "Custom Tip : $" << std::fixed << std::setprecision(2) << tenpercent << endl;
        cout << "Total with tip: $" << (taxedTotal + tenpercent) << endl;
        break;
    }
    default:
        cout << "Invalid number. Please enter 1, 2, 3, or 4." << endl;
        break;
    }

    std::cout << "Cashier Note: " << note << "\n";
    std::cout << "--------------------- End of Receipt ---------------------\n";
    return 0;
}