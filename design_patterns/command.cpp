#include<iostream>
using namespace std;

class receiver{
    public:
    void turnon(){
        cout<<"turned ON";
    }

    void turnoff(){
        cout<<"turned OFF";
    }
};


class command{
    public:
    virtual void execute() = 0;
    virtual ~command() {}
};

class turnoncmd : public command{
    private:
    receiver& rcv_ptr;

    public:
    turnoncmd(receiver& rec) : rcv_ptr(rec) {}
    void execute() override{
        rcv_ptr.turnon();
    }
};

class turnoffcmd : public command{
    private:
    receiver& rcv_ptr;

    public:
    turnoffcmd(receiver& rec) : rcv_ptr(rec) {}
    void execute() override{
        rcv_ptr.turnoff();
    }
};

class invoker{
    private:
    command* cmd;

    public:
    
    void setcmd(command* cmd){
        this->cmd = cmd;
    }

    void activatecmd(){
        cmd->execute();
    }
};


int main(){
    receiver receiver_obj;
    invoker invokerobj;

    command* cmd = new turnoncmd(receiver_obj);
    invokerobj.setcmd(cmd);
    invokerobj.activatecmd();
    cmd = new turnoffcmd(receiver_obj);
    invokerobj.setcmd(cmd);
    invokerobj.activatecmd();
    

}