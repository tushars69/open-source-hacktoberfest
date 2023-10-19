#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class NStacks {
private:
    int numStacks; // Number of stacks
    int stackSize; // Size of each stack
    vector<int> stackData; // Data storage for all stacks
    vector<int> stackTops; // Top index of each stack

public:
    NStacks(int n, int size) {
        numStacks = n;
        stackSize = size;
        stackData.resize(numStacks * stackSize);
        stackTops.resize(numStacks, -1);
    }

    bool isFull(int stackNum) {
        return stackTops[stackNum] == stackSize - 1;
    }

    bool isEmpty(int stackNum) {
        return stackTops[stackNum] == -1;
    }

    void push(int stackNum, int data) {
        if (isFull(stackNum)) {
            throw overflow_error("Stack is full.");
        }
        stackTops[stackNum]++;
        int index = stackNum * stackSize + stackTops[stackNum];
        stackData[index] = data;
    }

    int pop(int stackNum) {
        if (isEmpty(stackNum)) {
            throw underflow_error("Stack is empty.");
        }
        int index = stackNum * stackSize + stackTops[stackNum];
        int data = stackData[index];
        stackTops[stackNum]--;
        return data;
    }
};

int main() {
    int numStacks = 3;
    int stackSize = 3;
    NStacks stacks(numStacks, stackSize);

    stacks.push(0, 1);
    stacks.push(0, 2);
    stacks.push(0, 3);
    stacks.push(1, 4);
    stacks.push(2, 5);

    cout << "Pop from stack 0: " << stacks.pop(0) << endl;
    cout << "Pop from stack 1: " << stacks.pop(1) << endl;
    cout << "Pop from stack 2: " << stacks.pop(2) << endl;

    return 0;
}
