#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<fmod.h>

FMOD_SYSTEM *g_System;
FMOD_SOUND *g_Sound;

void Init()
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(g_System, "run.wav", FMOD_DEFAULT, 0, &g_Sound);
}

void Update()
{

}

void Release()
{
	FMOD_Sound_Release(g_Sound);
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void WaitRender(clock_t oldTime)
{
	clock_t CurTime;
	while (1)
	{
		CurTime = clock();
		if (CurTime - oldTime > 15)
			break;
	}
}

int main()
{
	int nKey;
	FMOD_CHANNEL *channel = NULL;
	float volume = 0.5f;
	FMOD_BOOL isPlaying;

	Init();

	while (1)
	{
		if (_kbhit())
		{
			nKey = _getch();
			if (nKey == 'q')
				break;
			switch (nKey)
			{
			case 'p':
				FMOD_System_PlaySound(g_System, channel, g_Sound, 0, &channel);
				break;
			case 's':
				FMOD_Channel_Stop(channel);
				break;
			case 'u':
				volume += 0.1f;
				if (volume > 1.0f)
					volume = 1.0f;
				FMOD_Channel_SetVolume(channel, volume);
				break;
			case 'd':
				volume -= 0.1f;
				if (volume < 0.0f)
					volume = 0.0f;
				FMOD_Channel_SetVolume(channel, volume);
				break;
			}
		}

		FMOD_Channel_IsPlaying(channel, &isPlaying);
		if (isPlaying == 1)
			FMOD_System_Update(g_System);
		Update();
		//WaitRender(clock());
	}
	Release();
	return 0;
}