//
//  CVLockController.h
//  Convergance
//
//  Created by Matt Clarke on 11/07/2013.
//
//

#import <UIKit/UIKit.h>
#import <UIKit2.framework/UIWebDocumentView.h>
#import "CVLockUpArrow.h"
#import "CVLockToggleController.h"
#import "CVLockFeedSlider.h"
#import "CVLockSlider.h"
#import "CVLockCameraOverlayView.h"
#import "CVLockTimeContainerView.h"
#import "CVLockBrightnessSlider.h"
#import "CVLockNotificationView.h"
#import "CVLockPasscodeView.h"
#import "CVLockSystemAlertWindow.h"
#import "CVLockWebCoreWindow.h"
#import <SpringBoard6.0/SBApplication.h>
#import <PhotoLibrary/PLCameraPageController.h>
#import <PSTCollectionView/PSTCollectionView.h>
#import "CVLockHTMLBackgroundView.h"

#import <SpringBoard7.0/SBLockScreenCameraController.h>
#import <SpringBoard7.0/SBLockScreenViewController.h>
#import <SpringBoardUIServices.framework/SBUIBiometricEventMonitor.h>
#import <SpringBoardFoundation/SBFProceduralWallpaperView.h>
#import <SpringBoard7.0/SBWallpaperController.h>

#import <SpringBoardFoundation/SBFProceduralWallpaper.h>

#import "CVLockCommon.h"
#import <SKBounceAnimation/SKBounceAnimation.h>

@class CVLockController, CVLockNotificationView, CVLockTimeContainerView, WebView;

#define TouchIDFingerDown  1
#define TouchIDFingerUp    0
#define TouchIDFingerHeld  2
#define TouchIDMatched     3
#define TouchIDNotMatched  9

@interface UIDevice (Convergance)
-(void)_setBacklightLevel:(float)arg1;
@end

@interface UIWindow (Additions)
- (void)setAutorotates:(BOOL)arg1;
@end

@interface Bokeh : SBFProceduralWallpaper

+ (id)identifier;
+ (id)presetWallpaperOptions;
+ (id)thumbnailImageName;
- (void)applyVariant:(int)arg1;
- (void)setAnimating:(BOOL)arg1;
- (void)setWallpaperVariant:(int)arg1;
- (void)setWallpaperOptions:(id)arg1;
- (void)_initialize;
- (id)averageColorForRect:(struct CGRect)arg1;
- (id)averageLifetimeColorForRect:(struct CGRect)arg1;
- (id)averageLifetimeColor;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;

@end

@interface CVLockController : UIWindow <UIScrollViewDelegate, UIGestureRecognizerDelegate, SBUIBiometricEventObserver, UIWebViewDelegate> {
    BOOL _wasMatching;
    id _monitorDelegate;
    BOOL isMonitoringEvents;
    
    BOOL waitOnSliderDelegate;
}

// Interface - the views below are listed in order of view heirarchy, with the highest first

@property (nonatomic, strong) CVLockSystemAlertWindow *sysAlrt;

// These views are all added onto the main scrollview
@property (nonatomic, strong) UIImageView *batteryIcon;
@property (nonatomic, strong) UILabel *battPercent;
@property (nonatomic, strong) UIImageView *leftArrow;
@property (nonatomic, strong) UIImageView *rightArrow;
@property (nonatomic, strong) UIImageView *defaultCamera;
@property (nonatomic, strong) CVLockNotificationView *notificationView;
@property (nonatomic, strong) UIImageView *brightnessIcon;
@property (nonatomic, strong) CVLockBrightnessSlider *brightness;
@property (nonatomic, strong) CVLockToggleController *toggles;
@property (nonatomic, strong) CVLockUpArrow *upArrow;
//@property (nonatomic, strong) UIImageView *artwork; // Only when album artwork is medium (variant is 1)
@property (nonatomic, strong) CVLockTimeContainerView *timeMusicView;
@property (nonatomic, strong) CVLockHTMLBackgroundView *bgHtml;
@property (nonatomic, strong) CVLockSlider *slider;

@property (nonatomic, strong) CVLockFeedSlider *feedslider;
@property (nonatomic, strong) CVLockPasscodeView *passcodeView;
@property (nonatomic, strong) CVLockHTMLBackgroundView *cydgetBg;
@property (nonatomic, strong) UIImageView *artwork; // Only when album artwork is fullscreen (variant is 0)
@property (nonatomic, strong) SBFProceduralWallpaperView *dynamicWallpaper; // iOS 7 only
@property (nonatomic, strong) UIImageView *blurredBackground;
@property (nonatomic, strong) UIImageView *background;


// Backends
@property (nonatomic) float aimedSliderContentOffset;
@property (readwrite) BOOL isPasscodeSet;
@property (readwrite) BOOL retreiveNewCamera;
@property (readwrite) BOOL allowSnoozeAlert;
@property (nonatomic, weak) NSTimer *passcodeTimer;
@property (nonatomic) BOOL sliderPressed;
@property (nonatomic, weak) NSTimer *batterytimer;
@property (nonatomic, strong) UIView *systemAlertAnimContainer;
@property (nonatomic, strong) UIView *passcodeAnimationContainer;
@property (nonatomic, strong) UIView *camView;
@property (nonatomic, strong) UIImageView *unlockui; // Not sure if this is used anymore?
@property (nonatomic, strong) UIImageView *fakedBiteSMSView;
@property (nonatomic, strong) CVLockCameraOverlayView *cameraGestureOverlay;
@property (nonatomic, strong) SBLockScreenCameraController *camController;
@property (nonatomic, strong) UIView *bokehSuperview;

+(void)setInCenter:(BOOL)val;
+(BOOL)getInCenter;
+(void)setInCamera:(BOOL)val;
+(BOOL)getInCamera;
+(void)setInToggles:(BOOL)val;
+(BOOL)getInToggles;

-(id)init;
-(void)tearDownUi;
-(void)_noteSystemAlertWasHidden;

-(void)returnCameraToCenter:(BOOL)anim;

-(void)showMusicView;
-(void)showTimeView;
-(void)changedNowPlayingItem;
-(void)updateDate;

@end