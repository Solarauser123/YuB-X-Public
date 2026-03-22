#pragma once

#include <cstdint>
#include <Windows.h>

struct lua_State;
struct WeakThreadRef;
struct DebuggerResult;

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    const uintptr_t Print = REBASE(0x1C8E7A0);
    const uintptr_t TaskDefer = REBASE(0x1C74F00);
    const uintptr_t OpcodeLookupTable = REBASE(0x616D2C0);
    const uintptr_t ScriptContextResume = REBASE(0x1BC2460);
    const uintptr_t GetLuaStateForInstance = REBASE(0x1ADA240);

    namespace Luau
    {
        const uintptr_t Luau_Execute = REBASE(0x3DDF850);
        const uintptr_t LuaO_NilObject = REBASE(0x5C6B9D8);
        const uintptr_t LuaH_DummyNode = REBASE(0x5C6B0B8);
    }

    namespace DataModel
    {
        const uintptr_t Children = 0x70;
        const uintptr_t GameLoaded = 0x600;
        const uintptr_t ScriptContext = 0x3F0;
        const uintptr_t FakeDataModelToDataModel = 0x1C0;

        const uintptr_t FakeDataModelPointer = REBASE(0x81D3EA8);
    }

    namespace ExtraSpace
    {
        const uintptr_t RequireBypass = 0x930;
        const uintptr_t ScriptContextToResume = 0x848;
    }
}

namespace Roblox
{
    inline auto Print = (uintptr_t(*)(int, const char*, ...))Offsets::Print;
    inline auto TaskDefer = (uint64_t(__fastcall*)(lua_State*))Offsets::TaskDefer;
    inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau::Luau_Execute;
    inline auto GetLuaStateForInstance = (lua_State*(__fastcall*)(uint64_t, uint64_t*, uint64_t*))Offsets::GetLuaStateForInstance;
    inline auto ScriptContextResume = (uint64_t(__fastcall*)(uint64_t, DebuggerResult*, WeakThreadRef**, uint32_t, uint8_t, uint64_t))Offsets::ScriptContextResume;
}

// Dont forget to update Encryptions and Structs