#pragma once
#pragma warning(disable : 4996)
#pragma once
#define MAXMAMBNAMB 50
#define MAXB        1024
/**  Класс семейного древа
   child Ц ребенок
   parent Ц  родитель
   /param[knee] - колено
*/
class FAMILY_TREE
{
public:
	char parent[MAXMAMBNAMB];
	char child[MAXMAMBNAMB];
	int knee; // колено
};
