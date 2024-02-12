#pragma once

#include "core/config/engine.h"
#include "core/string/ustring.h"

class PlatformUserCard
{
private:
    /* data */
public:
    virtual ~PlatformUserCard() { }

    virtual void SetCheater(const bool &value) = 0;
    virtual void SetTester(const bool &value) = 0;
    virtual void SetString(const String &key, const String &value) = 0;
    virtual void TryGetString(const String &key, const Callable &callback) = 0;
    virtual void SetFloat(const String &key, const float &value) = 0;
    virtual void TryGetFloat(const String &key, const Callable &callback) = 0;
    virtual void SetInt(const String &key, const int64_t &value) = 0;
    virtual void TryGetInt(const String &key, const Callable &callback) = 0;
    virtual void SetBool(const String &key, const bool &value) = 0;
    virtual void TryGetBool(const String &key, const Callable &callback) = 0;
    virtual void Unset(const String &property) = 0;
    virtual void UnsetArray(const PackedStringArray &properties) = 0;
    virtual void IncrementInteger(const String &key, const int64_t &value) = 0;
    virtual void IncrementFloat(const String &key, const float &value) = 0;
    virtual void ClearUser() = 0;
};