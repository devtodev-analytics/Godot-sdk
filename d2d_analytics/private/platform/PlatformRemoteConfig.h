#pragma once

#include "core/config/engine.h"
#include "core/string/ustring.h"
#include "../../DTDRemoteConfigValue.h"
#include "../../DTDRemoteConfigDefaults.h"

class PlatformRemoteConfig
{
private:
    /* data */
public:
    virtual ~PlatformRemoteConfig() { }

    virtual void SetRemoteConfigWaiting(const int &value) = 0;
    virtual int GetRemoteConfigWaiting() = 0;
    virtual void SetGroupDefinitionWaiting(const float &value) = 0;
    virtual float GetGroupDefinitionWaiting() = 0;
    virtual void SetDefaults(const Ref<GDDTDRemoteConfigDefaults> &defaults) = 0;
    virtual Ref<GDDTDRemoteConfigValue> GetRemoteConfigValue(const String &key) = 0;
    virtual bool HasKey(const String& key) = 0;
    virtual void ApplyConfig() = 0;
    virtual void CacheTestExperiment() = 0;
    virtual void ResetConfig() = 0;
};
