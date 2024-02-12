#include "core/string/print_string.h"
#include "AndroidAnalytics.h"
#include "AndroidConverter.h"

Dictionary AndroidConverter::Convert(const Ref<GDDTDAnalyticsConfiguration> configuration){
	Dictionary dict;

	dict["logLevel"] = configuration->logLevel;
    dict["trackingStatus"] = configuration->trackingStatus;

    if (configuration->GetIsUserIdChanged()) {
	    dict["userId"] = configuration->userId;
    }

    if (configuration->GetIsLevelChanged()) {
        dict["currentLevel"] = configuration->currentLevel;
    }

	return dict;
}

String AndroidConverter::Convert(const Ref<GDDTDCustomEventParams>& params){

    HashMap<String, String> strMap = params.ptr()->getStringValues();
    HashMap<String, int64_t> intMap = params.ptr()->getIntegerValues();
    HashMap<String, float> floatMap =  params.ptr()->getFloatValues();
    HashMap<String, bool> boolMap = params.ptr()->getBoolValues();

    Dictionary root;

    for (auto const& item : strMap)
    {
        root[item.key] = item.value;
    }
    
    for (auto const& item : intMap)
    {
        root[item.key] = item.value;
    }

    for (auto const& item : floatMap)
    {
        root[item.key] = item.value;
    }

    for (auto const& item : boolMap)
    {
        root[item.key] = item.value;
    }

    return JSON::stringify(root);
}

String AndroidConverter::Convert(const Ref<GDDTDInt64Resources>& balance) {

    HashMap<String, int64_t> intMap = balance->getIntegerValues();
    Dictionary root;

    for (auto const& item : intMap)
    {
        root[item.key] = item.value;
    }

    return JSON::stringify(root);
}

Dictionary AndroidConverter::Convert(const Ref<GDDTDInt32Resources>& balance) {

    HashMap<String, int32_t> intMap = balance->getIntegerValues();
    Dictionary root;

    for (auto const& item : intMap)
    {
        root[item.key] = item.value;
    }

    return root;
}

Dictionary AndroidConverter::Convert(const Ref<GDDTDStartProgressionEventParams>& params) {

    Dictionary root;

    if(params->IsSourceChanged()){
        root["source"] = params->GetSource();
    }

    if(params->IsDifficultyChanged()){
        root["difficulty"] = params->GetDifficulty();
    }
    
    return root;
}

Dictionary AndroidConverter::Convert(const Ref<GDDTDFinishProgressionEventParams>& params) {

    Dictionary root;
    Ref<GDDTDInt64Resources> spentMap = params->GetSpentResources();
    Ref<GDDTDInt64Resources>  earnedMap = params->GetEarnedResources();

    root["successfulCompletion"] = params->GetSuccessfulCompletion();
    root["duration"] = params->GetDuration();

    if(spentMap->getIntegerValues().size() !=0 ){
        root["spent"] = Convert(spentMap);
    }

    if(earnedMap->getIntegerValues().size() !=0 ){
        root["earned"] = Convert(earnedMap);
    }

    return root;
}

Dictionary AndroidConverter::Convert(const Ref<GDDTDReferralProperty> &utmData){
    Dictionary root;

    HashMap<String, String> map = utmData->getReferralData();
    for (auto const& item : map)
    {
        root[item.key] = item.value;
    }

    return root;
}

String AndroidConverter::ConvertToDefaults(const Ref<GDDTDRemoteConfigDefaults>& params){

    HashMap<String, String> strMap = params.ptr()->getStringDefaults();
    HashMap<String, int64_t> intMap = params.ptr()->getIntegerDefaults();
    HashMap<String, float> floatMap =  params.ptr()->getFloatDefaults();
    HashMap<String, bool> boolMap = params.ptr()->getBoolDefaults();

    Dictionary root;

    for (auto const& item : strMap)
    {
        root[item.key] = item.value;
    }
    
    for (auto const& item : intMap)
    {
        root[item.key] = item.value;
    }

    for (auto const& item : floatMap)
    {
        root[item.key] = item.value;
    }

    for (auto const& item : boolMap)
    {
        root[item.key] = item.value;
    }

    return JSON::stringify(root);
}

Ref<GDDTDRemoteConfigValue> AndroidConverter::ConvertRemoteConfigValue(Dictionary configValue) {
    Ref<GDDTDRemoteConfigValue> remoteConfigValue;
    remoteConfigValue.instantiate();

    int source = configValue["source"];
    if (source == 0){
        remoteConfigValue.ptr()->Source = GDDTDRemoteConfigSource::Source::Empty;
    } else if (source == 1){
        remoteConfigValue.ptr()->Source = GDDTDRemoteConfigSource::Source::Remote;
    } else if (source == 2){
        remoteConfigValue.ptr()->Source = GDDTDRemoteConfigSource::Source::Default;
    }

    remoteConfigValue.ptr()->StringValue = configValue["stringValue"];
    remoteConfigValue.ptr()->BoolValue = configValue["booleanValue"];
    remoteConfigValue.ptr()->IntValue = int(configValue["intValue"]);
    remoteConfigValue.ptr()->FloatValue = configValue["FloatValue"];
  
    return remoteConfigValue;
}

String AndroidConverter::Convert(const String &key, const int64_t &value){
    Dictionary root;
    root[key] = value;
    return JSON::stringify(root);
}

String AndroidConverter::Convert(const String &key, const float &value){
    Dictionary root;
    root[key] = value;
    return JSON::stringify(root);
}