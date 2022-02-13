#include<string.h> // strlen, strtok
#include<iostream>
#include<iomanip>
#include<fstream>
#include "functions.h"
#include<algorithm>
#include<vector>
int superTREE = 0;

int main()
{
	setlocale(LC_ALL, "Rus");
	FAMILY_TREE* mamber;

	std::vector<FAMILY_TREE*> mambers;

	char buffer[MAXB];

	std::ifstream inpf("input.txt");

	if (!inpf)
	{
		std::cout << "Неудается открыть input.txt\n";
		return 1;
	}

	int flag = 1, lnl = 0;
	char* child_name = NULL, * parent_name = NULL;

	for (int c = 0, ln = 0; inpf.getline(buffer, sizeof(buffer)); ln++)
	{
		if (buffer[0] == ';' || strlen(buffer) == 0) continue; 


		if (analyse_input(buffer, &child_name, &parent_name))
		{
			mamber = new FAMILY_TREE;

			if (lnl < strlen(child_name)) 
				lnl = strlen(child_name); 
			if (lnl < strlen(parent_name)) 
				lnl = strlen(parent_name);

			if (!c)
			{
				make_new_mamber(mamber, child_name, parent_name, c++);
				mambers.push_back(mamber);
				mamber = new FAMILY_TREE;
			}

			make_new_mamber(mamber, child_name, parent_name, c);

			mambers.push_back(mamber);
			++c;
		}
	}

	int knee = 1, max_knee = 0;
	max_knee = check_kinship(mambers);

	std::cout << "Укажите колено родства: [1," << max_knee << "] ";
	std::cin >> knee;
	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

	
	if (knee && knee <= max_knee)
	{
		show_knee(mambers, lnl, knee);
	}
	else
	{
		std::cout << "Fatal error\n";
		return 1;
	}

	std::cin.get();
	getchar();
	return 0;

}