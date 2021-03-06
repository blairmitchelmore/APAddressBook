//
//  APAddressBook.h
//  APAddressBook
//
//  Created by Alexey Belkevich on 1/10/14.
//  Copyright (c) 2014 alterplay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APTypes.h"

@class APContact;

@interface APAddressBook : NSObject

@property (nonatomic, assign) APContactField fieldsMask;
@property (nonatomic, copy) APContactFilterBlock filterBlock;
@property (nonatomic, strong) NSArray *sortDescriptors;

// Doc says:
// The info argument may eventually contain information describing the change. Currently
// it will always be NULL.
@property (nonatomic, copy) void (^addressBookExternalChangeCallback)(NSDictionary *changes);

+ (APAddressBookAccess)access;

- (void)loadContacts:(void (^)(NSArray *contacts, NSError *error))callbackBlock;
- (void)loadContactsOnQueue:(dispatch_queue_t)queue
                 completion:(void (^)(NSArray *contacts, NSError *error))completionBlock;

@end
