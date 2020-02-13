//
//  ETPPDebug.h
//  Elo iPadPOSDock
//
//  Created by Matthew Lintlop on 7/19/16.
//  Copyright © 2016 Elo touch solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>

typedef NS_ENUM(NSInteger, ETPPDebugLevel) {
    ETPPLogLevelOff,
    ETPPLogLevelError,
    ETPPLogLevelWarn,
    ETPPLogLevelInfo,
    ETPPLogLevelDebug,
    ETPPLogLevelVerbose,
    ETPPLogLevelAll
};

typedef NS_ENUM(NSInteger, ETPPLoggerLocation) {
    ETPPLoggerConsole,
    ETPPLoggerSystemLog,
    ETPPLoggerFile
};

//extern DDLogLevel ddLogLevel;
static DDLogLevel ddLogLevel = DDLogLevelError;
static ETPPLoggerLocation loggerLocation = ETPPLoggerConsole;

@interface ETPPDebug : NSObject

//@property (nonatomic) DDLogLevel ddLogLevel;

+ (instancetype)sharedInstance;

// Logging
+ (void)resetLogMessage;
+ (void)appendLogMessage:(NSString *)string;
+ (void)logMessage:(NSString *)message,...;
+ (void)logIt:(NSString *)string;
+ (void)saveLogMessage;

+ (void)clearLogFile __unused __deprecated;
+ (NSString *)readLogFile __unused __deprecated;


/**
 Get all SDK log files paths
 */
+ (NSArray *)logFilesPaths;

/**
 Clear all SDK log files
 */
+ (void)clearAllLogFiles;


// Thread methods
+ (void)debugThread:(NSThread*)thread withMessage:(NSString *)message;
+ (void)debugCurrentThreadWithMessage:(NSString *)message;


// Debug methods
- (void)setDebugLevel:(ETPPDebugLevel)debugLevel;
- (ETPPDebugLevel)getDebugLevel;
- (void)setLoggerLocation:(ETPPLoggerLocation)loggerLocation;

// Printing methods
+ (void)startDebugPrinting;
+ (void)endDebugPrintingWithStringToPrint:(NSString *)stringToPrint;
+ (void)debugPrintDidWriteByte:(Byte)sentByte;
+ (void)debugPrintDidReadByte:(Byte)readByte;

// Data methods
+ (void)logUnicodeArray:(unichar *)unicodeArrayPtr count:(NSUInteger)count message:(NSString *)message;
+ (void)logBytes:(const uint8_t *)byteArrayPtr count:(NSUInteger)count message:(NSString *)message;
+ (void)logData:(NSData *)data count:(NSUInteger)count message:(NSString *)message;
+ (void)logData:(NSData *)data message:(NSString *)message;
+ (BOOL)isData:(NSData *)data equalToData:(NSData *)otherData;
+ (unsigned long)checksumWithData:(NSData *)data;
+ (void)debugWriteDataPacketsWithMessage:(NSString *)message;

// Operation methods
+ (void)debugOperation:(NSOperation *)operation;
+ (void)debugAllOperationsWithMessage:(NSString *)message;




@end
