#pragma once

#include "core/object/ref_counted.h"

class GDDTDTrackingStatus: public RefCounted 
{ 
    GDCLASS(GDDTDTrackingStatus, RefCounted);

    public:
        enum TrackingStatus
            {   
                Unknown = 0, 
                Enable = 1, 
                Disable = 2,
            };

    protected:        
        static void _bind_methods();
};

VARIANT_ENUM_CAST(GDDTDTrackingStatus::TrackingStatus);