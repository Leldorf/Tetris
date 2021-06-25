#pragma once

typedef struct Rank
{
	char name[14];
	int score;
	int level;
	int time;
}Rank;

Rank* rank;

void ReadRanking(int* size);

void WriteRanking(int size);

void RankingSort(int* size, int level, int score, int time, char name[14]);

void RankingPrint(int size, int page);