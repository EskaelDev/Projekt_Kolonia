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

	// Akcje dla timera
	void start();
	void stop();
	void pause();
	void unpause();
	void count();
	void render();

	// Pobiera czas
	Uint32 getTicks();

	// Sprawdza status timera
	bool isStarted();
	bool isPaused();
private:
	// Czas timera kiedy jest wlaczony
	Uint32 mStartTicks;

	// Czas timera podczas pauzy
	Uint32 mPausedTicks;

	// Status timera
	bool mPaused;
	bool mStarted;

	std::stringstream timeText;

	STexture gTimeTextTexture;

	// Zmienne do wyswietlania czasu
	int h = 0, m = 0, s = 0;
};
extern STimer timer;
#endif