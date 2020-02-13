//
//  ProductCollectionReusableHeaderView.swift
//  StellaPOS
//
//  Created by Miles Fishman on 2/3/20.
//  Copyright © 2020 Miles Fishman. All rights reserved.
//

import Foundation
import UIKit

class ProductCollectionReusableHeaderView: UICollectionReusableView {
    
    override var reuseIdentifier: String? {
        return "Header"
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
}
