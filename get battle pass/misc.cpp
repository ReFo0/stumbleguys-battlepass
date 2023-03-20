#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdint>
#include <libloaderapi.h>
#include <stdio.h>
#include "minhook/minhook.h"
#include "misc.h"

const auto battlepass_address = 0x3656A0; // User$$get_BattlePass

uintptr_t gameassembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
void(__fastcall* battlepass_orginal)(DWORD*, DWORD*);



void battlepass_hook(DWORD* __this, DWORD* meth)
{
	printf("battlepass actived. \n");
}

bool init_hook()
{
	printf("discord : refo#0035 \n");
	MH_Initialize();
	MH_CreateHook(reinterpret_cast<LPVOID*>(gameassembly + battlepass_address), battlepass_hook, (LPVOID*)battlepass_orginal);
	MH_EnableHook(reinterpret_cast<LPVOID*>(gameassembly + battlepass_address));
	return true;
}


bool alloc_console()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	return true;
}