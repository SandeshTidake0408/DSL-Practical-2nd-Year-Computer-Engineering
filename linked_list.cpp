#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int val)
        {
            data = val;
            next = NULL;
        }
};

class Pinaccle
{
public:
    void insert_data(node *&head)

    {
        int val;
        int ch;
        int tra;
        cout << "\n1] Insert at Start\n2] Insert at Position\n3] Insert at End" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        if (ch <= 3)

        {
            node *temp = head;

            if (head == NULL)
            {
                cout << "Enter the data : ";
                cin >> val;
                node *n = new node(val);
                head = n;
            }
            else
            {
                switch (ch)
                {
                case 1:
                {
                    cout << "Enter the data : ";
                    cin >> val;
                    node *n = new node(val);
                    n->next = head;
                    head = n;
                    break;
                }
                case 2:
                {
                    cout << "\nEnter the postion at which you want to insert : ";
                    cin >> tra;
                    cout << "Enter the data : ";
                    cin >> val;
                    node *n = new node(val);
                    for (int i = 1; i < tra - 1; i++)
                    {
                        temp = temp->next;
                    }
                    n->next = temp->next;
                    temp->next = n;
                    break;
                }
                case 3:
                {
                    cout << "Enter the data : ";
                    cin >> val;
                    node *n = new node(val);
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = n;
                    break;
                }
                } 
            }
        }

        else
            cout << "\nERROR : Enter the Correct Choice" << endl;
    }

    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)

        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }

    void delete_at_index(node *&head)
    {

        cout << "\n1. Delete the first node.\n2. Delete at index.\n3. Delete the last node\n";
        cout << "\nEnter your choice : ";
        int ch;
        cin >> ch;
        node *temp = head;
        switch (ch)
        {
        case 1:
        {
            head = temp->next;
            free(temp);
            cout << "\nNode Deleted Successfully" << endl;
            break;
        }
        case 2:
        {
            int index;
            cout << "\nEnter the Index which you want to delete : ";
            cin >> index;
            node *val;
            for (int i = 1; temp != NULL && i < index - 1; i++)
            {
                temp = temp->next;
            }
            val = temp->next->next;
            free(temp->next);
            temp->next = val;
            free(val);
            cout << "\nNode Deleted Successfully" << endl;
            break;
        }
        case 3:
        {
            node *last_add;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            last_add = temp->next;
            temp->next = NULL;
            free(last_add);
            cout << "\nNode Deleted Successfully" << endl;
            break;
        }
        default:
        {
            break;
        }
        }
    }

    void Reverse_ll(node *&head)
    {
        node *prev = NULL;
        node *current = head;
        node *nest = NULL;
        while (current != NULL)
        {
            /* code */
            nest = current->next;
            current->next = prev;
            prev = current;
            current = nest;
        }
        head = prev;
    }

    void len_ll(node *&head)
    {
        int i = 0;
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        cout << "Length :" << i + 1 << "\n";
    }
    void concatenate(node *&head1, node *&head2)
    {
        node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
    }
};

int main()

{

    node *head1 = NULL;
    node *head2 = NULL;
    char choice, val;
    Pinaccle obj, obj2;
    while (true)
    {
        cout << "\nChoose Operation\n1.Insertion Of Node.\n2.Deletion Of Node.\n3.Reverse The Linked List.\n4.Check Length Of Linked List.\n5.Concatenate \n6.Exit Program.";
        cout << "\nEnter your Choice : ";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            do
            {
                obj.insert_data(head1);
                obj.display(head1);
                cout << "\nDo you want to Continue Insertion (y/n) : ";
                cin >> val;
            } while (val == 'y');
            break;
        case 2:
            do
            {
                obj.delete_at_index(head1);
                obj.display(head1);
                cout << "\nDo you want to Continue Deletion (y/n) : ";
                cin >> val;
            } while (val == 'y');
            break;
        case 3:
            obj.Reverse_ll(head1);
            cout << "\nReversed Succesful." << endl;
            obj.display(head1);
            break;
        case 4:
            obj.len_ll(head1);
            obj.display(head1);
            break;
        case 5:
            cout << "\nEnter data To create another ll: ";
            do
            {
                obj2.insert_data(head2);
                obj2.display(head2);
                cout << "\nDo you want to Continue Insertion (y/n) : ";
                cin >> val;
            } while (val == 'y');
            obj2.concatenate(head1, head2);
            obj2.display(head1);
            break;
        case 6:
            return 0;
        default:
            cout << "\nWarning :- Wrong Input !!!!";
        }
    }
    return 0;
}
