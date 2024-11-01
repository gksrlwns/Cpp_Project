#pragma once

enum class KeyCode
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	Down = VK_DOWN,

	Space = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',

	L = 'L',
	K = 'K',
	J = 'J',

	//필요시 더 추가하면됨.

	Control = VK_CONTROL
};

enum class KeyState
{
	None,
	Press,
	Down,
	Up,
	End
};

enum
{
	KEY_CODE_COUNT = static_cast<int>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int>(KeyState::End)
};

class InputManager
{
DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);
	void Update();

public:
	bool GetKey(KeyCode key);
	bool GetKeyDown(KeyCode key);
	bool GetKeyUp(KeyCode key);

	POINT GetMousePos();
	Vector2 GetMousePosVector2();
private:
	// _states['W'] => Press
	// _states['W'] => Up
	KeyState GetState(KeyCode key) { return _states[static_cast<unsigned char>(key)]; }

private:
	HWND _hwnd = {};
	POINT _mousePos = {};
	vector<KeyState> _states;
};

#define Input GET_SINGLE(InputManager)