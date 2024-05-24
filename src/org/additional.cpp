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

std::string additional::ConvertBackslashesToSlashes(std::string &path)
{

    for (size_t i = 0; i < path.length(); ++i)
    {
        if (path[i] == '\\')
        {
            path[i] = '/';
        }
    }

    return path;
}
