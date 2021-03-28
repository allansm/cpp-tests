/*
required

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

*/
class KeyBot{
	private:
		INPUT _buffer[1];

	public:
		KeyBot();
		void KeyUp( char key );
		void KeyDown( char key );
		void KeyUp( char* key ,int size);
		void KeyDown( char* key ,int size);
		void KeyClick( char key );
};

KeyBot::KeyBot(){
    _buffer->type = INPUT_KEYBOARD;
    _buffer->ki.wScan = 0;
    _buffer->ki.time = 0;
    _buffer->ki.dwExtraInfo = 0;
}

void KeyBot::KeyUp( char key ){
    _buffer->ki.wVk = key;
    _buffer->ki.dwFlags = /*KEYEVENTF_UNICODE |*/ KEYEVENTF_KEYUP;
    SendInput( 1, _buffer, sizeof( INPUT ) );
}

void KeyBot::KeyDown( char key ){
    _buffer->ki.wVk = key;
    _buffer->ki.dwFlags = 0;
    SendInput( 1, _buffer, sizeof( INPUT ) );
}

void KeyBot::KeyClick( char key ){
    KeyDown( key );
    Sleep( 10 );
    KeyUp( key );
}
///////////////////////////////////////


void KeyBot::KeyDown(char* key,int size){
	INPUT inputs[size];
	
	for(int i=0;i<size;i++){
		inputs[i].type = INPUT_KEYBOARD;
		inputs[i].ki.wVk = key[i];
	}
	
	SendInput(size, inputs, sizeof(INPUT));
	
}

void KeyBot::KeyUp(char* key,int size){
	INPUT inputs[size];
	
	for(int i=size;i>=0;i--){
		inputs[i].type = INPUT_KEYBOARD;
		inputs[i].ki.wVk = key[i];
		inputs[i].ki.dwFlags = KEYEVENTF_KEYUP;
	}
	
	SendInput(size, inputs, sizeof(INPUT));
	
}