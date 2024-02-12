#include "DTDReferralProperty.h"


GDDTDReferralProperty::GDDTDReferralProperty(){
}

GDDTDReferralProperty::~GDDTDReferralProperty(){

}

void GDDTDReferralProperty::AddSource(const String &value){
    map.insert("Source", value);
}

void GDDTDReferralProperty::AddCampaign(const String &value){
    map.insert("Campaign", value);
}

void GDDTDReferralProperty::AddContent(const String &value){
    map.insert("Content", value);
}

void GDDTDReferralProperty::AddMedium(const String &value){
    map.insert("Medium", value);
}

void GDDTDReferralProperty::AddTerm(const String &value){
    map.insert("Term", value);
}

HashMap<String ,String> GDDTDReferralProperty::getReferralData() const {
    return map;
}

void GDDTDReferralProperty::_bind_methods(){
    ClassDB::bind_method(D_METHOD("AddSource", "value"), &GDDTDReferralProperty::AddSource);
    ClassDB::bind_method(D_METHOD("AddCampaign", "value"), &GDDTDReferralProperty::AddCampaign);
    ClassDB::bind_method(D_METHOD("AddContent", "value"), &GDDTDReferralProperty::AddContent);
    ClassDB::bind_method(D_METHOD("AddMedium", "value"), &GDDTDReferralProperty::AddMedium);
    ClassDB::bind_method(D_METHOD("AddTerm", "value"), &GDDTDReferralProperty::AddTerm);
}