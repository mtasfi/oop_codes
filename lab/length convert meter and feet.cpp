#include<iostream>
using namespace std;

class DB;
class DM;

class DM{
    float m,cm;
public:
    DM(float mm,float cmm){
    m=mm;
    cm=cmm;
    }
     void show(){
        cout<<"meter: "<<m<<endl;
        cout<<"centimeter: "<<cm<<endl;
    }
    friend DB add(DB obj1, DM obj2);
    friend DM add(DM obj1, DB obj2);

};
class DB{
    float ft,in;
public:
    DB(float f,float i){
    ft=f;
    in=i;
    }
    void show(){
        cout<<"feet: "<<ft<<endl;
        cout<<"inch: "<<in<<endl;
    }
    friend DB add(DB obj1, DM obj2);
    friend DM add(DM obj1, DB obj2);
};

DB add(DB obj1, DM obj2){
    float ft=obj1.ft;
    float in=obj1.in;
    float m=obj2.m;
    float cm=obj2.cm;

    ft+=m/0.3048;
    in+=cm/2.54;

    DB obj(ft,in);
    return obj;
}
DM add(DM obj1, DB obj2){
    float m=obj1.m;
    float cm=obj1.cm;
    float ft=obj2.ft;
    float in=obj2.in;

    m+=ft*0.3048;
    cm+=in*2.54;

    DM obj(m,cm);
    return obj;
}

int main(){
    cout<<"Enter the length 1 in meter and centimeter"<<endl;
    int m,cm;
    cin>>m>>cm;
    cout<<"Enter the length 2 in feet and inch"<<endl;
    int ft,in;
    cin>>ft>>in;

    DM obj1(m,cm);
    DB obj2(ft,in);

    int t;
    cout<<"Select the addition Type "<<endl<<"1. Feet version"<<endl<<"2. Meter version"<<endl;
    cin>>t;

    if(t==1){
        DM obj(0,0);
        obj=add(obj1,obj2);
        obj.show();
    }
    else if(t==2){
        DB obj(0,0);
        obj=add(obj2,obj1);
        obj.show();
    }
    else cout<<"invalid!"<<endl;
}
