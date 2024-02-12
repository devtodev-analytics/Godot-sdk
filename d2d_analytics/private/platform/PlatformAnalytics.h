#pragma once

#include "core/config/engine.h"
#include "core/string/ustring.h"
#include "../../DTDAnalyticsConfiguration.h"
#include "../../DTDLogLevel.h"
#include "../../DTDCustomEventParams.h"
#include "../../DTDAccrualType.h"
#include "../../DTDInt32Resources.h"
#include "../../DTDInt64Resources.h"
#include "../../DTDStartProgressionEventParams.h"
#include "../../DTDFinishProgressionEventParams.h"
#include "../../DTDSocialNetwork.h"
#include "../../DTDReferralProperty.h"
#include "SDKConstants.h"

class PlatformAnalytics
{
private:
    /* data */
public:
    virtual ~PlatformAnalytics() { }
    
    virtual void GetDeviceId(const Callable &onResult) = 0;
    virtual void GetSdkVersion(const Callable &onResult) = 0;
    
    // Tracking
    virtual void SetTrackingAvailability(const bool value) = 0;
    virtual void GetTrackingAvailability(const Callable &onResult) = 0;

    // User custom identifier
    virtual void GetUserId(const Callable &onResult) = 0;
    virtual void SetUserId(const String &userId) = 0;
    virtual void ReplaceUserId(const String &fromUserId, const String &toUserId) = 0;

    // User level
    virtual void GetCurrentLevel(const Callable &onResult) = 0;
    virtual void SetCurrentLevel(const int32_t &level) = 0;

    // Prepare initialization
    virtual void SetLogLevel(GDDTDLogLevel::LogLevel logLevel) = 0;
    virtual void CoppaControlEnable() = 0;
    virtual void SetInitializationCompleteCallback(const Callable &callback) = 0;
    virtual void SetIdentifiersCallback(const Callable &callback) = 0;

    virtual void Initialize(const String &appKey) = 0;
	virtual void InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration) = 0;

    virtual void InitializeWithAbTest(const String &appKey, 
                                    const Callable &onRemoteConfigChange, 
                                    const Callable &onRemoteConfigPrepareToChange, 
                                    const Callable &onRemoteConfigReceive) = 0;
    virtual void InitializeWithConfigWithAbTest(const String &appKey, 
                                    const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                    const Callable &onRemoteConfigChange, 
                                    const Callable &onRemoteConfigPrepareToChange, 
                                    const Callable &onRemoteConfigReceive) = 0;

    // Events
    virtual void CustomEvent(const String& eventName) = 0;
	virtual void CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params) = 0;
    virtual void CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType) = 0;
    virtual void LevelUp(const int32_t &level) = 0;
    virtual void LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance) = 0;
    virtual void CurrentBalance(const Ref<GDDTDInt64Resources>& balance) = 0;
    virtual void VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency) = 0;
	virtual void VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources) = 0;
    virtual void AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit) = 0;
    virtual void RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode) = 0;
    virtual void Tutorial(int32_t step) = 0;
    virtual void StartProgressionEvent(const String& eventName) = 0;
    virtual void StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params) = 0;
    virtual void FinishProgressionEvent(const String& eventName) = 0;
    virtual void FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params) = 0;
    virtual void SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork) = 0;
	virtual void SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason) = 0;
    virtual void Referrer(Ref<GDDTDReferralProperty> utmData) = 0;
    virtual void SendBufferedEvents() = 0;

    virtual void SubscribeLogger(const Callable &callback) = 0; 
};
