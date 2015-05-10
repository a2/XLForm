//
//  testHideAndShow.m
//  XLForm Tests
//
//  Created by mathias Claassen on 10/4/15.
//
//

#import <UIKit/UIKit.h>
#import "XLTestCase.h"


static NSString * const kTextFieldCellTag = @"TextTag";
static NSString * const kIntegerFieldCellTag = @"IntegerTag";
static NSString * const kDisabledFieldCellTag = @"DisabledTag";

@interface XLFormDescriptor (_XLTestAdditions)

@property (readonly) NSMutableDictionary* allRowsByTag;
@property NSMutableDictionary* rowObservers;

@end

@interface XLTestHideAndShow : XLTestCase
@end

@implementation XLTestHideAndShow

- (void)testBasicPredicates {
    // Get the tableView
    UITableView * tableView = self.formController.tableView;
    
    // Check if the tableView matches with the form descriptor
    XCTAssertEqual([tableView numberOfSections], 2);
    XCTAssertEqual([tableView numberOfRowsInSection:0], 2);

    XLFormTextFieldCell * textFieldCell = (XLFormTextFieldCell*) [tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
    XLFormTextFieldCell * disabledFieldCell = (XLFormTextFieldCell*) [tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:1 inSection:0]];
    
    //Let's disable the row of the second section. The second row of the first section should hide.
    textFieldCell.rowDescriptor.value = @"dis";

    XCTAssertTrue(disabledFieldCell.rowDescriptor.isDisabled);

    XCTAssertEqual([tableView numberOfSections], 2);
    XCTAssertEqual([tableView numberOfRowsInSection:0], 1);

    // Now hide the second section. As the row will be enabled, the second row of the first section should reappear
    textFieldCell.rowDescriptor.value = @"hide that section";

    XCTAssertFalse(disabledFieldCell.rowDescriptor.isDisabled);

    XCTAssertEqual([tableView numberOfSections], 1);
    XCTAssertEqual([tableView numberOfRowsInSection:0], 2);

    //Now we disable the last row (even if its hidden) and consecuently the second row hides again.
    textFieldCell.rowDescriptor.value = @"dishide";

    XCTAssertEqual([tableView numberOfSections], 1);
    XCTAssertEqual([tableView numberOfRowsInSection:0], 1);

    //Now everything should be as at the beginning
    textFieldCell.rowDescriptor.value = @"Hello World";

    XCTAssertEqual([tableView numberOfSections], 2);
    XCTAssertEqual([tableView numberOfRowsInSection:0], 2);
}

-(void)testInternalDataStructures{
    UITableView * tableView = self.formController.tableView;
    
    XLFormRowDescriptor* disabledRow = ((XLFormTextFieldCell*) [tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:1]]).rowDescriptor;
    NSMutableDictionary* deps = self.formController.form.rowObservers;
    NSMutableDictionary* rows = self.formController.form.allRowsByTag;

    XCTAssertEqualObjects(rows[kDisabledFieldCellTag], disabledRow);
    XCTAssertEqualObjects(rows[kIntegerFieldCellTag], ((XLFormTextFieldCell*) [tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:1 inSection:0]]).rowDescriptor);
    XCTAssertEqualObjects(rows[kTextFieldCellTag], ((XLFormTextFieldCell*) [tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]]).rowDescriptor);

    XCTAssertEqualObjects(deps[[kDisabledFieldCellTag formKeyForPredicateType:XLPredicateTypeHidden]], @[kIntegerFieldCellTag]);
    XCTAssertNil(deps[[kIntegerFieldCellTag formKeyForPredicateType:XLPredicateTypeHidden]]);
    XCTAssertEqualObjects(deps[[kTextFieldCellTag formKeyForPredicateType:XLPredicateTypeHidden]], @[disabledRow.sectionDescriptor]);
    XCTAssertEqualObjects(deps[[kTextFieldCellTag formKeyForPredicateType:XLPredicateTypeDisabled]], @[kDisabledFieldCellTag]);

}

#pragma mark - Build Form

-(void)buildForm
{
    XLFormDescriptor * form = [XLFormDescriptor formDescriptor];
    self.formController.form = form;
    
    XLFormSectionDescriptor * section = [XLFormSectionDescriptor formSection];
    [self.formController.form addFormSection:section];
    
    XLFormRowDescriptor * row = [XLFormRowDescriptor formRowDescriptorWithTag:kTextFieldCellTag rowType:XLFormRowDescriptorTypeText title:@"Title"];
    [section addFormRow:row];
    
    XLFormRowDescriptor * row2 = [XLFormRowDescriptor formRowDescriptorWithTag:kIntegerFieldCellTag rowType:XLFormRowDescriptorTypeInteger title:@"Number"];
    row2.hidden = [NSString stringWithFormat:@"$%@.isDisabled == 1", kDisabledFieldCellTag];
    [section addFormRow:row2];
    
    XLFormSectionDescriptor * section2 = [XLFormSectionDescriptor formSection];
    section2.hidden = [NSString stringWithFormat:@"$%@ contains[c] 'hide'", row];
    [self.formController.form addFormSection:section2];
    
    XLFormRowDescriptor * row3 = [XLFormRowDescriptor formRowDescriptorWithTag:kDisabledFieldCellTag rowType:XLFormRowDescriptorTypeEmail title:@"Email"];
    row3.disabled = [NSString stringWithFormat:@"$%@ contains[c] 'dis'", row];
    [section2 addFormRow:row3];
    
}


@end
