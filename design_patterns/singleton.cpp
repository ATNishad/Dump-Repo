#include<iostream>
#include<iterator>

class singleton{
    private:
    singleton() {}
    singleton(const singleton&) = delete;
    singleton operator=(const singleton&) = delete;
    static singleton s_instance;
    static int counter;

    public:
    static singleton& get_instance(){
        counter++;
        return s_instance;
    } 

    void get_count(){
        std::cout<<counter;
    }

};

singleton singleton::s_instance;
int singleton::counter = 0;

int main(){
    singleton::get_instance().get_count();
    singleton::get_instance().get_count();
    singleton::get_instance().get_count();
    }