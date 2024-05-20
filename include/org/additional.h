#pragma once

#include <windows.h>
#include <shlobj.h>
#include <string>
#include <iostream>
#include <algorithm>

namespace additional
{
  std::string SelectFolder();
  std::string ConvertBackslashesToSlashes(const std::string& path);
}
