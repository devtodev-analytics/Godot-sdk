#pragma once

#include "core/object/ref_counted.h"

class GDDTDRemoteConfigReceiveResult: public RefCounted 
{ 
    GDCLASS(GDDTDRemoteConfigReceiveResult, RefCounted);

    public:
        enum ReceiveResult
            {   
                Failure = 0, 
                Success = 1,
                Empty = 2
            };

    protected:        
        static void _bind_methods();
};

VARIANT_ENUM_CAST(GDDTDRemoteConfigReceiveResult::ReceiveResult);