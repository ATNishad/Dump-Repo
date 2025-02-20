#include<iostream>
#include<vector>
using namespace std;

class strategy{
    public:
    virtual void sort(vector<int>& arr) = 0;
    virtual ~strategy() {} 
};

class bubblesort : public strategy{
    public:
    void sort(vector<int>& arr){
        cout<<"bubble sorted";
    }
};

class quicksort : public strategy{
    public:
    void sort(vector<int>& arr){
        cout<<"quick sorted";
    }
};

class context{
    private:
    strategy* strat;

    public:
    void setstrat(strategy* strat){
        this->strat = strat;
    }

    void executestrat(vector<int>& arr){
        strat->sort(arr);
    }
};

int main(){
    vector<int> arr = {3,12,6,34,11,87};
    context c;

    bubblesort bs;
    quicksort qs;

    c.setstrat(&bs);
    c.executestrat(arr);
    c.setstrat(&qs);
    c.executestrat(arr);
}