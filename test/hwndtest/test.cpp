#include <allansm/mswindow.hpp>

typedef LONG (NTAPI *NtSuspendProcess)(IN HANDLE ProcessHandle);

main(){
	auto processId = MsWindow("notepad").pid();
	
	HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

	NtSuspendProcess pfnNtSuspendProcess = (NtSuspendProcess)GetProcAddress(
	GetModuleHandle("ntdll"), "NtSuspendProcess");

	pfnNtSuspendProcess(processHandle);
	CloseHandle(processHandle);
}
