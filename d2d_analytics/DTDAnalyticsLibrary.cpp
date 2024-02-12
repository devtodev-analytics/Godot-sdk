#include "core/config/engine.h"
#include "DTDAnalyticsLibrary.h"
#include "private/platform/PlatformHub.h"


DTDAnalyticsLibrary::DTDAnalyticsLibrary() {
    stringCallback = callable_mp(this, &DTDAnalyticsLibrary::ProcessStringCallback);
    intCallback = callable_mp(this, &DTDAnalyticsLibrary::ProcessIntCallback);
    boolCallback = callable_mp(this, &DTDAnalyticsLibrary::ProcessBoolCallback);
    voidCallback = callable_mp(this, &DTDAnalyticsLibrary::ProcessVoidCallback);

	tryOnRemoteConfigChange = callable_mp(this, &DTDAnalyticsLibrary::RemoteConfigChangeCallback);
	tryOnRemoteConfigPrepareToChange = callable_mp(this, &DTDAnalyticsLibrary::RemoteConfigPrepareToChangeCallback);
    tryOnRemoteConfigReceive = callable_mp(this, &DTDAnalyticsLibrary::RemoteConfigReceiveCallback);
}

DTDAnalyticsLibrary::~DTDAnalyticsLibrary() {

}

void DTDAnalyticsLibrary::RemoteConfigReceiveCallback(const int32_t &result) {
    GDDTDRemoteConfigReceiveResult::ReceiveResult enumValue = GDDTDRemoteConfigReceiveResult::ReceiveResult::Failure;

    switch(result) {
    case 0:
        enumValue = GDDTDRemoteConfigReceiveResult::ReceiveResult::Failure;
        break;

    case 1:
        enumValue = GDDTDRemoteConfigReceiveResult::ReceiveResult::Success;
        break;

    case 2:
        enumValue = GDDTDRemoteConfigReceiveResult::ReceiveResult::Empty;
        break;
    }

    ProcessCallback(enumValue, onRemoteConfigReceive);
}

void DTDAnalyticsLibrary::RemoteConfigPrepareToChangeCallback() {
    ProcessCallback(onRemoteConfigPrepareToChange);
}

void DTDAnalyticsLibrary::RemoteConfigChangeCallback(const int32_t &result, const String &error) {
    GDDTDRemoteConfigChangeResult::ChangeResult enumValue = GDDTDRemoteConfigChangeResult::ChangeResult::Failure;

    switch(result) {
    case 0:
        enumValue = GDDTDRemoteConfigChangeResult::ChangeResult::Failure;
        break;

    case 1:
        enumValue = GDDTDRemoteConfigChangeResult::ChangeResult::Success;
        break;
    }

    ProcessCallback(enumValue, Variant(error), onRemoteConfigChange);
}

void DTDAnalyticsLibrary::GetDeviceId(const Callable &onResult) {
    listOfStringCallbacks.push_back(onResult);
    PlatformHub::GetInstance().GetAnalytics()->GetDeviceId(stringCallback);
}

void DTDAnalyticsLibrary::GetSdkVersion(const Callable &onResult) {
    listOfStringCallbacks.push_back(onResult);
    PlatformHub::GetInstance().GetAnalytics()->GetSdkVersion(stringCallback);
}


// Tracking
void DTDAnalyticsLibrary::SetTrackingAvailability(const bool value) {
    PlatformHub::GetInstance().GetAnalytics()->SetTrackingAvailability(value);
}

void DTDAnalyticsLibrary::GetTrackingAvailability(const Callable &onResult) {
    listOfBoolCallbacks.push_back(onResult);
    PlatformHub::GetInstance().GetAnalytics()->GetTrackingAvailability(boolCallback);
}


// User custom identifier
void DTDAnalyticsLibrary::SetUserId(const String &userId) {
    PlatformHub::GetInstance().GetAnalytics()->SetUserId(userId);
}

void DTDAnalyticsLibrary::GetUserId(const Callable &onResult) {
    listOfStringCallbacks.push_back(onResult);
    PlatformHub::GetInstance().GetAnalytics()->GetUserId(stringCallback);
}

void DTDAnalyticsLibrary::ReplaceUserId(const String &fromUserId, const String &toUserId) {
    PlatformHub::GetInstance().GetAnalytics()->ReplaceUserId(fromUserId, toUserId);
}


// User level
void DTDAnalyticsLibrary::SetCurrentLevel(const int32_t &level) {
    PlatformHub::GetInstance().GetAnalytics()->SetCurrentLevel(level);
}

void DTDAnalyticsLibrary::GetCurrentLevel(const Callable &onResult) {
    listOfIntCallbacks.push_back(onResult);
    PlatformHub::GetInstance().GetAnalytics()->GetCurrentLevel(intCallback);
}

