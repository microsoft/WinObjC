# Windows Bridge for iOS

## **DEV DESIGN SPECIFICATION: NSError + NSCFError**

### Feature Summary

NSError is a specially bridged class that, unlike other bridged classes, is subclassable without primitive method overrides.

### Technology/Architecture Decisions

Because of its subclassable nature, NSError must implement all methods, and its alloc methods must return an NSError rather than an instance of the concrete bridged subclass NSCFError.

### Design

NSError design:

- Unlike other bridged classes, NSError is not an abstract class and can be subclass without overriding any methods
- NSCFError is kept around as the bridged subclassed, but NSError alloc does not return NSCFError - only CFErrorCreate will return a NSCFError object
- NSCFError does not define any ivars and passes on all accessors to CFError
- NSCFError retain and release call CF equivalents, and CFRetain/Release recognize that NSError is not bridged while NSCFError is bridged
- NSError and NSCFError have identical memory layouts. CF accessors called on NSError therefore work appropriately. StrongId is used for NSError properties - while this does not strictly conform, we are safe because CFError accesses these properties only through getters.