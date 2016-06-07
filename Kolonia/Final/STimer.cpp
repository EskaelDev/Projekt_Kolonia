#include "STimer.h"

STimer::STimer()
{
	mStartTicks = 0;
	mPausedTicks = 0;

	mPaused = true;
	mStarted = true;
}

void STimer::start()
{
	// Wlaczenie timera
	mStarted = true;

	// Odpauzowanie timera
	mPaused = false;

	// Pobranie aktualnego czasu
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void STimer::stop()
{
	// Zatrzymanie timera
	mStarted = false;

	// Odpauzowanie timera
	mPaused = false;

	// Wyszczyszczenie pol
	mStartTicks = 0;
	mPausedTicks = 0;
}

void STimer::pause()
{
	// Jesli timer jest wlaczony i dziala
	if (mStarted && !mPaused)
	{
		// Wlacz pauze
		mPaused = true;

		// Oblicz zapauzowany czas
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void STimer::unpause()
{
	// Jesli timer jest wlaczony i jest zapauzowany
	if (mStarted && mPaused)
	{
		// Wylacz pauze
		mPaused = false;

		// Zresetuj poczatkowy czas
		mStartTicks = SDL_GetTicks() - mPausedTicks;

		// Zresetuj zapausowany czas
		mPausedTicks = 0;
	}
}

Uint32 STimer::getTicks()
{
	// Aktualny czas timera
	Uint32 time = 0;

	// Jesli timer dziala
	if (mStarted)
		// Jesli timer jest zapauzowany
		if (mPaused)
			// Zwroc czas w momencie wlaczenie pauzy
			time = mPausedTicks;
		else
			// Zwroc aktualny czas minus poczatkowy czas
			time = SDL_GetTicks() - mStartTicks;
	return time;
}

bool STimer::isStarted()
{
	// Timera dziala
	return mStarted;
}

bool STimer::isPaused()
{
	// Timer dziala i jest zapauzowany
	return mPaused && mStarted;
}

void STimer::count()
{
	if (s == 60)
	{
		m++;
		s = 0;
	}
	s = (getTicks() / 1000) - (m * 60);
}

void STimer::render()
{
	timeText.str("");
	timeText << m << " m " << s << " sekund";

	// Kolor renderowanego tekstu
	SDL_Color textColor = { 255, 255, 255, 255 };

	// Renderowanie tekstu
	if (!gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor, gFont))
		std::cout << "Nie mozna wyrenderowac czasu!" << std::endl;
	else
		gTimeTextTexture.render((325 - gTimeTextTexture.getWidth()), 312);
}
STimer timer;