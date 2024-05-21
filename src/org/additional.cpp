#include "org/additional.h"

std::string additional::SelectFolder()
{
    BROWSEINFOW bi;
    ZeroMemory(&bi, sizeof(bi));
    WCHAR path[MAX_PATH];

    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI;
    bi.lpszTitle = L"Select Folder";
    bi.pszDisplayName = path;
    bi.hwndOwner = NULL;

    LPITEMIDLIST pidl = SHBrowseForFolderW(&bi);
    if (pidl != 0)
    {

        if (SHGetPathFromIDListW(pidl, path))
        {

            int len = WideCharToMultiByte(CP_UTF8, 0, path, -1, NULL, 0, NULL, NULL);
            std::string folderPath(len, '\0');
            WideCharToMultiByte(CP_UTF8, 0, path, -1, &folderPath[0], len, NULL, NULL);

            return folderPath;
        }
    }

    return std::string("");
}

std::string additional::ConvertBackslashesToSlashes(const std::string &path)
{
    std::string convertedPath = path;
    std::replace(convertedPath.begin(), convertedPath.end(), '\\', '/');
    return convertedPath;
}

std::string additional::ReplaceNullWithSlash(const std::string &path)
{
    // std::string result = path;
    // std::string::size_type pos = 0;
    // while ((pos = result.find("\000/", pos)) != std::string::npos) {
    //     result.replace(pos, 2, "/"); // Заменяем \000/ на /
    //     pos += 1; // Продвигаемся на один символ
    // }
    // return result;
    // for (size_t i = 0; i < path.size(); i++)
    // {
    //     if (path[i]+path[i+1]+path[i+2]+path[i+3]=="\000")
    //     {
    //         path.erase(path.begin()+ i ,path.begin()+i+3);
    //     }

    // }
    // std::string target = "\000/";  
    // std::string replacement = "/"; 

    // size_t pos = path.find(target);
    // while (pos != std::string::npos)
    // {
    //     path.replace(pos, target.length(), replacement);     
    //     pos = path.find(target, pos + replacement.length());
    // }

    // return path;
}


std::string additional::RemoveBackslashAndZero(const std::string& input) {
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), '\\'), result.end());
    result.erase(std::remove(result.begin(), result.end(), '0'), result.end());
    return result;
}


std::string removeSubstring(std::string str, size_t start)
{
    if (start < str.length())
    {
        str.erase(start, 4);
    }
    return str;
}