#pragma once

#include "core/object/class_db.h"

class DTDUserCardLibrary: public Object
{
    GDCLASS(DTDUserCardLibrary, Object);

private:
    List<Callable> listOfStringCallbacks;
    List<Callable> listOfFloatCallbacks;
    List<Callable> listOfIntCallbacks;
    List<Callable> listOfBoolCallbacks;

    Callable tryGetStringValue;
    Callable tryGetFloatValue;
    Callable tryGetIntValue;
    Callable tryGetBoolValue;

    void ProcessTryGetStringCallback(const bool &isValid, const String &value);
    void ProcessTryGetFloatCallback(const bool &isValid, const float &value);
    void ProcessTryGetIntCallback(const bool &isValid, const int64_t &value);
    void ProcessTryGetBoolCallback(const bool &isValid, const bool &value);

    void ProcessCallback(const Variant &isValid, const Variant &value, const Callable &callback);

protected:
    static DTDUserCardLibrary *instance;
    static void _bind_methods();

public:
    DTDUserCardLibrary();
    ~DTDUserCardLibrary();

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