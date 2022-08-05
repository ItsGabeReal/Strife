#pragma once

/* STrife Pre-Compiled Header:
* Include everything we use often and don't need to re-compile
* for every build. If this project becomes very large, having
* all of the common headers pre-compiled like this will decrease
* compile times considerably.
*/

// Utilities
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

// Data Types
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Platform Specific
#ifdef ST_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