// Prepare initialization
void DTDAnalyticsLibrary::SetLogLevel(GDDTDLogLevel::LogLevel logLevel) {
    PlatformHub::GetInstance().GetAnalytics()->SetLogLevel(logLevel);
}

void DTDAnalyticsLibrary::CoppaControlEnable() {
    PlatformHub::GetInstance().GetAnalytics()->CoppaControlEnable();
}

void DTDAnalyticsLibrary::SetInitializationCompleteCallback(const Callable &callback) {
    listOfVoidCallbacks.push_back(callback);
    PlatformHub::GetInstance().GetAnalytics()->SetInitializationCompleteCallback(voidCallback);
}

void DTDAnalyticsLibrary::SetIdentifiersCallback(const Callable &callback) {
    identifierCallback = callback;
    PlatformHub::GetInstance().GetAnalytics()->SetIdentifiersCallback(identifierCallback);
}


void DTDAnalyticsLibrary::Initialize(const String &appKey) {
    PlatformHub::GetInstance().GetAnalytics()->Initialize(appKey);
}

void DTDAnalyticsLibrary::InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration){
    PlatformHub::GetInstance().GetAnalytics()->InitializeWithConfig(appKey, configuration);
}

void DTDAnalyticsLibrary::InitializeWithAbTest(const String &appKey, 
                                            const Callable &onRemoteConfigChange, 
                                            const Callable &onRemoteConfigPrepareToChange, 
                                            const Callable &onRemoteConfigReceive) {
    this->onRemoteConfigChange = onRemoteConfigChange;
    this->onRemoteConfigPrepareToChange = onRemoteConfigPrepareToChange;
    this->onRemoteConfigReceive = onRemoteConfigReceive;

    PlatformHub::GetInstance().GetAnalytics()->InitializeWithAbTest(appKey, this->tryOnRemoteConfigChange, this->tryOnRemoteConfigPrepareToChange, this->tryOnRemoteConfigReceive);
}

void DTDAnalyticsLibrary::InitializeWithConfigWithAbTest(const String &appKey, 
                                                        const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                                        const Callable &onRemoteConfigChange,
                                                        const Callable &onRemoteConfigPrepareToChange, 
                                                        const Callable &onRemoteConfigReceive) {                                      
    this->onRemoteConfigChange = onRemoteConfigChange;
    this->onRemoteConfigPrepareToChange = onRemoteConfigPrepareToChange;
    this->onRemoteConfigReceive = onRemoteConfigReceive;

    PlatformHub::GetInstance().GetAnalytics()->InitializeWithConfigWithAbTest(appKey, configuration, this->tryOnRemoteConfigChange, this->tryOnRemoteConfigPrepareToChange, this->tryOnRemoteConfigReceive);
}

// Events

void DTDAnalyticsLibrary::CustomEvent(const String& eventName) {
    PlatformHub::GetInstance().GetAnalytics()->CustomEvent(eventName);
}

void DTDAnalyticsLibrary::CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params) {
    PlatformHub::GetInstance().GetAnalytics()->CustomEventWithParams(eventName, params);
}

void DTDAnalyticsLibrary::CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType) {
    PlatformHub::GetInstance().GetAnalytics()->CurrencyAccrual(currencyName, currencyAmount, source, accrualType);
}

void DTDAnalyticsLibrary::LevelUp(const int32_t &level)
{
    PlatformHub::GetInstance().GetAnalytics()->LevelUp(level);
}

void DTDAnalyticsLibrary::LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance)
{
    PlatformHub::GetInstance().GetAnalytics()->LevelUpWithBalance(level, balance);
}

void DTDAnalyticsLibrary::CurrentBalance(const Ref<GDDTDInt64Resources>& balance) {
    PlatformHub::GetInstance().GetAnalytics()->CurrentBalance(balance);
}

void DTDAnalyticsLibrary::VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency) {
    PlatformHub::GetInstance().GetAnalytics()->VirtualCurrencyPayment(purchaseId, purchaseType, purchaseAmount, purchasePrice, purchaseCurrency);
}

void DTDAnalyticsLibrary::VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources) {
    PlatformHub::GetInstance().GetAnalytics()->VirtualCurrencyPaymentWithResources(purchaseId, purchaseType, purchaseAmount, resources);
}

void DTDAnalyticsLibrary::AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit) {
    PlatformHub::GetInstance().GetAnalytics()->AdImpression(socialNetwork, revenue, placement, unit);
}

void DTDAnalyticsLibrary::RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode) {
    PlatformHub::GetInstance().GetAnalytics()->RealCurrencyPayment(orderId, price, productId, currencyCode);
}

