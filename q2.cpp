/*
    QUESTION FROM LAB
*/

#include <iostream>
#include <ctime>
#include <string>
#define MENU_MAX 10
#define TABLE_MAX 5

using namespace std;

class Food
{
public:
    string dishName;
    int price;

    void addFood(string dn, int p)
    {
        dishName = dn;
        price = p;
    }
};

class TableInfo
{
public:
    int TableNo, menuIndex;
    Food Menu[MENU_MAX];

    TableInfo()
    {
        TableNo = time(0);
        // For unique TableNo
        menuIndex = 0;
    }

    void addMenuItem(Food f)
    {
        Menu[menuIndex] = f;
        menuIndex++;
    }
};

class BillAmount : public TableInfo
{
public:
    float netAmount, VAT, serviceCharge, grossAmount;

    BillAmount()
    {
        netAmount = 0;
    }

    float getGrossAmount()
    {
        for (int i = 0; i < menuIndex; i++)
        {
            netAmount += Menu[i].price;
        }
        VAT = 0.13 * netAmount;
        serviceCharge = 0.1 * netAmount;
        grossAmount = netAmount + VAT + serviceCharge;
        return grossAmount;
    }
};

int main()
{
    BillAmount tables[TABLE_MAX];
    string tempName;
    int tempPrice, menuLength;
    Food tempFood;
    float tempGross;
    // Getting Input
    for (int i = 0; i < TABLE_MAX; i++)
    {
        cout << "For table no:" << i + 1 <<"\n\n"<< endl;
        cout << "Enter no. of menu items: " << endl;
        cin >> menuLength;
        for (int j = 0; j < menuLength; j++)
        {
            cout << "Menu item" << j+1 << endl;
            cout << "Enter name of food: " << endl;
            cin >> tempName;
            cout << "Enter price of food: " << endl;
            cin >> tempPrice;
            tempFood.addFood(tempName, tempPrice);
            tables[i].addMenuItem(tempFood);
        }
    }

    // Printing Final Data
    cout << "SN\tNetAmt\tVAT\tServiceCharge\tGrossAmount"<<endl;
    for(int k=0; k<TABLE_MAX; k++){
        tempGross = tables[k].getGrossAmount();
        cout<<k+1<<"\t"<<tables[k].netAmount<<"\t"<<tables[k].VAT<<"\t"<<tables[k].serviceCharge<<"\t"<<tempGross<<endl;
    }

    return 0;
}