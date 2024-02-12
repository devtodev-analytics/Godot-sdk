#include "register_types.h"
#include "core/config/engine.h"
#include "core/object/class_db.h"

#include "DTDAnalyticsLibrary.h"
#include "DTDUserCardLibrary.h"
#include "DTDRemoteConfigLibrary.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDLogLevel.h"
#include "DTDSocialNetwork.h"
#include "DTDReferralProperty.h"
#include "DTDCustomEventParams.h"
#include "DTDAccrualType.h"
#include "DTDInt32Resources.h"
#include "DTDInt64Resources.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDTrackingStatus.h"
#include "DTDRemoteConfigValue.h"
#include "DTDRemoteConfigSource.h"
#include "DTDRemoteConfigDefaults.h"
#include "DTDRemoteConfigReceiveResult.h"
#include "DTDRemoteConfigChangeResult.h"


static DTDAnalyticsLibrary* analyticsPtr = NULL;
static DTDUserCardLibrary* userCardPtr = NULL;
static DTDRemoteConfigLibrary* remoteConfigPtr = NULL;


void initialize_d2d_analytics_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_CORE) {
        ClassDB::register_class<DTDAnalyticsLibrary>();
        ClassDB::register_class<GDDTDAnalyticsConfiguration>();
        ClassDB::register_class<GDDTDLogLevel>();
        ClassDB::register_class<GDDTDSocialNetwork>();
        ClassDB::register_class<GDDTDReferralProperty>();
        ClassDB::register_class<GDDTDCustomEventParams>();
        ClassDB::register_class<GDDTDAccrualType>();
        ClassDB::register_class<GDDTDInt32Resources>();
        ClassDB::register_class<GDDTDInt64Resources>();
        ClassDB::register_class<GDDTDStartProgressionEventParams>();
        ClassDB::register_class<GDDTDFinishProgressionEventParams>();
        ClassDB::register_class<GDDTDTrackingStatus>();
        ClassDB::register_class<GDDTDRemoteConfigValue>();
        ClassDB::register_class<GDDTDRemoteConfigSource>();
        ClassDB::register_class<GDDTDRemoteConfigDefaults>();
        ClassDB::register_class<GDDTDRemoteConfigChangeResult>();
        ClassDB::register_class<GDDTDRemoteConfigReceiveResult>();

        ClassDB::register_class<DTDUserCardLibrary>();
        ClassDB::register_class<DTDRemoteConfigLibrary>();

        
        
        

        analyticsPtr = memnew(DTDAnalyticsLibrary);
        Engine::get_singleton()->add_singleton(Engine::Singleton("DTDAnalytics", analyticsPtr));

        userCardPtr = memnew(DTDUserCardLibrary);
        Engine::get_singleton()->add_singleton(Engine::Singleton("DTDUserCard", userCardPtr));

        remoteConfigPtr = memnew(DTDRemoteConfigLibrary);
        Engine::get_singleton()->add_singleton(Engine::Singleton("DTDRemoteConfig", remoteConfigPtr));
	}
}

void uninitialize_d2d_analytics_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_CORE) {
        if (analyticsPtr != NULL)
            memdelete(analyticsPtr);
        if (userCardPtr != NULL)
            memdelete(userCardPtr);
        if (remoteConfigPtr != NULL)
            memdelete(remoteConfigPtr);
    }
}