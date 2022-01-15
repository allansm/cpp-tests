#include <iostream>
#include <windows.h>
#include <allansm/win.hpp>
#include <allansm/io.hpp>
#include <allansm/time.hpp>

//using namespace std;

void test(){
	auto t = Time().currentTimeToMs();
	auto test = GetDC(Win().getFocused());
	
	std::vector<COLORREF> px;
	
	auto console = GetConsoleWindow();
	auto test2 = GetDC(console);

	auto dc = CreateCompatibleDC(test);
	auto bmp = CreateCompatibleBitmap(test,100,100);
	SelectObject(dc, bmp);
	BitBlt(dc, 0, 0, 100, 100, test, 0, 0, SRCCOPY);	
	
	ReleaseDC(NULL, test);
	DeleteDC(test);	
	
	for(int x = 0;x<=100;x++){
		for(int y = 0;y<=100;y++){
			px.push_back(GetPixel(dc,x,y));
		}
	}
	
	ReleaseDC(NULL,dc);
	DeleteObject(bmp);
	DeleteDC(dc);	
	println(Time().elapsedTime(t));
		
	while(true){
		int i = 0;
		for(int x = 0;x<=100;x++){
			for(int y = 0;y<=100;y++){
				SetPixel(test2,x,y,px[i++]);
			}
		}
	}

	ReleaseDC(console, test2);
	DeleteDC(test2);
}

int main(){
	auto f = Win().getFocused();
	while(true){
		auto t = Time().currentTimeToMs();
		auto test = GetDC(NULL);
		
		std::vector<COLORREF> px;
		
		auto console = GetConsoleWindow();
		auto test2 = GetDC(console);

		auto dc = CreateCompatibleDC(test);
		auto bmp = CreateCompatibleBitmap(test,200,200);
		SelectObject(dc, bmp);
		BitBlt(dc, 0, 0, 200, 200, test, 896, 0, SRCCOPY);	
		
		ReleaseDC(NULL, test);
		DeleteDC(test);	
		
		for(int x = 0;x<=200;x++){
			for(int y = 0;y<=200;y++){
				px.push_back(GetPixel(dc,x,y));
			}
		}
		
		ReleaseDC(NULL,dc);
		DeleteObject(bmp);
		DeleteDC(dc);	
		println(Time().elapsedTime(t));
			
		int i = 0;
		for(int x = 0;x<=200;x++){
			for(int y = 0;y<=200;y++){
				SetPixel(test2,x,y,px[i++]);
			}
		}	

		ReleaseDC(console, test2);
		DeleteDC(test2);
	}
}
