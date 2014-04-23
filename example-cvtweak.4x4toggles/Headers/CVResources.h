//
//  CVResources.h
//  Convergance
//
//  Created by Matt Clarke on 21/07/2013.
//
//

#import <Foundation/Foundation.h>
#import <SpringBoard6.0/SBAwayBulletinListItem.h>
#import <BulletinBoard/BBBulletin.h>
#import <QuartzCore/QuartzCore.h>
#import <SpringBoard6.0/SBWorkspace.h>
#import <SpringBoard7.0/SBLockScreenViewController.h>
#import "UIImageAverageColorAddition.h"

@interface CVResources : NSObject

// Unlocking variables

+(void)setIsUnlocking:(BOOL)val; // Set this to deallocate Convergance on unlock
+(BOOL)getIsUnlocking;
+(BOOL)unlockedWithBulletin;
+(void)setUnlockedWithBulletin:(BOOL)val;
+(void)setDontAnimateOut:(BOOL)dontAnimate; // Prevent Convergance from animating while unlocking
+(BOOL)getDontAnimateOut;

// ===================================================

+(NSMutableArray*)getLockBulletinIds;
+(void)setLockFullscreenNotificationBundleId:(NSString*)bundleid;
+(NSString*)getLockFullscreenNotificationBundleId;
+(void)setShowingLockFullscreenNotification:(BOOL)enabled;
+(BOOL)getShowingLockFullscreenNotification;
+(void)setLockFullscreenBBBulletin:(id)bulletin;
+(BBBulletin*)getLockFullscreenBBBulletin;

// Easy way of checking whether some tweaks are enabled

+(BOOL)biteSMSQrEnabled;
+(BOOL)biteSMSEnabled;
+(BOOL)couriaEnabledForBulletin:(NSString*)arg1;
+(BOOL)isGuestModeEnabled;

// ===================================================

// Passcode detection - supports use of CleverPin etc

+(BOOL)deviceIsLocked;
// CVLockPasscodeView will provide further information about the passcode

// ===================================================

// Returns various images and strings used within Convergance appropriate to the current theme and device language

+(NSString*)themedResourceFilePathWithName:(NSString*)name andExtension:(NSString*)ext;
+(NSString*)themedBundleFilePathWithName:(NSString*)name;
+(NSString*)localisedStringForKey:(NSString*)key value:(NSString*)val;

// ===================================================

// Main Convergance settings

+(BOOL)lockScreenEnabled;
+(BOOL)showBatteryPercent;
+(NSArray*)lockWidgets;
+(NSArray*)lockToggles;
+(int)lockBlurRadius;
+(BOOL)isUsingLightFonts;
+(int)lockArtworkVariant;
+(BOOL)lockHTMLEnabled;
+(NSString*)lockHTMLTheme;
+(BOOL)lockHTMLDoesScroll;
+(BOOL)showDismissButton;
+(double)lockScreenIdleTime;
+(NSString*)htmlDirectory;
+(BOOL)fadeHTMLUnderNotif;
+(BOOL)showClock;
+(BOOL)dontUseCustomNotificationIcons;
+(BOOL)useSquareIcons;
+(BOOL)disableBatteryUI;
+(BOOL)disableIntensiveEffects;
+(BOOL)hasLightWallpaper;
+(UIColor*)adjustedColour;
+(BOOL)useTransparentText;

// ===================================================

// Used internally, but exposed if needed

+(SBLockScreenViewController*)lockScreenViewController;
+(void)reloadSettings;
+(void)reloadNotificationInformation;

// ===================================================

@end
