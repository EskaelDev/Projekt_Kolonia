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

	const int getSeconds() const;
	const int getMinutes() const;
	void setSeconds(int);
	void setMinutes(int);

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
	int m, s, prevS;
};
extern STimer timer;
#endif