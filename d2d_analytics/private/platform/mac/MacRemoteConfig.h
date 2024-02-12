#pragma once

#include "../PlatformRemoteConfig.h"
#include "core/string/ustring.h"

class MacRemoteConfig: public PlatformRemoteConfig 
{
private:
    HashMap<String, Ref<GDDTDRemoteConfigValue>> localConfig;
	void UpdateLocalConfig();

public:
    MacRemoteConfig(/* args */);
    ~MacRemoteConfig();

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
