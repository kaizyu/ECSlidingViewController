//
//  ECS.h
//  ECSlidingViewController
//
//  Created by caojianhua on 15/7/13.
//
//

#import <Foundation/Foundation.h>
#import "ECSlidingViewController.h"


/**
 The `ECSlidingViewControllerDelegate` protocol is adopted by an object that may customize a sliding view controller's animation transition, interactive transition, or the layout of the child views.
 */
@protocol ECSlidingViewControllerDelegate

@optional
/**
 Called to allow the delegate to return a non-interactive animator object for use during a transition.

 Returning an object will disable the sliding view controller's `transitionCoordinator` animation and completion callbacks.

 @param slidingViewController The sliding view controller that is being transitioned.
 @param operation The type of transition that is occuring. See `ECSlidingViewControllerOperation` for a list of possible values.
 @param topViewController

 @return The animator object responsible for managing the transition animations, or nil if you want to use the standard sliding view controller transitions. The object you return must conform to the `UIViewControllerAnimatedTransitioning` protocol.
 */
- (id<UIViewControllerAnimatedTransitioning>)slidingViewController:(ECSlidingViewController *)slidingViewController
                                   animationControllerForOperation:(ECSlidingViewControllerOperation)operation
                                                 topViewController:(UIViewController *)topViewController;

/**
 Called to allow the delegate to return an interactive animator object for use during a transition.

 Returning an object will disable the sliding view controller's `transitionCoordinator` block given to `notifyWhenInteractionEndsUsingBlock:`

 @param slidingViewController The sliding view controller that is being transitioned.
 @param animationController The non-interactive animator object. This will be the same object that is returned from `slidingViewController:animationController:topViewController`.

 @return The animator object responsible for managing the interactive transition, or nil if you want to use the standard sliding view controller transitions. The object you return must conform to the `UIViewControllerInteractiveTransitioning` protocol.
 */
- (id<UIViewControllerInteractiveTransitioning>)slidingViewController:(ECSlidingViewController *)slidingViewController
                          interactionControllerForAnimationController:(id <UIViewControllerAnimatedTransitioning>)animationController;

/**
 Called to allow the delegate to return a layout object to customize the layout of a sliding view controller's child views.

 @param slidingViewController The sliding view controller whose layout needs updated.
 @param topViewPosition The position of the top view.

 @return The layout object responsible for managing the layout, or nil if you want to use the standard sliding view controller layout. The object you return must conform to the `ECSlidingViewControllerLayout` protocol.
 */
- (id<ECSlidingViewControllerLayout>)slidingViewController:(ECSlidingViewController *)slidingViewController
                        layoutControllerForTopViewPosition:(ECSlidingViewControllerTopViewPosition)topViewPosition;
@end
