#include "IOSConverter.h"

String IOSConverter::Convert(const NSString* value) {
    return String::utf8([value UTF8String]);
}

NSString* IOSConverter::Convert(const String &value)
{
    return [[NSString alloc] initWithUTF8String:value.utf8().get_data()];
}

DTDAnalyticsConfiguration* IOSConverter::Convert(const Ref<GDDTDAnalyticsConfiguration> &config)
{
    DTDAnalyticsConfiguration *objConfig = [[DTDAnalyticsConfiguration alloc] init];
    [objConfig setLogLevel:Convert(config->logLevel)];
	
    if (config->GetIsLevelChanged()) {
        [objConfig setCurrentLevel:ConvertToPointer(config->currentLevel)];
    }

    if (config->GetIsUserIdChanged()) {
        [objConfig setUserId:Convert(config->userId)];
    }

    [objConfig setTrackingAvailability:Convert(config->trackingStatus)];

    return objConfig;
}

DTDTrackingStatus IOSConverter::Convert(GDDTDTrackingStatus::TrackingStatus trackingStatus)
{
	switch (trackingStatus)
	{
	case GDDTDTrackingStatus::Unknown:
        return DTDTrackingStatusUnknown;
	case GDDTDTrackingStatus::Enable:
        return DTDTrackingStatusEnable;
	case GDDTDTrackingStatus::Disable:
        return DTDTrackingStatusDisable;
	default:
        return DTDTrackingStatusUnknown;
	}
}

DTDCustomEventParameters* IOSConverter::Convert(const Ref<GDDTDCustomEventParams> &params) {
    DTDCustomEventParameters *objParams = [[DTDCustomEventParameters alloc] init];
    
    for (const KeyValue<String, String> &E : params->getStringValues()) {
		[objParams addString:Convert(E.key) value:Convert(E.value)];
	}

    for (const KeyValue<String, int64_t> &E : params->getIntegerValues()) {
		[objParams addInt:Convert(E.key) value:ConvertInt64(E.value)];
	}

    for (const KeyValue<String, float> &E : params->getFloatValues()) {
		[objParams addDouble:Convert(E.key) value:(double)(E.value)];
	}

    for (const KeyValue<String, bool> &E : params->getBoolValues()) {
		[objParams addBool:Convert(E.key) value:ConvertToObjC(E.value)];
	}

    return objParams;
}

DTDLogLevel IOSConverter::Convert(GDDTDLogLevel::LogLevel value)
{
	switch (value)
	{
	case GDDTDLogLevel::Unknown:
		return DTDLogLevelUnknown;
	case GDDTDLogLevel::No:
		return DTDLogLevelNo;
	case GDDTDLogLevel::Error:
		return DTDLogLevelError;
	case GDDTDLogLevel::Warning:
		return DTDLogLevelWarning;
	case GDDTDLogLevel::Info:
		return DTDLogLevelInfo;
	case GDDTDLogLevel::Debug:
		return DTDLogLevelDebug;
	default:
		return DTDLogLevelUnknown;
	}
}

DTDAccrualType IOSConverter::Convert(GDDTDAccrualType::AccrualType value) {
    switch (value) {
	case GDDTDAccrualType::Earned:
        return DTDAccrualTypeEarned;
	case GDDTDAccrualType::Bought:
        return DTDAccrualTypeBought;
	default:
        return DTDAccrualTypeEarned;
	}
}

BOOL IOSConverter::ConvertToObjC(bool value)
{
    return value ? YES : NO;
}

bool IOSConverter::ConvertToCpp(BOOL value)
{
	return value ? true : false;
}

NSInteger IOSConverter::ConvertInt64(int64_t value)
{
    return NSInteger(value);
}

NSInteger IOSConverter::ConvertInt32(int32_t value)
{
    return NSInteger(value);
}

int64_t IOSConverter::ConvertToInt64(NSInteger value)
{
	return (int64_t)value;
}

NSNumber* IOSConverter::ConvertToPointer(int32_t value)
{
    return [NSNumber numberWithInt:value];
}


NSNumber* IOSConverter::ConvertToPointer(int64_t value)
{
    return [NSNumber numberWithInt:value];
}


NSArray<NSString*>* IOSConverter::Convert(const PackedStringArray &array)
{
    NSMutableArray* nsArray = [[NSMutableArray alloc] init];
    for (const String& str : array)
	{
        [nsArray addObject:Convert(str)];
	}

    return nsArray;
}

