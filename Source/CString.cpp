/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#include "CString.h"
#include <Ishiko/Platform/Compilers.h>
#include <string.h>

namespace Ishiko
{

char* CString::Duplicate(const char* str)
{
#if ISHIKO_COMPILER == ISHIKO_COMPILER_GCC
    return strdup(str);
#elif ISHIKO_COMPILER == ISHIKO_COMPILER_MSVC
    return _strdup(str);
#else
    #error Unsupported or unrecognized compiler
#endif
}

}
