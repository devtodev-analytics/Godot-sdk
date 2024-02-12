#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DTDLogLevel.h"
#include "DTDTrackingStatus.h"

class GDDTDAnalyticsConfiguration: public RefCounted
{
    GDCLASS(GDDTDAnalyticsConfiguration, RefCounted);

private:
	bool levelIsChanged;
    bool userIdIsChanged;

	void SetCurrentLevel(const int32_t &value);
	int32_t GetCurrentLevel();
	
	void SetUserId(const String &userId);
	String GetUserId();

	void SetLogLevel(GDDTDLogLevel::LogLevel logLevel);
	GDDTDLogLevel::LogLevel GetLogLevel();

	void SetTrackingStatus(GDDTDTrackingStatus::TrackingStatus trackingStatus);
	GDDTDTrackingStatus::TrackingStatus GetTrackingStatus();
	
protected:
    static void _bind_methods();

public:
	GDDTDLogLevel::LogLevel logLevel = GDDTDLogLevel::LogLevel::Unknown;
	GDDTDTrackingStatus::TrackingStatus trackingStatus = GDDTDTrackingStatus::TrackingStatus::Unknown;
	int32_t currentLevel;
	String userId;

	bool GetIsLevelChanged() const;
    bool GetIsUserIdChanged() const;
};