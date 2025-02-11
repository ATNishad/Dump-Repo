#include<iostream>
#include<string>
#include<unordered_map>
#include<functional>
using namespace std;


enum operators{
    ADD = 1 , SUB = 2 , MUL = 3 , DIV = 4
};



class calculator{
    private:
    int x , y;
    static const unordered_map<char,operators> op_map;

    public:

    void set_val(const int& x, const int& y){
        this->x = x;
        this->y = y;
    }

    void map_operator(const char& op,int& opval){
    const unordered_map<char,operators>::const_iterator map_iterator = op_map.find(op);
    if(map_iterator != op_map.end()){
        opval = map_iterator->second;
    }
    else{
        throw invalid_argument("invalid operator");
    }
}

    void perform_operation(const int& opval){
    unordered_map<int,function<void()>> func_map = {
        {ADD, [this](){cout << this->x+ this->y;}},
        {SUB, [this]() {cout<< this->x - this->y;}},
        {MUL, [this]() {cout<<this->x * this->y;}},
        {DIV, [this]() {cout<<this->x / this->y;}}
    };

    const unordered_map<int,function<void()>>::const_iterator itr = func_map.find(opval);
    if(itr != func_map.end()){
        itr->second();
    }
    else{
        throw invalid_argument("func_map fucked up"); 
    }
    }
};

const unordered_map<char,operators>calculator:: op_map  = {
        {'+',ADD},
        {'-',SUB},
        {'*',MUL},
        {'/',DIV},
};

int main(){
    string a,b;
    char op;
    int opval;
    calculator calcobj;
    while (true){
    cout<<"\n";
    cin>>a>>op>>b; 

    calcobj.set_val(stoi(a),stoi(b));
    calcobj.map_operator(op,opval);
    calcobj.perform_operation(opval);
    }

}