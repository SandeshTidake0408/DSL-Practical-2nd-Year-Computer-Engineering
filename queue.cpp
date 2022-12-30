#include <iostream>
using namespace std;

class queue{
    int front, rear, size;
    int arr[];
    public:
        queue(int n){
            size = n;
            arr[size];
            front=-1;
            rear=-1;
        }
    
    bool is_empty(){
        if (rear ==-1 and front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool is_full(){
        if (rear==size-1){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        if(is_full()){
            cout<<"Queue is full";
        }
        else if (is_empty())
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }
    int dequeue(){
        int temp;
        if(is_empty()){
            cout<<"The queue is Empty";
        }
        else if (front == rear)
        {
            temp = arr[front];
            front = -1;
            rear = -1;
            return temp;
        }
        else{
            
            temp=arr[front];
            front++;
            return temp;
        }
        return -1;   
    }
    void display()
    {
        if (is_empty())
        {
            cout << "Queue Is Empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " | ";
            }
            cout << endl;
        }
    }
};


int main() {
    queue s(5);
    s.enqueue(5);
    s.enqueue(63);
    s.enqueue(56);
    s.enqueue(89);
    s.display();
    int p;
    p=s.dequeue();
    cout<<"This is deleted value "<<p<<endl;
    s.display();
    return 0;
}

































