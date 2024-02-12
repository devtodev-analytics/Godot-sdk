#pragma once

#include "core/object/class_db.h"
#include "DTDRemoteConfigValue.h"
#include "DTDRemoteConfigDefaults.h"

class DTDRemoteConfigLibrary: public Object
{
    GDCLASS(DTDRemoteConfigLibrary, Object);

protected:
    static DTDRemoteConfigLibrary *instance;
    static void _bind_methods();

public:
    DTDRemoteConfigLibrary(/* args */);
    ~DTDRemoteConfigLibrary();

    void SetRemoteConfigWaiting(const int &value);
    int GetRemoteConfigWaiting();
    void SetGroupDefinitionWaiting(const float &value);
    float GetGroupDefinitionWaiting();

    void SetDefaults(const Ref<GDDTDRemoteConfigDefaults> &defaults);
    Ref<GDDTDRemoteConfigValue> GetRemoteConfigValue(const String &key);
    bool HasKey(const String& key);
    void ApplyConfig();
    void CacheTestExperiment();
    void ResetConfig();
};
