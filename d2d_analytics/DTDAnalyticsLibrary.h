#pragma once

#include "core/variant/variant.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDLogLevel.h"
#include "DTDCustomEventParams.h"
#include "DTDAccrualType.h"
#include "DTDInt32Resources.h"
#include "DTDInt64Resources.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDSocialNetwork.h"
#include "DTDReferralProperty.h"
#include "DTDRemoteConfigReceiveResult.h"
#include "DTDRemoteConfigChangeResult.h"

class DTDAnalyticsLibrary: public Object
{
    GDCLASS(DTDAnalyticsLibrary, Object);

private:
    void ProcessStringCallback(const String &value);
    void ProcessIntCallback(const int64_t &value);
    void ProcessBoolCallback(const bool &value);
    void ProcessVoidCallback();

    void ProcessCallback(const Callable &callback);
    void ProcessCallback(const Variant &value, const Callable &callback);
    void ProcessCallback(const Variant &value, const Variant &value1, const Callable &callback);

    Callable stringCallback;
    Callable intCallback;
    Callable boolCallback;
    Callable voidCallback;
    Callable identifierCallback;

    Callable onRemoteConfigChange;
    Callable onRemoteConfigPrepareToChange;
	Callable onRemoteConfigReceive;

    Callable tryOnRemoteConfigChange;
    Callable tryOnRemoteConfigPrepareToChange;
	Callable tryOnRemoteConfigReceive;

    List<Callable> listOfStringCallbacks;
    List<Callable> listOfIntCallbacks;
    List<Callable> listOfBoolCallbacks;
    List<Callable> listOfVoidCallbacks;

    void RemoteConfigReceiveCallback(const int32_t &result);
    void RemoteConfigPrepareToChangeCallback();
    void RemoteConfigChangeCallback(const int32_t &result, const String &error);

protected:
    static DTDAnalyticsLibrary *instance;
    static void _bind_methods();

public:
    DTDAnalyticsLibrary();
    ~DTDAnalyticsLibrary();

    void GetDeviceId(const Callable &onResult);
    void GetSdkVersion(const Callable &onResult);
    
    // Tracking
    void SetTrackingAvailability(const bool value);
    void GetTrackingAvailability(const Callable &onResult);

    // User custom identifier
    void SetUserId(const String &userId);
    void GetUserId(const Callable &onResult);
    void ReplaceUserId(const String &fromUserId, const String &toUserId);

    // User level
    void SetCurrentLevel(const int32_t &level);
    void GetCurrentLevel(const Callable &onResult);

    // Prepare initialization
    void SetLogLevel(GDDTDLogLevel::LogLevel logLevel);
    void CoppaControlEnable();
    void SetInitializationCompleteCallback(const Callable &callback);
    void SetIdentifiersCallback(const Callable &callback);

    // Initialization
    void Initialize(const String &appKey);
    void InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration);
    void InitializeWithAbTest(const String &appKey, 
                            const Callable &onRemoteConfigChange, 
                            const Callable &onRemoteConfigPrepareToChange, 
                            const Callable &onRemoteConfigReceive);
    void InitializeWithConfigWithAbTest(const String &appKey, 
                                    const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                    const Callable &onRemoteConfigChange, 
                                    const Callable &onRemoteConfigPrepareToChange, 
                                    const Callable &onRemoteConfigReceive);

    // Events
    void CustomEvent(const String& eventName);
	void CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params);
    void CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType);
    void LevelUp(const int32_t &level);
    void LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance);
    void CurrentBalance(const Ref<GDDTDInt64Resources>& balance);
    void VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency);
	void VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources);
    void AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit);
    void RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode);
    void Tutorial(int32_t step);
    void StartProgressionEvent(const String& eventName);
    void StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params);
    void FinishProgressionEvent(const String& eventName);
    void FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params);
    void SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork);
	void SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason);
    void Referrer(Ref<GDDTDReferralProperty> utmData);
    void SendBufferedEvents();
};
