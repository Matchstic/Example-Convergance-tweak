#line 1 "/Users/Matt/iOS/Projects/Convergance/Convergance/Interface tweaks/example-cvtweak.4x4toggles/example-cvtweak.4x4toggles/Tweak.xm"









#import "Headers/Convergance.h"

#define is_IOS7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) && ([[[UIDevice currentDevice] systemVersion] floatValue] < 8.0)
#define is_IOS6 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) && ([[[UIDevice currentDevice] systemVersion] floatValue] < 7.0)
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define IS_IPHONE_5 ([[UIScreen mainScreen] bounds].size.height == 568.0f)



@interface SpringBoard
-(CVLockController*)converganceLs;
@end







#include <logos/logos.h>
#include <substrate.h>
@class SBLockScreenManager; @class SBAwayController; 


#line 30 "/Users/Matt/iOS/Projects/Convergance/Convergance/Interface tweaks/example-cvtweak.4x4toggles/example-cvtweak.4x4toggles/Tweak.xm"
static void (*_logos_orig$iOS6$SBAwayController$lock)(SBAwayController*, SEL); static void _logos_method$iOS6$SBAwayController$lock(SBAwayController*, SEL); 



static void _logos_method$iOS6$SBAwayController$lock(SBAwayController* self, SEL _cmd) {
    _logos_orig$iOS6$SBAwayController$lock(self, _cmd);

    
    CVLockController *conv = [(SpringBoard*)[UIApplication sharedApplication] converganceLs];
        
    CGRect frame = CGRectMake(SCREEN_WIDTH*0.2, SCREEN_HEIGHT*0.25, SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.375);
    if (IS_IPHONE_5) {
        frame.size.height = SCREEN_HEIGHT*0.45;
        frame.origin.y = SCREEN_HEIGHT*0.235;
    }
    
    conv.toggles.collectionView.frame = frame;
}





static void (*_logos_orig$iOS7$SBLockScreenManager$lockUIFromSource$withOptions$)(SBLockScreenManager*, SEL, int, id); static void _logos_method$iOS7$SBLockScreenManager$lockUIFromSource$withOptions$(SBLockScreenManager*, SEL, int, id); 



static void _logos_method$iOS7$SBLockScreenManager$lockUIFromSource$withOptions$(SBLockScreenManager* self, SEL _cmd, int arg1, id arg2) {
    _logos_orig$iOS7$SBLockScreenManager$lockUIFromSource$withOptions$(self, _cmd, arg1, arg2);
    
    
    CVLockController *conv = [(SpringBoard*)[UIApplication sharedApplication] converganceLs];
        
    CGRect frame = CGRectMake(SCREEN_WIDTH*0.125, SCREEN_HEIGHT*0.2, SCREEN_WIDTH*0.75, SCREEN_HEIGHT*0.375);
    if (IS_IPHONE_5)
        frame.size.height = SCREEN_HEIGHT*0.45;
        
    conv.toggles.collectionView.frame = frame;
}





static __attribute__((constructor)) void _logosLocalCtor_4c282753() {
    {}
    if (is_IOS6)
        {Class _logos_class$iOS6$SBAwayController = objc_getClass("SBAwayController"); MSHookMessageEx(_logos_class$iOS6$SBAwayController, @selector(lock), (IMP)&_logos_method$iOS6$SBAwayController$lock, (IMP*)&_logos_orig$iOS6$SBAwayController$lock);}
    else
        {Class _logos_class$iOS7$SBLockScreenManager = objc_getClass("SBLockScreenManager"); MSHookMessageEx(_logos_class$iOS7$SBLockScreenManager, @selector(lockUIFromSource:withOptions:), (IMP)&_logos_method$iOS7$SBLockScreenManager$lockUIFromSource$withOptions$, (IMP*)&_logos_orig$iOS7$SBLockScreenManager$lockUIFromSource$withOptions$);}
}
