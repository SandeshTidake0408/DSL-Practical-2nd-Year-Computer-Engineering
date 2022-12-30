#include <iostream>
using namespace std;
class deque{
    
    int front, rear, size;
    int arr[];
    public:
    deque(int length){
        
        size = length;
        arr[size];
        front = -1;
        rear = -1;
    }
     bool Is_empty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    bool Is_full()
    {
        if ((front==0 && rear == size - 1) || (front==rear+1))
            return true;
        else
            return false;
    }
    void enque_rear(int data)
    {
        if (Is_full())
        {
            cout << "\nQueue Is Full !!" << endl;
        }
        else if (Is_empty())
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if (rear==size -1)
        {
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }
    void enque_front(int data){
        if (Is_full())
        {
            cout << "\nQueue Is Full !!" << endl;
        }
        else if (Is_empty())
        {
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else if (front==0)
        {
            front = size-1;
            arr[front] = data;
        }
        else{
            front--;
            arr[front]=data;
        }

    }

    void dqueue_front()
    {
        if (Is_empty())
        {
            cout << "\nQueue Is Empty " << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    void dqueue_rear()
    {
        int temp;
        if (Is_empty())
        {
            cout << "\nQueue Is Empty " << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if(rear==0){
            rear = size-1;
        }
        else
        {
            rear--;
        }
    }
    void display(){
        if (Is_empty())
        {
            cout << "\nQueue Is Empty" << endl;
        }
        else
        {   
            int i = front;
            while (i != rear)
            {
                cout<<arr[i]<<" ";
                i = (i+1)%size;
            }
            cout<<arr[rear]<<endl;  
        }
    }

};

int main()
{
    int capacity;
    cout << "Enter the Size Of queue : ";
    cin >> capacity;
    deque obj(capacity);
    obj.enque_rear(21);
    obj.enque_rear(56);
    obj.enque_front(4);
    obj.enque_rear(14);
    obj.enque_rear(18);
    obj.display();
    obj.dqueue_rear();
    obj.enque_front(5);
    obj.display();
    obj.dqueue_front();


    obj.display();
    return 0;
}