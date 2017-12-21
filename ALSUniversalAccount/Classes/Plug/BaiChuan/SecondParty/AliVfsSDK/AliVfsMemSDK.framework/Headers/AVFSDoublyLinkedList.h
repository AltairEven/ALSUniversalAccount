//
//  AVFSLRULinkedList.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/2/19.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AVFSDoublyLinkedListNode : NSObject {
@package
    __weak AVFSDoublyLinkedListNode *_prev; //由List retain
    __weak AVFSDoublyLinkedListNode *_next; //由List retain
    NSString *_key;
    id _value;
    NSUInteger _cost;
    NSTimeInterval _time;
}


@end

@interface AVFSDoublyLinkedList : NSObject {
@public
    NSMutableDictionary *_dict;
    NSUInteger _totalBytes;
    NSUInteger _totalCount;
    AVFSDoublyLinkedListNode *_head;
    AVFSDoublyLinkedListNode *_tail;
}


/**
 *  插入头节点
 *
 *  @param node 节点
 */
- (void)insertNodeAtHead:(AVFSDoublyLinkedListNode *)node;

/**
 *  节点换到头部
 *
 *  @param node 节点
 */
- (void)bringNodeToHead:(AVFSDoublyLinkedListNode *)node;

/**
 *  删除节点
 *
 *  @param node 节点
 */
- (AVFSDoublyLinkedListNode *)removeNode:(AVFSDoublyLinkedListNode *)node;

/**
 *  删除尾节点
 */
- (AVFSDoublyLinkedListNode *)removeTailNode;

/**
 *  清除全部节点
 */
- (void)removeAllNodes;

/**
 *  所有键值对
 */
- (NSDictionary *)allKeysAndValues;

@end
