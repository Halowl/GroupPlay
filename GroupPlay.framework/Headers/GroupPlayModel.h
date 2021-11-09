//
//  GrougPlayModel.h
//
//  Created by mac on 2021/8/4.
//

#import <Foundation/Foundation.h>

@class GroupPlayGameModel;
@interface GroupPlayModel : NSObject
/** 游戏状态 0,未开始游戏 1,游戏中*/
@property (nonatomic,assign)int gameStatus;
/** 游戏成员数组*/
@property (nonatomic,strong)NSArray<GroupPlayGameModel*> *members;
@property (nonatomic,strong)GroupPlayGameModel *body;
@property (nonatomic,assign)int command;
@property (nonatomic,copy)NSString *msgId;
@property (nonatomic,copy)NSString *sessionId;
@property (nonatomic,assign)long time;
@property (nonatomic,assign)int type;
- (instancetype)initModelWithDict:(NSDictionary*)dict;
+ (instancetype)initModelWithDict:(NSDictionary*)dict;
@end

@interface GroupPlayGameModel : NSObject
/** 倒计时时间*/
@property (nonatomic,assign)int timeLimit;
/** 游戏类型*/
@property (nonatomic,assign)int gameType;
/** 答案长度*/
@property (nonatomic,assign)int answerLength;
/** 提示*/
@property (nonatomic,copy)NSString *tips;
/** 0选项 1选字*/
@property (nonatomic,assign)int answerType;
/** 游戏问题*/
@property (nonatomic,copy)NSString *question;
/** 游戏答案/用户选择的选项  判断对错使用isRight */
@property (nonatomic,copy)NSString *answer;
/** 游戏一轮总题数*/
@property (nonatomic,assign)int size;
/** 游戏选项 */
@property (nonatomic,strong)NSArray *choice;
/** 当前第几题*/
@property (nonatomic,assign)int currentSize;
/** 开始时间*/
@property (nonatomic,assign)long startTime;
/** 用户头像 */
@property (nonatomic,copy)NSString *headImg;
/** 用户uid*/
@property (nonatomic,copy)NSString *uid;
/** 用户昵称*/
@property (nonatomic,copy)NSString *uname;
/** 对错 1,对 2,错*/
@property (nonatomic,assign)int isRight;
/** 答对题数*/
@property (nonatomic,assign)int num;
/** 游戏状态 0,未开始游戏 1,游戏中*/
@property (nonatomic,assign)int gameStatus;
/** 通知文字*/
@property (nonatomic,copy)NSString *text;
/** 1开始游戏 2加入游戏 3退出游戏 4结束游戏*/
@property (nonatomic,assign)int type;
/** 答对玩家数*/
@property (nonatomic,assign)int rightNum;
- (instancetype)initModelWithDict:(NSDictionary*)dict;
+ (instancetype)initModelWithDict:(NSDictionary*)dict;

@end


