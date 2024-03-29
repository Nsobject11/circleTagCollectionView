//
//  AGHomeCalendarView.h
//  RunTime
//
//  Created by qt on 2020/3/26.
//  Copyright © 2020 wonders. All rights reserved.
//

#import <UIKit/UIKit.h>
@class AGWeekView;
typedef NS_ENUM(NSInteger,CalendarType) {
    CalendarType_Week,
    CalendarType_Month,
};
NS_ASSUME_NONNULL_BEGIN
@class AGAppearance;
typedef void(^RefreshH)(CGFloat viewH); //高度回调刷新
typedef void(^sendSelectDate)(NSString *dateStr); //当前选择日期回调刷新
@interface AGHomeCalendarView : UIView
@property (nonatomic, copy) sendSelectDate sendSelectDate;
/**实现该block滑动时更新控件高度*/
@property (nonatomic, copy) RefreshH refreshH;
/**
 根据日期获取控件总高度
 
 @param date 日期
 @param type 类型
 @return return value description
 */
+ (CGFloat)getMonthTotalHeight:(NSDate *)date type:(CalendarType)type;
- (instancetype)initWithFrame:(CGRect)frame date:(NSDate *)date appearance:(AGAppearance *)appearance type:(CalendarType)type;
@end

@interface AGAppearance : NSObject
@property (nonatomic,assign) BOOL isScrollDate;//是否可以滑动
@property (nonatomic,strong) UIFont * weekFont;//周大小
@property (nonatomic,strong) UIColor * weekColor; //日 六 一 二 三 四 五 颜色
@property (nonatomic,strong) UIColor * weekSunColor;//日 六单独设置颜色
@property (nonatomic,strong) UIColor * yearMonthColor; //头年月字体颜色
@property (nonatomic,strong) UIFont * yearFont;//头年月字体大小
@property (nonatomic,strong) UIColor * yerarLayerColor;//头边框大小
@property (nonatomic,assign) CGFloat yearLayerWidth;//头边框宽度

@property (nonatomic,strong) UIColor * itemTextColor; //日期字体颜色
@property (nonatomic,strong) UIColor * itemTextSelectColor;//日期字体选中颜色
@property (nonatomic,strong) UIColor * itemSelectColor;//选中背景色
@property (nonatomic,strong) UIFont * itemTextFont;//日期字体大小
@property (nonatomic,strong) UIColor * ItemSunTextColor;//日 六 字体颜色
@end
NS_ASSUME_NONNULL_END
