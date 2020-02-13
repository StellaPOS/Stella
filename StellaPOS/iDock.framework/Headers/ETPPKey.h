//
//  Key.h
//  FrameworkTestApp
//
//  Created by Himanshu  on 02/09/15.
//  Copyright (c) 2015 Elo Touch. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ETPPKey : NSObject
@property (strong, nonatomic) NSString *keyDescription;
@property (nonatomic, assign) BOOL isKeyDescription;
@property (strong, nonatomic) NSString *keyID;
@property (nonatomic, assign) BOOL isKeyID;
@property (strong, nonatomic) NSString *keyKSI;
@property (nonatomic, assign) BOOL isKeyKSI;
@property (strong, nonatomic) NSString *keyName;
@property (nonatomic, assign) BOOL isKeyName;
@property (strong, nonatomic) NSString *keySlotNamePrefix;
@property (nonatomic, assign) BOOL isKeySlotNamePrefix;
@end
