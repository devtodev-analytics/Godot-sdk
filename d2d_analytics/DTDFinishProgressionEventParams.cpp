#include "DTDFinishProgressionEventParams.h"

void GDDTDFinishProgressionEventParams::SetSuccessfulCompletion(const bool &successfulCompletion) {
    this->successfulCompletion = successfulCompletion;
}

void GDDTDFinishProgressionEventParams::SetDuration(const int32_t &duration) {
    this->duration = duration;
}

void GDDTDFinishProgressionEventParams::SetSpentResources(const Ref<GDDTDInt64Resources> &spent) {
    this->spent = spent;
}

void GDDTDFinishProgressionEventParams::SetEarnedResources(const Ref<GDDTDInt64Resources> &earned) {
    this->earned = earned;
}

bool GDDTDFinishProgressionEventParams::GetSuccessfulCompletion() const
{
    return successfulCompletion;
}

int32_t GDDTDFinishProgressionEventParams::GetDuration() const
{
    return duration;
}

Ref<GDDTDInt64Resources> GDDTDFinishProgressionEventParams::GetSpentResources() const
{
    return spent;
}

Ref<GDDTDInt64Resources> GDDTDFinishProgressionEventParams::GetEarnedResources() const
{
    return earned;
}

void GDDTDFinishProgressionEventParams::_bind_methods() {
    ClassDB::bind_method(D_METHOD("SetSuccessfulCompletion", "successfulCompletion"), &GDDTDFinishProgressionEventParams::SetSuccessfulCompletion);
    ClassDB::bind_method(D_METHOD("SetDuration", "duration"), &GDDTDFinishProgressionEventParams::SetDuration);
    ClassDB::bind_method(D_METHOD("SetSpentResources", "resources"), &GDDTDFinishProgressionEventParams::SetSpentResources);
    ClassDB::bind_method(D_METHOD("SetEarnedResources", "resources"), &GDDTDFinishProgressionEventParams::SetEarnedResources);
}
