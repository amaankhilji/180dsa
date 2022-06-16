#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{   Node *prev = NULL;
    Node *root = head1;
    int carry = 0;
    while (head1 && head2) {
        int x = carry + head1->data + head2->data;
        //cout<<x<<"\n";
        head1->data = x % 10;
        carry = x / 10;
        prev = head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL) {
        if (carry > 0) {
            Node* newnode = new Node(carry);
            prev->next = newnode;
            prev = prev->next;
        }
    }

    if (head1) {
        while (head1) {
            int x = carry + head1->data;
            head1->data = x % 10;
            carry = x / 10;
            prev = head1;
            head1 = head1->next;
        }
        if (carry > 0) {
            Node* newnode = new Node(carry);
            ;
            head1->next = newnode;

        }

    }
    if (head2) {
        while (head2) {
            int x = carry + head2->data;
            Node* newnode = new Node(x % 10);

            prev->next = newnode;

            carry = x / 10;

            prev = prev->next;
            head2 = head2->next;
        }
        if (carry > 0) {
            Node* newnode1 = new Node(carry);

            head1->next = newnode1;

        }
    }
    return root;
}