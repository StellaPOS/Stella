//
//  AppDelegate.swift
//  StellaPOS
//
//  Created by Miles Fishman on 1/13/20.
//  Copyright © 2020 Miles Fishman. All rights reserved.
//

import UIKit
import CocoaLumberjack

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    
    public let fileLogger: DDFileLogger = DDFileLogger()
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        /// Elo
        ETPPiDockControl.hardwareInstance().establishFirmwareConnection()
        
        /// Cocoalumberjack
        DDLog.add(DDTTYLogger.sharedInstance!)
        fileLogger.rollingFrequency = TimeInterval(60*60*24)
        fileLogger.logFileManager.maximumNumberOfLogFiles = 7
        DDLog.add(fileLogger, with: .info)
        
        return true
    }

   
}

