//
//  ETPPiDockControl.h
//  FrameworkTestApp
//
//  Created by Rey Jenald Peña on 2/16/15.
//  Copyright (c) 2015 Elo Touch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ETPPKeyInjectionAPICall.h"
#import "ETPPCommand.h"
#import "ETPPDebug.h"
#import "ETPPConstants.h"

typedef void(^PPResultBlock)(id _Nullable results);
typedef void(^PPFailedBlock)(NSError * _Nullable error);
typedef void(^PPContinueBlock)(id _Nullable attributes);

typedef NS_ENUM(NSInteger, MSRKeyInjectionStatus) {
    MSRKeyInjectionMSRConnectingDevice,
    MSRKeyInjectionResetMSRDeviceDisconnected,
    MSRKeyInjectionKSNReading,
    MSRKeyInjectionKSNReadingFailure,
    MSRKeyInjectionKSNReadingSuccess,
    MSRKeyInjectionKSNReadingDeviceDisconnected,
    MSRKeyInjectionMUTReading,
    MSRKeyInjectionMUTReadingFailure,
    MSRKeyInjectionMUTReadingSuccess,
    MSRKeyInjectionMUTReadingDeviceDisconnected,
    MSRKeyInjectionKeyLoadCommandAPI,
    MSRKeyInjectionKeyLoadCommandAPISuccess,
    MSRKeyInjectionKeyLoadCommandAPIInternetConnectivityFailure,
    MSRKeyInjectionKeyLoadCommandAPIParseFailure,
    MSRKeyInjectionKeyLoadCommandAPIWebserviceFailure,
    MSRKeyInjectionCommandByKSNAPI,
    MSRKeyInjectionCommandByKSNAPISuccess,
    MSRKeyInjectionCommandByKSNAPIInternetConnectivityFailure,
    MSRKeyInjectionCommandByKSNAPIParseFailure,
    MSRKeyInjectionCommandByKSNAPIWebserviceFailure,
    MSRKeyInjectionWriteKeyLoadCommandToMSR,
    MSRKeyInjectionWriteKeyLoadCommandToMSRDeviceDisconnected,
    MSRKeyInjectionWriteKeyLoadCommandToMSRComplete,
    MSRKeyInjectionWriteKSNCommandToMSR,
    MSRKeyInjectionWriteKSNCommandToMSRDeviceDisconnected,
    MSRKeyInjectionWriteKSNCommandToMSRComplete,
    MSRKeyInjectionKSNTimeExpire,
    MSRKeyInjectionMUTTimeExpire,
    MSRKeyInjectionResetMSRTimeExpire,
    MSRKeyInjectionDefault
};

NS_ASSUME_NONNULL_BEGIN

@class CyEAConnection;

@protocol MSRInjectionDelegate;
@protocol FileDownloaderDelegate;

static NSInteger const ID_CFD_DEFAULT_SCROLL_SPEED = 2;
static NSInteger const ID_CFD_MAX_SCROLL_SPEED = 5;

// typedef void(^myCompletion)(BOOL);

@interface ETPPiDockControl : NSObject <NSURLSessionTaskDelegate,NSURLSessionDownloadDelegate> {
    // CyEAConnection *control;
    __weak id<MSRInjectionDelegate> msrInjectionDelegate;
    CyEAConnection *control;
    NSURLSessionDownloadTask *download;
    __weak id<FileDownloaderDelegate> _fileDownloaderDelegate;
}

@property (assign) enum FWVersion fwVersion;


@property (nonatomic, copy) void(^openCashDrawerCompletionHandler)(BOOL didOpen);
@property (nonatomic, weak) id<MSRInjectionDelegate> msrInjectionDelegate;
@property (nonatomic, strong ) CyEAConnection *control;

+ (instancetype)hardwareInstance;

