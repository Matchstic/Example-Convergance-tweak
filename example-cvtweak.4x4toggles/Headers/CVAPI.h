//
//  CVAPI.h
//  Convergance
//
//  Created by Matt Clarke on 15/04/2014.
//
//

#import <Foundation/Foundation.h>
#import "CVLockController.h"
#import "CVResources.h"

@interface CVAPI : NSObject

// =================================================

// Interface

+(CVLockController*)mainWindow;
// The main UIWindow of Convergance. Default windowLevel property is 1060

+(CVLockSlider*)mainScrollView;
// By default, has three 'pages', with all UI elements except the widget container and the wallpapers shown on it.

+(CVLockToggleController*)toggleCollectionView;
+(CVLockNotificationView*)notificationCollectionView;

+(CVLockFeedSlider*)widgetContainerView;
// This contains a UIScrollView, which in turns holds all the widgets

+(CVLockSystemAlertWindow*)fullscreenAlertView;
// Only shown when eg. an alarm is set off

+(CVLockPasscodeView*)numericalPasscodeView;
// On iOS 6, this also returns the alphanumerical passcode view

+(CVLockUpArrow*)unlockSlidingView;
// The view containing the up arrow image

+(CVLockTimeContainerView*)timeDateAndMusicContainerView;
// All time, date, and music control handling is done in this view. It comprises of two further container views, one for music, and the other for displaying the time and date.

// ===================================================

// Backends

+(void)openPasscodeUI;
+(void)fadeAllWidgetsToOpacity:(float)arg1;
+(void)setAboutToUnlock:(BOOL)arg1;
+(void)fadeHTMLLockscreenToOpacity:(float)arg1;

// ===================================================

// CFNotificationCenter notifications
#define midnightPassed "com.matchstic.Convergance-significantTimeChange"
#define homeButtonPressed "com.matchstic.Convergance-homeButtonPressed"

// ===================================================

@end
