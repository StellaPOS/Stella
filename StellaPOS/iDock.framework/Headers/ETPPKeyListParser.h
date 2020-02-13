//
//  KeyListParser.h
//  FrameworkTestApp
//
//  Created by Himanshu  on 04/09/15.
//  Copyright (c) 2015 Elo Touch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ETPPKey.h"

@protocol KeyListParserDelegate;


@interface ETPPKeyListParser : NSObject <NSXMLParserDelegate> {
    __weak id<KeyListParserDelegate> keyListParserDelegate;
}
@property (nonatomic, weak) id <KeyListParserDelegate> keyListParserDelegate;
@property (strong, nonatomic) NSMutableArray *arrayKeylist;
@property (strong, nonatomic) ETPPKey *key;

- (id)init;
- (void)startParsing:(NSString *)data;


@end

@protocol KeyListParserDelegate <NSObject>
@optional
- (void)keyListSuccess:(NSArray *)arrayKeylist;
- (void)keyListFailure;
@end



