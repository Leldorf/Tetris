#include<stdio.h>
#include<string.h>
#include"screen.h"

#define _CRT_SECURE_NO_WARNINGS

typedef struct Rank
{
	char name[14];
	int score;
	int level;
	int time;
}Rank;

Rank* rank;

void ReadRanking(int *size)
{
	FILE* file = fopen("Ranking.txt", "r");
	if (file == NULL)
	{
		return;
	}
	do {
		rank = realloc(rank, sizeof(Rank) * ++*size);
	} while (fread(&rank[*size - 1], sizeof(Rank), 1, file));
	rank = realloc(rank, sizeof(Rank) * -- * size);
	fclose(file);
}

void WriteRanking(int size)
{
	FILE* file = fopen("Ranking.txt", "w");
	fwrite(rank, sizeof(Rank), size, file);
	fclose(file);
}

void RankingSort(int *size, int level, int score, int time, char name[14])
{
	rank = realloc(rank, sizeof(Rank) * ++(*size));
	strcpy(rank[*size - 1].name, name);
	rank[*size - 1].score = score;
	rank[*size - 1].level = level;
	rank[*size - 1].time = time / 1000;
	for (int i = *size - 1; i > 0; i--)
	{
		if (rank[i].score > rank[i - 1].score || rank[i].score == rank[i - 1].score && rank[i].time < rank[i - 1].time)
		{
			Rank temp;
			temp = rank[i];
			rank[i] = rank[i - 1];
			rank[i - 1] = temp;
		}
	}
}

void RankingPrint(int size, int page)
{
	char *str;
	str = (char*)malloc(sizeof(char) * 50);
	for (int i = 10 * page; i < page * 10 + 10; i++)
	{
		if (i >= size)
		{
			sprintf(str, "%3d                                      ", i);
		}
		else
		{
			sprintf(str, "%3d¦¢%14s¦¢ LV.%d¦¢%10dpoint¦¢%5dsec", i, rank[i].name, rank[i].score, rank[i].level, rank[i].time);
		}
		ScreenPrint(3, 9 + (i % 10) * 2, str);
	}
}