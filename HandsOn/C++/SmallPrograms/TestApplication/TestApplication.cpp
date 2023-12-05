// TestApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

class Friend
{
public:
	std::vector<Friend*> friends;
	int V;

	Friend(std::string email)
	{
		this->email = email;
		V = StringToIntegerHash(this->email);
		
	}

	int StringToIntegerHash(string str)
	{
		long randomizer = 100;

		std::cout << "Enter a string: ";
		// std::getline(std::cin, myString);

		// Converts each character of string into an integer
		// and adds them together
		for (int i = 0; i < str.size(); i++)
		{
			randomizer += str[i];
		}

		// Make our number a little bit more unique
		randomizer *= 3.1415;
		randomizer += str.size() * (int)str[0];
		randomizer *= (int)str[str.size() - 1];
		return randomizer;
	}

	void addFriendship(Friend* target)
	{
		friends.push_back(target);
		target->friends.push_back(this);
		int targetV = StringToIntegerHash(this->email);
		this->friends[V][targetV] = 1;
	}

	bool canBeConnected(Friend* target)
	{
		// throw std::logic_error("Waiting to be implemented");
		if (this->email == target->email) {
			return true;
		}

		// Use Floyd Warshall algorithm
		// to detect if a path exists
		for (int k = 1; k <= V; k++) {

			// Try every vertex as an
			// intermediate vertex
			// to check if a path exists
			for (int i = 1; i <= V; i++) {
				for (int j = 1; j <= V; j++)
					friends[i][j] = friends[i][j]
					| (friends[i][k] && friends[k][j]);
			}
		}
		return false;
	}

private:
	std::string email;
};


#ifndef RunTests
int main()
{
	Friend a("A");
	Friend b("B");
	Friend c("C");

	a.addFriendship(&b);
	b.addFriendship(&c);

	std::cout << a.canBeConnected(&c);
}
#endif


