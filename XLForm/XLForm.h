//
//  XLForm.h
//  XLForm ( https://github.com/xmartlabs/XLForm )
//
//  Copyright (c) 2015 Xmartlabs ( http://xmartlabs.com )
//
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>

// Descriptors
#import <XLForm/XLFormDescriptor.h>
#import <XLForm/XLFormSectionDescriptor.h>
#import <XLForm/XLFormRowDescriptor.h>

// Categories
#import <XLForm/NSObject+XLFormAdditions.h>
#import <XLForm/NSString+XLFormAdditions.h>
#import <XLForm/NSArray+XLFormAdditions.h>
#import <XLForm/NSExpression+XLFormAdditions.h>
#import <XLForm/UIView+XLFormAdditions.h>
#import <XLForm/NSPredicate+XLFormAdditions.h>

// Helpers
#import <XLForm/XLFormOptionsObject.h>

// Controllers
#import <XLForm/XLFormOptionsViewController.h>
#import <XLForm/XLFormViewController.h>

// Protocols
#import <XLForm/XLFormDescriptorCell.h>
#import <XLForm/XLFormInlineRowDescriptorCell.h>
#import <XLForm/XLFormRowDescriptorViewController.h>

// Cells
#import <XLForm/XLFormBaseCell.h>
#import <XLForm/XLFormInlineSelectorCell.h>
#import <XLForm/XLFormTextFieldCell.h>
#import <XLForm/XLFormTextViewCell.h>
#import <XLForm/XLFormSelectorCell.h>
#import <XLForm/XLFormDatePickerCell.h>
#import <XLForm/XLFormButtonCell.h>
#import <XLForm/XLFormSwitchCell.h>
#import <XLForm/XLFormCheckCell.h>
#import <XLForm/XLFormDatePickerCell.h>
#import <XLForm/XLFormPickerCell.h>
#import <XLForm/XLFormLeftRightSelectorCell.h>
#import <XLForm/XLFormDateCell.h>
#import <XLForm/XLFormStepCounterCell.h>
#import <XLForm/XLFormSegmentedCell.h>
#import <XLForm/XLFormSliderCell.h>
#import <XLForm/XLFormRightDetailCell.h>
#import <XLForm/XLFormRightImageButton.h>

// Validation
#import <XLForm/XLFormRegexValidator.h>

extern NSString *const XLFormRowDescriptorTypeText;
extern NSString *const XLFormRowDescriptorTypeName;
extern NSString *const XLFormRowDescriptorTypeURL;
extern NSString *const XLFormRowDescriptorTypeEmail;
extern NSString *const XLFormRowDescriptorTypePassword;
extern NSString *const XLFormRowDescriptorTypeNumber;
extern NSString *const XLFormRowDescriptorTypePhone;
extern NSString *const XLFormRowDescriptorTypeTwitter;
extern NSString *const XLFormRowDescriptorTypeAccount;
extern NSString *const XLFormRowDescriptorTypeInteger;
extern NSString *const XLFormRowDescriptorTypeDecimal;
extern NSString *const XLFormRowDescriptorTypeTextView;
extern NSString *const XLFormRowDescriptorTypeSelectorPush;
extern NSString *const XLFormRowDescriptorTypeSelectorPopover;
extern NSString *const XLFormRowDescriptorTypeSelectorActionSheet;
extern NSString *const XLFormRowDescriptorTypeSelectorAlertView;
extern NSString *const XLFormRowDescriptorTypeSelectorPickerView;
extern NSString *const XLFormRowDescriptorTypeSelectorPickerViewInline;
extern NSString *const XLFormRowDescriptorTypeMultipleSelector;
extern NSString *const XLFormRowDescriptorTypeMultipleSelectorPopover;
extern NSString *const XLFormRowDescriptorTypeSelectorLeftRight;
extern NSString *const XLFormRowDescriptorTypeSelectorSegmentedControl;
extern NSString *const XLFormRowDescriptorTypeDateInline;
extern NSString *const XLFormRowDescriptorTypeDateTimeInline;
extern NSString *const XLFormRowDescriptorTypeTimeInline;
extern NSString *const XLFormRowDescriptorTypeCountDownTimerInline;
extern NSString *const XLFormRowDescriptorTypeDate;
extern NSString *const XLFormRowDescriptorTypeDateTime;
extern NSString *const XLFormRowDescriptorTypeTime;
extern NSString *const XLFormRowDescriptorTypeCountDownTimer;
extern NSString *const XLFormRowDescriptorTypeDatePicker;
extern NSString *const XLFormRowDescriptorTypePicker;
extern NSString *const XLFormRowDescriptorTypeSlider;
extern NSString *const XLFormRowDescriptorTypeBooleanCheck;
extern NSString *const XLFormRowDescriptorTypeBooleanSwitch;
extern NSString *const XLFormRowDescriptorTypeButton;
extern NSString *const XLFormRowDescriptorTypeInfo;
extern NSString *const XLFormRowDescriptorTypeStepCounter;
