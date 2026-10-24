#include<iostream>
#include<vector>
class Enemy
{
public:
	Enemy();
	~Enemy();

private:




};




int main()
{
	Enemy enmy;
   
	std::vector<int>number;
	std::vector<float>number2;

	number.push_back(10);
	number.push_back(20);
	number.push_back(30);

	std::cout << number.size() << std::endl;

	int num = number[0];
	std::cout <<  num;

	number.clear();
	return 0;
}

