#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"

class GDDTDRemoteConfigDefaults: public RefCounted {
    GDCLASS(GDDTDRemoteConfigDefaults, RefCounted);

private:
	HashMap<String, String> stringValues;
    HashMap<String, int64_t> integerValues;
    HashMap<String, float> floatValues;
    HashMap<String, bool> boolValues;

protected:
    static void _bind_methods();

public:
    void AddStringValue(const String &key, const String &value);
    void AddIntegerValue(const String &key, const int64_t &value);
    void AddFloatValue(const String &key, const float &value);
    void AddBoolValue(const String &key, const bool &value);

    HashMap<String, String> getStringDefaults() const;
    HashMap<String, int64_t> getIntegerDefaults() const;
    HashMap<String, float> getFloatDefaults() const;
    HashMap<String, bool> getBoolDefaults() const;
};