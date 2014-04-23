//
//  CVLockUpArrow.h
//  Convergance
//
//  Created by Matt Clarke on 12/07/2013.
//
//

#import <UIKit/UIKit.h>

@interface CVLockUpArrow : UIView <UIGestureRecognizerDelegate>

@property (nonatomic, retain) UIImageView *up;
@property (readwrite) BOOL isDragging;

-(id)initWithFrame:(CGRect)frame;
-(void)bounce;

@end
