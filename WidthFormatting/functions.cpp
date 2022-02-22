#include <stdio.h>
#include <string.h>
#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
#include "FAMILY_TREE.h"

bool analyse_input(char* buffer, char** child, char** parent)
{
	//Анализ входных данных
	*child = strtok(buffer, "\t ");
	*parent = strtok(NULL, "\t ");
	//Возвращаем наличие/отсутствие входных данных
	return(*child && *parent) ? true : false;
}

void make_new_mamber(FAMILY_TREE* mamb, char* child, char* parent, int x)
{
	//Копируем в класс FAMILY_TREE родителя
	strncpy_s(mamb->parent, parent, MAXMAMBNAMB);
	//Копируем в класс FAMILY_TREE ребенка от данного родителя(при наличии)
	strncpy_s(mamb->child, ((x) ? child : parent), MAXMAMBNAMB);
	return;
}
int check_kinship(std::vector<FAMILY_TREE*>& mambers)
{
	int max_deph = 0;
	//Для всего дерева родства
	for (int i = 0, n = 0; i < mambers.size(); i++)
	{
		n = 0;
		//Получаем колени родства
		get_deep(mambers, i, n);
		mambers[i]->knee = n;
		//Если найден родитель первого родителя, то добавляется начальное колено родства
		if (max_deph < n) max_deph = n;
	}
	//Возвращает количество коленей родства
	return max_deph;
}
int get_deep(std::vector<FAMILY_TREE*>& mamb, int index, int& n)
{
	//Для количества связей членов семьи
	for (int i = mamb.size() - 1; i >= 0; i--)
	{
		//Если при сравнивании отца и родителя все верно, тогда 
		if (i != index && _stricmp(mamb[i]->child, mamb[index]->parent) == 0)
		{
			//Если показатель количества меньше размерности связей между членами семьи, тогда происходит выход 
			if (n > mamb.size()) break;
			//Иначе происходит подсчет связи между членом семьи
			get_deep(mamb, i, ++n);
		}
	}
	//Возвращает число связи между членами семьи
	return n;
}