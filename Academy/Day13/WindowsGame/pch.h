#pragma once

// 미리컴파일된 헤더는 다른 cpp파일 첫번째줄에 
// #include "pch.h" 를 해줘야한다.

//==========================================
//	## Windows Api 구성에 꼭 필요한 헤더 ##
//==========================================
#include <sdkddkver.h>
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <format>
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//==========================================
//	## C++ 관련 헤더 ##
//==========================================
#include <algorithm>
#include <string>
using namespace std;
using namespace Draw;

//==========================================
//	## Custom 헤더 ##
//==========================================
#include "CommonFunction.h"

