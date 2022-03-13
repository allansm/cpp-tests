#include <windows.h>

void down(char key){
	INPUT buffer[1];
	
	buffer->type = INPUT_KEYBOARD;
	buffer->ki.wScan = 0;
	buffer->ki.time = 0;
	buffer->ki.dwExtraInfo = 0;

	buffer->ki.wVk = key;
	buffer->ki.dwFlags = 0;
	SendInput(1, buffer, sizeof(INPUT));

}

void up(char key){
	INPUT buffer[1];
	
	buffer->type = INPUT_KEYBOARD;
	buffer->ki.wScan = 0;
	buffer->ki.time = 0;
	buffer->ki.dwExtraInfo = 0;


	buffer->ki.wVk = key;
	buffer->ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, buffer, sizeof(INPUT));
}
