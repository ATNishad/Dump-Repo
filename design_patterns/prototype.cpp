#include<iostream>
using namespace std;

class prot{
    public:
    virtual ~prot() {}
    virtual prot* clone() =  0;
};

class prot1 : public prot{
    public:
    prot1(int u) : x(u){}
    virtual prot* clone() override{
        return new prot1(*this);
    }
    
    private:
    int x;
};

class prot2 : public prot{
    public:
    prot2(int u, int v) : a(u), b(v) {} 
    virtual prot* clone() override{
        return new prot2(*this);
    }
    
    private:
    int a,b;
};

int main(){
    prot2 p2(10,20);
    prot1 p1(50);
    
    prot* newp1 = p1.clone();
    prot* newp2 = p2.clone();
}