#include "core/string/print_string.h"

#include "AndroidUserCard.h"
#include "AndroidConverter.h"

const String signal_peopleCardGetString = "signal_peopleCardGetString";
const String signal_peopleCardGetFloat = "signal_peopleCardGetFloat";
const String signal_peopleCardGetInt = "signal_peopleCardGetInt";
const String signal_peopleCardGetBool = "signal_peopleCardGetBool";

const String pluginName = "Analytics";
const String message = pluginName + " plugin is not found";

AndroidUserCard::AndroidUserCard()
{
    Engine *engane = Engine::get_singleton();
	if (engane->has_singleton(pluginName)) {
		analyticsRef = engane->get_singleton_object(pluginName);
	} else {
		print_line("Analytics plugin not found");
	}
}

AndroidUserCard::~AndroidUserCard()
{
}

void AndroidUserCard::SetCheater(const bool &value)
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }   

    analyticsRef->call("setCheater", value);
}

void AndroidUserCard::SetTester(const bool &value) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setTester", value);
}

void AndroidUserCard::SetString(const String &key, const String &value) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setString", key, value);
}

void AndroidUserCard::TryGetString(const String &key, const Callable &callback) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_peopleCardGetString, callback) == false) {
        analyticsRef->connect(signal_peopleCardGetString, callback);
    }

    analyticsRef->call("tryGetString", key);
}

void AndroidUserCard::SetFloat(const String &key, const float &value) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setFloat", key, value);
}

void AndroidUserCard::TryGetFloat(const String &key, const Callable &callback) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_peopleCardGetFloat, callback) == false) {
        analyticsRef->connect(signal_peopleCardGetFloat, callback);
    }

     analyticsRef->call("tryGetFloat", key);
}

void AndroidUserCard::SetInt(const String &key, const int64_t &value) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String strValue = String(std::to_string(value).c_str());
    analyticsRef->call("setInt", key, strValue);
}

void AndroidUserCard::TryGetInt(const String &key, const Callable &callback) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_peopleCardGetInt, callback) == false) {
        analyticsRef->connect(signal_peopleCardGetInt, callback);
    }

    analyticsRef->call("tryGetInt", key);
}

void AndroidUserCard::SetBool(const String &key, const bool &value) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setBool", key, value);
}

void AndroidUserCard::TryGetBool(const String &key, const Callable &callback) 
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_peopleCardGetBool, callback) == false) {
        analyticsRef->connect(signal_peopleCardGetBool, callback);
    }

    analyticsRef->call("tryGetBool", key);
}

void AndroidUserCard::Unset(const String &property) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("unset", property);
}

void AndroidUserCard::UnsetArray(const PackedStringArray &properties) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    Array array;
    for (const String& str : properties)
	{
       array.push_back(str);
	}
    analyticsRef->call("unsetArray", array);
}

void AndroidUserCard::IncrementInteger(const String &key, const int64_t &value) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String data = AndroidConverter::Convert(key,value);
    analyticsRef->call("increment", data);
}

void AndroidUserCard::IncrementFloat(const String &key, const float &value) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String data = AndroidConverter::Convert(key,value);
    analyticsRef->call("increment", data);
}

void AndroidUserCard::ClearUser() {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
    
    analyticsRef->call("clearUser");
}