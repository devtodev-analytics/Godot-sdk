#include "private/platform/PlatformHub.h"
#include "DTDRemoteConfigLibrary.h"

DTDRemoteConfigLibrary::DTDRemoteConfigLibrary()
{
}

DTDRemoteConfigLibrary::~DTDRemoteConfigLibrary()
{
}

void DTDRemoteConfigLibrary::SetRemoteConfigWaiting(const int &value){
    PlatformHub::GetInstance().GetRemoteConfig()->SetRemoteConfigWaiting(value);
}

int DTDRemoteConfigLibrary::GetRemoteConfigWaiting(){
    return PlatformHub::GetInstance().GetRemoteConfig()->GetRemoteConfigWaiting();
}

void DTDRemoteConfigLibrary::SetGroupDefinitionWaiting(const float &value){
    PlatformHub::GetInstance().GetRemoteConfig()->SetGroupDefinitionWaiting(value);
}

float DTDRemoteConfigLibrary::GetGroupDefinitionWaiting(){
    return PlatformHub::GetInstance().GetRemoteConfig()->GetGroupDefinitionWaiting();
}

void DTDRemoteConfigLibrary::SetDefaults(const Ref<GDDTDRemoteConfigDefaults> &defaults) {
    PlatformHub::GetInstance().GetRemoteConfig()->SetDefaults(defaults);
}

Ref<GDDTDRemoteConfigValue> DTDRemoteConfigLibrary::GetRemoteConfigValue(const String &key)
{
    return PlatformHub::GetInstance().GetRemoteConfig()->GetRemoteConfigValue(key);
}

bool DTDRemoteConfigLibrary::HasKey(const String& key) {
    return PlatformHub::GetInstance().GetRemoteConfig()->HasKey(key);
}

void DTDRemoteConfigLibrary::ApplyConfig(){
    PlatformHub::GetInstance().GetRemoteConfig()->ApplyConfig();
}

void DTDRemoteConfigLibrary::CacheTestExperiment(){
    PlatformHub::GetInstance().GetRemoteConfig()->CacheTestExperiment();
}

void DTDRemoteConfigLibrary::ResetConfig(){
    PlatformHub::GetInstance().GetRemoteConfig()->ResetConfig();
}

void DTDRemoteConfigLibrary::_bind_methods() {
    ClassDB::bind_method(D_METHOD("SetRemoteConfigWaiting", "value"), &DTDRemoteConfigLibrary::SetRemoteConfigWaiting);
    ClassDB::bind_method(D_METHOD("GetRemoteConfigWaiting"), &DTDRemoteConfigLibrary::GetRemoteConfigWaiting);
    ClassDB::bind_method(D_METHOD("SetGroupDefinitionWaiting", "value"), &DTDRemoteConfigLibrary::SetRemoteConfigWaiting);
    ClassDB::bind_method(D_METHOD("GetGroupDefinitionWaiting"), &DTDRemoteConfigLibrary::GetGroupDefinitionWaiting);
    ClassDB::bind_method(D_METHOD("SetDefaults", "defaults"), &DTDRemoteConfigLibrary::SetDefaults);
    ClassDB::bind_method(D_METHOD("ApplyConfig"), &DTDRemoteConfigLibrary::ApplyConfig);
    ClassDB::bind_method(D_METHOD("CacheTestExperiment"), &DTDRemoteConfigLibrary::CacheTestExperiment);
    ClassDB::bind_method(D_METHOD("ResetConfig"), &DTDRemoteConfigLibrary::ResetConfig);
    ClassDB::bind_method(D_METHOD("GetRemoteConfigValue", "key"), &DTDRemoteConfigLibrary::GetRemoteConfigValue);
    ClassDB::bind_method(D_METHOD("HasKey", "key"), &DTDRemoteConfigLibrary::HasKey);
}