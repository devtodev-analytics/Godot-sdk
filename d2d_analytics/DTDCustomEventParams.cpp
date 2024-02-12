#include "core/config/engine.h"

#include "DTDCustomEventParams.h"

void GDDTDCustomEventParams::AddStringValue(const String &key, const String &value) {
    stringValues[key] = value;
}

void GDDTDCustomEventParams::AddIntegerValue(const String &key, const int64_t &value) {
    integerValues[key] = value;
}

void GDDTDCustomEventParams::AddFloatValue(const String &key, const float &value) {
    floatValues[key] = value;
}

void GDDTDCustomEventParams::AddBoolValue(const String &key, const bool &value) {
    boolValues[key] = value;
}

HashMap<String, String> GDDTDCustomEventParams::getStringValues() const {
    return stringValues;
}

HashMap<String, int64_t> GDDTDCustomEventParams::getIntegerValues() const {
    return integerValues;
}

HashMap<String, float> GDDTDCustomEventParams::getFloatValues() const {
    return floatValues;
}

HashMap<String, bool> GDDTDCustomEventParams::getBoolValues() const {
    return boolValues;
}

void GDDTDCustomEventParams::_bind_methods() {
    ClassDB::bind_method(D_METHOD("AddStringValue", "key", "value"), &GDDTDCustomEventParams::AddStringValue);
    ClassDB::bind_method(D_METHOD("AddIntegerValue", "key", "value"), &GDDTDCustomEventParams::AddIntegerValue);
    ClassDB::bind_method(D_METHOD("AddFloatValue", "key", "value"), &GDDTDCustomEventParams::AddFloatValue);
    ClassDB::bind_method(D_METHOD("AddBoolValue", "key", "value"), &GDDTDCustomEventParams::AddBoolValue);
}