#pragma once

#include "../PlatformRemoteConfig.h"
#include "core/string/ustring.h"
#include "AndroidConverter.h"

class AndroidRemoteConfig: public PlatformRemoteConfig 
{
private:
    Object *analyticsRef;
    HashMap<String, Ref<GDDTDRemoteConfigValue>> localConfig;
	void UpdateLocalConfig();
public:
    AndroidRemoteConfig(/* args */);
    ~AndroidRemoteConfig();

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
