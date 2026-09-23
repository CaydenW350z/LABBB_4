#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    char itemCode;
    int itemQuantity = 0;
    double unitPrice = 0.0;
    char isMember = 'n';
    string itemName;
    string note;

    cout << "Is the customer a member? (y for yes, n for no): ";
    cin >> isMember;
    cout << "Name of the item: ";
    cin >> itemName;
    cout << "Enter the item code (A, B, C, D): ";
    cin >> itemCode;
    cout << "Enter the quantity of the item: ";
    cin >> itemQuantity;
    cout << "Enter the unit price of the item: ";
    cin >> unitPrice;
    cout << "Enter Cashier Note: ";
    cin.ignore();
    getline(cin, note);
    double totalPrice = itemQuantity * unitPrice;

    cout << setw(35) << "--------------------Store Receipt -----------------" << endl;
    cout << setw(35) << "------------------------------------------------------" << endl;
    cout << setw(10) << "Item Quantity" << setw(15) << "Unit Price" << setw(20) << "Total Price" << setw(25) << "Item Code" << endl;
    cout << setw(10) << itemQuantity << setw(15) << unitPrice << setw(20) << "$" << fixed << setprecision(2) << totalPrice << setw(20) << itemCode << endl;
    if (isMember == 'y' || isMember == 'Y') {
        double discount = 0.10; // 10% discount for members
        double discountedPrice = totalPrice * (1.0 - discount);
        cout << "             " << endl;
        cout << setw(45) << "Discounted price for members: $" << discountedPrice << endl;
    }
    else {
        cout << setw(25) << "Item Code: " << itemCode << endl;
        cout << fixed << setprecision(2);
        cout << setw(25) << "Total price: $" << totalPrice << endl;

    }
    cout << setw(15) << "------------End of Receipt -----------------" << endl;
    cout << setw(5) << "Item" << setw(15) << "# of Items " << setw(18) << " Price per unit " << setw(20) << "Total in inventory" << setw(20) << "Item Code" << endl;
 
    cout << setw(5) << itemName << setw(10) << itemQuantity << setw(15) << unitPrice << setw(20) << "$" << fixed << setprecision(2) << totalPrice << setw(20) << itemCode << endl;
    return 0;
}