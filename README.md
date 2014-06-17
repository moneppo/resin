Resin
=====

Mac OSX (and soon Windows 7) application for running SAP (Software As a Product) apps. 

What is SAP?
------------

Software As a Product is the idea that by structuring a web app for offline experiences first, you can create a single app that seamlessly works as a local (double-click installed) application, a website, or an app, with transparent, automatic updates. Essentially you get all the benefits the web promises: multi-platform support, transparent updates, open standards, etc. in every environment you want to deploy to. 

The name is a play on the idea of Software as a Service (SaaS) where it is assumed that when one is always online and always connected, there is little to no need for local storage. SAP assumes the opposite - connectivity is rarely consistent, especially on mobile devices - and therefore changing the architecture of apps to assume the disconnected state first provides a better user experience, while providing most of the benefits of SaaS.

What is Resin?
--------------

Resin is the PC client for running SAP apps. Rather than a single, dedicated web browser, Resin aims to be a tool for making standalone apps out of web app assets for clean integration into the host OS. 

Resin is a simple extension of the Chromium Embedded Framework. By simply changing the name of the application and including a manifest file that points Resin to your SAP-architected web app, Resin suddenly transforms into a fully-fledged, installable version of your app. And whenever the user is connected to the web, this app will automatically and transparently update itself to the latest version, simply by redownloading assets where the HTTP cache-control headers expire, just like a web browser. But unlike a web browser, the user can be completely disconnected from the web to use the app.

Building
--------

You first need to download the CEF binaries for your platform, available at http://cefbuilds.com/. Clone this repo, and decompress the archive contents into the project directory. 

For Mac OSX, the XCode project is configured to build from there.
For other platforms, stay tuned.

Making An App
-------------

Once you have a built version of Resin, making work as your custom app is just two steps:

1. Rename the package (TODO)
2. Include a package.json file (TODO)

I am working on a quick script that does this automatically, given the name of the app and the url to it. This could be run as a CGI script to dynamically create a link to download the app on a website. I may even set up a service for this.

Why not just use node-webkit?
-----------------------------
node-webkit and related frameworks are great for using web standards for desktop applications. But node-webkit app design encourages server-like code to be written in Node.JS, which complicates portability to the web. It would be possible to hack a SAP application together using something like require.js and a custom auto-updater, but CEF is such a straightforward platform that the additional pieces to build resin amount to less code, fewer moving pieces, and therefore easier support.

Why not just use PhoneGap/Cordova?
----------------------------------
PhoneGap inspired SAP, for sure. But PhoneGap is meant for standalone apps with a pre-defined manifest, which limits the transparent updating concept of SAP. So a new packaging concept was needed. For SAP, this packaging model is actually just a manifest - no zip, 7z, or native mobile app needs to be created, as Resin pulls the same resources as the web browser would.

Why not comply with the W3C "Widget" standard?
----------------------------------------------
For the same reasons PhoneGap isn't a good solution for SAP. Widgets are standalone apps with a pre-defined manifest.

Other SAP Projects
------------------
 * Syrup - SAP boilerplate using PouchDB and some other frameworks (Coming Soon).
 * Sugar - Android app for running SAP apps as if they were native apps (Coming Soon).

