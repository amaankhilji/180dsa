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

int findIntersection(Node *f, Node *s)
{
    unordered_map<Node *, int> mp;
    while (f) {
        mp[f]++;
        f = f->next;
    }
    int ans = -1;
    while (s) {
        mp[s]++;
        if (mp[s] > 1) {
            ans = s->data;
            break;
        }
        s = s->next;
    }
    return ans;

}