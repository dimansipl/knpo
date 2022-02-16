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
