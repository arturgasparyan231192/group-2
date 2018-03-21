#include <iostream>
#include <string>
int main(){
	std::string name1, name2;
	int age1;
	int age2;
	std::cout << "Hello" << std::endl;
	std::cout << "What's your name?"<< std::endl;
	std::cin >> name1;
	std::cout << "How old are you?"<< std::endl;
	std::cin >> age1;
	std::cout << "Ok, enough talking about you" << std::endl;
	std::cout << "What's your pair name?"<< std::endl;
	std::cin >> name2;
	std::cout << "How old is your pair?" << std::endl;
	std::cin >> age2;

	if(age1>age2){
		std::cout << name1 << " older than " << name2 << std::endl;
	} else if(age1<age2){
		std::cout << name2 << " older than " << name1 << std::endl;
	} else {
		std::cout << "You are of the same age" << std::endl;
	}


	return 0;
} 
