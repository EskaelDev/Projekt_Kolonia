#ifndef STIMER_H 
#define STIMER_H

#include <sstream>
#ifndef STEXTURE_H
#include "STexture.h"
#endif

class STimer
{
public:
	STimer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	void count();
	void render();

	//Gets the timer's time
	Uint32 getTicks();

	//Checks the status of the timer
	bool isStarted();
	bool isPaused();

private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;

	std::stringstream timeText;

	STexture gTimeTextTexture;

	// Zmienne do wyswietlania czasu
	int h = 0, m = 0, s = 0;
};

#endif