void DTDAnalyticsLibrary::Tutorial(int32_t step) {
    PlatformHub::GetInstance().GetAnalytics()->Tutorial(step);
}

void DTDAnalyticsLibrary::StartProgressionEvent(const String& eventName) {
    PlatformHub::GetInstance().GetAnalytics()->StartProgressionEvent(eventName);
}

void DTDAnalyticsLibrary::StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params) {
    PlatformHub::GetInstance().GetAnalytics()->StartProgressionEventWithParams(eventName, params);
}

void DTDAnalyticsLibrary::FinishProgressionEvent(const String& eventName)
{
	PlatformHub::GetInstance().GetAnalytics()->FinishProgressionEvent(eventName);
}

void DTDAnalyticsLibrary::FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params)
{
	PlatformHub::GetInstance().GetAnalytics()->FinishProgressionEventWithParams(eventName, params);
}

void DTDAnalyticsLibrary::SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork) {
    PlatformHub::GetInstance().GetAnalytics()->SocialNetworkConnect(socialNetwork);
}

void DTDAnalyticsLibrary::SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason) {
    PlatformHub::GetInstance().GetAnalytics()->SocialNetworkPost(socialNetwork, reason);
}

void DTDAnalyticsLibrary::Referrer(Ref<GDDTDReferralProperty> utmData){
    PlatformHub::GetInstance().GetAnalytics()->Referrer(utmData);
}

void DTDAnalyticsLibrary::SendBufferedEvents() {
    PlatformHub::GetInstance().GetAnalytics()->SendBufferedEvents();
}

void DTDAnalyticsLibrary::_bind_methods() {
    ClassDB::bind_method(D_METHOD("GetDeviceId", "onResult"), &DTDAnalyticsLibrary::GetDeviceId);
    ClassDB::bind_method(D_METHOD("GetSdkVersion", "onResult"), &DTDAnalyticsLibrary::GetSdkVersion);
    ClassDB::bind_method(D_METHOD("SetTrackingAvailability", "value"), &DTDAnalyticsLibrary::SetTrackingAvailability);
    ClassDB::bind_method(D_METHOD("GetTrackingAvailability", "onResult"), &DTDAnalyticsLibrary::GetTrackingAvailability);
    ClassDB::bind_method(D_METHOD("GetUserId", "onResult"), &DTDAnalyticsLibrary::GetUserId);
    ClassDB::bind_method(D_METHOD("SetUserId", "userId"), &DTDAnalyticsLibrary::SetUserId);
    ClassDB::bind_method(D_METHOD("ReplaceUserId", "fromUserId", "toUserId"), &DTDAnalyticsLibrary::ReplaceUserId);
    ClassDB::bind_method(D_METHOD("GetCurrentLevel", "onResult"), &DTDAnalyticsLibrary::GetCurrentLevel);
    ClassDB::bind_method(D_METHOD("SetCurrentLevel", "level"), &DTDAnalyticsLibrary::SetCurrentLevel);
    ClassDB::bind_method(D_METHOD("SetLogLevel", "logLevel"), &DTDAnalyticsLibrary::SetLogLevel);
    ClassDB::bind_method(D_METHOD("CoppaControlEnable"), &DTDAnalyticsLibrary::CoppaControlEnable);
    ClassDB::bind_method(D_METHOD("SetInitializationCompleteCallback", "callback"), &DTDAnalyticsLibrary::SetInitializationCompleteCallback);
    ClassDB::bind_method(D_METHOD("SetIdentifiersCallback", "callback"), &DTDAnalyticsLibrary::SetIdentifiersCallback);

    ClassDB::bind_method(D_METHOD("Initialize", "applicationKey"), &DTDAnalyticsLibrary::Initialize);
    ClassDB::bind_method(D_METHOD("InitializeWithConfig", "applicationKey", "dtdAnalyticsConfiguration"), &DTDAnalyticsLibrary::InitializeWithConfig);

    ClassDB::bind_method(D_METHOD("CustomEvent", "eventName"), &DTDAnalyticsLibrary::CustomEvent);
    ClassDB::bind_method(D_METHOD("CustomEventWithParams", "eventName", "params"), &DTDAnalyticsLibrary::CustomEventWithParams);
    ClassDB::bind_method(D_METHOD("CurrencyAccrual", "currencyName", "currencyAmount", "source", "accrualType"), &DTDAnalyticsLibrary::CurrencyAccrual);
    ClassDB::bind_method(D_METHOD("LevelUp", "level"), &DTDAnalyticsLibrary::LevelUp);
    ClassDB::bind_method(D_METHOD("LevelUpWithBalance", "level", "balance"), &DTDAnalyticsLibrary::LevelUpWithBalance);
    ClassDB::bind_method(D_METHOD("CurrentBalance", "balance"), &DTDAnalyticsLibrary::CurrentBalance);
    ClassDB::bind_method(D_METHOD("VirtualCurrencyPayment", "purchaseId", "purchaseType", "purchaseAmount", "purchasePrice", "purchaseCurrency"), &DTDAnalyticsLibrary::VirtualCurrencyPayment);
    ClassDB::bind_method(D_METHOD("VirtualCurrencyPaymentWithResources", "purchaseId", "purchaseType", "purchaseAmount", "resources"), &DTDAnalyticsLibrary::VirtualCurrencyPaymentWithResources);
    ClassDB::bind_method(D_METHOD("AdImpression", "socialNetwork", "revenue", "placement", "unit"), &DTDAnalyticsLibrary::AdImpression);
    ClassDB::bind_method(D_METHOD("RealCurrencyPayment", "orderId", "price", "productId", "currencyCode"), &DTDAnalyticsLibrary::RealCurrencyPayment);
    ClassDB::bind_method(D_METHOD("Tutorial", "step"), &DTDAnalyticsLibrary::Tutorial);
    ClassDB::bind_method(D_METHOD("StartProgressionEvent", "eventName"), &DTDAnalyticsLibrary::StartProgressionEvent);
    ClassDB::bind_method(D_METHOD("StartProgressionEventWithParams", "eventName", "params"), &DTDAnalyticsLibrary::StartProgressionEventWithParams);
    ClassDB::bind_method(D_METHOD("FinishProgressionEvent", "eventName"), &DTDAnalyticsLibrary::FinishProgressionEvent);
    ClassDB::bind_method(D_METHOD("FinishProgressionEventWithParams", "eventName", "params"), &DTDAnalyticsLibrary::FinishProgressionEventWithParams);
    ClassDB::bind_method(D_METHOD("SocialNetworkConnect", "socialNetwork"), &DTDAnalyticsLibrary::SocialNetworkConnect);
    ClassDB::bind_method(D_METHOD("SocialNetworkPost", "socialNetwork", "reason"), &DTDAnalyticsLibrary::SocialNetworkPost);
    ClassDB::bind_method(D_METHOD("Referrer", "utmData"), &DTDAnalyticsLibrary::Referrer);
    ClassDB::bind_method(D_METHOD("SendBufferedEvents"), &DTDAnalyticsLibrary::SendBufferedEvents);

    ClassDB::bind_method(D_METHOD("InitializeWithAbTest", "appKey", "onRemoteConfigChange", "onRemoteConfigPrepareToChange", "onRemoteConfigReceive"), &DTDAnalyticsLibrary::InitializeWithAbTest);
    ClassDB::bind_method(D_METHOD("InitializeWithConfigWithAbTest", "appnKey", "configuration", "onRemoteConfigChange", "onRemoteConfigPrepareToChange", "onRemoteConfigReceive"), &DTDAnalyticsLibrary::InitializeWithConfigWithAbTest);
}

