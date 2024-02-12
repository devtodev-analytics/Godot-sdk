#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DTDRemoteConfigSource.h"

class GDDTDRemoteConfigValue: public RefCounted
{
    GDCLASS(GDDTDRemoteConfigValue, RefCounted);

private:
	
protected:
    static void _bind_methods();

public:
    GDDTDRemoteConfigValue() {}

	GDDTDRemoteConfigValue(String value) : StringValue(value) {}
	GDDTDRemoteConfigValue(float value) : FloatValue(value) {}
	GDDTDRemoteConfigValue(int value) : IntValue(value) {}
	GDDTDRemoteConfigValue(bool value) : BoolValue(value) {}

	GDDTDRemoteConfigSource::Source Source = GDDTDRemoteConfigSource::Source::Empty;
	String StringValue = "";
	float FloatValue = 0.0f;
	int IntValue = 0;
	bool BoolValue = false;

    GDDTDRemoteConfigSource::Source GetSource();
    String GetStringValue();
    float GetFloatValue();
    int GetIntValue();
    bool GetBoolValue();
};