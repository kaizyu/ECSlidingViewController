//
//  ECSlidingViewControllerLayout.h
//  ECSlidingViewController
//
//  Created by caojianhua on 15/7/13.
//
//

#import <Foundation/Foundation.h>
#import "ECSlidingViewController.h"

/**
 The `ECSlidingViewControllerLayout` protocol is adopted by an object that specifies a custom layout for the child view controllers.
 */
@protocol ECSlidingViewControllerLayout <NSObject>

/**
 Called when the sliding view controller needs to update the child views in response to a rotation or bounds change.

 @param slidingViewController The sliding view controller that needs to update its layout.
 @param viewController The view controller that needs a layout update.
 @param topViewPosition The position of the top view.

 @return A frame for the given view controller at the given top view position. Return `CGRectInfinite` to use the default layout.
 */
- (CGRect)slidingViewController:(ECSlidingViewController *)slidingViewController
         frameForViewController:(UIViewController *)viewController
                topViewPosition:(ECSlidingViewControllerTopViewPosition)topViewPosition;
@end
