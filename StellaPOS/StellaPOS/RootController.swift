//
//  RootController.swift
//  StellaPOS
//
//  Created by Miles Fishman on 2/1/20.
//  Copyright © 2020 Miles Fishman. All rights reserved.
//

import Foundation
import UIKit

class RootController: UIViewController {
    
    @IBOutlet weak var rootCollectionView: UICollectionView!
    
    var colors: [UIColor] = []
    
    var randomColor: UIColor {
        return colors.isEmpty ? .lightGray : colors[Int(arc4random_uniform(7))]
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        colors = [.red,.blue,.yellow,.green,.darkGray,.black,.orange,.cyan,.brown,.purple]
        
        rootCollectionView.delegate = self
        rootCollectionView.dataSource = self
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
    }
    
    // Color Flash
    func funColors() {
       
    }
    
    func swapColors() {
        _ = rootCollectionView
            .visibleCells
            .map({
                let cell = $0
                UIView.animate(withDuration: 0.1) {
                    cell.backgroundColor = self.randomColor
                }
            })
    }
}

extension RootController: UICollectionViewDelegate, UICollectionViewDataSource {
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 6
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        collectionView.deselectItem(at: indexPath, animated: false)
        
        let sb = UIStoryboard(name: "Main", bundle: nil)
        let controller = sb.instantiateViewController(withIdentifier: "master") as? MasterViewController
        
        navigationController?.pushViewController(controller!, animated: true)
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath)
        cell.layer.cornerRadius = 12
        cell.backgroundColor = randomColor
        return cell
    }
}


extension RootController: UICollectionViewDelegateFlowLayout {
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let width = (collectionView.frame.width / 3) - 10
        let height = (collectionView.frame.height / 2) - 10
        return CGSize(width: width, height: height)
    }
}
