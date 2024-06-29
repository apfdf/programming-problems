#include "heap.h"

#include <bits/stdc++.h>
using namespace std;

vector<int> heap;

int p_index(int i) {
    return (i-1) / 2;
}

int l_index(int i) {
    return 2*i+1;
}

int getMax(){
    if (heap.size() != 0) {
        return heap[0];
    } else {
        return -1;
    }
}

int getSize(){
    return heap.size();
}

void insert(int element){

    heap.reserve(heap.size()+1);
    heap.push_back(element);

    int i = heap.size()-1;
    while (i != 0) {
        int pi = p_index(i);
        if (heap[pi] < heap[i]) {
            int temp = heap[pi];
            heap[pi] = heap[i];
            heap[i] = temp;
            i = pi;
        } else {
            break;
        }
    }

}

void removeMax(){

    heap[0] = heap[heap.size()-1];
    heap.pop_back();

    int i = 0;

    while (true) {

        int l = l_index(i);
        int r = l+1;

        if (l >= heap.size()) {
            break;
        }

        int swap = (heap[l] > heap[r]) ? l : r;

        if (heap[swap] < heap[i]) {
            break;
        }

        int temp = heap[swap];
        heap[swap] = heap[i];
        heap[i] = temp;

    }


}

