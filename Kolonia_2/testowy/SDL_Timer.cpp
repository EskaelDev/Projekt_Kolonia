#include "SDL_Timer.h"



SDL_Timer::SDL_Timer()
{
	mStartTicks = 0;
	mPausedTicks = 0;

	mPaused = true;
	mStarted = true;
}

void SDL_Timer::start()
{
	//Start the SDL_SDL_Timer
	mStarted = true;

	//Unpause the SDL_SDL_Timer
	mPaused = false;

	//Get the current clock time
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void SDL_Timer::stop()
{
	//Stop the SDL_SDL_Timer
	mStarted = false;

	//Unpause the SDL_Timer
	mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

void SDL_Timer::pause()
{
	//If the SDL_Timer is running and isn't already paused
	if (mStarted && !mPaused)
	{
		//Pause the SDL_Timer
		mPaused = true;

		//Calculate the paused ticks
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void SDL_Timer::unpause()
{
	//If the SDL_Timer is running and paused
	if (mStarted && mPaused)
	{
		//Unpause the SDL_Timer
		mPaused = false;

		//Reset the starting ticks
		mStartTicks = SDL_GetTicks() - mPausedTicks;

		//Reset the paused ticks
		mPausedTicks = 0;
	}
}

Uint32 SDL_Timer::getTicks()
{
	//The actual SDL_Timer time
	Uint32 time = 0;

	//If the SDL_Timer is running
	if (mStarted)
	{
		//If the SDL_Timer is paused
		if (mPaused)
		{
			//Return the number of ticks when the SDL_Timer was paused
			time = mPausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

bool SDL_Timer::isStarted()
{
	//SDL_Timer is running and paused or unpaused
	return mStarted;
}

bool SDL_Timer::isPaused()
{
	//SDL_Timer is running and paused
	return mPaused && mStarted;
}

void SDL_Timer::count()
{/*
	if (getTicks() % 130 == 0)
	{
		if (s1 < 56)
		{
			s1++;
			s1++;
			s15++;
		}
		if (s5 < 56)
			s5++;
		if (s18 < 56)
			s18++;
	}
	if (getTicks() % 150 == 0)
	{
		if (s2 < 56)
			s2++;
		if (s6 < 56)
			s6++;
		if (s10 < 56)
			s10++;
		if (s11 < 56)
			s11++;
		if (s16 < 56)
			s16++;
	}
	if (getTicks() % 200 == 0)
	{
		if (s3 < 56)
			s3++;
		if (s13 < 56)
			s13++;
		if (s19 < 56)
			s19++;
		if (s12 < 56)
			s12++;
	}
	if (getTicks() % 300 == 0)
	{
		if (s4 < 56)
			s4++;
		if (s7 < 56)
		{
			s7++;
			s7++;
		}
		if (s15 < 56)
			s15++;
		if (s20 < 56)
		{
			s20++;
			s20++;
			s20++;

		}
	}
	if (getTicks() % 200 == 0)
	{
		if (s8 < 56)
			s8++;
		if (s11 < 56)
			s11++;
		if (s14 < 56)
		{

			s14++;
			s14++;
			s14++;
		}
		if (s17 < 56)
			s17++;
	}
	if (getTicks() % 300 == 0)
	{
		s9++;
		if (s1 < 0)
			s1--;
		if (s2 < 0)
			s2--;
		if (s3 < 0)
			s3--;
		if (s4 < 0)
			s4--;
		if (s5 < 0)
			s5--;
		if (s6 < 0)
			s6--;
		if (s7 < 0)
			s7--;
		if (s8 < 0)
			s8--;
		if (s9 < 0)
			s9--;
		if (s10 < 0)
			s10--;
		if (s11 < 0)
			s11--;
		if (s12 < 0)
			s12--;
		if (s13 < 0)
			s13--;
		if (s14 < 0)
			s14--;
		if (s15 < 0)
			s15--;
		if (s16 < 0)
			s16--;
		if (s17 < 0)
			s17--;
		if (s18 < 0)
			s18--;
		if (s19 < 0)
			s19--;
		if (s20 < 0)
			s20--;
	}
	if (s == 60)
	{
		m++;
		s = 0;
	}
	s = (getTicks() / 1000) - (m * 60);
	*/
}

void SDL_Timer::render()
{

	timeText.str("");
	timeText << m << " m " << s << " sekund";
	// Renderowanie tekstu
	if (!gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
	{
		cout << "Nie mozna wyrenderowac czasu!" << endl;
	}
	else
	{
		gTimeTextTexture.render((350 - gTimeTextTexture.getWidth()), 310);
	}
}