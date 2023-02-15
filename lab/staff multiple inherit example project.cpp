#include <iostream>
using namespace std;

class staff{
    int code;
    string name;
public:
    staff(int c,string n){
    code=c;
    name=n;
    }
    friend class teacher;
    friend class officer;
    friend class typist;
    friend class regular;
    friend class casual;
};

 class education{
    int edu_lvl;
public:
    education(int e){
    edu_lvl=e;
    }
    friend class teacher;
    friend class officer;
 };

 class teacher:public staff, public education{
    string subject, publication;
public:
    teacher(int c,string n,int e,string s,string p):staff(c,n),education(e){
    subject=s;
    publication=p;
    }
     void show(){
    cout<<"Name: "<<name<<endl
    <<"Code: "<<code<<endl
    <<"Education: "<<edu_lvl<<endl
    <<"Subject: "<<subject<<endl
    <<"Publication: "<<publication<<endl;
    }
 };

 class officer:public staff, public education{
    int grade;
public:
    officer(int c,string n,int e,int g):staff(c,n),education(e){
    grade=g;
    }
     void show(){
    cout<<"Name: "<<name<<endl
    <<"Code: "<<code<<endl
    <<"Education: "<<edu_lvl<<endl
    <<"Grade: "<<grade<<endl;
    }
 };

 class typist:public staff{
    int speed;
public:
    typist(int c,string n,int s):staff(c,n){
    speed=s;
    }
    friend class regular;
    friend class casual;
 };

 class regular:public typist{
    string worktime="Daily";
public:
    regular(int c,string n,int s):typist(c,n,s){}
    void show(){
    cout<<"Name: "<<name<<endl
    <<"Code: "<<code<<endl
    <<"Speed: "<<speed<<endl
    <<"Worktime: "<<worktime<<endl;
    }
 };

  class casual:public typist{
    string worktime="Weekly";
public:
    casual(int c,string n,int s):typist(c,n,s){}
     void show(){
    cout<<"Name: "<<name<<endl
    <<"Code: "<<code<<endl
    <<"Speed: "<<speed<<endl
    <<"Worktime: "<<worktime<<endl;
    }
 };


int main(){
cout<<"Enter the type of the employee"<<endl;
cout<<1<<":  Teacher"<<endl
<<2<<": Officer"<<endl
<<3<<": Regular Typist"<<endl
<<4<<": Weekly Typist"<<endl;

int t; cin>>t;

if(t==1){
    cout<<"Enter name"<<endl;
    string n; cin>>n;
    cout<<"Enter Code"<<endl;
    int c; cin>>c;
    cout<<"Enter Education"<<endl;
    int e; cin>>e;
    cout<<"Enter subject"<<endl;
    string s; cin>>s;
    cout<<"Enter publication"<<endl;
    string p; cin>>p;

    teacher obj(c,n,e,s,p);
    obj.show();
}
else if(t==2){
    cout<<"Enter name"<<endl;
    string n; cin>>n;
    cout<<"Enter Code"<<endl;
    int c; cin>>c;
    cout<<"Enter Education"<<endl;
    int e; cin>>e;
    cout<<"Enter grade"<<endl;
    int g; cin>>g;

    officer obj(c,n,e,g);
    obj.show();
}
else if(t==3){
    cout<<"Enter name"<<endl;
    string n; cin>>n;
    cout<<"Enter Code"<<endl;
    int c; cin>>c;
    cout<<"Enter Speed"<<endl;
    int s; cin>>s;

    regular obj(c,n,s);
    obj.show();
}
else if(t==4){
    cout<<"Enter name"<<endl;
    string n; cin>>n;
    cout<<"Enter Code"<<endl;
    int c; cin>>c;
    cout<<"Enter Speed"<<endl;
    int s; cin>>s;

    casual obj(c,n,s);
    obj.show();
}
else cout<<"Invalid!"<<endl;

}
