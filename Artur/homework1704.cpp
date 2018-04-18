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
	~Stack(){
		delete arr[]
	} 
	int pop() {
            if (top == 0) {
                std::cout << "Stack is empty!\n" <<  std::endl;
	    } else {
	        return arr[top--]
	    }
 	}
	bool isEmpty() { 
		return(top==0) ;
	    }
	}
	int size() {
	    return top;
	}
	
};


int main() {
	int n;
    cin >> n;
    Stack stack(n);
    for (int i=0; i < n+1; i++) {
        stack.push(i);
    }
    Stack stack1(n);
    stack1.pop();

    return 0;
}
