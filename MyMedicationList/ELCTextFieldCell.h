//
//  ELCTextFieldCell.h
//  ELC Utility
//
//  Copyright 2012 ELC Tech. All rights reserved.
//
/*The MIT License
 
 Copyright (c) 2012 ELC Technologies
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#import <UIKit/UIKit.h>

@class ELCTextFieldCell;

@interface ELCInsetTextField : UITextField

@property (nonatomic, assign) UIEdgeInsets inset;
@property (nonatomic, assign) UIEdgeInsets leftViewInset;

@end

@protocol ELCTextFieldDelegate <NSObject>

@optional
//Called to the delegate whenever return is hit when a user is typing into the rightTextField of an ELCTextFieldCell
- (BOOL)textFieldCell:(ELCTextFieldCell *)inCell shouldReturnForIndexPath:(NSIndexPath*)inIndexPath withValue:(NSString *)inValue;
//Called to the delegate whenever the text in the rightTextField is changed
- (void)textFieldCell:(ELCTextFieldCell *)inCell updateTextLabelAtIndexPath:(NSIndexPath *)inIndexPath string:(NSString *)inValue;

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;
- (void)textFieldDidBeginEditing:(UITextField *)textField;
- (void)textFieldDidEndEditing:(UITextField *)textField;

@end

@interface ELCTextFieldCell : UITableViewCell <UITextFieldDelegate>

@property (nonatomic, assign) id<ELCTextFieldDelegate> delegate;
@property (nonatomic, retain) UILabel *leftLabel;
@property (nonatomic, retain) ELCInsetTextField *rightTextField;
@property (nonatomic, retain) NSIndexPath *indexPath;

@end

@interface ELCInsetTextFieldCell : ELCTextFieldCell
@property (nonatomic, assign) UIEdgeInsets inset;
@end

