//
//  resin_scheme.cpp
//  resin
//
//  Created by Michael Oneppo on 6/15/14.
//
//

#include "resin_scheme.h"

using namespace std;

CefString getFileExtension(CefString& fileName) {
    string filename = fileName.ToString();
    string::size_type idx;
    
    CefString result;
    
    idx = filename.rfind('.');
    
    if(idx != std::string::npos)
    {
        result.FromString(filename.substr(idx+1));
        return result;
    }
   
    return result;
}

ResinSchemeHandlerFactory::ResinSchemeHandlerFactory(string basePath) {
    m_basePath = basePath;
}

CefRefPtr<CefResourceHandler> ResinSchemeHandlerFactory::Create(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    const CefString& scheme_name,
    CefRefPtr<CefRequest> request) {
    
    CefString url = request->GetURL();
    CefURLParts parts;
    CefParseURL(url, parts);
    CefString path(&parts.path);
    CefString filename = m_basePath + path.ToString();
    cout << filename.ToString() << endl;

    CefString mime = CefGetMimeType(getFileExtension(path));
    
    CefRefPtr<CefStreamReader> stream = CefStreamReader::CreateForFile(filename);
    
    if (!stream.get()) {
        CefResponse::HeaderMap emptyHeader;
        CefRefPtr<CefStreamReader> notFound = CefStreamReader::CreateForData((void*) "Not Found", 10);
        return new CefStreamResourceHandler(404, "NOT FOUND", mime, emptyHeader, notFound);
    }
    
    return new CefStreamResourceHandler(mime, stream);
}
