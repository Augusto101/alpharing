#pragma once

#include <halo1.h>

#include "mcc/module/entry/entry.h"

extern EntrySet g_pHalo1EntrySet;
inline EntrySet* Halo1EntrySet() {return &g_pHalo1EntrySet;};

#define Halo1Entry(name, offset, returnType, pDetour, ...) \
    returnType pDetour(__VA_ARGS__); \
    typedef returnType (*pDetour##_t)(...); \
    ::Entry name(Halo1EntrySet(), offset, pDetour); \
    returnType pDetour(__VA_ARGS__)
