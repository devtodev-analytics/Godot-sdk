#include "core/string/print_string.h"

#include "IOSUserCard.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "IOSConverter.h"

IOSUserCard::IOSUserCard() { }

IOSUserCard::~IOSUserCard() { }

void IOSUserCard::SetCheater(const bool &value) {
	[::DTDUserCard setCheater:IOSConverter::ConvertToObjC(value)];
}

void IOSUserCard::SetTester(const bool &value) {
	[::DTDUserCard setTester:IOSConverter::ConvertToObjC(value)];
}

void IOSUserCard::SetString(const String &key, const String &value) {
    [::DTDUserCard setString:IOSConverter::Convert(key) value:IOSConverter::Convert(value)];
}

void IOSUserCard::TryGetString(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
		bool isValid;
		String result;
		if ([value isKindOfClass:[NSString class]]) { 
			isValid = true;
			result = String([value UTF8String]);
		} else if (value && [value respondsToSelector:@selector(stringValue)]) {
			isValid = true;
			result = String([[value stringValue] UTF8String]);
        } else {
			isValid = false;
			result = String("");
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void IOSUserCard::SetFloat(const String &key, const float &value) {
    [::DTDUserCard setDouble:IOSConverter::Convert(key) value:(double)value];
}

void IOSUserCard::TryGetFloat(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
		bool isValid;
		float result;
		if (value && [value respondsToSelector:@selector(doubleValue)]) {
			isValid = true;
			result = [value doubleValue];
        } else {
			isValid = false;
			result = 0.0;
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void IOSUserCard::SetInt(const String &key, const int64_t &value) {
    [::DTDUserCard setInt:IOSConverter::Convert(key) value:IOSConverter::ConvertInt64(value)];
}

void IOSUserCard::TryGetInt(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
		bool isValid;
		int64_t result;
		if (value && [value respondsToSelector:@selector(longLongValue)]) {
			isValid = true;
			result = [value longLongValue];
        } else {
			isValid = false;
			result = 0;
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void IOSUserCard::SetBool(const String &key, const bool &value) {
    [::DTDUserCard setBool:IOSConverter::Convert(key) value:IOSConverter::ConvertToObjC(value)];
}

void IOSUserCard::TryGetBool(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
		bool isValid;
		bool result;
		if (value && [value respondsToSelector:@selector(boolValue)]) {
			isValid = true;
			result = IOSConverter::ConvertToCpp([value boolValue]);
        } else {
			isValid = false;
			result = false;
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void IOSUserCard::Unset(const String &property) {
	[::DTDUserCard unsetProperty:IOSConverter::Convert(property)];
}

void IOSUserCard::UnsetArray(const PackedStringArray &properties) {
    const auto oco_keys = IOSConverter::Convert(properties);
	[::DTDUserCard unset:oco_keys];
}

void IOSUserCard::IncrementInteger(const String &key, const int64_t &value) {
	[::DTDUserCard increment:IOSConverter::Convert(key) byInt:IOSConverter::ConvertInt64(value)];
}

void IOSUserCard::IncrementFloat(const String &key, const float &value) {
	[::DTDUserCard increment:IOSConverter::Convert(key) byDouble:(double)value];
}

void IOSUserCard::ClearUser() {
	[::DTDUserCard clearUser];
}