#include "core/config/engine.h"

#include "DTDAnalyticsConfiguration.h"

void GDDTDAnalyticsConfiguration::SetLogLevel(GDDTDLogLevel::LogLevel level) {
    logLevel = level;
}

GDDTDLogLevel::LogLevel GDDTDAnalyticsConfiguration::GetLogLevel() {
    return logLevel;
}

void GDDTDAnalyticsConfiguration::SetTrackingStatus(GDDTDTrackingStatus::TrackingStatus status) {
    trackingStatus = status;
}

GDDTDTrackingStatus::TrackingStatus GDDTDAnalyticsConfiguration::GetTrackingStatus() {
    return trackingStatus;
}

void GDDTDAnalyticsConfiguration::SetCurrentLevel(const int32_t &level){
    levelIsChanged = true;
    currentLevel = level;
}

int32_t GDDTDAnalyticsConfiguration::GetCurrentLevel(){
    return currentLevel;
}
	
void GDDTDAnalyticsConfiguration::SetUserId(const String &id){
    userIdIsChanged = true;
    userId = id;
}

String GDDTDAnalyticsConfiguration::GetUserId(){
    return userId;
}

bool GDDTDAnalyticsConfiguration::GetIsLevelChanged() const {
    return levelIsChanged;
}

bool GDDTDAnalyticsConfiguration::GetIsUserIdChanged() const {
    return userIdIsChanged;
}

void GDDTDAnalyticsConfiguration::_bind_methods() {
    ClassDB::bind_method(D_METHOD("SetLogLevel", "logLevel"), &GDDTDAnalyticsConfiguration::SetLogLevel);
    ClassDB::bind_method(D_METHOD("GetLogLevel"), &GDDTDAnalyticsConfiguration::GetLogLevel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "logLevel", PROPERTY_HINT_ENUM, "Unknown, No, Error, Warning, Info, Debug"), "SetLogLevel", "GetLogLevel");

    ClassDB::bind_method(D_METHOD("SetTrackingStatus", "logLevel"), &GDDTDAnalyticsConfiguration::SetTrackingStatus);
    ClassDB::bind_method(D_METHOD("GetTrackingStatus"), &GDDTDAnalyticsConfiguration::GetTrackingStatus);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "trackingStatus", PROPERTY_HINT_ENUM, "Unknown, Enable, Disable"), "SetTrackingStatus", "GetTrackingStatus");

    ClassDB::bind_method(D_METHOD("SetCurrentLevel", "currentLevel"), &GDDTDAnalyticsConfiguration::SetCurrentLevel);
    ClassDB::bind_method(D_METHOD("GetCurrentLevel"), &GDDTDAnalyticsConfiguration::GetCurrentLevel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "currentLevel"),"SetCurrentLevel", "GetCurrentLevel");

    ClassDB::bind_method(D_METHOD("SetUserId", "userId"), &GDDTDAnalyticsConfiguration::SetUserId);
    ClassDB::bind_method(D_METHOD("GetUserId"), &GDDTDAnalyticsConfiguration::GetUserId);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "userId"), "SetUserId", "GetUserId");
}