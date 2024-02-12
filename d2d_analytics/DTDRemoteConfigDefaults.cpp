#include "DTDRemoteConfigDefaults.h"

void GDDTDRemoteConfigDefaults::AddStringValue(const String &key, const String &value) {
    stringValues[key] = value;
}

void GDDTDRemoteConfigDefaults::AddIntegerValue(const String &key, const int64_t &value) {
    integerValues[key] = value;
}

void GDDTDRemoteConfigDefaults::AddFloatValue(const String &key, const float &value) {
    floatValues[key] = value;
}

void GDDTDRemoteConfigDefaults::AddBoolValue(const String &key, const bool &value) {
    boolValues[key] = value;
}

HashMap<String, String> GDDTDRemoteConfigDefaults::getStringDefaults() const {
    return stringValues;
}

HashMap<String, int64_t> GDDTDRemoteConfigDefaults::getIntegerDefaults() const {
    return integerValues;
}

HashMap<String, float> GDDTDRemoteConfigDefaults::getFloatDefaults() const {
    return floatValues;
}

HashMap<String, bool> GDDTDRemoteConfigDefaults::getBoolDefaults() const {
    return boolValues;
}

void GDDTDRemoteConfigDefaults::_bind_methods() {
    ClassDB::bind_method(D_METHOD("AddStringValue", "key", "value"), &GDDTDRemoteConfigDefaults::AddStringValue);
    ClassDB::bind_method(D_METHOD("AddIntegerValue", "key", "value"), &GDDTDRemoteConfigDefaults::AddIntegerValue);
    ClassDB::bind_method(D_METHOD("AddFloatValue", "key", "value"), &GDDTDRemoteConfigDefaults::AddFloatValue);
    ClassDB::bind_method(D_METHOD("AddBoolValue", "key", "value"), &GDDTDRemoteConfigDefaults::AddBoolValue);
}