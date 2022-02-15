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