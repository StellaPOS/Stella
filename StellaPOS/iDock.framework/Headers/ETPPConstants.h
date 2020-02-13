//
//  ETPPConstants.h
//  Test
//
//  Created by Rey Jenald Peña on 2/3/15.
//  Copyright (c) 2015 elotouch. All rights reserved.
//

#import <Foundation/Foundation.h>

#define IDAccessoryDidConnectNotification @"FirmwareDidConnect"
#define IDAccessoryDidDisconnectNotification @"AccessoryDidDisonnect"
#define IDAccessoryDidDisconnectOnUpdateNotification @"AccessoryDidDisonnectOnUpdate"
#define IDMagneticStripeReaderReadDataNotification @"didReadMSRData"
#define IDBarcodeReaderReadDataNotification @"didReadBarcodeData"
#define IDCashDrawerDidChangeStatusNotification @"CashDrawerChangeStatus"
#define IDBarcodeScannerDidChangeStatusNotification @"BarcodeDidChangeStatus"
#define IDBootloadStatusDidChangeStatusNotification @"BootloadValueDidChange"
#define IDWeightValueDidChangeStatusNotification @"WeightDidReceiveValue"
#define IDSerialNumberNotification @"SerialNumberDidReceiveValue"
#define IDFWVersionNotification @"FWVersionDidReceiveValue"
#define BootloaderEndNotification @"BootloaderEnd"
#define IDHWVersionNotification @"FWVersionDidReceiveValue"
#define IDHDidRecieveSerialDataNotification @"DidRecieveSerialData"
#define IDHDidRecieveMiniUSBSerialDataNotification @"DidRecieveMiniUSBSerialData"


#define IDOCK_MSR_DATA @"msrData"
#define IDOCK_MSR_DATA_TRACK_1 @"track1"
#define IDOCK_MSR_DATA_TRACK_2 @"track2"
#define IDOCK_MSR_DATA_TRACK_3 @"track3"
#define IDOCK_MSR_DATA_DUKPT_SERIAL_NUMBER @"msrDUKPTSerialNumber"
#define IDOCK_MSR_DATA_DEVICE_SERIAL_NUMBER @"msrDeviceSerialNumber"
#define IDOCK_MSR_DATA_MAGNE_PRINT_STATUS @"msrMagnePrintStatus"
#define IDOCK_MSR_DATA_ENCRYPTED_MAGNE_PRINT_DATA @"msrEncryptedMagnePrintData"
#define IDOCK_MSR_DATA_IIN @"msrIIN"
#define IDOCK_MSR_DATA_LASTFOUR @"msrLastFour"
#define IDOCK_MSR_DATA_NAME @"msrName"
#define IDOCK_FW_SERIAL_NUMBER @"fwSerialNumber"
#define IDOCK_FW_VERSION @"fwVersion"
#define IDOCK_HW_VERSION @"HWVersion"

#define IDOCKMAGTEKKEYINJECTIONotification @"magTekInjection"
#define IDOCKREADINGKSNNotification @"ksnReading"
#define IDOCKREADINGMUTNotification @"mutReading"
#define IDOCKGETKEYLOADCOMMANDNotification @"getKeyLoadCommand"
#define IDOCKGETCOMMANDBYKSNNotification @"getCommandByKSN"
#define IDOCKGETCOMMANDBYMUTNotification @"getCommandByMUT"
#define IDOCKWRITINGTOMSRNotification @"writingtomsr"
#define IDOCKEWRITEKLCNotification @"writeKLC"
#define IDOCKEWRITECBKNotification @"writeCBK"
#define IDOCKCHECKINTERNETCONNECTIONNotification @"checkInternatConnection"

typedef NS_ENUM(NSInteger, IDAlignment) {
    IDAlignmentLeft,
    IDAlignmentRight,
    IDAlignmentCenter,
    IDAlignmentDefault
};

typedef NS_ENUM(NSInteger, IDFontSize) {
    IDFontSizeSmall,
    IDFontSizeMedium,
    IDFontSizeLarge,
    IDFontSizeDefault
};

typedef NS_ENUM(NSInteger, IDLanguage) {
    IDLanguageEnglish,
    IDLanguageChinese,
    IDLanguageJapanese,
    IDLanguageArabic,
    IDLanguageWestEurope,
    //IDLanguageLatinAmerica,
    //IDLanguageKorean
};


typedef enum : NSUInteger {
    upcA = 65,
    upcE = 66,
    ean13 = 67,
    ean8 = 68,
    code39 = 69,
    itf = 70,
    codabar = 71,
    code93 = 72,
    code128 = 73
} ETPPBarcodeFormat;

typedef enum : NSUInteger {
    noPrint = 0x00,
    top = 0x01,
    bottom = 0x02
} ETPPBarcodeHRILocation;

typedef enum : NSUInteger {
    w1 = 0x01, //Auto size
    w2 = 0x02,
    w3 = 0x03,
    w4 = 0x04,
    w5 = 0x05,
    w6 = 0x06
} ETPPBarcodeWidth;

enum ETPPHWVersion : NSInteger {
  
    HW_1 = 0x01,
    HW_2 = 0x02,
    
};

enum FWVersion
{
    FW9_11 = 1,
    FW9_X,
    FW9_29,
    FW10_0x,
    FW10_1x,
    FW10_2x
};
