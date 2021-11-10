//
//  GPWebSocket.h
//  GroupPlay
//
//  Created by mac on 2021/11/10.
//

#import <Foundation/Foundation.h>
#import <Security/SecCertificate.h>

typedef NS_ENUM(NSInteger, GPReadyState) {
    GP_CONNECTING   = 0,
    GP_OPEN         = 1,
    GP_CLOSING      = 2,
    GP_CLOSED       = 3,
};

typedef enum GPStatusCode : NSInteger {
    // 0–999: Reserved and not used.
    GPStatusCodeNormal = 1000,
    GPStatusCodeGoingAway = 1001,
    GPStatusCodeProtocolError = 1002,
    GPStatusCodeUnhandledType = 1003,
    // 1004 reserved.
    GPStatusNoStatuGPeceived = 1005,
    GPStatusCodeAbnormal = 1006,
    GPStatusCodeInvalidUTF8 = 1007,
    GPStatusCodePolicyViolated = 1008,
    GPStatusCodeMessageTooBig = 1009,
    GPStatusCodeMissingExtension = 1010,
    GPStatusCodeInternalError = 1011,
    GPStatusCodeServiceRestart = 1012,
    GPStatusCodeTryAgainLater = 1013,
    // 1014: Reserved for future use by the WebSocket standard.
    GPStatusCodeTLSHandshake = 1015,
    // 1016–1999: Reserved for future use by the WebSocket standard.
    // 2000–2999: Reserved for use by WebSocket extensions.
    // 3000–3999: Available for use by libraries and frameworks. May not be used by applications. Available for registration at the IANA via first-come, first-serve.
    // 4000–4999: Available for use by applications.
} GPStatusCode;

@class GPWebSocket;

extern NSString *const GPWebSocketErrorDomain;
extern NSString *const GPHTTPResponseErrorKey;

#pragma mark - GPWebSocketDelegate

@protocol GPWebSocketDelegate;

#pragma mark - GPWebSocket
@interface GPWebSocket : NSObject<NSStreamDelegate>

@property (nonatomic, weak) id <GPWebSocketDelegate> delegate;

@property (nonatomic, readonly) GPReadyState readyState;
@property (nonatomic, readonly, retain) NSURL *url;


@property (nonatomic, readonly) CFHTTPMessageRef receivedHTTPHeaders;

// Optional array of cookies (NSHTTPCookie objects) to apply to the connections
@property (nonatomic, readwrite) NSArray * requestCookies;

// This returns the negotiated protocol.
// It will be nil until after the handshake completes.
@property (nonatomic, readonly, copy) NSString *protocol;

// Protocols should be an array of strings that turn into Sec-WebSocket-Protocol.
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols;
- (id)initWithURLRequest:(NSURLRequest *)request;

// Some helper constructors.
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols;
- (id)initWithURL:(NSURL *)url;

// Delegate queue will be dispatch_main_queue by default.
// You cannot set both OperationQueue and dispatch_queue.
- (void)setDelegateOperationQueue:(NSOperationQueue*) queue;
- (void)setDelegateDispatchQueue:(dispatch_queue_t) queue;

// By default, it will schedule itself on +[NGPunLoop GP_networkRunLoop] using defaultModes.
- (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
- (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// GPWebSockets are intended for one-time-use only.  Open should be called once and only once.
- (void)open;

- (void)close;
- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

// Send a UTF8 String or Data.
- (void)send:(id)data;

// Send Data (can be nil) in a ping message.
- (void)sendPing:(NSData *)data;

@end

#pragma mark - GPWebSocketDelegate

@protocol GPWebSocketDelegate <NSObject>

// message will either be an NSString if the server is using text
// or NSData if the server is using binary.
- (void)webSocket:(GPWebSocket *)webSocket didReceiveMessage:(id)message;

@optional

- (void)webSocketDidOpen:(GPWebSocket *)webSocket;
- (void)webSocket:(GPWebSocket *)webSocket didFailWithError:(NSError *)error;
- (void)webSocket:(GPWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;
- (void)webSocket:(GPWebSocket *)webSocket didReceivePong:(NSData *)pongPayload;

// Return YES to convert messages sent as Text to an NSString. Return NO to skip NSData -> NSString conversion for Text messages. Defaults to YES.
- (BOOL)webSocketShouldConvertTextFrameToString:(GPWebSocket *)webSocket;

@end

#pragma mark - NSURLRequest (GPCertificateAdditions)

@interface NSURLRequest (GPCertificateAdditions)

@property (nonatomic, retain, readonly) NSArray *GP_SSLPinnedCertificates;

@end

#pragma mark - NSMutableURLRequest (GPCertificateAdditions)

@interface NSMutableURLRequest (GPCertificateAdditions)

@property (nonatomic, retain) NSArray *GP_SSLPinnedCertificates;

@end

#pragma mark - NGPunLoop (GPWebSocket)

@interface NSRunLoop (GPWebSocket)

+ (NSRunLoop *)GP_networkRunLoop;

@end

