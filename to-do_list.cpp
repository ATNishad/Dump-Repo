#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

class tasks{
private:
string name;
string task;
string due;
  
public:
//constructor
tasks(string name,string task,string due){
      this->name = name;
      this->task = task;
      this->due = due;
  }
  
//member function to remove task
static void removetask(string name,vector<tasks> &taskvec){
      for(auto itr = taskvec.begin();itr != taskvec.end();){
          if(itr->name == name){
              itr = taskvec.erase(itr);
          }
          else{
              ++itr;
          }
      }
  }
  
//member function to view all tasks.
void viewtask(){
      cout<<"Task name:"<<name<<"\n";
      cout<<"Task:"<<task<<"\n";
      cout<<"Due date:"<<due<<"\n";
  }
};

//non-member function to display menu
void menu(){
    cout<<"-----TO-DO LIST-----\n";
    cout<<"1.View list\n";
    cout<<"2.Add to list\n";
    cout<<"3.Remove from list\n";
    cout<<"4.Exit\n";
    cout<<"\n";
    cout<<"Enter your choice:";
}

int main(){
    int choice;
    vector<tasks> taskvec;
    do{
    menu();
    cin>>choice;
    cin.ignore();
    switch(choice){
        case 1:{
            if(taskvec.empty()){
                cout<<"List is empty!!\n";
                cout<<"\n";
            }
            else{
            for(auto ch : taskvec){
            ch.viewtask();
            }
            }
            break;
        }
        case 2:{
            string name;
            string task;
            string due;
            cout<<"enter task name:";
            getline(cin,name);
            cout<<"enter the task:";
            getline(cin,task);
            cout<<"enter due date(DD-MM-YYYY):";
            getline(cin,due);
            taskvec.push_back(tasks(name,task,due));
            break;
        }
        case 3:{
            cout<<"Enter task name to remove:";
            string name;
            cin>>name;
            tasks::removetask(name,taskvec);
            cout<<name<<" Removed successfully!\n";
            break;
        }
        case 4:{
            break;    
        }
        default:
        cout<<"INVALID CHOICE!\n";
    }
    }while(choice != 4);
}