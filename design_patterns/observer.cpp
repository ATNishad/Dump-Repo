#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

class observer{
    public:
    virtual void update() = 0;
    virtual ~observer(){}
};


class lights : public observer{
    public:
    void update() override{
        cout<<"lights on";
    }
};

class fans : public observer{
    public:
    void update() override{
        cout<<"fans on";
    }
};

class subject{
    private:
    vector<observer*> obsvec;
    int temperature;

    public:
    void addsub(observer* obs){
        obsvec.push_back(obs);
    }
    
    void unsub(observer* obs){
        obsvec.erase(remove(obsvec.begin(),obsvec.end(),obs),obsvec.end());
    }
    
    void notify(){
        for(auto obs : obsvec){
            obs->update();
        }
    }
};


int main(){
    subject S;
    observer* Lptr = new lights();
    observer* Fptr = new fans();
    S.addsub(Lptr);
    S.addsub(Fptr);
    S.notify();
    
    delete Lptr;
    delete Fptr;
}
