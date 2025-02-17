#include<iostream>
using namespace std;

class target{
    public:
    virtual ~target() {}
    virtual void target_method() = 0;
};

class adaptee{
    public:
    void adaptee_method(){
        cout<<"adaptee method";
    }
};

class adapter : public target{
    private:
    adaptee& ADP;

    public:
    adapter(adaptee& a) : ADP(a) {}
    void target_method() override {
        ADP.adaptee_method();
    }
};

int main(){
    adaptee A1;

    adapter ADP(A1);
    ADP.target_method();
}