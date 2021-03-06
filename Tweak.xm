// Example tweak for Convergance
//
// 4x4 Toggles
//
// (c) Matt Clarke, 2014

// As more features are added, new headers will be required - easiest way to obtain 
// these is by running class-dump against the latest dylib

#import "Headers/Convergance.h"

#define is_IOS7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) && ([[[UIDevice currentDevice] systemVersion] floatValue] < 8.0)
#define is_IOS6 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) && ([[[UIDevice currentDevice] systemVersion] floatValue] < 7.0)
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define IS_IPHONE_5 ([[UIScreen mainScreen] bounds].size.height == 568.0f)

// Interface declaration for accessing Convergance at runtime

@interface SpringBoard
-(CVLockController*)converganceLs;
@end

// Hooks
//
// On iOS 6, Convergance finishes init during -(void)lock; of SBAwayController.
// On iOS 7, it finishes init during -(void)_lockUI; of SBLockScreenManager, which
// is called by -(void)lockUIFromSource:(int)arg1 withOptions:(id)arg2;

%group iOS6

%hook SBAwayController

-(void)lock {
    %orig;

    // Adjust toggle frame
    CVLockController *conv = [(SpringBoard*)[UIApplication sharedApplication] converganceLs];
        
    CGRect frame = CGRectMake(SCREEN_WIDTH*0.125, SCREEN_HEIGHT*0.2, SCREEN_WIDTH*0.75, SCREEN_HEIGHT*0.375);
    if (IS_IPHONE_5)
        frame.size.height = SCREEN_HEIGHT*0.45;
        
    conv.toggles.collectionView.frame = frame;
}

%end

%end

%group iOS7

%hook SBLockScreenManager

-(void)lockUIFromSource:(int)arg1 withOptions:(id)arg2 {
    %orig;
    
    // Adjust toggle frame
    CVLockController *conv = [(SpringBoard*)[UIApplication sharedApplication] converganceLs];
        
    CGRect frame = CGRectMake(SCREEN_WIDTH*0.125, SCREEN_HEIGHT*0.2, SCREEN_WIDTH*0.75, SCREEN_HEIGHT*0.375);
    if (IS_IPHONE_5)
        frame.size.height = SCREEN_HEIGHT*0.45;
        
    conv.toggles.collectionView.frame = frame;
}

%end

%end

%ctor {
    %init;
    if (is_IOS6)
        %init(iOS6);
    else
        %init(iOS7);
}