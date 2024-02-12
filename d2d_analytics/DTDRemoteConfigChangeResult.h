#pragma once

#include "core/object/ref_counted.h"

class GDDTDRemoteConfigChangeResult: public RefCounted 
{ 
    GDCLASS(GDDTDRemoteConfigChangeResult, RefCounted);

    public:
        enum ChangeResult
            {   
                Failure = 0, 
                Success = 1
            };

    protected:        
        static void _bind_methods();
};

VARIANT_ENUM_CAST(GDDTDRemoteConfigChangeResult::ChangeResult);