@property (assign) BOOL isPaperBinEmpty;
@property (assign) BOOL isCashDrawerOpen;
@property (assign) BOOL isConnectedToFirmware;
@property (assign) BOOL isBarcodeReaderOn;
@property (assign) BOOL isKSNCheck;
@property (assign) BOOL isResetMSRCheck;
@property (assign) BOOL isSecurityLevelCheck;
@property (nonatomic, assign,readonly) BOOL isConnected;
@property (assign) BOOL isCFDBacklightOn;
@property (assign) BOOL isChangeSecurityLevel;
@property (assign) BOOL isLogEnable;
@property (nonatomic, strong) NSString *ksnString;
@property (nonatomic, strong) NSString *mutString;
@property (nonatomic, strong) NSString *customerCodeString;
@property (nonatomic, strong) NSString *usernameString;
@property (nonatomic, strong) NSString *passwordString;
@property (nonatomic, strong) NSString *KSIDString;
@property (nonatomic, strong) NSString *keyIdString;
@property (nonatomic, strong) NSString *securityLevelString;
@property (nonatomic, strong) ETPPKeyInjectionAPICall *keyInjectionAPICall;
@property (strong, nonatomic) ETPPCommand *getKeyloadCommand;
@property (strong, nonatomic) ETPPCommand *getCommandByKSN;
@property (strong, nonatomic) ETPPCommand *getCommandByMUT;
@property (strong, nonatomic) NSMutableDictionary *dictonaryGetKeyloadCommand;
@property (strong, nonatomic) NSMutableDictionary *dictonaryGetCommandByKSN;
@property (strong, nonatomic) NSMutableDictionary *dictonaryGetCommandByMUT;
@property (nonatomic, strong) NSURLSession *backgroundSession;
@property (nonatomic, weak) id <FileDownloaderDelegate> fileDownloaderDelegate;

- (void)establishFirmwareConnection;

//FW Reset Reason
- (void) getFWResetReason;
- (void) clearFWResetReason;


// Drawer
- (void)openDrawerWithCompletionHandler:(void (^)(BOOL didOpen))completionHandler;
- (BOOL)checkCashDrawerStatus;

// Printer
- (void)checkPaperStatusWithCompletionHandler:(void (^)(BOOL paperBinIsEmpty))completionHandler;

- (void)printSync:(NSString *)string;
- (void)printSync:(NSString *)string withCompletionHandler:(void (^)(BOOL donePrinting))completionHandler;

- (void) printBarcode:(NSString *)barcode withFormat:(ETPPBarcodeFormat)format completion:(void (^)(NSError *))completionHandler;
- (void)printBarcode:(NSString *)barcode withFormat:(ETPPBarcodeFormat) format  withHeight: (NSUInteger) codeHeight withWidth:(ETPPBarcodeWidth) codeWidth withLeftMargin: (NSUInteger) leftMargin withHRILocation: (ETPPBarcodeHRILocation) hriLocation completion:(void (^)(NSError *error)) completion;

- (void)printArabicString:(NSString *)string withFontSize:(IDFontSize)fontSize withBold:(BOOL) isBold withUnderline:(BOOL) hasUnderline  completion:(void (^)(BOOL donePrinting))completionHandler;

- (void)resetPrinterFormats;
- (void)setPrinterFontSize:(IDFontSize)fontSize;
- (void)setPrinterUnderlined:(BOOL)isOn;
- (void)setPrinterBold:(BOOL)isOn;
- (void)setPrinterAlignment:(IDAlignment)alignment;

- (void)setPrinterLanguage:(IDLanguage)language;
- (IDLanguage)getPrinterLanguage;

- (void)cancelPrinting;

// Barcode
- (void) setBarcodeReaderOn:(BOOL)status;
- (void) toggleBarcodeReader; //HW 1.0 only
- (void) checkBarcodeReaderStatusWithCompletionHandler:(void (^)(BOOL isOn))completionHandler; // HW 1.0 Only
- (void) sendBCRCommand:(NSString *)command; // HW 2.0 Only
- (void) sendBCRTriggerCommand:(BOOL)isOn; // HW 2.0 Only

// CFD
- (void)startDisplayCFDLineSync:(NSDictionary *)dictionaryLines;
- (void)startDisplayCFDLineSync:(NSDictionary *)dictionaryLines withComletionHandler:(void (^_Nullable)(BOOL)) completion;
- (void)setCustomerDisplayBacklightOn:(BOOL)state;
- (void)customerDisplayStopScroll;
- (void)customerDisplayClearText;
- (void)customerDisplayDecreaseLeftScrollSpeed;
- (void)customerDisplayIncreaseLeftScrollSpeed;
- (void)customerDisplayDecreaseRightScrollSpeed;
- (void)customerDisplayIncreaseRightScrollSpeed;

