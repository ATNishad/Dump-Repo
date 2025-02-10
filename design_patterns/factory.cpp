#include<iostream>
using namespace std;

class product{
  public:
  virtual ~product(){}
  virtual string getname() = 0;
};

class product1 : public product{
    public:
    string getname() override{
        return "p1";
    }
};

class product2 : public product{
    public:
    string getname() override{
        return "p2";
    }
};

class factory{
  public:
  virtual product* makeproduct() = 0;
  virtual ~factory() {} 
};

class factory1 : public factory{
    public:
    virtual product* makeproduct(){
        return new product1;
    }
};

class factory2 : public factory{
    public:
    virtual product* makeproduct(){
        return new product2;
    }
};

void client(factory* f){
    product* P = f->makeproduct();
    cout<<P->getname();
}

int main(){
    factory* F = new factory2;
    client(F);
}
