# WinObjC Unit Tests on OSX

As a measure to help ensure the accuracy of the WinObjC platform, we are beginning to support building and running WinObjC unit tests on OSX devices. By verifying our tests against the reference platform, we hope to reduce errors in test writing and incorrect assumptions about Objective-C APIs. Foundation.UnitTests are currently supported, with other test modules expected to follow suit.

It is recommended that edits to unit tests be verified on an OSX machine, if the developer has access to one. A list of current known failures is provided at the bottom.

#### Sharing your Windows enlistment with an OSX machine

While it's possible to checkout a separate git enlistment on an OSX machine and build WinObjC tests, it's recommended that developers maintain just one enlistment and share it out to an OSX machine instead. Below are some example steps for setting up a shared enlistment/ssh workflow, assuming your machines are on the same network.

1. Windows machine - share your Windows WinObjC enlistment with yourself:

    1. Right-click your enlistment root > Share with > Specific people...
    2. Select your own account, then click 'Share'.
    3. You should receive an address for the shared folder.

2. OSX machine - mount the shared volume:

    1. Open Finder.
    2. Press Command+K (Go > Connect to Server).
    3. Type in the address generated in 1.3, then press Connect. (You may wish to press + to save the address as a favorite)
    4. Finder may regenerate the address with a URI scheme such as smb://. If so, press Connect again. (You may need to adjust the number of slashes)
    5. Finder should open your shared folder.

3. OSX machine - enable remote login:
    
    1. Open System Preferences > Sharing.
    2. Click the checkbox next to Remote Login
    3. The right side should say something like: 
        * Remote Login: On 
        * To log in to this computer remotely, type "ssh address@address.com"
    4. Make note of the address.
    
4. Windows machine - install PuTTY and ssh into your OSX machine:

    1. Install PuTTY from http://www.putty.org/
    2. Using the address from 3.4 - run "putty address@address.com"
    3. Type in your password.

#### Building & Running Foundation Unit Tests

1. In a shell, cd to \<enlistment root\>/tests/unittests/Foundation
    * If your enlistment is shared from another machine, such as in the recommended steps above, your enlistment root will be in /Volumes/ (eg: /Volumes/WinObjC/)
2. Run 'make Foundation.UnitTests.exe' - this creates Foundation.UnitTests.exe in your current directory
3. The makefile will print an output location for Foundation.UnitTests.exe, eg: 
    * Done, please run from /Volumes/WinObjC/build/Tests/UnitTests/Foundation/OSX/Foundation.UnitTests.exe

4. Run '/Volumes/WinObjC/build/Tests/UnitTests/Foundation/OSX/Foundation.UnitTests.exe', or your equivalent address - 
    * --gtest_filter and similar options are available

#### Current known failures:

There are no known failures in Foundation.UnitTests