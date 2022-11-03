/*This application take name as a input and gives a random account number. A user can deposit,withdraw or see the acount information */

#include<bits/stdc++.h>
using namespace std;

class account{
    string name;
    int acc_num;
    string type;

public:
    account(string s,int n,string t){
        name=s;
        acc_num=n;
        type=t;
    }
        void print(int x){
        cout<<"Dear "<<name<<endl<<"Your account type: "<<type<<endl<<"Your account number: "<<acc_num<<endl<<"Your balance: "<<x<<" tk "<<endl;
    }
};

class current:public account{
    int balance=0;

public:
    current(string s):account(s,rand(),"CURRENT"){}

    void deposit(int x){
        balance+=x;
        cout<<x<<"tk added successfully! New Balance is "<<balance<<"tk"<<endl;
    }

      void withdraw(int x){
        if(x<=balance){
                    balance-=x;
                    cout<<x<<"tk withdrawn successfully! New Balance is "<<balance<<"tk"<<endl;

        }

        else cout<<"Insufficient Balance!"<<endl;
    }
    void show(){
        print(balance);
    }

};


class saving:public account{
    int balance=0;

public:
    saving(string s):account(s,rand(),"SAVING"){}

    void deposit(int x){
        balance+=x;
        cout<<x<<"tk added successfully! New Balance is "<<balance<<"tk"<<endl;
    }

      void withdraw(int x){
       if(x<=balance){
                    balance-=x;
                    cout<<x<<"tk withdrawn successfully! New Balance is "<<balance<<"tk"<<endl;

        }
        else cout<<"Insufficient Balance!"<<endl;
    }
    void show(){
        print(balance);
    }

};

void options(){
cout<<"Select an Option"<<endl;
cout<<0<<". Exit"<<endl;
cout<<1<<". Deposit"<<endl;
cout<<2<<". Withdraw"<<endl;
cout<<3<<". Show"<<endl<<endl;
}


int main(){
    srand(time(0));

    cout<<"Welcome to ASFI Bank"<<endl;
    string s;
    cout<<"Please Enter Your Name"<<endl;
    getline(cin,s);
    cout<<endl;
    cout<<"Hi "<<s<<" , Select Your Account Type:"<<endl<<1<<". Current"<<endl<<2<<". Saving"<<endl;
    int t;
    cin>>t;
    system("CLS");

    if(t==1){
        current usr(s);
        usr.show();
        cout<<endl;

        while(1){
        cout<<endl<<endl;
        options();
        int o; cin>> o;

        if(o==0)break;
        else if(o==1){
            system("CLS");
            int y;
            cout<<"Enter the amount"<<endl;
            cin>>y;
            usr.deposit(y);
        }
        else if(o==2){
            system("CLS");
            int y;
            cout<<"Enter the amount"<<endl;
            cin>>y;
            usr.withdraw(y);
        }
        else if(o==3){
             system("CLS");
             usr.show();
        }
        else cout<<"Invalid option"<<endl;

        }
    }
    else {
        saving usr(s);
        usr.show();
        cout<<endl;

        while(1){
        cout<<endl<<endl;
        options();
        int o; cin>> o;

        if(o==0)break;
        else if(o==1){
            system("CLS");
            int y;
            cout<<"Enter the amount"<<endl;
            cin>>y;
            usr.deposit(y);
        }
        else if(o==2){
            system("CLS");
            int y;
            cout<<"Enter the amount"<<endl;
            cin>>y;
            usr.withdraw(y);
        }
        else if(o==3){
             system("CLS");
             usr.show();
        }
        else cout<<"Invalid option"<<endl;
        }
    }

}
