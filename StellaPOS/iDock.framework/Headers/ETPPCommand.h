//
//  Command.h
//  iDock
//
//  Created by Himanshu  on 08/10/15.
//  Copyright (c) 2015 Elo touch solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ETPPCommand : NSObject
@property (strong, nonatomic) NSString *commandDescription;
@property (nonatomic, assign) BOOL isCommandDescription;
@property (strong, nonatomic) NSString *commandExecutionTypeEnum;
@property (nonatomic, assign) BOOL isCommandExecutionTypeEnum;
@property (strong, nonatomic) NSString *commandID;
@property (nonatomic, assign) BOOL isCommandID;
@property (strong, nonatomic) NSString *commandName;
@property (nonatomic, assign) BOOL isCommandName;
@property (strong, nonatomic) NSString *commandValue;
@property (nonatomic, assign) BOOL isCommandValue;
@property (strong, nonatomic) NSString *commandMagTranId;
@property (nonatomic, assign) BOOL isCommandMagTranId;
@property (nonatomic, assign) BOOL isCommand;
@property (nonatomic, assign) NSMutableArray *arrayCommand;
@end
