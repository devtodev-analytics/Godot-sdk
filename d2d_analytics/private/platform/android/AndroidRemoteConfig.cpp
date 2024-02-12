#include "AndroidRemoteConfig.h"
#include "AndroidConverter.h"


const String pluginName = "Analytics";
const String message = pluginName + " plugin is not found";


AndroidRemoteConfig::AndroidRemoteConfig()
{
	Engine *engane = Engine::get_singleton();
	if (engane->has_singleton(pluginName)) {
		analyticsRef = engane->get_singleton_object(pluginName);
	} else {
		print_line("Analytics plugin not found");
	}
}

AndroidRemoteConfig::~AndroidRemoteConfig()
{
}

void AndroidRemoteConfig::SetRemoteConfigWaiting(const int &value){
	if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

	analyticsRef->call("setRemoteConfigWaiting", value);
}

int AndroidRemoteConfig::GetRemoteConfigWaiting(){
	if (analyticsRef == nullptr) {
        print_line(message);
        return 0.0;
    }

	float value = analyticsRef->call("getRemoteConfigWaiting");	
    return value;
}

void AndroidRemoteConfig::SetGroupDefinitionWaiting(const float &value){
	if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

	analyticsRef->call("setGroupDefinitionWaiting", value);
}

float AndroidRemoteConfig::GetGroupDefinitionWaiting(){
	if (analyticsRef == nullptr) {
        print_line(message);
        return 0.0;
    }

	float value = analyticsRef->call("getGroupDefinitionWaiting");	
    return value;
}

void AndroidRemoteConfig::SetDefaults(const Ref<GDDTDRemoteConfigDefaults> &defaults){
	if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
	
	String dict = AndroidConverter::ConvertToDefaults(defaults);
    analyticsRef->call("setDefaults", dict);
    UpdateLocalConfig();
}

void AndroidRemoteConfig::ApplyConfig(){
	if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
	
	analyticsRef->call("applyConfig");
    UpdateLocalConfig();
}

void AndroidRemoteConfig::CacheTestExperiment(){
	if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
	
	analyticsRef->call("cacheTestExperiment");
}

void AndroidRemoteConfig::ResetConfig(){
	if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
	
	analyticsRef->call("resetConfig");
    UpdateLocalConfig();
}

bool AndroidRemoteConfig::HasKey(const String& key) {
	if (analyticsRef == nullptr) {
        print_line(message);
        return false;
    }

	return localConfig.has(key);
}

Ref<GDDTDRemoteConfigValue> AndroidRemoteConfig::GetRemoteConfigValue(const String &key) {
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

void AndroidRemoteConfig::UpdateLocalConfig() {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
    
    localConfig.clear();
	String config = analyticsRef->call("getConfig");
    Dictionary dictionary = JSON::parse_string(config);
    for (int i = 0; i < dictionary.size(); i++) {
        String key = dictionary.get_key_at_index(i);
        Dictionary configValue = dictionary.get_value_at_index(i);
        Ref<GDDTDRemoteConfigValue> value = AndroidConverter::ConvertRemoteConfigValue(configValue);
        localConfig.insert(key, value);
    }
}