// Private
void DTDAnalyticsLibrary::ProcessStringCallback(const String &value) {
    Callable callback = listOfStringCallbacks.front()->get();
    listOfStringCallbacks.pop_front();
    ProcessCallback(Variant(value), callback);
}

void DTDAnalyticsLibrary::ProcessIntCallback(const int64_t &value) {
    Callable callback = listOfIntCallbacks.front()->get();
    listOfIntCallbacks.pop_front();
	ProcessCallback(Variant(value), callback);
}

void DTDAnalyticsLibrary::ProcessBoolCallback(const bool &value) {
    Callable callback = listOfBoolCallbacks.front()->get();
    listOfBoolCallbacks.pop_front();
	ProcessCallback(Variant(value), callback);
}

void DTDAnalyticsLibrary::ProcessVoidCallback() {
    Callable callback = listOfVoidCallbacks.front()->get();
    listOfVoidCallbacks.pop_front();
    Variant returnValue;

    Callable::CallError error;
    callback.callp(nullptr, 0, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
        print_line("Call inposible");
    }
}

void DTDAnalyticsLibrary::ProcessCallback(const Callable &callback) {
	Variant returnValue;

    Callable::CallError error;
    callback.callp(nullptr, 0, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
        print_line("Call inposible");
    }
}

void DTDAnalyticsLibrary::ProcessCallback(const Variant &value, const Callable &callback) {
	const Variant *args[1] = { &value };
	Variant returnValue;

    Callable::CallError error;
    callback.callp(args, 1, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
        print_line("Call inposible");
    }
}

void DTDAnalyticsLibrary::ProcessCallback(const Variant &value, const Variant &value1, const Callable &callback) {
	const Variant *args[2] = { &value, &value1};
	Variant returnValue;

    Callable::CallError error;
    callback.callp(args, 2, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
        print_line("Call inposible");
    }
}
