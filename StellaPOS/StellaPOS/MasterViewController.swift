//
//  MasterViewController.swift
//  StellaPOS
//
//  Created by Miles Fishman on 2/3/20.
//  Copyright © 2020 Miles Fishman. All rights reserved.
//

import Foundation

class MasterViewController: UIViewController {
    
    @IBOutlet weak var productCollectionView: UICollectionView!
    @IBOutlet weak var customerCollectionView: UICollectionView!
    
    @IBOutlet weak var searchBarHeightConstraint: NSLayoutConstraint!
    @IBOutlet weak var customerCollectionViewHeightConstraint: NSLayoutConstraint!
        
    var sectionTitles: [String] = ["Flower"]
    
    var tempCusts = [1,1,1,1,1]
    
    var bluetoothManager: SMBluetoothManager?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupNavigationBar()
        setup()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        UIView.animate(withDuration: 1.5) {
            self.customerCollectionView.scrollToItem(
                at: IndexPath(item: 4, section: 0),
                at: .right,
                animated: false
            )
        }
    
        //test
        DispatchQueue.main.asyncAfter(deadline: .now() + 5.0) {
            self.tempCusts += [1]
            self.customerCollectionView.reloadData()
            self.customerCollectionView.scrollToItem(
                at: IndexPath(item: self.tempCusts.count - 1, section: 0),
                at: .right,
                animated: true
            )
            
            ETPPiDockControl.hardwareInstance().openDrawer(completionHandler: { (didOpen) in
                print(didOpen)
            })
        }
    }
    
}

extension MasterViewController {
    
    func setup() {
        title = "Herbarium"
        
        productCollectionView.delegate = self
        productCollectionView.dataSource = self
        customerCollectionView.delegate = self
        customerCollectionView.dataSource = self
        
        customerCollectionView.register(
            ProductCollectionReusableHeaderView.self,
            forSupplementaryViewOfKind: UICollectionView.elementKindSectionHeader,
            withReuseIdentifier       : "Customers"
        )
    }
    
    func setupNavigationBar() {
        let searchButton = UIBarButtonItem(barButtonSystemItem: .search, target: self, action: #selector(toggleSearchbar))
        let customersButton = UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(toggleCustomersCollection))
        navigationItem.rightBarButtonItems = [searchButton, customersButton]
    }
    
    @objc func toggleSearchbar() {
        let constant = searchBarHeightConstraint.constant == 56 ? 0 : 56
        UIView.animate(withDuration: 0.3) {
            self.searchBarHeightConstraint.constant = CGFloat(constant)
            self.view.layoutIfNeeded()
        }
    }
    
    @objc func toggleCustomersCollection() {
        let constant = customerCollectionViewHeightConstraint.constant == 60 ? 0.5 : 60
        UIView.animate(withDuration: 0.3) {
            self.customerCollectionViewHeightConstraint.constant = CGFloat(constant)
            self.customerCollectionView.alpha = constant == 0.5 ? 0 : 1
            self.view.layoutIfNeeded()
        }
    }
    
//    @objc func toggleFilter() {
//        let constant = customerCollectionViewHeightConstraint.constant == 31 ? 0 : 31
//        UIView.animate(withDuration: 0.3) {
//            self.filterSegments.isHidden = true
//            self.view.layoutIfNeeded()
//        }
//    }
    
}

extension MasterViewController: UICollectionViewDelegate, UICollectionViewDataSource {
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        if collectionView == productCollectionView {
            return 16
        }
        
        return tempCusts.count
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        collectionView.deselectItem(at: indexPath, animated: false)
        let sb = UIStoryboard(name: "Main", bundle: nil)
        let controller = sb.instantiateViewController(withIdentifier: "master") as? MasterViewController
        //navigationController?.pushViewController(controller!, animated: true)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, referenceSizeForHeaderInSection section: Int) -> CGSize {
        return CGSize(width: collectionView.frame.width, height: 50)
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        if collectionView == productCollectionView {
            let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath)
            cell.layer.cornerRadius = 12
            cell.layer.borderColor = UIColor.black.cgColor
            cell.layer.borderWidth = 1.0
            return cell
        }
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell2", for: indexPath)
        
        cell.layer.cornerRadius = cell.frame.height / 2
        cell.layer.borderColor = UIColor.black.cgColor
        cell.layer.borderWidth = 1.0
        
        return cell
    }
}


extension MasterViewController: UICollectionViewDelegateFlowLayout {
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        if collectionView == productCollectionView {
            let width = (collectionView.bounds.width / 5) - 10
            let height = (collectionView.bounds.width / 4) - 10
            return CGSize(width: width, height: height)
        }
        
        return CGSize(width: 50, height: 50)
    }
}
