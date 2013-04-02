//
//  ActionzAppDelegate.h
//  Actionz
//
//  Created by ananda on 9/3/11.
//  Copyright 香川高専（宅間） 2011. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RootViewController;

@interface ActionzAppDelegate : NSObject <UIApplicationDelegate> {
	UIWindow			*window;
	RootViewController	*viewController;
}

@property (nonatomic, retain) UIWindow *window;

@end
