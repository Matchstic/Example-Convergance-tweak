@protocol CVLockWidgetController <NSObject>
@required
-(id)view;
-(float)viewHeight;

@optional // I'll implement these eventually
-(void)viewWillAppear;
-(void)viewDidAppear;
-(void)viewWillDisappear;
-(void)viewDidDisappear;
-(void)didRotateFromInterfaceOrientation:(int)interfaceOrientation;
-(void)didRotateToInterfaceOrientation:(int)interfaceOrientation;
-(void)willAnimateRotationToInterfaceOrientation:(int)interfaceOrientation;
-(void)willRotateToInterfaceOrientation:(int)interfaceOrientation;
@end