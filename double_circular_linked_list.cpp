#include <iostream>
#include<string>
using namespace std;

class node
{   public:
    node *prev;
    node *next;
    int data;
    int seat;
    string id;

    node(){
        prev=NULL;
        next=NULL;
        data = 0;
        seat = 0;
        id = "";
    }
};


class cinemax {
    public:
    void create(node *&head){
        node * temp1;
        node * temp2;
        node *n= new node();
        head = n;
        n->data=1;
        temp2=n;
        for (int i=2; i<=71; i++){
            temp1 = new node();
            temp2->next=temp1;
            temp1->prev=temp2;
            temp1->data=i;
            temp2=temp1;
        }
        head->prev=temp1;
        temp1->next=head;
    }

    void display(node *& head){
        node* temp =head;
        cout<<"\n############################### Screen This Way #############################"<<endl<<endl;
        while (temp->next != head){
            cout<<"[ "<<temp->data<<" | "<<temp->seat<<" ]"<<" ";
            if ((temp->data)%7==0){
                cout<<endl<<endl;
            }
            temp=temp->next;
        }
    }

    void book(node *&head, int n, string check){
        node * temp = head;
        if (n <=70){
            for(int i =1; i<n; i++){
                temp=temp->next;
            }
            if (temp->seat==0){
                temp->id=check;
                temp->seat=1;
                cout<<"\nBooking Confirmed\n";
            }
            else{
                cout<<"\nSeat is Already Booked, choose another !!\n";
            }
        }
        else{
            cout<<"\nInvalid Entry !!\n";
        }


    }
    void cancel(node *&head, int n, string check){
        node *temp=head;
        if (n <=70){
            for(int i =1; i<n; i++){
                temp=temp->next;
                }
            if (temp->seat==1){
                if(temp->id==check){
                    temp->seat=0;
                    cout<<"\nSeat Cancelled Successfully !!\n";
                }
                else{
                    cout<<"Enter the Correct Id \n";
                }
                
            }
            else{
                cout<<"\nSeat is Already Empty,first You need to book seat !!\n";
            }
            
        }   
        else{
            cout<<"\nInvalid Entry !!\n";
        }
    }   
    

};

int main(){
    cinemax obj;
    node *head = NULL;
    obj.create(head);
    // obj.display(head);
    int choice;
    char ch;
    string id;
    int no;
    cout<<"Instructions : \n[Seat no. | Status ]\nIf Status = 1 then seat is booked otherwise Empty"<<endl;

    do{
        cout<<"\nWelcome To Cinemax Please Enter Your Chice :\n1) Book Seat\n2) Cancel Seat"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            obj.display(head);
            cout<<"Enter Seat no. For booking  and your id :";
            cin>>no>>id;
            obj.book(head,no,id);
            obj.display(head);
            break;
        case 2:
            cout<<"Choice "<<choice<<endl;
            obj.display(head);
            cout<<"Enter your Seat no. for cancelation and your id :";
            cin>>no>>id;
            obj.cancel(head,no,id);
            obj.display(head);

            break;
        default:
            break;
        }
        cout<<"Do You Want to Continue [y/n] : "<<endl;
        cin>>ch;
        if (ch == 'n'){break;}
    }while(ch='y');
    return 0;
}