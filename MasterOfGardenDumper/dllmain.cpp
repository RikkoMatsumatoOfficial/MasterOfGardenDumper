// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include "UnityResolve.hpp"
using namespace std;
namespace f = std::filesystem;
DWORD WINAPI Thread() {
    HWND hwnd_m;
    hwnd_m = FindWindowA(0, "MasterOfGarden");
    if (!hwnd_m) {
        MessageBoxA(0, "Not Founded MasterOfGarden Window!!!", "MasterOfGardenDumper", MB_OK | MB_ICONERROR);
        exit(43212);
    }
    else {
        UnityResolve::Init(GetModuleHandleA("GameAssembly.dll"), UnityResolve::Mode::Il2Cpp);
        UnityResolve::DumpToFile("MasterOfGarden_DumpedRVA_OffsetsANDfunctions"); //RVA it's Real Virtual Address :D
        f::path p("MasterOfGarden_DumpedRVA_OffsetsANDfunctions.h");
        if (p.empty()) {
            exit(421);
        }
        else {
            MessageBoxA(0, "Dumped Successfully!!! This Dumper is Created by RikkoMatsumatoOfficial", "MasterOfGardenDumper", MB_OK | MB_ICONINFORMATION);
            exit(42);
        }
        return TRUE;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

