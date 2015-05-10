//
//  XLFormTestCase.h
//  XLForm Tests
//
//  Created by Martin Barreto on 8/5/14.
//
//

#import <XCTest/XCTest.h>

#import <XLForm/XLForm.h>

@interface XLTestCase : XCTestCase

@property (nonatomic, strong) XLFormViewController * formController;

-(void)buildForm;

@end
