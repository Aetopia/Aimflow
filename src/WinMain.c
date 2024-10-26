#include <windows.h>
#include <winternl.h>

VOID ThreadProc(LPVOID lpParameter)
{
    WaitForSingleObject(lpParameter, INFINITE);
    CloseHandle(lpParameter);
    ExitProcess(EXIT_SUCCESS);
}

VOID WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread,
                  DWORD dwmsEventTime)
{
    HANDLE hThread = OpenThread(THREAD_SET_LIMITED_INFORMATION, FALSE, dwEventThread);
    SetThreadPriority(hThread, THREAD_PRIORITY_HIGHEST);
    CloseHandle(hThread);
    PostQuitMessage(EXIT_SUCCESS);
}

VOID WinMainCRTStartup()
{
    PROCESS_BASIC_INFORMATION _ = {};
    NtQueryInformationProcess(GetCurrentProcess(), ProcessBasicInformation, &_, sizeof(PROCESS_BASIC_INFORMATION),
                              NULL);

    CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc,
                             OpenProcess(SYNCHRONIZE, FALSE, _.InheritedFromUniqueProcessId), 0, NULL));

    MSG $ = {};
    SetWinEventHook(EVENT_OBJECT_CREATE, EVENT_OBJECT_CREATE, NULL, WinEventProc, _.InheritedFromUniqueProcessId, 0,
                    WINEVENT_OUTOFCONTEXT);
    while (GetMessageW(&$, NULL, 0, 0))
        ;

    ExitProcess(EXIT_SUCCESS);
}