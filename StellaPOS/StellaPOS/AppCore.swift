//
//  RootController.swift
//  StellaPOS
//
//  Created by Miles Fishman on 1/13/20.
//  Copyright © 2020 Miles Fishman. All rights reserved.
//

import Foundation
import UIKit

class App: NSObject {
    
    static var elo: ETPPiDockControl? {
        return ETPPiDockControl.hardwareInstance()
    }
}

// MARK:- Cash Drawer Methods
extension App {
    
    static func openRegister() {
        App.elo?.openDrawer(completionHandler: { (isOpen) in
            print(isOpen)
        })
    }
}

// MARK:- Printer Methods
extension App {
    
    static func printReceipt(_ content: String) {
        App.elo?.printSync(content, withCompletionHandler: { (complete) in
            print(complete)
        })
    }
}
