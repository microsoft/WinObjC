# Windows Bridge for iOS

## **DEV DESIGN SPECIFICATION: NSUserDefaults

### Feature Summary

NSUserDefaults is a Foundation interface to CFPreferences that stores a preference plist in the package appdata directory.

### Technology/Architecture Decisions and Caveats

- Changes to standardDefaults are written to cache and synchronized to disk as soon as possible on an asynchronous queue.
- setObjectForKey and objectForKey are non-blocking and threadsafe with other NSUserDefaults calls, but are not threadsafe against calls to CFPreferences. Thus mixed calls to NSUserDefaults and CFPreferences can result in race conditions and should be avoided.
- synchronize is write only and does not read from file (read occurs only at initialization). External changes to the preferences file will be overwritten.
- CFPreferences currently has only minimal support necessary for NSUserDefaults functionality. Use with caution.
