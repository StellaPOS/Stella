//
//  ETPPKeyInjectionAPICall.h
//  FrameworkTestApp
//
//  Created by Himanshu  on 02/09/15.
//  Copyright (c) 2015 Elo Touch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ETPPKeyListParser.h"
#import "ETPPCommandParser.h"

@protocol KeyInjectionAPIDelegate;

@interface ETPPKeyInjectionAPICall : NSObject <KeyListParserDelegate,CommandParserDelegate> {
}
@property (nonatomic, assign ) id<KeyInjectionAPIDelegate> delegate;

@property (nonatomic, assign) BOOL isGetCommandByKSN;
@property (nonatomic, assign) BOOL isGetCommandByMUT;
@property (nonatomic, assign) BOOL isGetKeyLoadCommand;

@property (strong, nonatomic) ETPPCommandParser *commandParser;
@property (strong, nonatomic) ETPPKeyListParser *keyListParser;



- (id)init;

- (void)getKeyList:(UIView *)view WithCustomerCode:(NSString *)customerCode withUsername:(NSString *)username andPassword:(NSString *)password;

- (void)GetCommandByKSN:(UIView *)view WithCustomerCode:(NSString *)customerCode withUsername:(NSString *)username withPassword:(NSString *)password withBillingLabel:(NSString *)billingLabel withCustomerTransactionID:(NSString *)customerTransactionID withCommandID:(NSString *)commandID withKSN:(NSString *)kSN andKeyID:(NSString *)keyID;

- (void)getCommandList:(UIView *)view WithCustomerCode:(NSString *)customerCode withUsername:(NSString *)username andPassword:(NSString *)password withBillingLabel:(NSString *)billingLabel withCustomerTransactionID:(NSString *)customerTransactionID andExecutionType:(NSString *)executionType;

- (void)getKeyLoadCommand:(UIView *)view WithCustomerCode:(NSString *)customerCode withUsername:(NSString *)username withPassword:(NSString *)password withBillingLabel:(NSString *)billingLabel withCustomerTransactionID:(NSString *)customerTransactionID withUpdateToken:(NSString *)updateToken withKSN:(NSString *)kSN andKeyID:(NSString *)keyID;

- (void)getCommandByMUT:(UIView *)view WithCustomerCode:(NSString *)customerCode withUsername:(NSString *)username withPassword:(NSString *)password withBillingLabel:(NSString *)billingLabel withCustomerTransactionID:(NSString *)customerTransactionID withCommandID:(NSString *)commandID withUpdateToken:(NSString *)updateToken andKSN:(NSString *)kSN;

@end


@protocol KeyInjectionAPIDelegate<NSObject>

@optional
- (void)keyListAPIWithSuccess:(NSArray *)arrayKeylist;
- (void)keyListAPIWithFailure:(NSString *)failureData;

- (void)getCommandByKSNAPIWithSuccess:(NSMutableDictionary *)dictinoaryCommand;
- (void)getCommandByKSNWithFailure:(NSString *)failureData;

- (void)getCommandByMUTAPIWithSuccess:(NSMutableDictionary *)dictinoaryCommand;
- (void)getCommandByMUTAPIWithFailure:(NSString *)failureData;

- (void)getKeyLoadCommandAPIWithSuccess:(NSMutableDictionary *)dictinoaryCommand;
- (void)getKeyLoadCommandAPIWithFailure:(NSString *)failureData;

@end

/*

 - (void)removeActivityIndicator;
 - (void)removeObserver:(UIViewController*)observer;
 - (void)addObserver:(UIViewController*)observer;
 */
