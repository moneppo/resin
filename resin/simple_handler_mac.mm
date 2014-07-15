// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "resin/simple_handler.h"

#import <Cocoa/Cocoa.h>

#include "resin/util.h"
#include "include/cef_browser.h"

void SimpleHandler::OnTitleChange(CefRefPtr<CefBrowser> browser,
                                  const CefString& title) {
    REQUIRE_UI_THREAD();
    
    NSView* view = (NSView*)browser->GetHost()->GetWindowHandle();
    NSWindow* window = [view window];
    std::string titleStr(title);
    NSString* str = [NSString stringWithUTF8String:titleStr.c_str()];
    [window setTitle:str];
}

void SimpleHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
 REQUIRE_UI_THREAD();
 
 // Add to the list of existing browsers.
 browser_list_.push_back(browser);
 
 NSView* view = (NSView*)browser->GetHost()->GetWindowHandle();
 NSWindow* window = [view window];

 [window setCollectionBehavior: NSWindowCollectionBehaviorFullScreenPrimary];
}

