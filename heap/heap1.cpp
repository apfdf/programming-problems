#include "heap.h"

struct Node {
    int val;
    Node* p;
    Node* l;
    Node* r;
};

int siz = 0;
Node top;
Node X;

int getMax() {
    if (siz != 0) {
        return top.val;
    } else {
        return -1;
    }
}

int getSize() {
    return siz;
}

void insert(int element) {

    if (siz == 0) {
        
        top.val = element;
        top.l = &X;
        X.p = &top;

    } else {
        
        X.val = element;
        Node cur_node = X;
        
        while (cur_node.p != nullptr) {
            if (cur_node.p->val < cur_node.val) {

                int tmp = cur_node.p->val;
                cur_node.p->val = cur_node.val;
                cur_node.val = tmp;

                cur_node = *(cur_node.p);

            }
        }

    }
}

void removeMax() {

}
