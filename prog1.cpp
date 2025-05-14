// Banking System

#include<iostream>
using namespace std;

class BankAccount{
    public:
            long int acc_no;
            string holder_name;
            double balance;
            double deposit_amount;
            double withdraw_amount;
            string account_type;
    
    public:
        void  setAccount()
        {
            cout<<"Enter Account Number: ";
            cin>>acc_no;
            if(acc_no <= 0)
            {
                cout<<"Account no shoulde be positive"<<endl;
                cout<<"Please enter valid account no ";
                cin>>acc_no;
            }

            cout<<"Enter Account Holder Name: ";
            cin>>holder_name;

            cout<<"Enter Account Type (Saving Account Enter : S, Current Account Enter : C, Fixed Deposit Account Enter :F ) :- ";
            cin>>account_type;

            if(account_type == "S" || account_type == "C" || account_type == "F")
            {
                cout<<"Enter Account Balance: ";
                cin>>balance;

                if(balance <= 0)
                {
                    cout<<"Account Balance Should be positive"<<endl;
                    cout<<"Please enter a valid acclont balance :- ";
                    cin>>balance;
                }

            }
            else
            {
                cout<<endl<<"Wrong Input ";
            }

            if(account_type =="S")
            {
                cout<<endl<<"Saving Account Succesfully Created."<<endl;
            }
            else if(account_type =="C")
            {
                cout<<endl<<"Current Account Succesfully Created."<<endl;
            }
            else if(account_type =="F")
            {
                cout<<endl<<"Fixed Deposit Account Succesfully Created."<<endl;
            }
            
        }

        void deposit()
        {
            cout<<endl;
            cout<<"Enter Deposit Amount: ";
            cin>>deposit_amount;

            if(deposit_amount <0)
            {
                cout<<"Deposit Amount Should Be Positive "<<endl;
                cout<<"Please Enter a Valid Deposit Amount :-";
                cin>>deposit_amount;
            }  
            balance = balance + deposit_amount;
        }

        void withdraw()
        {
            cout<<"Enter Withdraw Amount: ";
            cin>>withdraw_amount;

            if (withdraw_amount <= 0)
            {
                cout<<"Withdraw Amount Must be positive or greater than 0"<<endl;
                cout<<"Please Enter A Valid Withdraw Amount :- ";
                cin>>withdraw_amount;
            }
        }

        double getBalance()
        {
            return balance;
        }

        void displayAccountInfo()
        {   
            cout<<endl;
            cout<<endl;
            cout<<"Account Number: "<<acc_no<<endl;
            cout<<"Account Holder Name: "<<holder_name<<endl;
            cout<<"Account Balance: "<<balance<<endl;
        }
}; 

class SavingsAccount: public BankAccount{
    private: 
        double intesret_rate;

    public:
        double interest_rate;

        void calculateInterest()
        {
             intesret_rate= (balance * 0.05 ) / 100;
             cout<<"Your bank is providing "<<intesret_rate<<"of money"<<endl;
        }
};

class CheckingAccount: public BankAccount{
    public:
        void checkOverdraft()
        {

        }
};

class FixedDepositAccount: public BankAccount{
    public:
        int term;
        double fixed_deposit_interest=0.15;
        double interest;

        void calculateInterest()
        {
            cout<<"Enter Time Duration in months :- ";
            cin>>term;

            fixed_deposit_interest= (balance * 0.02);
            interest = (balance * fixed_deposit_interest) * term;
            cout<<endl;

            cout<<"Your Bank Will provide "<<fixed_deposit_interest<<"Rupees of Interest in "<< term <<" Months."<<endl;
            cout<<endl;
        }
};

int main()
{
    BankAccount obj;
    obj.setAccount();

    SavingsAccount obj2;
    CheckingAccount obj3;
    FixedDepositAccount obj4;

    int choice;
    cout<<endl << "Welcome " << endl;

    do
    {
        cout<<"Press 1 for deposit / withraw or account details: "<<endl;
        cout<<"Press 2 for Saving Account "<<endl;
        cout<<"Press 3 for Over draft Checking"<<endl;
        cout<<"Press 4 for FD"<<endl;
        cout<<"Press 0 to Exit"<<endl;
        cout<<"Enter Your Choice :-";
        cin>>choice;

        switch(choice)
        if(obj.account_type == "S")
        {
            case 0:
                cout<<"Program Is Successfully Exited "<<endl;
                break;
            case 1:
                int choice_1;
                do
                {
                    cout<<endl;
                    cout<<"Press 1 to Deposit :"<<endl;
                    cout<<"Press 2 to Witdraw:"<<endl;
                    cout<<"Press 3 to check Balance"<<endl;
                    cout<<"Press 4 for Account Details"<<endl;
                    cout<<"Enter Your Choice"<<endl;
                    cin>>choice_1;

                    switch(choice_1)
                    {
                        case 1:
                            obj.deposit();
                            break;
                        case 2:
                            obj.withdraw();
                            break;
                        case 3:
                            obj.getBalance();
                            break;
                        case 4:
                            obj.displayAccountInfo();
                            break;
                    }
                } while (choice_1= 0);   

            case 2:
                int choice_2;
                do
                {
                    cout<<endl;
                    cout<<"Welcome To Saving Account Service "<<endl;
                    cout<<"Press 1 to Deposit :"<<endl;
                    cout<<"Press 2 to Witdraw:"<<endl;
                    cout<<"Press 3 to check Balance"<<endl;
                    cout<<"Press 4 for Account Details"<<endl;
                    cout<<"Enter Your Choice :";
                    cin>>choice_2;
                     switch(choice_2)
                    {
                        case 1:
                            obj.deposit();
                            break;
                        case 2:
                            obj.withdraw();
                            break;
                        case 3:
                            cout<<"Your Current balance  is :"<<obj.getBalance();
                            break;
                        case 4:
                            obj.displayAccountInfo();
                            break;
                    }
                } while (choice_2 !=0);                
        }
    }while (choice != 0);
    return 0;
}


