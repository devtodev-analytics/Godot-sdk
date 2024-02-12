#pragma once

#include "../../../DTDAnalyticsConfiguration.h"
#include "../../../DTDLogLevel.h"
#include "../../../DTDCustomEventParams.h"
#include "../../../DTDAccrualType.h"
#include "../../../DTDInt32Resources.h"
#include "../../../DTDInt64Resources.h"
#include "../../../DTDStartProgressionEventParams.h"
#include "../../../DTDFinishProgressionEventParams.h"
#include "../../../DTDReferralProperty.h"
#include "../../../DTDRemoteConfigDefaults.h"
#include "../../../DTDRemoteConfigValue.h"
#include "core/io/json.h"

class AndroidConverter
{
public:
    static int Convert(GDDTDLogLevel::LogLevel value);
    static Dictionary Convert(const Ref<GDDTDAnalyticsConfiguration> config);
    static String Convert(const Ref<GDDTDCustomEventParams>& params);
    static String Convert(const Ref<GDDTDInt64Resources>& balance);
    static Dictionary Convert(const Ref<GDDTDInt32Resources>& balance);
    static Dictionary Convert(const Ref<GDDTDStartProgressionEventParams>& params);
    static Dictionary Convert(const Ref<GDDTDFinishProgressionEventParams>& params);
    static Dictionary Convert(const Ref<GDDTDReferralProperty> &utmData);
    static String ConvertToDefaults(const Ref<GDDTDRemoteConfigDefaults>& defaults);
    static Ref<GDDTDRemoteConfigValue> ConvertRemoteConfigValue(Dictionary configValue);
    static String Convert(const String &key, const int64_t &value);
    static String Convert(const String &key, const float &value);
};
