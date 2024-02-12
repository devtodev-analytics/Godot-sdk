#include "MacRemoteConfig.h"
#include "MacConverter.h"

MacRemoteConfig::MacRemoteConfig() { }

MacRemoteConfig::~MacRemoteConfig() { }

// Public

void MacRemoteConfig::SetRemoteConfigWaiting(const int &value){
    [::DTDRemoteConfig setRemoteConfigWaiting:(double)value];
}

int MacRemoteConfig::GetRemoteConfigWaiting(){
    return [::DTDRemoteConfig remoteConfigWaiting];
}

void MacRemoteConfig::SetGroupDefinitionWaiting(const float &value){
    [::DTDRemoteConfig setGroupDefinitionWaiting:(double)value];
}

float MacRemoteConfig::GetGroupDefinitionWaiting(){
    return [::DTDRemoteConfig groupDefinitionWaiting];
}

void MacRemoteConfig::SetDefaults(const Ref<GDDTDRemoteConfigDefaults> &defaults){
    const auto oco_defaults = MacConverter::ConvertToDefaults(defaults);
	[::DTDRemoteConfig setDefaults:oco_defaults];
	UpdateLocalConfig();
}

void MacRemoteConfig::ApplyConfig(){
    [::DTDRemoteConfig applyConfig];
	UpdateLocalConfig();
}

void MacRemoteConfig::CacheTestExperiment(){
    [::DTDRemoteConfig cacheTestExperiment];
}

void MacRemoteConfig::ResetConfig(){
    [::DTDRemoteConfig resetConfig];
	UpdateLocalConfig();
}

bool MacRemoteConfig::HasKey(const String& key) {
	return localConfig.has(key);
}

Ref<GDDTDRemoteConfigValue> MacRemoteConfig::GetRemoteConfigValue(const String &key) {
    if (localConfig.has(key)) {
		return localConfig[key];
	} else {
		Ref<GDDTDRemoteConfigValue> value;
        value.instantiate();
        value.ptr()->Source = GDDTDRemoteConfigSource::Source::Empty;
		return value;
	}
}

// Private

void MacRemoteConfig::UpdateLocalConfig() {
    localConfig.clear();

    NSDictionary<NSString *, DTDRemoteConfigValue *> * rawConfig = [[::DTDRemoteConfig config] getRawConfig];
    for (NSString* key in [rawConfig allKeys]) {
        DTDRemoteConfigValue *nativeValue = rawConfig[key];
        Ref<GDDTDRemoteConfigValue> value;
        value.instantiate();
        value.ptr()->Source = MacConverter::Convert([nativeValue source]);
        value.ptr()->StringValue = MacConverter::Convert([nativeValue stringValue]);
        value.ptr()->FloatValue = [nativeValue floatValue];
        value.ptr()->IntValue = MacConverter::ConvertToInt64([nativeValue integerValue]);
        value.ptr()->BoolValue = MacConverter::ConvertToCpp([nativeValue boolValue]);
        localConfig.insert(MacConverter::Convert(key), value);
    }
}