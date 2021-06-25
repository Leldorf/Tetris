#include<stdio.h>
#include"screen.h"
#include"Block.h"

char* br[4] = { "  ", "﹥", "十", "﹤" };

void MapPrint(int(*map)[24])
{
	for (int j = 0; j < 24; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (map[i][j] >= 2)
			{
				SetColor(map[i][j]);
				ScreenPrint(2 * i + 18, 2 + j, br[2]);	//裘斜葬晦 
			}
			else
				ScreenPrint(2 * i + 18, 2 + j, br[0]);	//裘斜葬晦 
		}
	}
	SetColor(15);
}

void MapPrint2(int(*map)[24])
{
	for (int j = 0; j < 24; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (map[i][j] >= 2)
			{
				SetColor(map[i][j]);
				ScreenPrint(2 * i + 82, 2 + j, br[2]);	//裘斜葬晦 
			}
			else
				ScreenPrint(2 * i + 82, 2 + j, br[0]);	//裘斜葬晦 
		}
	}
	SetColor(15);
}

void MapInit()
{
	ScreenClear();
	ScreenPrint(16, 1, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(16, 26, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ScreenPrint(16, i + 2 + j * 6, br[3]);
			ScreenPrint(38, i + 2 + j * 6, br[3]);
			ScreenPrint(2 + 2 * i, 1 + 5 * j, br[3]);
			ScreenPrint(2 + 2 * i, 6 + 5 * j, br[3]);
			ScreenPrint(2, 1 + i + 5 * j, br[3]);
			ScreenPrint(12, 1 + i + 5 * j, br[3]);
		}
		ScreenPrint(42 + 2 * i, 1, br[3]);
		ScreenPrint(42 + 2 * i, 6, br[3]);
		ScreenPrint(42, 1 + i, br[3]);
		ScreenPrint(52, 1 + i, br[3]);
	}
}

void MapInit2()
{
	ScreenPrint(80, 1, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(80, 26, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ScreenPrint(80, i + 2 + j * 6, br[3]);
			ScreenPrint(102, i + 2 + j * 6, br[3]);
			ScreenPrint(106 + 2 * i, 1 + 5 * j, br[3]);
			ScreenPrint(106 + 2 * i, 6 + 5 * j, br[3]);
			ScreenPrint(106, 1 + i + 5 * j, br[3]);
			ScreenPrint(116, 1 + i + 5 * j, br[3]);
		}
		ScreenPrint(66 + 2 * i, 1, br[3]);
		ScreenPrint(66 + 2 * i, 6, br[3]);
		ScreenPrint(66, 1 + i, br[3]);
		ScreenPrint(76, 1 + i, br[3]);
		ScreenPrint(59, 1 + 5*i, "ll");
		ScreenPrint(59, 2 + 5*i, "ll");
	}
}

void NextBlock(int* n)
{
	int nBlock[4][4] = { 0, };
	for (int k = 0; k < 4; k++)
	{
		CopyBlock(nBlock, n[k], 0);
		SetColor(9 + n[k]);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ScreenPrint(4 + j * 2, i + 2 + k * 5, br[nBlock[i][j]]);
			}
		}
	}
}

void NextBlock2(int* n)
{
	int nBlock[4][4] = { 0, };
	for (int k = 0; k < 4; k++)
	{
		CopyBlock(nBlock, n[k], 0);
		SetColor(9 + n[k]);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ScreenPrint(108 + j * 2, i + 2 + k * 5, br[nBlock[i][j]]);
			}
		}
	}
}

