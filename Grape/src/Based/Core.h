#pragma once

#include <windows.h>
#include <stdio.h>

#ifdef GP_DYNAMIC_LNK
#ifdef GP_BUILD_DLL
#define GP_DLL _declspec(dllexport)
#else
#define GP_DLL _declspec(dllexport)
#endif
#else
#define GP_DLL
#endif // GP_DYNAMIC_LNK


#ifdef __cplusplus
#define BEGIN_GP_NAMESPACE namespace grape{
#define END_GP_NAMESPACE }
#else
#define BEGIN_GP_NAMESPACE
#define END_GP_NAMESPACE
#endif

#define BIT(x) (1 << x)