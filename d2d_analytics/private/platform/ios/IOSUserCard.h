#pragma once

#include "../PlatformUserCard.h"
#include "core/string/ustring.h"

class IOSUserCard: public PlatformUserCard
{
private:

public:
    IOSUserCard();
    ~IOSUserCard();

    void SetCheater(const bool &value);
    void SetTester(const bool &value);
    void SetString(const String &key, const String &value);
    void TryGetString(const String &key, const Callable &callback);
    void SetFloat(const String &key, const float &value);
    void TryGetFloat(const String &key, const Callable &callback);
    void SetInt(const String &key, const int64_t &value);
    void TryGetInt(const String &key, const Callable &callback);
    void SetBool(const String &key, const bool &value);
    void TryGetBool(const String &key, const Callable &callback);
    void Unset(const String &property);
    void UnsetArray(const PackedStringArray &properties);
    void IncrementInteger(const String &key, const int64_t &value);
    void IncrementFloat(const String &key, const float &value);
    void ClearUser();
};