NSDictionary<NSString*, NSNumber*>* IOSConverter::Convert(const Ref<GDDTDInt64Resources>& balance)
{
    NSMutableDictionary* objDic = [[NSMutableDictionary alloc] init];
    for (const KeyValue<String, int64_t> &E : balance->getIntegerValues()) {
	    [objDic setObject:ConvertToPointer(E.value) forKey:Convert(E.key)];
	}

    return objDic;
}

NSDictionary<NSString*, NSNumber*>* IOSConverter::Convert(const Ref<GDDTDInt32Resources>& balance)
{
    NSMutableDictionary* objDic = [[NSMutableDictionary alloc] init];
    for (const KeyValue<String, int32_t> &E : balance->getIntegerValues()) {
	    [objDic setObject:ConvertToPointer(E.value) forKey:Convert(E.key)];
	}

    return objDic;
}

DTDStartProgressionEventParameters* IOSConverter::Convert(const Ref<GDDTDStartProgressionEventParams>& params) {
    DTDStartProgressionEventParameters *objParams = [[DTDStartProgressionEventParameters alloc] init];

	if (params->GetSource().size() > 0 && params->IsSourceChanged())
	{
    	[objParams setSource:Convert(params->GetSource())];
	}

	if (params->IsDifficultyChanged())
	{
    	[objParams setDifficultyWithDifficulty:ConvertInt32(params->GetDifficulty())];
	}

    return objParams;
}

DTDFinishProgressionEventParameters* IOSConverter::Convert(const Ref<GDDTDFinishProgressionEventParams>& params)
{
    DTDFinishProgressionEventParameters *objParams = [[DTDFinishProgressionEventParameters alloc] init];
    [objParams setSuccessfulCompletion:ConvertToObjC(params->GetSuccessfulCompletion())];
    [objParams setDuration:ConvertInt32(params->GetDuration())];
    [objParams setSpent:Convert(params->GetSpentResources())];
    [objParams setEarned:Convert(params->GetEarnedResources())];
    return objParams;
}

DTDReferralProperty* IOSConverter::ConvertFromString(const String referral)
{
    if (referral == "Source") {
        return [DTDReferralProperty source];
    } else if (referral == "Campaign") {
        return [DTDReferralProperty campaign];
    } else if (referral == "Content") {
        return [DTDReferralProperty content];
    } else if (referral == "Medium") {
        return [DTDReferralProperty medium];
    } else if (referral == "Term") {
        return [DTDReferralProperty term];
    } else {
        return [DTDReferralProperty source];
    }
}

NSDictionary<DTDReferralProperty*, NSString*>* IOSConverter::Convert(const Ref<GDDTDReferralProperty> utmData)
{
    NSMutableDictionary* objReferrer = [[NSMutableDictionary alloc] init];
    for (const KeyValue<String, String> &E : utmData->getReferralData()) {
	    [objReferrer setObject:Convert(E.value) forKey:ConvertFromString(E.key)];
	}

    return objReferrer;
}

GDDTDRemoteConfigSource::Source IOSConverter::Convert(DTDRemoteConfigSource value)
{
	switch (value)
	{
	case DTDRemoteConfigSourceEmpty:
		return GDDTDRemoteConfigSource::Source::Empty;
	case DTDRemoteConfigSourceRemote:
		return GDDTDRemoteConfigSource::Source::Remote;
	case DTDRemoteConfigSourceDefaults:
		return GDDTDRemoteConfigSource::Source::Default;
	default:
		return GDDTDRemoteConfigSource::Source::Empty;
	}
}

NSDictionary<NSString *, id>* IOSConverter::ConvertToDefaults(const Ref<GDDTDRemoteConfigDefaults>& defaults)
{
	NSMutableDictionary<NSString *, id> *nativeDefaults = [[NSMutableDictionary<NSString *, id> alloc] init];

    for (const KeyValue<String, String> &E : defaults->getStringDefaults()) {
	    [nativeDefaults setValue:Convert(E.value) forKey:Convert(E.key)];
	}

    for (const KeyValue<String, bool> &E : defaults->getBoolDefaults()) {
	    [nativeDefaults setValue:E.value ? @YES : @NO forKey:Convert(E.key)];
	}

    for (const KeyValue<String, int64_t> &E : defaults->getIntegerDefaults()) {
	    [nativeDefaults setValue:ConvertToPointer(E.value) forKey:Convert(E.key)];
	}

    for (const KeyValue<String, float> &E : defaults->getFloatDefaults()) {
	    [nativeDefaults setValue:Convert(E.value) forKey:Convert(E.key)];
	}

	return nativeDefaults;
}

NSNumber* IOSConverter::Convert(float value)
{
    return [NSNumber numberWithFloat:value];
}