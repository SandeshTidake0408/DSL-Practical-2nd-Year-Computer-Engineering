#include <iostream>
using namespace std;

class circular
{

    int front, rear, size;
    int arr[];

public:
    circular(int n)
    {
        front = -1;
        rear = -1;
        size = n;
        arr[size];
    }
    bool is_empty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_full()
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void en(int data)
    {
        if (is_full())
        {
            cout << "\nThe Circular Queue is FUll\n";
        }
        else if (is_empty())
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }
    int de()
    {
        int temp;
        if (is_empty())
        {
            return -1;
        }
        else if (front == rear)
        {
            temp = arr[front];
            front = -1;
            rear = -1;
            return temp;
        }
        else
        {
            temp = arr[front];
            front = (front + 1) % size;
            return temp;
        }
    }

    void display()
    {
        if (is_empty())
        {
            cout << "\nThe Queue is Empty";
        }
        else
        {
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main()
{
    int hold;
    circular obj(5);
    obj.en(45);
    obj.en(12);
    obj.en(74);
    obj.en(36);
    obj.en(37);
    obj.display();
    obj.en(89);
    hold = obj.de();
    cout << "Deleted : " << hold << endl;
    obj.display();

    return 0;
}
