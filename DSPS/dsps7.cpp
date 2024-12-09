#include<iostream>
#define MAX 10
using namespace std;
class pizza{
public:
string type,size;
int price,count;
};
class queue{
    public:
        pizza q[MAX];
        int f=-1,r=-1;
void insert()
{
    if(r==MAX-1)
    {
        cout<<"\nOverflow";
    }
    else
    {
        pizza pz;
        cout<<"Enter size of pizza: ";
        cin>>pz.size;

        cout<<"Enter type of pizza: ";
        cin>>pz.type;

        cout<<"Enter price of pizza: ";
        cin>>pz.price;

        cout<<"Enter how many pizzas: ";
        cin>>pz.count;
        r++;
        q[r]=pz;
        if(f==-1){
            f=0;
        }
        cout<<"\nYour Order is: \nType of pizza: "<<pz.type<<"\nSize of pizza: "<<pz.size<<"\nHow many pizzas: "<<pz.count<<"\nPrice per pizza: "<<pz.price<<"\nTotal price: "<<pz.price*pz.count;
    }
}
void serve()
{
    if(f==-1)
    {
        cout<<"\nUnderflow";
    }
    else{
        cout<<"\nserving your order: \nType of pizza: "<<q[f].type<<"\nSize of pizza: "<<q[f].size<<"\nHow many pizzas: "<<q[f].count<<"\nPrice per pizza: "<<q[f].price<<"\nTotal price: "<<q[f].price*q[f].count;
        f++;
        if(f>r)
        {
            f=-1;
            r=-1;
        }
    }
}


};

int main()
{
    queue q1;
    int ch;

    do{
        cout<<"\n\nEnter your choice:\n1.place order\n2.serve order";
        cin>>ch;

        switch(ch)
        {
            case 1:
            q1.insert();
            cout<<"\nInsertion sucessful";
            break;

            case 2:
            q1.serve();
            break;

            case 3:
            cout<<"\nExiting from the code! ";
            return 0;
            break;

            default:
            cout<<"\nInvalid case!";
        }

    }while(ch!=3);



    q1.insert();
    return 0;
}
