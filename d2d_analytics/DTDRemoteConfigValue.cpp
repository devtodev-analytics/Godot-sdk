#include "core/config/engine.h"
#include "DTDRemoteConfigValue.h"

GDDTDRemoteConfigSource::Source GDDTDRemoteConfigValue::GetSource()
{
    return Source;
}

String GDDTDRemoteConfigValue::GetStringValue()
{
    return StringValue;
}

float GDDTDRemoteConfigValue::GetFloatValue()
{
    return FloatValue;
}

int GDDTDRemoteConfigValue::GetIntValue()
{
    return IntValue;
}

bool GDDTDRemoteConfigValue::GetBoolValue()
{
    return BoolValue;
}

void GDDTDRemoteConfigValue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("GetSource"), &GDDTDRemoteConfigValue::GetSource);
    ClassDB::bind_method(D_METHOD("GetStringValue"), &GDDTDRemoteConfigValue::GetStringValue);
    ClassDB::bind_method(D_METHOD("GetFloatValue"), &GDDTDRemoteConfigValue::GetFloatValue);
    ClassDB::bind_method(D_METHOD("GetIntValue"), &GDDTDRemoteConfigValue::GetIntValue);
    ClassDB::bind_method(D_METHOD("GetBoolValue"), &GDDTDRemoteConfigValue::GetBoolValue);
}