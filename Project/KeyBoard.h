#include <SFML/Window/Keyboard.hpp>

class KeyBoard {
public:
	KeyBoard();
	~KeyBoard();
	bool getIsMultiPlayer();
	void setMultiPlayer(bool isMultiPlayer = true);
	void pressKey();

private:
	bool isMultiPlayer;
};