#include<iostream>
using namespace std;

class base_interface{
    public:
    virtual ~base_interface() {}
    virtual void method() = 0;
};

class real_obj : public base_interface{
    public:
    void method() override{
        cout<<"real object";
    }
};

class proxy : public base_interface{
    private:
    base_interface* RO_ptr = nullptr;

    public:
    proxy(base_interface* real_obj) : RO_ptr(real_obj) {}
    
    void method() override{
        RO_ptr->method();
    }
};

int main(){
    real_obj RO;
    proxy proxy_obj(&RO);
    proxy_obj.method();
}