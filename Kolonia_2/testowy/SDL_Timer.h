#pragma once

class SDL_Timer
	{
	public:
		SDL_Timer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		void count();
		void render();

		//Gets the SDL_SDL_Timer's time
		Uint32 getTicks();

		//Checks the status of the SDL_SDL_Timer
		bool isStarted();
		bool isPaused();

	private:
		//The clock time when the SDL_SDL_Timer started
		Uint32 mStartTicks;

		//The ticks stored when the SDL_SDL_Timer was paused
		Uint32 mPausedTicks;

		//The SDL_SDL_Timer status
		bool mPaused;
		bool mStarted;

		stringstream timeText;
	};
