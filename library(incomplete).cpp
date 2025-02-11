#include<iostream>
#include<fstream>
using namespace std;


class library{
    private:
    string id,name,author;
    fstream file;

    private:
    void addbook();
    void removebook();
    void displayall();
};

int main(){
    char choice;
    cout<<"-------------------------------------";
    cout<<"1.Display all the books";
    cout<<"2.Add book";
    cout<<"3.Remove book";
    cout<<"4.Exit";
    cout<<"-------------------------------------";
    cout<<"Enter your choice";
    cin>>choice;

    switch(choice){
        case 1:

        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;

        default:
        cout<<"invalid choice";
    }
}

void library::addbook(){
    cout<<"enter book id";
    getline(cin,id);
    cout<<"enter book name:";
    getline(cin,name);
    cout<<"enter author name:";
    getline(cin,author);

    file.open("lib_data.txt", ios::out | ios::app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}

void library :: displayall(){
    file.open("lib_data.txt", ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n";
    cout<<"\t\t BOOK ID \t\t\t BOOK NAME \t\t\t AUTHORS NAME"<<endl;
    while(!file.eof()){
        cout<<"\t\t "<<id<<" \t\t\t "<<name <<" \t\t\t "<<author<<endl;
    }
    file.close();
}

void library:: removebook(){
    string temp;
    cout<<"enter bookid:";
    cin.ignore();
    getline(cin,temp);
}