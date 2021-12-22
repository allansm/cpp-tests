#include <iostream>
#include <windows.h>
#include <allansm/win.hpp>
#include <allansm/io.hpp>
#include <allansm/time.hpp>

using namespace std;

void chaos(){
	COLORREF centerColor;
	POINT cent;

    
//HWND hd = FindWindow(NULL, "Untitled - Notepad");
    auto hd = Win().getFocused();
    auto console = GetConsoleWindow();
    //LPRECT r;
	
    //GetWindowRect(hd,r);

    //print(r.width);
    	auto t = Time().currentTimeToMs();
	//std::vector<COLORREF> test;
	//std::vector<POINT> test2;
    	HDC hdc = GetDC(NULL); 
    	/*for(int ii=0;ii<264;ii++){
	    	for(int i=0;i<=470;i++){
			cent.x = i;
			cent.y = ii;
			centerColor = GetPixel(hdc, cent.x, cent.y);
			//test.push_back(centerColor);
			//test2.push_back(cent);
		    //cout << centerColor;
		    //cout << int(GetRValue(centerColor)) << " " << int(GetGValue(centerColor)) << " " << int(GetBValue(centerColor)) << endl;
		}
    	}*/

	
	println(Time().elapsedTime(t));
	//println(Time().toSec(Time().elapsedTime(t)));
	/*auto test3 = GetDC(console);
	while(true){
	
	int i = 0;
	for(auto n : test){
		SetPixel(test3,test2[i].x,test2[i].y,n);
		i++;
	}
	}*/
	auto test3 = GetDC(console);
	while(true){
	for(int x =0;x<=100;x++){
		for(int y =0;y<=100;y++){
			//SetPixel(test3,x,y,0x00FFFFFF);
			SetPixel(test3,x,y,GetPixel(hdc,x,y));
		}
	}
	}
	ReleaseDC(NULL, hdc);
	ReleaseDC(console,test3);
}

int main(){
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
