#include <cpp-lib/io.hpp>
#include <cpp-lib/win.hpp>

using namespace std;

main(){	
	/*DEVMODE desiredMode = { 0 };
	desiredMode.dmSize = sizeof(DEVMODE);
	desiredMode.dmPelsWidth = 1366;
	desiredMode.dmPelsHeight = 768;
	desiredMode.dmFields = DM_PELSHEIGHT | DM_PELSWIDTH;
	LONG res = ChangeDisplaySettings(&desiredMode, CDS_UPDATEREGISTRY | CDS_GLOBAL | CDS_RESET);*/

	Win().changeResolution(1024,768);
	input("");
	Win().changeResolution(1366,768);
}
