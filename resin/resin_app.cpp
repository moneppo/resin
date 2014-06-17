// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "resin/resin_app.h"

#include <string>

#include "resin/simple_handler.h"
#include "resin/util.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "resin_scheme.h"
#include <string>

using namespace std;

ResinApp::ResinApp(string basePath) {
    m_basePath = basePath;
}

void ResinApp::OnContextInitialized() {
  REQUIRE_UI_THREAD();

  // Information used when creating the native window.
  CefWindowInfo window_info;

#if defined(OS_WIN)
  // On Windows we need to specify certain flags that will be passed to
  // CreateWindowEx().
  window_info.SetAsPopup(NULL, "resin");
#endif

  // SimpleHandler implements browser-level callbacks.
  CefRefPtr<SimpleHandler> handler(new SimpleHandler());

  // Specify CEF browser settings here.
  CefBrowserSettings browser_settings;
    
    CefRefPtr<CefSchemeHandlerFactory> factory =
        new ResinSchemeHandlerFactory(m_basePath);
    
    CefRegisterSchemeHandlerFactory("resin", "", factory);

  string url;

  // Check if a "--url=" value was provided via the command-line. If so, use
  // that instead of the default URL.
  CefRefPtr<CefCommandLine> command_line =
      CefCommandLine::GetGlobalCommandLine();
  url = command_line->GetSwitchValue("url");
  if (url.empty())
    url = "resin://index.html";

  // Create the first browser window.
  CefBrowserHost::CreateBrowser(window_info, handler.get(), url,
                                browser_settings, NULL);
}
