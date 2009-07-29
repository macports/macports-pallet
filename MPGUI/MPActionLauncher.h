//
//  MPActionLauncher.h
//  MPGUI
//
//  Created by Juan Germán Castañeda Echevarría on 6/15/09.
//  Copyright 2009 UNAM. All rights reserved.
//

/*!
 @header MPActionLauncher
 The MPActionLauncher allows acces to a shared per thread MacPorts Framework 
 wrapper to excecute MacPorts actions. It performs all the actions in another 
 thread in order to leave the GUI responsive.
*/

#import <Cocoa/Cocoa.h>
#import <MacPorts/MacPorts.h>

/*!
 @class MPActionLauncher
 @abstract Wrapper for MacPorts Framework actions
 @discussion Contains a shared per thread MacPorts Framework wrapper
*/
@interface MPActionLauncher : NSObject {
    NSArray *ports;
    NSTask *actionTool;
    NSConnection *connectionToActionTool;
    BOOL isLoading, isBusy;
}
/*! 
 @var ports
 @abstract An array of available MPPorts
*/
@property (copy) NSArray *ports;

@property NSTask *actionTool;

/*! 
 @var isLoading
 @abstract Tells whether the instance is loading the ports array or not
*/
@property BOOL isLoading;

@property BOOL isBusy;

/*!
 @brief Return singleton shared MPActionLauncher instance
*/
+ (MPActionLauncher*)sharedInstance;

/*!
 @brief Loads the MPPorts array with the available ports current PKGPath in another thread
*/
- (void)loadPorts;

/*!
 @brief Installs a single port in another thread
 @param port MPPort that represents the port to install
*/
- (void)installPort:(MPPort *)port;

/*!
 @brief Uninstalls a single port in another thread
 @param port MPPort that represents the port to install
 */
- (void)uninstallPort:(MPPort *)port;

/*!
 @brief Upgrades a single port in another thread
 @param port MPPort that represents the port to upgrade
 */
- (void)upgradePort:(MPPort *)port;


/*!
 @brief Syncs the MacPorts installation in another thread
 */
- (void)sync;

/*!
 @brief Selfupdates the MacPorts installation in another thread
 */
- (void)selfupdate;

- (void)cancelPortProcess;

@end
