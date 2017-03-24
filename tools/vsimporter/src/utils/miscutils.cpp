//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "miscutils.h"
#include <time.h>
#include <Windows.h>
#include <string>

String getTime() {
    time_t rawtime;
    time(&rawtime);
    return ctime(&rawtime);
}

double getEpochTime() {
    time_t now;
    time(&now);
    struct tm start = { 0, 0, 0, 0, 0 };
    return difftime(now, mktime(&start));
}

void removeDupes(StringVec& vec) {
    StringSet found;
    StringVec ret;

    StringVec::const_iterator it = vec.begin();
    for (; it != vec.end(); it++) {
        if (found.insert(*it).second)
            ret.push_back(*it);
    }

    vec.assign(ret.begin(), ret.end());
}

// Checks whether or not the user has opted in to Visual Studio telemetry
bool checkTelemetryOptIn() {
    bool isOptIn = FALSE;
    const std::wstring basePath = L"Software\\Microsoft\\VSCommon";
    const std::wstring policyKeyPath = L"SOFTWARE\\Policies\\Microsoft\\VisualStudio\\SQM";
    const DWORD maxKeyLength = 255;

    // First check group policy
    HKEY policyKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, policyKeyPath.c_str(), 0, KEY_READ, &policyKey) == ERROR_SUCCESS) {
        WCHAR buffer[2];
        DWORD bufferSize = sizeof(buffer);

        if (RegQueryValueEx(policyKey, "OptIn", 0, NULL, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS) {
            if (wcscmp(buffer, L"0") == 0) {
                return FALSE;
            }
        }

        RegCloseKey(policyKey);
    }

    // Then check user preferences
    HKEY baseKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, basePath.c_str(), 0, KEY_READ, &baseKey) == ERROR_SUCCESS) {
        WCHAR subKeyName[maxKeyLength];
        DWORD subKeyNameSize;
        DWORD numSubKeys;

        DWORD i;
        if (RegQueryInfoKey(baseKey, NULL, NULL, NULL, &numSubKeys, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            for (i = 0; i < numSubKeys; i++) {
                subKeyNameSize = maxKeyLength;
                if (RegEnumKeyExW(baseKey, i, subKeyName, &subKeyNameSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
                    HKEY subHKey;
                    std::wstring subKeyNameStr(subKeyName);
                    std::wstring subPath = basePath + L"\\" + subKeyName + L"\\SQM";

                    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, subPath.c_str(), 0, KEY_READ, &subHKey) == ERROR_SUCCESS) {
                        DWORD value;
                        DWORD bufferSize = sizeof(DWORD);
                        if (RegQueryValueExW(subHKey, L"OptIn", NULL, NULL, (LPBYTE)(&value), &bufferSize) == ERROR_SUCCESS) {
                            if (!value) {
                                return FALSE;
                            } else {
                                isOptIn = TRUE;
                            }
                        }

                        RegCloseKey(subHKey);
                    }
                }
            }
        }

        RegCloseKey(baseKey);
    }

    return isOptIn;
}

// Generate boolean based on whether machine is internal to Microsoft. Return false if query fails.
bool isMSFTInternalMachine() {
    bool isInternal = false;
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Policies\\Microsoft\\SQMClient", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        DWORD result;
        DWORD size = sizeof(DWORD);
        if (RegQueryValueEx(hKey, "MSFTInternal", NULL, NULL, (LPBYTE)(&result), &size) == ERROR_SUCCESS) {
            isInternal = (bool)result;
        }

        RegCloseKey(hKey);
    }
    return isInternal;
}

// Generate a machine ID from SQMClient data. Return empty string if query fails.
std::string getMachineID() {
    HKEY machineHKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\SQMClient", 0, KEY_READ | KEY_WOW64_64KEY, &machineHKey) == ERROR_SUCCESS) {
        char buffer[39];
        DWORD bufferSize = sizeof(buffer);
        if (RegQueryValueEx(machineHKey, "MachineId", 0, NULL, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS) {
            RegCloseKey(machineHKey);
            return std::string(buffer);
        }

        RegCloseKey(machineHKey);
        return std::string("");
    }
    return std::string("");
}
