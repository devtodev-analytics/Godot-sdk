
#include "core/config/engine.h"

#include "DTDUserCardLibrary.h"
#include "private/platform/PlatformHub.h"


DTDUserCardLibrary::DTDUserCardLibrary() {
    tryGetStringValue = callable_mp(this, &DTDUserCardLibrary::ProcessTryGetStringCallback);
    tryGetFloatValue = callable_mp(this, &DTDUserCardLibrary::ProcessTryGetFloatCallback);
    tryGetIntValue = callable_mp(this, &DTDUserCardLibrary::ProcessTryGetIntCallback);
    tryGetBoolValue = callable_mp(this, &DTDUserCardLibrary::ProcessTryGetBoolCallback);
}

DTDUserCardLibrary::~DTDUserCardLibrary() {}

// Public methods

void DTDUserCardLibrary::SetCheater(const bool &value) {
    PlatformHub::GetInstance().GetUserCard()->SetCheater(value);
}

void DTDUserCardLibrary::SetTester(const bool &value) {
    PlatformHub::GetInstance().GetUserCard()->SetTester(value);
}

void DTDUserCardLibrary::SetString(const String &key, const String &value) {
    PlatformHub::GetInstance().GetUserCard()->SetString(key, value);
}

void DTDUserCardLibrary::TryGetString(const String &key, const Callable &callback){
    listOfStringCallbacks.push_back(callback);
    PlatformHub::GetInstance().GetUserCard()->TryGetString(key, tryGetStringValue);
}

void DTDUserCardLibrary::SetFloat(const String &key, const float &value) {
    PlatformHub::GetInstance().GetUserCard()->SetFloat(key, value);
}

void DTDUserCardLibrary::TryGetFloat(const String &key, const Callable &callback) {
    listOfFloatCallbacks.push_back(callback);
    PlatformHub::GetInstance().GetUserCard()->TryGetFloat(key, tryGetFloatValue);
}

void DTDUserCardLibrary::SetInt(const String &key, const int64_t &value) {
    PlatformHub::GetInstance().GetUserCard()->SetInt(key, value);
}

void DTDUserCardLibrary::TryGetInt(const String &key, const Callable &callback) {
    listOfIntCallbacks.push_back(callback);
    PlatformHub::GetInstance().GetUserCard()->TryGetInt(key, tryGetIntValue);
}

void DTDUserCardLibrary::SetBool(const String &key, const bool &value) {
    PlatformHub::GetInstance().GetUserCard()->SetBool(key, value);
}

void DTDUserCardLibrary::TryGetBool(const String &key, const Callable &callback) {
    listOfBoolCallbacks.push_back(callback);
    PlatformHub::GetInstance().GetUserCard()->TryGetBool(key, tryGetBoolValue);
}

void DTDUserCardLibrary::Unset(const String &property) {
    PlatformHub::GetInstance().GetUserCard()->Unset(property);
}

void DTDUserCardLibrary::UnsetArray(const PackedStringArray &properties) {
    PlatformHub::GetInstance().GetUserCard()->UnsetArray(properties);
}

void DTDUserCardLibrary::IncrementInteger(const String &key, const int64_t &value) {
    PlatformHub::GetInstance().GetUserCard()->IncrementInteger(key, value);
}

void DTDUserCardLibrary::IncrementFloat(const String &key, const float &value) {
    PlatformHub::GetInstance().GetUserCard()->IncrementFloat(key, value);
}

void DTDUserCardLibrary::ClearUser() {
    PlatformHub::GetInstance().GetUserCard()->ClearUser();
}

// Private methods

void DTDUserCardLibrary::ProcessTryGetStringCallback(const bool &isValid, const String &value) {
    Callable callback = listOfStringCallbacks.front()->get();
    listOfStringCallbacks.pop_front();
    ProcessCallback(Variant(isValid), Variant(value), callback);
}

void DTDUserCardLibrary::ProcessTryGetFloatCallback(const bool &isValid, const float &value) {
    Callable callback = listOfFloatCallbacks.front()->get();
    listOfFloatCallbacks.pop_front();
	ProcessCallback(Variant(isValid), Variant(value), callback);
}

void DTDUserCardLibrary::ProcessTryGetIntCallback(const bool &isValid, const int64_t &value) {
    Callable callback = listOfIntCallbacks.front()->get();
    listOfIntCallbacks.pop_front();
	ProcessCallback(Variant(isValid), Variant(value), callback);
}

void DTDUserCardLibrary::ProcessTryGetBoolCallback(const bool &isValid, const bool &value) {
    Callable callback = listOfBoolCallbacks.front()->get();
    listOfBoolCallbacks.pop_front();
	ProcessCallback(Variant(isValid), Variant(value), callback);
}

void DTDUserCardLibrary::ProcessCallback(const Variant &isValid, const Variant &value, const Callable &callback) {
	const Variant *args[2] = { &isValid, &value};
	Variant returnValue;

    Callable::CallError error;
    callback.callp(args, 2, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
        print_line("Call inposible");
    }
}

void DTDUserCardLibrary::_bind_methods() {
    ClassDB::bind_method(D_METHOD("SetCheater", "value"), &DTDUserCardLibrary::SetCheater);
    ClassDB::bind_method(D_METHOD("SetTester", "value"), &DTDUserCardLibrary::SetTester);
    ClassDB::bind_method(D_METHOD("SetString", "key", "value"), &DTDUserCardLibrary::SetString);
    ClassDB::bind_method(D_METHOD("TryGetString", "key", "callback"), &DTDUserCardLibrary::TryGetString);
    ClassDB::bind_method(D_METHOD("SetFloat", "key", "value"), &DTDUserCardLibrary::SetFloat);
    ClassDB::bind_method(D_METHOD("TryGetFloat", "key", "callback"), &DTDUserCardLibrary::TryGetFloat);
    ClassDB::bind_method(D_METHOD("SetInt", "key", "value"), &DTDUserCardLibrary::SetInt);
    ClassDB::bind_method(D_METHOD("TryGetInt", "key", "callback"), &DTDUserCardLibrary::TryGetInt);
    ClassDB::bind_method(D_METHOD("SetBool", "key", "value"), &DTDUserCardLibrary::SetBool);
    ClassDB::bind_method(D_METHOD("TryGetBool", "key", "callback"), &DTDUserCardLibrary::TryGetBool);
    ClassDB::bind_method(D_METHOD("Unset", "property"), &DTDUserCardLibrary::Unset);
    ClassDB::bind_method(D_METHOD("UnsetArray", "properties"), &DTDUserCardLibrary::UnsetArray);
    ClassDB::bind_method(D_METHOD("IncrementInteger", "key", "value"), &DTDUserCardLibrary::IncrementInteger);
    ClassDB::bind_method(D_METHOD("IncrementFloat", "key", "value"), &DTDUserCardLibrary::IncrementFloat);
    ClassDB::bind_method(D_METHOD("ClearUser"), &DTDUserCardLibrary::ClearUser);
}