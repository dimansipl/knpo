#pragma once
#pragma warning(disable : 4996)
#pragma once
#define MAXMAMBNAMB 50
#define MAXB        1024
/** ʊ���� ��������� �����
   child � �������
   parent �  ��������
   /param[knee] - ������
*/
class FAMILY_TREE
{
public:
	char parent[MAXMAMBNAMB];
	char child[MAXMAMBNAMB];
	int knee; // ������
};
