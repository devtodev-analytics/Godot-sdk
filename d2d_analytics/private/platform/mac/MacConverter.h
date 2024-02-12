#pragma once

#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "../../../DTDAnalyticsConfiguration.h"
#include "../../../DTDLogLevel.h"
#include "../../../DTDCustomEventParams.h"
#include "../../../DTDAccrualType.h"
#include "../../../DTDInt32Resources.h"
#include "../../../DTDInt64Resources.h"
#include "../../../DTDStartProgressionEventParams.h"
#include "../../../DTDFinishProgressionEventParams.h"
#include "../../../DTDReferralProperty.h"
#include "../../../DTDTrackingStatus.h"
#include "../../../DTDRemoteConfigSource.h"
#include "../../../DTDRemoteConfigDefaults.h"

class MacConverter
{
public:
    static String Convert(const NSString* value);
    static NSString* Convert(const String &value);
    static DTDAnalyticsConfiguration* Convert(const Ref<GDDTDAnalyticsConfiguration> &config);
    static DTDTrackingStatus Convert(GDDTDTrackingStatus::TrackingStatus trackingStatus);
    static DTDLogLevel Convert(GDDTDLogLevel::LogLevel value);
    static BOOL ConvertToObjC(bool value);
    static bool ConvertToCpp(BOOL value);
    static NSInteger ConvertInt64(int64_t value);
    static NSInteger ConvertInt32(int32_t value);
    static int64_t ConvertToInt64(NSInteger value);
    static NSArray<NSString*>* Convert(const PackedStringArray &array);
    static DTDCustomEventParameters* Convert(const Ref<GDDTDCustomEventParams>& params);
    static DTDAccrualType Convert(GDDTDAccrualType::AccrualType value);
    static NSDictionary<NSString*, NSNumber*>* Convert(const Ref<GDDTDInt64Resources>& balance);
    static NSDictionary<NSString*, NSNumber*>* Convert(const Ref<GDDTDInt32Resources>& balance);
    static NSNumber* ConvertToPointer(int32_t value);
    static NSNumber* ConvertToPointer(int64_t value);
    static DTDStartProgressionEventParameters* Convert(const Ref<GDDTDStartProgressionEventParams>& params);
    static DTDFinishProgressionEventParameters* Convert(const Ref<GDDTDFinishProgressionEventParams>& params);
    static DTDReferralProperty* ConvertFromString(const String referral);
    static NSDictionary<DTDReferralProperty*, NSString*>* Convert(const Ref<GDDTDReferralProperty> utmData);

    static GDDTDRemoteConfigSource::Source Convert(DTDRemoteConfigSource value);
    static NSDictionary<NSString *, id>* ConvertToDefaults(const Ref<GDDTDRemoteConfigDefaults>& defaults);
    static NSNumber* Convert(float value);
};