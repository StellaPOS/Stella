//
//  CommandParser.h
//  iDock
//
//  Created by Himanshu  on 08/10/15.
//  Copyright (c) 2015 Elo touch solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ETPPCommand.h"

@protocol CommandParserDelegate;
@interface ETPPCommandParser : NSObject <NSXMLParserDelegate> {
    
}

@property (nonatomic, assign ) id<CommandParserDelegate> delegate;
@property (strong, nonatomic) NSMutableArray *arrayCommand;
@property (strong, nonatomic) ETPPCommand *command;
@property (strong, nonatomic) NSString *commandMagTranId;
@property (strong, nonatomic) NSMutableDictionary *dictinoaryCommand;

- (id)init;
- (void)startParsing:(NSString *)data;

@end

@protocol CommandParserDelegate<NSObject>

@required
- (void)commandParserSuccess:(NSMutableDictionary *)dictinoaryCommand;
- (void)commandParserFailure;

@end