void MenuInit()
{
	char* tetris[6][5] = {
		   "﹤﹤﹤﹤﹤",
		   "    ﹤    ",
		   "    ﹤    ",
		   "    ﹤    ",
		   "    ﹤    ",

		   "  ﹥﹥﹥﹥",
		   "﹥        ",
		   "﹥﹥﹥﹥﹥",
		   "﹥        ",
		   "  ﹥﹥﹥﹥",

		   "﹤﹤﹤﹤﹤",
		   "    ﹤    ",
		   "    ﹤    ",
		   "    ﹤    ",
		   "    ﹤    ",

		   "﹥﹥﹥﹥  ",
		   "﹥      ﹥",
		   "﹥﹥﹥﹥  ",
		   "﹥      ﹥",
		   "﹥      ﹥",

		   "﹤﹤﹤﹤﹤",
		   "    ﹤    ",
		   "    ﹤    ",
		   "    ﹤    ",
		   "﹤﹤﹤﹤﹤",

		   "  ﹥﹥﹥  ",
		   "﹥        ",
		   "  ﹥﹥﹥  ",
		   "        ﹥",
		   "  ﹥﹥﹥  ",
	};
	char* menu[10] = { "start", "battle", "ranking", "help", "exit" };
	ScreenClear();
	for (int i = 0; i < 6; i++)
	{
		switch (9 + i)
		{
		case 9:
			SetColor(12);
			break;
		case 10:
			SetColor(14);
			break;
		case 11:
			SetColor(10);
			break;
		case 12:
			SetColor(11);
			break;
		case 13:
			SetColor(9);
			break;
		case 14:
			SetColor(13);
			break;
		default:
			break;
		}
		for (int j = 0; j < 5; j++)
		{
			ScreenPrint(24 + i * 12, 2 + j, tetris[i][j]);
		}
	}

	SetColor(15);
	ScreenPrint(48, 18, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(48, 26, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int j = 0; j < 7; j++)
	{
		ScreenPrint(48, 19 + j, "﹤");
		ScreenPrint(66, 19 + j, "﹤");
	}
	for (int j = 0; j < 4; j++)
	{
		SetColor(11 + j);
		ScreenPrint(54, 20 + j, menu[j]);
	}
	SetColor(8);
	ScreenPrint(54, 24, menu[4]);
	SetColor(15);
	ScreenPrint(0, 1, "LeeJaeHun");
}

void MenuPrint(int num)
{
	for (int i = 0; i < 5; i++)
	{
		if (i == num)
			ScreenPrint(52, 20 + i, "⊥");
		else
			ScreenPrint(52, 20 + i, "  ");
	}
}

void HelpPrint()
{
	ScreenPrint(48, 12, "Drop       ～      w");
	ScreenPrint(48, 13, "Move     ９  Ⅱ   a d");
	ScreenPrint(48, 14, "Down       ∪      s");
	ScreenPrint(48, 15, "Rotate	   j  l    4 6 ");
	ScreenPrint(48, 16, "Hold         k      5 ");
	ScreenPrint(48, 17, "Pause   ESC    ");
}

void PauseInit()
{
	ScreenPrint(20, 10, "﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(20, 16, "﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int i = 0; i < 5; i++)
	{
		ScreenPrint(20, 11+i, "﹤");
		ScreenPrint(34, 11+i, "﹤");
	}
	ScreenPrint(24, 12, "Resume");
	ScreenPrint(24, 13, "ReStart");
	ScreenPrint(24, 14, "Menu");
}

void PausePrint(int select)
{
	for (int i = 0; i < 3; i++)
	{
		if(i == select)
			ScreenPrint(22, 12 + i, "⊥");
		else
			ScreenPrint(22, 12 + i, "  ");
	}
}

void PauseInit2()
{
	ScreenPrint(50, 13, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(50, 19, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int i = 0; i < 5; i++)
	{
		ScreenPrint(50, 14 + i, "﹤");
		ScreenPrint(68, 14 + i, "﹤");
	}
	ScreenPrint(56, 15, "Resume");
	ScreenPrint(56, 16, "ReStart");
	ScreenPrint(56, 17, "Menu");
}

void PausePrint2(int select)
{
	for (int i = 0; i < 3; i++)
	{
		if(select == i)
			ScreenPrint(54, 15 + i, "⊥");
		else 
			ScreenPrint(54, 15 + i, "  ");
	}

}

void KeepBlock(int n)
{
	int nBlock[4][4] = { 0, };
	CopyBlock(nBlock, n, 0);
	SetColor(9 + n);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ScreenPrint(44 + j * 2, i + 2, br[nBlock[i][j]]);
		}
	}
	SetColor(15);
}

void KeepBlock2(int n)
{
	int nBlock[4][4] = { 0, };
	CopyBlock(nBlock, n, 0);
	SetColor(9 + n);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ScreenPrint(68 + j * 2, i + 2, br[nBlock[i][j]]);
		}
	}
	SetColor(15);
}

