#pragma once
#include<vector>
#include "FAMILY_TREE.h"
/** Функция проверяет входные данные
   buffer – поток входных данных
   child – указатель на указатель потомка родителя
   parent – указатель на указатель родителя 
*/
bool analyse_input(char* buffer, char** child, char** parent);
/** Функция создает нового участника
    mamb – указатель на класс FAMILY_TREE child – указатель потомка родителя 
	parent – указатель родителя
    \param[x] – счетчик номера строки int 
*/
void make_new_mamber(FAMILY_TREE* mamb, char* child, char* parent, int x);
/** Функция eузнает глубину участника.
    \param[index] – счетчик номера строки
    \param[n] – колено
*/
int get_deep(std::vector<FAMILY_TREE*>& mamb, int index, int& n);
/** Функция смотрит колени
    \param[lnl] - уровень колена
	\param[knee] - входной уровень колена
*/
void show_knee(const std::vector<FAMILY_TREE*>& mambers, int lnl, int knee);
/** Функция проверка родства.
    \param[mambers] - переменная вектора класса FAMILY TREE
*/
int check_kinship(std::vector<FAMILY_TREE*>& mambers);