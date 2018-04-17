#include <iostream>


class Stack {
    private:
	unsigned int top = 0; 
	unsigned int n = 0;
	int *arr;
    public:
        Stack(int n) {
	    (*this).n = n;
            (*this).arr = new int[n];
	}
 	void push(int k) {
	    if (top == n) {
		std::cout << "Stack is full!\n" <<  std::endl; 
            } else {
	        arr[top] = k;
                top++;
            }
        }
	int pop() {
            if (top == 0) {
                std::cout << "Stack is empty!\n" <<  std::endl;
	    } else {
	        int m = arr[top];
                arr[top] = 0;
	        top--;
                return m;
	    }
 	}
	bool isEmpty() {
	    if (top == 0) {
	        return false; 
            } else {
		return true;
	    }
	}
	int size() {
	    return top;
	}
	
};


int main() {


    return 0;
}
