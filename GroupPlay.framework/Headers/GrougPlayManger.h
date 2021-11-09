//
//  GroupPlayManger.h
//
//  Created by mac on 2021/8/4.
//

#import <Foundation/Foundation.h>
#import "GroupPlayModel.h"
#import "GPWebSocket.h"
typedef void(^SocketFailureSuccess)(NSInteger code, NSDictionary * msg);
typedef void(^SocketRequestSuccess)(GroupPlayModel *model);
@protocol GrougPlayMangerDelegate <NSObject>

@optional
/** 答题*/
- (void)answerGameMessageWithModel:(GroupPlayModel*)model;

/** 获取当前题目*/
- (void)currentGameMessageWithModel:(GroupPlayModel*)model;

/** 游戏状态*/
- (void)gameStatusMessageWithModel:(GroupPlayModel*)model;

/** 成员*/
- (void)memberMessageWithModel:(GroupPlayModel*)model;

/** 游戏通知*/
- (void)gameNotiMessageWithModel:(GroupPlayModel*)model;

/** 正确答案*/
- (void)rightAnswerMessageWithModel:(GroupPlayModel*)model;

/** socket连接断开*/
- (void)socketDidCloseWithCode:(NSInteger)code reason:(NSString *)reason;

/** socket连接失败*/
- (void)socketDidFailWithError:(NSError *)error;

@end

@interface GrougPlayManger : NSObject
+ (instancetype)share;
@property (nonatomic, copy)NSString *sessionId;
@property (nonatomic, copy)NSString *accountSecToken;
@property (nonatomic,strong) GPWebSocket *socket;
@property (nonatomic,strong) GroupPlayModel *model;
@property(nonatomic,weak) id<GrougPlayMangerDelegate> delegate;

/** 开始连接 */
- (void)openGPWebSocketWithURLString:(NSString *)urlString Success:(SocketRequestSuccess)success failure:(SocketFailureSuccess)failure;

/** 关闭连接 */
- (void)closeGPWebSocket;

/** 开始游戏*/
- (void)startGameWithGameType:(int)gameType;

/** 答题*/
- (void)answerTheQuestionsWithMsg:(NSString *)msg AndCurrentSize:(int)currentSize;

/** 结束游戏*/
- (void)endGame;

/** 获取当前题目*/
- (void)getCurrentGameMessage;

/** 获取成员*/
- (void)getMembers;

/** 获取游戏状态*/
- (void)getGameStatus;
@end