void ResultInit()
{
	ScreenClear();
	ScreenPrint(36, 2, "  ﹥﹥﹥        ﹤      ﹥      ﹥  ﹤﹤﹤﹤﹤");
	ScreenPrint(36, 3, "﹥            ﹤  ﹤    ﹥﹥  ﹥﹥  ﹤        ");
	ScreenPrint(36, 4, "﹥    ﹥﹥  ﹤      ﹤  ﹥  ﹥  ﹥  ﹤﹤﹤﹤﹤");
	ScreenPrint(36, 5, "﹥      ﹥  ﹤﹤﹤﹤﹤  ﹥      ﹥  ﹤        ");
	ScreenPrint(36, 6, "  ﹥﹥﹥    ﹤      ﹤  ﹥      ﹥  ﹤﹤﹤﹤﹤");

	ScreenPrint(36,  7, "  ﹤﹤﹤    ﹥      ﹥  ﹤﹤﹤﹤﹤  ﹥﹥﹥﹥  ");
	ScreenPrint(36,  8, "﹤      ﹤  ﹥      ﹥  ﹤          ﹥      ﹥");
	ScreenPrint(36,  9, "﹤      ﹤  ﹥      ﹥  ﹤﹤﹤﹤﹤  ﹥﹥﹥﹥  ");
	ScreenPrint(36, 10, "﹤      ﹤    ﹥  ﹥    ﹤          ﹥      ﹥");
	ScreenPrint(36, 11, "  ﹤﹤﹤        ﹥      ﹤﹤﹤﹤﹤  ﹥      ﹥");

	ScreenPrint(54, 20, "Menu");
	ScreenPrint(54, 21, "Restart");
	ScreenPrint(54, 22, "Raking");
}

void ResultPrint(int select)
{
	for (int i = 0; i < 3; i++)
	{
		if(i == select)
			ScreenPrint(52, 20+i, "⊥");
		else
			ScreenPrint(52, 20+i, "  ");
	}
}

void ResultInit2(int win)
{
	ScreenPrint(50, 13, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(50, 19, "﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int i = 0; i < 5; i++)
	{
		ScreenPrint(50, 14 + i, "﹤");
		ScreenPrint(68, 14 + i, "﹤");
	}
	ScreenPrint(56, 14, "Menu");
	ScreenPrint(56, 15, "ReStart");

	ScreenPrint(20, 10, "﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(20, 14, "﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(84, 10, "﹤﹤﹤﹤﹤﹤﹤﹤");
	ScreenPrint(84, 14, "﹤﹤﹤﹤﹤﹤﹤﹤");
	for (int i = 0; i < 3; i++)
	{
		ScreenPrint(84, 11 + i, "﹤            ﹤");
		ScreenPrint(20, 11 + i, "﹤            ﹤");
	}
	if (win == -1)
	{
		ScreenPrint(22, 12, "    Win   ");
		ScreenPrint(86, 12, "    Lose  ");
	}
	else if(win == 1)
	{
		ScreenPrint(22, 12, "    Lose  ");
		ScreenPrint(86, 12, "    Win   ");
	}
	else
	{
		ScreenPrint(22, 12, "    Tie   ");
		ScreenPrint(86, 12, "    Tie   ");
	}
}

void ResultPrint2(int select)
{
	for (int i = 0; i < 2; i++)
	{
		if (select == i)
			ScreenPrint(54, 14, "⊥");
		else
			ScreenPrint(54, 14, "  ");

	}
}

void RankingInit()
{
	ScreenClear();
	ScreenPrint(10, 2, "﹥﹥﹥﹥    ﹤      ﹤  ﹥﹥﹥﹥﹥  ﹤      ﹤    ﹥﹥﹥  ");
	ScreenPrint(10, 3, "﹥      ﹥  ﹤  ﹤﹤        ﹥      ﹤﹤    ﹤  ﹥        ");
	ScreenPrint(10, 4, "﹥﹥﹥﹥    ﹤﹤﹤          ﹥      ﹤  ﹤  ﹤  ﹥    ﹥﹥");
	ScreenPrint(10, 5, "﹥      ﹥  ﹤    ﹤        ﹥      ﹤    ﹤﹤  ﹥      ﹥");
	ScreenPrint(10, 6, "﹥      ﹥  ﹤      ﹤  ﹥﹥﹥﹥﹥  ﹤      ﹤    ﹥﹥﹥  ");

	ScreenPrint(2, 8, "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	for (int i = 0; i < 10; i++)
	{
		ScreenPrint(2, 10 + 2 * i, "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");

	}
	ScreenPrint(80, 10, "Menu  : ESC");
	ScreenPrint(80, 11, "Scroll: ㏒");

}