// Weight
- (void)getWeight;

- (void) getWeightWithScaleParser:(NSString * _Nullable (^ _Nullable)(uint8_t))parser;

// MSR
- (void)writeToMSRWithString:(NSString *)string;
- (void)enableMSRConfig;
- (void)disableMSRConfig;
- (void)getKsnAndMut;
- (void)resetMSRCheckKey;
- (void)resetMSRCheckSL;
- (void)getSecurityLevelCheck;
- (void)changeSecurityLevel;
- (void)clearMSR;

- (void)readFWKSN;
- (void)readFWMUT;
- (void)resetFWMSR;
- (void)readFWSecurityLevel;

- (NSString *)trimMSRResponse:(NSString *)response;
- (NSString *)trimKSN:(NSString *)KSN;
- (BOOL)validateMSRResponse:(NSString *)output;
- (void)calliOSKeyinjectionWithKSID:(NSString *)KSID KeyID:(NSString *)keyID CustomerCode:(NSString *)customerCode Username:(NSString *)username Password:(NSString *)password SecurityLevel:(NSString *)securityLevel;
-(void)KSNTimerAction:(NSTimer*)timer;
-(void)MUTTimerAction:(NSTimer*)timer;
-(void)resetMSRTimerAction:(NSTimer*)timer;
-(void)getSecurityLevelTimerAction:(NSTimer*)timer;
-(void)MSRConnectionTimerAction:(NSTimer*)timer;
-(void)writeToMSRTimerAction:(NSTimer*)timer;
-(void)writeCommandToMSR:(NSString *)commandValue;

- (void) enableFWConnectCount;

- (void) disableFWConnectCount;


// Bootload
- (void)startBootloadWithFileName:(NSString *)bootloadFileName;

// Info
- (void)getFWSerialNumber;
- (void)getFWVersion;
- (void)getHWVersion;

+ (enum FWVersion) getFWLoggedVersion;

+ (enum ETPPHWVersion) getHWLoggedVersion;

//SDK Version
-(NSString *)getSDKVersion;

//Key Injection
- (void)magTekKeyInjectionAPICall:(NSDictionary *)dictionaryCredentials;
- (void)magTekKeyInjectionSuccess:(NSString *)response;
- (void)magTekKeyInjectionFailure:(NSError *)error;

// Utility
+ (BOOL)appendData:(NSData *)data count:(NSUInteger)count toString:(NSMutableString *)string;

// Heartbeat, watchdog
- (void)setHeartbeat:(BOOL)enable;
- (void)enableWatchdog;

// Queue control
- (void)pauseAllTasks;
- (void)unpauseAllTasks;

- (void) cancelAllTasks;

// Debug methods
- (void)setDebugLevel:(ETPPDebugLevel)debugLevel;
- (ETPPDebugLevel)getDebugLevel;
- (void)setLoggerLocation:(ETPPLoggerLocation)loggerLocation;
- (void)clearLogFiles;
- (NSArray *)logFilesPaths;


//Serial Speed

- (void) setSerialSpeed:(NSString *)speed;

- (void) setWeightScaleCommand:(NSString *)command;

- (void) sendDataToSerialPort:(NSData *)data;

- (void) sendDataToMiniUSBSerialPort:(NSData *)data;

- (void) setDataSerialPortSpeed:(NSString *)speed;

//Serial number trigger APIs

- (void) enableSerialNumberScan;
- (void) disableSerialNumberScan;

- (void) setSerialNumberString:(NSString *)serialNumber;

@end


@protocol FileDownloaderDelegate <NSObject>

@optional
- (void)fileDownloadProgress:(float)progress;
- (void)fileDownloadSuccess:(NSString *)filePath;
- (void)fileDownloadFailure:(NSError *)error;
@end

NS_ASSUME_NONNULL_END

@protocol MSRInjectionDelegate<NSObject>

@optional
- (void)msrInjectionDelegateMethod:(MSRKeyInjectionStatus )msrKeyInjectionStatus messgae:(NSString *_Nullable)message;
- (void)securityLevelDelegateMethod:(NSString *_Nullable)securityLevelOutput;
@end
