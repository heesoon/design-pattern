#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	c++ state pattern - version 1
	
	reference : https://www.robertlarsononline.com/2017/05/11/state-pattern-using-cplusplus/
	
	아래 music player의 예제는 동작과 상태가 mixing되어 있는 예제이다.
	예제로부터 상태를 객체로 뽑아내서 캡슐화하여 music player의 실제 동작과 분리하는 작업이 목표이다.
	상태가 추가되거나 삭제될 경우, CMusicPlayer 객체 전체에 대해서 코드 수정이 이루어져야 한다.
*/

enum class State
{
	STATE_PLAY,
	STATE_STOP,
	STATE_PAUSE
};

class CMusicPlayer
{
public:
	virtual ~CMusicPlayer() = default;

	void play()
	{
		std::cout << "play.." << std::endl;
	}

	void stop()
	{
		std::cout << "stop.." << std::endl;
	}

	void pause()
	{
		std::cout << "pause.." << std::endl;
	}
	
	void handleState(State st)
	{
		mCurrentState = st;
		switch(st)
		{
			case State::STATE_PLAY:
			{
				play();
				break;
			}
			case State::STATE_STOP:
			{
				stop();
				break;
			}
			case State::STATE_PAUSE:
			{
				pause();
				break;
			}			
		}
	}
	
private:
	State mCurrentState = State::STATE_STOP;
};

int main()
{
	CMusicPlayer musicPlayer;
	musicPlayer.handleState(State::STATE_PLAY);

	return 0;
}