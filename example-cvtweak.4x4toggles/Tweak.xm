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

// Interface declarations
@interface CVAPI : NSObject
+(CVLockController*)mainWindow;
+(CVLockSlider*)mainScrollView;
@end

@interface CVResources : NSObject
+(BOOL)lockScreenEnabled;
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
    
    if ([objc_getClass("CVResources") lockScreenEnabled]) {
        // Adjust toggle frame
        CVLockController *conv = [objc_getClass("CVAPI") mainWindow];
    
        UIView *example = [[UIView alloc] initWithFrame:CGRectMake(SCREEN_WIDTH, 0, 50, 50)];
        example.backgroundColor = [UIColor blueColor];
    
        [[objc_getClass("CVAPI") mainScrollView] addSubview:example];
        
        CGRect frame = CGRectMake(SCREEN_WIDTH*0.2, SCREEN_HEIGHT*0.25, SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.375);
        if (IS_IPHONE_5) {
            frame.size.height = SCREEN_HEIGHT*0.45;
            frame.origin.y = SCREEN_HEIGHT*0.235;
        }
    
        conv.toggles.collectionView.frame = frame;
    }
}

%end

%end

static BOOL isLocked;

%group iOS7

%hook SBLockScreenManager

-(void)lockUIFromSource:(int)arg1 withOptions:(id)arg2 {
    %orig;
    
    if ([objc_getClass("CVResources") lockScreenEnabled] && !isLocked) {
        // Adjust toggle frame
        CVLockController *conv = [objc_getClass("CVAPI") mainWindow];
        
        UIView *example = [[UIView alloc] initWithFrame:CGRectMake(SCREEN_WIDTH, 0, 50, 50)];
        example.backgroundColor = [UIColor blueColor];
        
        [[objc_getClass("CVAPI") mainScrollView] addSubview:example];
        
        CGRect frame = CGRectMake(SCREEN_WIDTH*0.2, SCREEN_HEIGHT*0.25, SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.375);
        if (IS_IPHONE_5) {
            frame.size.height = SCREEN_HEIGHT*0.45;
            frame.origin.y = SCREEN_HEIGHT*0.235;
        }
        
        conv.toggles.collectionView.frame = frame;
        
        isLocked = YES;
    }
}

%end

%hook SBLockScreenViewController

-(void)deactivate {
    %orig;
    
    isLocked = NO;
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