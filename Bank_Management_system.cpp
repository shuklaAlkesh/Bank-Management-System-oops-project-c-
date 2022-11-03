#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
using namespace std;

class Account
{
protected: // protected is used so that we can use protected member in derived class
    string customer_name;
    char type;
    int Money_deposite;
    string Address;

public:
    int account_number;
    int getAccountNo()
    {
        return this->account_number;
    }
    void Addcustomer()
    {
        cout << " Please Enter the new Account_no that you want generated :" << endl;
        cin >> account_number;
        cout << "Enter the name of the new customer : " << endl;
        fflush(stdin);
        getline(cin, customer_name);
        cout << "Enter the Address :" << endl;
        fflush(stdin);
        getline(cin, Address);
        cout << "Please Enter the type of Account (savingAccount = S),(currentAccount = C) :" << endl;
        cin >> type;
        cout << "Enter the min(10,000) Amount that you want to deposite : " << endl;
        cin >> Money_deposite;
        cout << "Account has been created succesfully" << endl;
        //sql = "INSERT INTO PERSON VALUES("+account_number+", "+customer_name+", 'GATES', 30, 'PALO ALTO', 1000.0);"
    }
    void Accept_deposite()
    {
        int x;
        cout << "Enter the Amount that you want to be add " << endl;
        cin >> x;
        Money_deposite += x;
    }

    void display_Account_detail()
    {
        cout << "Bank Account NO : " << this->account_number << endl;
        cout << "Bank Holder Name : " << this->customer_name << endl;
        cout << "Account Type : " << this->type << endl;
        cout << "Account Balance : " << this->Money_deposite << endl;
    }
};

class cur_acct : public Account
{
private:
    int check_balance;
    int penality;

public:
    int mininimum_balance()
    {
        int flag = 1;
        if (Money_deposite <= 10000)
        {
            penality = 10;
            Money_deposite = Money_deposite - penality;
            flag = 0;
        }
        else
        {
            cout << " No penality has been imposed" << endl;
        }
        return flag;
    }

    void withdrawal()
    {
        int amount;
        cout << "Enter the amount that you want withdrawn" << endl;
        cin >> amount;
        int temp = mininimum_balance();
        if (temp == 1)
        {
            if (Money_deposite >= amount)
                Money_deposite = Money_deposite - amount;
        }
        else
        {
            cout << "The amount cannot be withdrawn" << endl;
        }
    }
};
class sav_acct : public Account
{
    int total;

public:
    int compound_increment()
    {
        int time_to, rate_per;
        rate_per = 20;
        cout << " Enter the time that tou deposite money" << endl;
        cin >> time_to;
        total = Money_deposite * pow(1 + rate_per / 100.0, time_to) - Money_deposite;
        return total;
    }

    void update_balance()
    {
        Money_deposite = Money_deposite + compound_increment();
    }
    void withdrawal()
    {
        int amount;
        cout << "Enter amount that you want to withdrawn" << endl;
        cin >> amount;
        if (Money_deposite < 10000)
        {
            cout << " Warning !!! Amount is less than as per minimum requirement " << endl;
        }
        if (Money_deposite >= amount)
        {
            Money_deposite = Money_deposite - amount;
        }
        else
        {
            cout << "The amount cannot be withdrawn" << endl;
        }
    }
};

int n;
int main()
{
    cout << "Enter the type of account you want to open (Saving = S / Current = C) " << endl;
    char type;
    cin >> type;
    type = toupper(type);
    if (type == 'S')
    {
        sav_acct customer[50]; // saving Account
        while (1)
        {

            cout << "1: addcustomer " << endl;
            cout << "2: display account detail" << endl;
            cout << "3: Deposit Money" << endl;
            cout << "4: withdrawal" << endl;
            cout << "5: display All account detail" << endl;

            cout << "0: for exit " << endl;
            int opt;
            cout << "Enter the option :" << endl;
            cin >> opt;
            switch (opt)
            {
            case 1:
            {
                cout << "Enter the no of customer you want to ADD " << endl;
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    customer[i].Addcustomer();
                }
                break;
            }

            case 2:
            {
                int AC_NO;
                cout << "Enter the Account no that you want to display " << endl;
                cin >> AC_NO;
                for (int i = 0; i < n; i++)
                {
                    if (customer[i].getAccountNo() == AC_NO)
                    {
                        customer[i].display_Account_detail();
                    }
                }
                break;
            }

            case 3:
            {
                int AC_NO;
                cout << "Enter the Account no that you want to deposite " << endl;
                cin >> AC_NO;

                for (int i = 0; i < n; i++)
                {
                    if (customer[i].getAccountNo() == AC_NO)
                    {
                        customer[i].Accept_deposite();
                    }
                }
                break;
            }
            case 4:
            {
                for (int i = 0; i < n; i++)
                {
                    int AC_NO;
                    cout << "Enter the Account no that you want to Withdraw " << endl;
                    cin >> AC_NO;
                    if (customer[i].getAccountNo() == AC_NO)
                    {
                        customer[i].withdrawal();
                    }
                }
                break;
            }

            case 5:
            {
                for (int i = 0; i < n; i++)
                {
                    customer[i].display_Account_detail();
                }
                break;
            }

            case 0:
            {
                exit(0);
            }
            }
        }
    }
    else
    {
        cur_acct customer1[50]; // saving Account
        while (1)
        {

            cout << "1: addcustomer " << endl;
            cout << "2: display account detail" << endl;
            cout << "3: Deposit Money" << endl;
            cout << "4: withdrawal" << endl;
            cout << "5: display All account detail" << endl;

            cout << "0: for exit " << endl;
            int opt;
            cout << "Enter the option :" << endl;
            cin >> opt;
            switch (opt)
            {
            case 1:
            {
                cout << "Enter the no of customer you want to ADD " << endl;
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    customer1[i].Addcustomer();
                }
                break;
            }

            case 2:
            {
                int AC_NO;
                cout << "Enter the Account no that you want to display " << endl;
                cin >> AC_NO;
                for (int i = 0; i < n; i++)
                {
                    if (customer1[i].getAccountNo() == AC_NO)
                    {
                        customer1[i].display_Account_detail();
                    }
                }
                break;
            }

            case 3:
            {
                int AC_NO;
                cout << "Enter the Account no that you want to deposite " << endl;
                cin >> AC_NO;

                for (int i = 0; i < n; i++)
                {
                    if (customer1[i].getAccountNo() == AC_NO)
                    {
                        customer1[i].Accept_deposite();
                    }
                }
                break;
            }
            case 4:
            {
                for (int i = 0; i < n; i++)
                {
                    int AC_NO;
                    cout << "Enter the Account no that you want to Withdraw " << endl;
                    cin >> AC_NO;
                    if (customer1[i].getAccountNo() == AC_NO)
                    {
                        customer1[i].withdrawal();
                    }
                }
                break;
            }

            case 5:
            {
                for (int i = 0; i < n; i++)
                {
                    customer1[i].display_Account_detail();
                }
                break;
            }

            case 0:
            {
                exit(0);
            }
            }
        }
    }

    return 0;
}
