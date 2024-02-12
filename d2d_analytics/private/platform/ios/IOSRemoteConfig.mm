#include "IOSRemoteConfig.h"
#include "IOSConverter.h"

IOSRemoteConfig::IOSRemoteConfig() { }

IOSRemoteConfig::~IOSRemoteConfig() { }

// Public

void IOSRemoteConfig::SetRemoteConfigWaiting(const int &value){
    [::DTDRemoteConfig setRemoteConfigWaiting:(double)value];
}

int IOSRemoteConfig::GetRemoteConfigWaiting(){
    return [::DTDRemoteConfig remoteConfigWaiting];
}

void IOSRemoteConfig::SetGroupDefinitionWaiting(const float &value){
    [::DTDRemoteConfig setGroupDefinitionWaiting:(double)value];
}

float IOSRemoteConfig::GetGroupDefinitionWaiting(){
    return [::DTDRemoteConfig groupDefinitionWaiting];
}

void IOSRemoteConfig::SetDefaults(const Ref<GDDTDRemoteConfigDefaults> &defaults){
    const auto oco_defaults = IOSConverter::ConvertToDefaults(defaults);
	[::DTDRemoteConfig setDefaults:oco_defaults];
	UpdateLocalConfig();
}

void IOSRemoteConfig::ApplyConfig(){
    [::DTDRemoteConfig applyConfig];
	UpdateLocalConfig();
}

void IOSRemoteConfig::CacheTestExperiment(){
    [::DTDRemoteConfig cacheTestExperiment];
}

void IOSRemoteConfig::ResetConfig(){
    [::DTDRemoteConfig resetConfig];
	UpdateLocalConfig();
}

bool IOSRemoteConfig::HasKey(const String& key) {
	return localConfig.has(key);
}

Ref<GDDTDRemoteConfigValue> IOSRemoteConfig::GetRemoteConfigValue(const String &key) {
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

void IOSRemoteConfig::UpdateLocalConfig() {
    localConfig.clear();

    NSDictionary<NSString *, DTDRemoteConfigValue *> * rawConfig = [[::DTDRemoteConfig config] getRawConfig];
    for (NSString* key in [rawConfig allKeys]) {
        DTDRemoteConfigValue *nativeValue = rawConfig[key];
        Ref<GDDTDRemoteConfigValue> value;
        value.instantiate();
        value.ptr()->Source = IOSConverter::Convert([nativeValue source]);
        value.ptr()->StringValue = IOSConverter::Convert([nativeValue stringValue]);
        value.ptr()->FloatValue = [nativeValue floatValue];
        value.ptr()->IntValue = IOSConverter::ConvertToInt64([nativeValue integerValue]);
        value.ptr()->BoolValue = IOSConverter::ConvertToCpp([nativeValue boolValue]);
        localConfig.insert(IOSConverter::Convert(key), value);
    }
}