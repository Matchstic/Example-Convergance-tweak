//
//  CVLockPasscodeView.h
//  Convergance
//
//  Created by Matt Clarke on 05/10/2013.
//
//

#import <UIKit/UIKit.h>
#import <UIKit2.framework/UIKeyboard.h>
#import "CVLockPasscodeButton.h"
#import "CVLockPasscodeTextView.h"
#import "CVReactiveButton.h"
#import <PhotoLibrary/PhotoLibrary.h>

@interface CVLockPasscodeView : UIView

@property (nonatomic, retain) CVReactiveButton *emergency;
@property (nonatomic, retain) CVReactiveButton *del;
@property (nonatomic, retain) UIImageView *delOrCancel;
@property (nonatomic, retain) UIView *dotContainer;

@property (readwrite) BOOL deleteButtonShowing;

@property (readwrite) BOOL isNumberPasscode;
@property (readwrite) BOOL needsOkayButton; // Returns YES if long numerical passcode
@property (readwrite) BOOL usesKeyboard; // returns YES if alphanumeric passcode

-(void)phoneHome:(BOOL)arg1; // Closes the passcode view

@end
