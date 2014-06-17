//
//  resin_scheme.h
//  resin
//
//  Created by Michael Oneppo on 6/15/14.
//
//

#ifndef __resin__resin_scheme__
#define __resin__resin_scheme__

#include <iostream>
#include <string>
#include "include/wrapper/cef_stream_resource_handler.h"
#include "include/cef_scheme.h"
#include "include/cef_url.h"

class ResinSchemeHandlerFactory : public virtual CefSchemeHandlerFactory {
public:
    ResinSchemeHandlerFactory(std::string basePath);
    
    virtual CefRefPtr<CefResourceHandler> Create(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        const CefString& scheme_name,
        CefRefPtr<CefRequest> request);
    
protected:
    std::string m_basePath;
    
    IMPLEMENT_REFCOUNTING(ResinSchemeHandlerFactory)
};


#endif /* defined(__resin__resin_scheme__) */
