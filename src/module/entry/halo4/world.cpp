#include "./Halo4.h"

namespace Halo4::Entry::World {
    extern void Prologue(); extern void Epilogue();
    void detour();

    Halo4Entry(entry, OFFSET_HALO4_PF_WORLD, detour);
}

void Halo4::Entry::World::detour() {
    typedef void (__fastcall* func_t)();
    auto func = (func_t)entry.m_pOriginal;

    Prologue();
    func();
    Epilogue();
}